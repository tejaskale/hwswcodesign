//fifo_2.cpp

#include "fifo_2.h"			// our header file
#include "tlm.h"
#include "systemc.h"


#include <iostream>
#include <iomanip>
             
// to make things easier readable...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;


//*******================================================*******
//  b_transport implementation calls from initiators 
//*******================================================*******
void                                        
fifo_2::b_transport
( tlm_generic_payload  &payload,               // ref to Generic Payload 
  sc_time              &delay_time             // ref to delay time 
)
{ 
	unsigned int first_part;
	tlm_response_status status;

	// functions to get information out of the generic payload
	tlm_command cmd = payload.get_command();  // determine operation
	unsigned char* ptr = payload.get_data_ptr();   // get pointer to data
	unsigned int len = payload.get_data_length();  // how much data
	
	if(cmd == TLM_WRITE_COMMAND)
	{
		if(fill_level == fifo_size){ // no free space
			status = TLM_GENERIC_ERROR_RESPONSE;
			payload.set_response_status(status);
			return;
		}
		if(fill_level+len > fifo_size){ // not enough space for all data
			len = fifo_size-fill_level;  // less data will be written
			payload.set_data_length(len);
			status = TLM_INCOMPLETE_RESPONSE;
		}
		else
			status = TLM_OK_RESPONSE;			

		if(write_addr+len < fifo_size)  // write in one chunk
			memcpy((fifo_data+write_addr), ptr, len);
		else{
			first_part = fifo_size-write_addr; // write in two chunks
			memcpy((fifo_data+write_addr), ptr, first_part);
			memcpy((fifo_data), ptr+first_part, len-first_part);
		}

		write_addr = (write_addr+len)%fifo_size;

		fill_level = fill_level + len;

		cout << endl << sc_time_stamp() << " fifo: 0x ";
		cout << hex;
		for(int i=0;i<len;i++)
			cout << std::setw(2) << std::setfill('0') << (int)*(ptr+i) << " ";
		cout << dec  << " written. "<< endl;
		cout << "Current write address: " << write_addr<<" fill level "<< fill_level << endl;   
		output_fifo_status();
	}

	else if(cmd == TLM_READ_COMMAND)
	{
		if(fill_level == 0){
			status = TLM_GENERIC_ERROR_RESPONSE;
			payload.set_response_status(status);
			return;
		}

		if(fill_level < len){ // not enough data to read
			len = fill_level;  // less data will be read
			payload.set_data_length(len);
			status = TLM_INCOMPLETE_RESPONSE;
		}
		else
			status = TLM_OK_RESPONSE;

		if(read_addr+len < fifo_size)  // read in one chunk
			memcpy(ptr, (fifo_data+read_addr), len);
		else{
			first_part = fifo_size-read_addr; // read in two chunks
			memcpy(ptr, (fifo_data+read_addr), first_part);
			memcpy(ptr+first_part, (fifo_data), len-first_part);
		}

		read_addr = (read_addr+len)%fifo_size;
		fill_level = fill_level - len;
  
		cout << endl << sc_time_stamp() << " fifo: 0x ";
		cout << hex;
		for(int i=0;i<len;i++)
			cout << std::setw(2) << std::setfill('0') << (int)*(ptr+i) << " ";
		cout << dec  << " read. " << endl;
		cout << "Current read address: " << read_addr<<" fill level "<< fill_level << endl;  
		output_fifo_status();
	}
	// set dalay according to transfertime of len bytes over 32 bit wide interface
	// with 50 ns cycle time
	delay_time = sc_time((int)((len+3)/4)*50, SC_NS);
	payload.set_response_status(status);
	return;

}


// helper function to output content of FIFO as a text line
void fifo_2::output_fifo_status()
{
		cout << hex;    // switch to hexadecimal mode;
		if(fill_level==0)
			for(int i=0;i<fifo_size;i++)
				cout<<"-- ";
		else if(fill_level==fifo_size)
			for(int i=0;i<fifo_size;i++)
				cout<<std::setw(2)<<std::setfill('0')<<(int)*(fifo_data+i)<<" ";
		else if(write_addr>read_addr)
			for(int i=0;i<fifo_size;i++)
				if((i>=read_addr)&&(i<write_addr))
					cout<<std::setw(2)<<std::setfill('0')<<(int)*(fifo_data+i)<<" ";
				else
					cout<<"-- ";
		else if(write_addr<read_addr)
			for(int i=0;i<fifo_size;i++)
				if((i>=read_addr)||(i<write_addr))
					cout<<std::setw(2)<<std::setfill('0')<<(int)*(fifo_data+i)<<" ";
				else
					cout<<"-- ";
		cout << dec<<endl;
}

