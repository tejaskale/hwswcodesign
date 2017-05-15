#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void allread(FILE *fi, unsigned char *buf, int len);  

int main(int argc, char *argv[])
{
	int fd, rc, mf, frame_number;
	float cumulative = 0;
	unsigned char buf[16];
	int f_clocks;

	// needed for debugging the debugger....
	int wrap_position;

	//File pointer for reading and writting
	FILE *file_read;

	if (argc!=2) 
	{
		fprintf(stderr, "Usage: %s devfile\n", argv[0]);
		exit(1);
	}

/************************* Open debug fifo ******************************/
	// open xillybus device in binary mode
	if(!(file_read = fopen("/dev/xillybus_read_32", "rb")))
	{
		fprintf(stderr, "Error in opening /dev/xillybus_read_32\n");
		exit(0);
	}

	while(1)
	{

		allread(file_read, buf, sizeof(buf));		

		// normally, only the first option should apply
		if(*((unsigned int *)(buf)) == 0x3c3c3c3c) 
		{
			if(*((unsigned int *)(buf+12)) != 0x3e3e3e3e)
				continue;
			wrap_position = 0;
			f_clocks = *((unsigned int *)(buf+4));
			frame_number = *((unsigned int *) (buf+8));
		}
		else if(*((unsigned int *)(buf+4)) == 0x3c3c3c3c) 
		{
			if(*((unsigned int *)(buf)) != 0x3e3e3e3e)
				continue;
			wrap_position = 1;
			f_clocks = *((unsigned int *)(buf+8));
			frame_number = *((unsigned int *)(buf+12));
		}
		else if(*((unsigned int *)(buf+8)) == 0x3c3c3c3c) 
		{
			if(*((unsigned int *)(buf+4)) != 0x3e3e3e3e)
				continue;
			wrap_position = 2;
			f_clocks = *((unsigned int *)(buf+12));
			frame_number = *((unsigned int *)(buf));
		}
		else 
		{
			if(*((unsigned int *)(buf+8)) != 0x3e3e3e3e)
				continue;
			wrap_position = 3;
			f_clocks = *((unsigned int *)(buf));
			frame_number = *((unsigned int *)(buf+4));
		}

		// hardware debugger has a problem probably with FIFO write/read
		// therefore we skip obviously sensless values
		if(frame_number == 0x3c3c3c3c || frame_number == 0x3e3e3e3e || f_clocks == 0x3c3c3c3c || f_clocks == 0x3e3e3e3e || f_clocks == 0)
			continue;

		if(frame_number == 0)
			cumulative = (float)(f_clocks);
		else
			cumulative = cumulative + (float)(f_clocks);

		fprintf(stderr, "Frame no %d took %d clock cycles. Current overall average %d cycles per frame.\n",\
				frame_number, f_clocks, (int)(cumulative/(frame_number+1)));

		// used for debug purposes		
		// printf("%d Frame no %d took %d clock cycles. Current overall average %d cycles per frame.\n",\
				wrap_position, frame_number, f_clocks, (int)(cumulative/(frame_number+1)));
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
