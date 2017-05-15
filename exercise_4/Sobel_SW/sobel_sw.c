#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> /* memset */
#include <unistd.h> /* close */
#include <math.h>

//Declare Height Width and  Number of Frames of video
#define FRAME_HEIGHT      480 
#define FRAME_WIDTH       854
#define FRAME_NUM   	  812
#define DEFAULT_THRESHOLD 20

/************** function prototypes ********************************************/

//allocation of memory
void init(unsigned char **img_ptr_input, unsigned char **img_ptr_output);
// For Loading Video File
void frame_load(unsigned char *img_ptr_input, FILE *file_read, const int frame_num);
//Sobel operation 3 x 3 matrix
void sobel_3x3(unsigned char *in, unsigned char *out, const int frame_width, const int frame_height, const size_t threshold);
//Saving each frame to output file
void frame_write(unsigned char *img_ptr_output);



/********************* MAIN FUNCTION**********************************/

int main(int argc, char * argv[])
{    
/*********************************** Variable Declaration ******************************/
	int frame_num = 0 ; // loop variable
	int  threshold = DEFAULT_THRESHOLD; // input arguments

	// variables for time measurement
	struct timespec start, stop;
	float cumulative_frame_time_in_ms = 0;
	long int frame_time_in_us;

	//File pointer for reading and writting
	FILE *file_read, *file_write;

	//Image FRAMES pointer's
	unsigned char *img_ptr_input;
	unsigned char *img_ptr_output;

/*************************************************************************************/
	// Argument Handler
	if(argc == 3)
	{
		fprintf(stderr, "File %s will be read.\n", argv[1]);

		threshold = atoi(argv[2]); // threshold could be anything between 0 to 255 otherwise use default
		if(threshold < 0 || threshold > 255)
		{
			threshold = (int) DEFAULT_THRESHOLD;
			fprintf(stderr, "%s is not a correct value for threshold.\nProgram will run with default threshold of %d \n",\
				argv[2], (int)DEFAULT_THRESHOLD);
		}
	}
	else if(argc == 2)
	{
		fprintf(stderr, "File %s will be read.\n", argv[1]);

		threshold = (int)DEFAULT_THRESHOLD; // use default Threshold
	}
	else
	{
		fprintf(stderr, "Wrong number of arguments: %s input_file [threshold]\n", argv[0]);
	}

/*********************************** Open input file  ***************************************/
	
	//Read Input imgae file in binary mode
	if(!(file_read = fopen(argv[1], "rb")))
	{
		fprintf(stderr, "\nError in opening input file %s\n", argv[1]);
		exit(0);
	}
	
/****************************** Allocate memory for storing frames  ******************************/

	init(&img_ptr_input, &img_ptr_output);
	
/********************************* Processing frame by frame  ************************************/
	for(frame_num = 0; frame_num < FRAME_NUM; frame_num++) 
	{
		frame_load(img_ptr_input, file_read , frame_num);

		clock_gettime(CLOCK_REALTIME, &start);
		sobel_3x3(img_ptr_input, img_ptr_output, FRAME_WIDTH, FRAME_HEIGHT, threshold);
		clock_gettime(CLOCK_REALTIME, &stop);

		frame_time_in_us = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_nsec - start.tv_nsec)/1000;
		cumulative_frame_time_in_ms += frame_time_in_us/1000;

		fprintf(stderr, "\rFrame no %d took %.3f ms. Current overall average processing time per frame:  %d ms ",\
			frame_num, frame_time_in_us/1000.0, (int)(cumulative_frame_time_in_ms/(frame_num+1)));

		frame_write(img_ptr_output);
	}
	
	fclose(file_read);
	return 0;
}

/*
  Function: init

  Allocates memory equivalent to the frame size for processed and unprocessed frame.  

  Parameters:

  img_ptr_input - Memory pointer of the memory allocated to unprocessed frame.
  img_ptr_output - Memory pointer of the memory allocated to processed frame.
     

  Returns:

  Void

        
*/

void init(unsigned char **img_ptr_input, unsigned char **img_ptr_output)
{
	size_t temp;
	//for input frame
	if(!(*img_ptr_input = (unsigned char *) malloc((size_t)(1.5f * FRAME_WIDTH * FRAME_HEIGHT) * sizeof(unsigned char))))
	{
		fprintf(stderr, "\nMemory can not be allocated for unprocessed frame");
		exit(0);
	}

	//for output frame
	if(!(*img_ptr_output = (unsigned char *) malloc((size_t)(1.5f * FRAME_WIDTH * FRAME_HEIGHT) * sizeof (unsigned char))))
	{
		fprintf(stderr, "\nMemory can not be allocated for processed frame");
		exit(0);
	}

	temp = (size_t)(1.5f * FRAME_WIDTH * FRAME_HEIGHT) * sizeof(unsigned char);
	memset(*img_ptr_output, 128, temp); // sets initial value of memory block

}

/*
  Function: frame_load

  loades the unprocessed frame from input file to main memory 

  Parameters:

  img_ptr_input - Memory pointer of the memory allocated to unprocessed frame.
  file_read - The file from which the frame has to be copied to main memory.
  frame_num - Counts the number of frame.

  Returns:

  Void

  See Also:

  <frame_save>
*/

void frame_load(unsigned char *img_ptr_input, FILE *file_read, const int frame_num)
{
	//size of file in term of bytes
	size_t read_size;
	
	//read the image and store bytes in Input_Imgae_ptr along with get its size in terms of bytes in read_size
	if(((read_size = fread(img_ptr_input, sizeof(unsigned char), (size_t)(1.5f * FRAME_WIDTH * FRAME_HEIGHT), file_read)) != (1.5 * FRAME_HEIGHT * FRAME_WIDTH)))
	{
		fprintf(stderr, "reached end of video file at frame number %d\n", frame_num);
		fprintf(stderr, "read size is %d\n", read_size);
		exit(0);
	}
}


/*
  Function: sobel_3x3

  applies 3x3 sobel edge detection filter on unprocessed frame from main memory and saves the processed frame in main memory

  Parameters:

  in - Memory pointer of the memory allocated to unprocessed frame.
  out - Memory pointer of the memory allocated to processed frame.
  frame_width - Width of the frame.
  frame_height - Height of the frame.
  threshold - Threshold for edhe detection.
      

  Returns:

  Void

*/
void sobel_3x3(unsigned char *in, unsigned char *out, const int frame_width, const int frame_height, const size_t threshold)
{
	//row for Number of Row and col for Number of Colomn
	int row, col;
	
	//gradient of image in horizontal and vertical direction and final gradient
	float gradient_h, gradient_v ;

	//
	// WRITE YOUR CODE HERE
	//
	// declare more local variables if you need them
	// 
}


/*
  Function: frame_wite
  
  Saves the processed frame from main memory to stdout

  Parameters:
  
  img_ptr_output - Memory pointer of the processed frame.
  
  Returns:
  
  Void

  See Also:
  
  <frame_load>
*/
void frame_write(unsigned char *img_ptr_output)
{
	fwrite(img_ptr_output, sizeof(unsigned char), (size_t)(1.5 * FRAME_WIDTH * FRAME_HEIGHT), stdout);
}
