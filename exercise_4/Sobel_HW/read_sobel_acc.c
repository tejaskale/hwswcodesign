#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> /* memset */
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define FRAME_WIDTH  854
#define FRAME_HEIGHT 480
#define FRAME_NUM    812
#define FRAME_MEM_SIZE ((FRAME_WIDTH) * (FRAME_HEIGHT) * (1.5))

void allread(FILE *fi, unsigned char *buf, int len);

/********************* MAIN FUNCTION**********************************/
int main(int argc, char *argv[]) 
{

/*********************************** Variable Declaration ******************************/
	int frame_num = 0; // loop variable
	size_t read_size, write_size;

	//File pointer for reading and writting
	FILE *file_read, *file_write;

	//Image FRAMES pointer
	unsigned char *img_ptr;

/************************** Argument Handler ***************************************/
	if(argc!=1) 
	{
		fprintf(stderr, "%s does not accept arguments\n", argv[0]);
		exit(1);
	}
  
/************************* Open accelerator device ******************************/
	// open xillybus device in binary mode
	if(!(file_read = fopen("/dev/xillybus_read_8", "rb")))
	{
		fprintf(stderr, "Error in opening /dev/xillybus_read_8\n");
		exit(0);
	}
	
/************************** Initialize buffer ****************************************/
	if(!(img_ptr = (unsigned char *) malloc((size_t)(FRAME_MEM_SIZE) * sizeof(unsigned char))))
	{
		fprintf(stderr, "\nMemory can not be allocated for processed frame");
		exit(0);
	}

	// pre-initialize UV component
	memset(img_ptr + (FRAME_WIDTH * FRAME_HEIGHT), 128, FRAME_MEM_SIZE - (FRAME_WIDTH * FRAME_HEIGHT));


/************* read processed frame from accelerator and write to stdout *************/
// last frame cannot be completely processed as not data will be fed into input FIFO  
// and pipeline thus stalls. Therefore, we stop one frame before
	for(frame_num = 0; frame_num < FRAME_NUM-1; frame_num++) 
	{
		// read processed Y component of frame
		allread(file_read, img_ptr, (size_t)(FRAME_WIDTH * FRAME_HEIGHT));

		//write the image including U and V components to stdout
		if(((write_size = fwrite(img_ptr, sizeof(unsigned char), (size_t)(FRAME_MEM_SIZE), stdout)) != (FRAME_MEM_SIZE)))
		{
			fprintf(stderr, "reached end of video file at frame number %d\n", frame_num);
			fprintf(stderr, "write size is %d\n", write_size);
			exit(0);
		}
	}
}



/************************************************************************ 
   Plain fread() may not read all bytes requested from the Xillybus FIFO, so
   allread() loops until all data was indeed read, or exits in case of failure.

   The function has no return value, because it always succeeds (or exits
   instead of returning).
*************************************************************************/


void allread(FILE *fi, unsigned char *buf, int len)
{
	int read_data = 0;
	int rc;

	while(read_data < len)
	{
		rc = fread(buf + read_data, sizeof(unsigned char), (size_t)(len - read_data), fi);

		if(rc == 0)
		{
			fprintf(stderr, "Reached read EOF (?!)\n");
			exit(1);
		}
		read_data += rc;
	}
}
