// memory.cpp

#include "memory.h"

void memory::b_transport(tlm_generic_payload  &gp, sc_time &delay_time)
{
	unsigned char    *data;
	unsigned  int     length;
	tlm_command command;
		
	// Access the required attributes from the payload.
	// As we do not store actual data, neither data or address are required,
	// we only need type of access and amount of data 
	command  = gp.get_command();     // memory command
	length   = gp.get_data_length(); // data length
  
  	
	// take account of memory access latency
  	delay_time += sc_time(MEM_ACCESS_LATENCY*MEMORY_CLK_PERIOD, SC_NS);

	// execute command and account of memory tranfer latency for a 32 bit wide memory
	switch (command)
	{
		case TLM_WRITE_COMMAND:
		{
			delay_time += sc_time(ceil(length/4)*MEMORY_CLK_PERIOD, SC_NS);
			if(LOG)
			  cout << sc_time_stamp()<<" "<<name()<<" write: delay time " <<delay_time<<endl;
			break;     
		}

		case TLM_READ_COMMAND:
		{
			delay_time += sc_time(ceil(length/4)*MEMORY_CLK_PERIOD, SC_NS);
			if(LOG)
			   cout << sc_time_stamp()<<" "<<name()<<" read: delay time " <<delay_time<<endl;
			break;
		}
	
		default:
		{
			if(LOG)
			  cout <<sc_time_stamp() <<" "\
			     << name()<<": invalid command. We should have never reached this line..."<< endl;
			break;
		}
	} 

	gp.set_response_status(TLM_OK_RESPONSE);
  
	return;
} 
