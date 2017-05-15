// traffic_generator.cpp

#include "traffic_generator.h"

void traffic_generator::gen_traffic()
{

  	tlm_generic_payload trans;
  	tlm_response_status gp_status;
  	sc_time access_delay = SC_ZERO_TIME;
  	sc_time trans_delay = SC_ZERO_TIME;

  	unsigned int data_length;
  	unsigned int traffic_latency;
	
  	while(true)
	{
 
  		traffic_latency = 1+rand()%INTERARRIVAL_DELAY_MAX_LATENCY;
  		access_delay = sc_time(traffic_latency, SC_NS);

   		wait(access_delay);

 		data_length = 1+rand()%MAX_DATA_LENGTH; 

  		if(rand()%2 == 1)
			trans.set_command(TLM_WRITE_COMMAND);
		else
			trans.set_command(TLM_READ_COMMAND);

  		trans.set_data_length(data_length);
  		trans.set_address(0); // memory
  		trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
  
  		do
  		{
          	//init trans_delay
    	    trans_delay = SC_ZERO_TIME;

			generator_socket->b_transport(trans, trans_delay);
			wait(trans_delay);
 	  		gp_status = trans.get_response_status();
   			if(trans.get_response_status() == TLM_GENERIC_ERROR_RESPONSE)
				wait(sc_time(BACKOFF_LATENCY*RG_CLOCK_PERIOD,SC_NS));
  		} while(gp_status != TLM_OK_RESPONSE);
  	}
}
