#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> /* close */

//Declare Height Width and  Number of Frames of video
#define FRAME_HEIGHT      480 
#define FRAME_WIDTH       854
#define FRAME_NUM   	  812
#define FRAME_MEM_SIZE ((FRAME_WIDTH) * (FRAME_HEIGHT) * (1.5))


void allwrite(FILE *fo, unsigned char *buf, int len);


/********************* MAIN FUNCTION**********************************/

int main(int argc, char * argv[])
{    
/*********************************** Variable Declaration ******************************/
	int frame_num = 0 ; // loop variable
	size_t read_size, write_size;

	//File pointer for reading and writting
	FILE *file_read, *file_write;

	//Image FRAMES pointer
	unsigned char *img_ptr;

	// variables for time measurement		
	struct timespec start, stop;
	float cumulative_frame_time_in_ms = 0;
	long int frame_time_in_us;

/************************** Argument Handler ***************************************/
	if(argc == 2)
	{
		fprintf(stderr, "File %s will be read.\n", argv[1]);

	}
	else
	{
		fprintf(stderr, "Wrong number of arguments: %s input_file\n", argv[0]);
	}

/********************* Open input file and accelerator device **************************/
	// open input image file in binary mode
	if(!(file_read = fopen(argv[1], "rb")))
	{
		fprintf(stderr, "\nError in opening input file %s\n", argv[1]);
		exit(0);
	}
	
	// open xillybus device in binary mode
	if(!(file_write = fopen("/dev/xillybus_write_8", "wb")))
	{
		fprintf(stderr, "\nError in opening /dev/xillybus_write_8\n");
		exit(0);
	}
	
/************************** Initialize buffer ****************************************/
	if(!(img_ptr = (unsigned char *) malloc((size_t)(FRAME_MEM_SIZE) * sizeof(unsigned char))))
	{
		fprintf(stderr, "\nMemory can not be allocated for unprocessed frame");
		exit(0);
	}

/******************************** copy frame to output file / named pipe  ****************************/
	for(frame_num = 0; frame_num < FRAME_NUM; frame_num++) 
	{
		// we measure the duration of a frame period that consists of reading from file and writing to accel
		clock_gettime(CLOCK_REALTIME, &start); 
		
		//read the image and store bytes in Image_ptr along with get its size in terms of bytes in read_size
		if(((read_size = fread(img_ptr, sizeof(unsigned char), (size_t)(FRAME_MEM_SIZE), file_read)) != (FRAME_MEM_SIZE)))
		{
			fprintf(stderr, "reached end of video file at frame number %d\n", frame_num);
			fprintf(stderr, "read size is %d\n", read_size);
			exit(0);
		}

		//write the image from Image_ptr to output; write only Y component, U and V components are not needed
		allwrite(file_write, img_ptr, (size_t)(FRAME_WIDTH * FRAME_HEIGHT));

		// now a period is over
		clock_gettime(CLOCK_REALTIME, &stop);
	
		frame_time_in_us = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_nsec - start.tv_nsec)/1000;
		cumulative_frame_time_in_ms += frame_time_in_us/1000;

		fprintf(stderr, "\rFrame no %d took %.3f ms. Current overall average time per frame:  %.1f ms ",\
			frame_num, frame_time_in_us/1000.0, cumulative_frame_time_in_ms/(frame_num+1));
	}

	fclose(file_read);
	return 0;
}


/************************************************************************ 
   Plain fwrite() may not write all bytes to the Xillybus FIFO, so
   allwrite() loops until all data was indeed written, or exits in case of failure.

   The function has no return value, because it always succeeds (or exits
   instead of returning).
*************************************************************************/

void allwrite(FILE *fo, unsigned char *buf, int len)
{
	int sent = 0;
	int wc;

	while(sent < len) 
	{
		wc = fwrite(buf + sent, sizeof(unsigned char), (size_t)(len - sent), fo);

		if(wc == 0) 
		{
			fprintf(stderr, "Reached write EOF (?!)\n");
			exit(1);
		}
		sent += wc;
	}
} 
