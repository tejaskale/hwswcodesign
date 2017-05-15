// accelerator.cpp

#include "accelerator.h"

void accelerator::b_transport(tlm_generic_payload &trans, sc_time &delay_time)
{
	unsigned int length;
	
	command   = trans.get_command();
	length   = trans.get_data_length(); // data length

	if(LOG)
	  cout<<sc_time_stamp()<<" "<<name()<<": command="<<command<<" length="<<length<<endl;

	if(DMA_MODE == false)
	{
	    if(sc_time_stamp()<accel_busy_end_time && command == TLM_WRITE_COMMAND) // read is accepted to enable 
										    // a blocking read to fetch the
										    // processed data
	    {
		if(LOG)
		  cout<<sc_time_stamp()<<" "<<name()\
			<<": I am busy, write request denied, no now processing can be initiated."<< endl;
		trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
		return;
	    }
		
	    switch (command)
	    {
	    case TLM_WRITE_COMMAND: // we assume that now processing can start 
				    // right after the transfer
					
		trans.set_response_status(TLM_OK_RESPONSE);
		delay_time += sc_time(ceil(length/4)*BUS_CLK_PERIOD, SC_NS);
		// CPU will have to wait for delay_time representing the transfer duration
			
		// accelerator starts after delay_time and will be busy until accel_busy_end_time
		accel_busy_end_time = sc_time_stamp()+sc_time(ceil(length/4)*BUS_CLK_PERIOD, SC_NS)+\
			sc_time(ACCEL_PROCESSING*ACCELERATOR_CLK_PERIOD, SC_NS);
		total_processing_time += sc_time(ACCEL_PROCESSING*ACCELERATOR_CLK_PERIOD, SC_NS);

		if(LOG)
		  cout<<sc_time_stamp()<<" "<<name()<<": receiving "<<length<<" bytes. Processing starts in "\
			<<delay_time<<" (duration  "\
			<<sc_time(ACCEL_PROCESSING*ACCELERATOR_CLK_PERIOD, SC_NS)<<".)"<<endl;
			
		break;
		
	    case TLM_READ_COMMAND:
		if(sc_time_stamp()<accel_busy_end_time){
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": processing not yet complete. You have to wait..."<<endl;
				wait(accel_busy_end_time - sc_time_stamp());
			}
		trans.set_response_status(TLM_OK_RESPONSE);
		delay_time += sc_time(ceil(length/4)*BUS_CLK_PERIOD, SC_NS);
		// CPU will have to wait for this time
		return;

	    default:
		trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
		if(LOG)
		  cout <<sc_time_stamp()<<" " \
		       << name()<<": invalid command. We should have never reached this line..."<< endl;
		break;
	    } // switch(command)
	}	
	else // If DMA_MODE is true
	{
	    if(accel_busy){
	        if(LOG)
		  cout<<sc_time_stamp()<<" "<<name()<<": I am busy, request denied"<< endl;
		trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
		return;
	    }
		
	    switch (command)
	    {
		case TLM_WRITE_COMMAND: // we assume that now the DMA descriptor is written,which defines
					// where to fetch and store the data before and after processing
			// we need delay_time to transfer the DMA descriptor
			delay_time += sc_time(ceil(length/4)*BUS_CLK_PERIOD, SC_NS);
			trans.set_response_status(TLM_OK_RESPONSE);
			if(LOG)
			  cout <<sc_time_stamp()<<" "<< name()<<": DMA programmed. ..."<< endl;

			// accel will have to start processing after the transfer time
			// the event idct_with_dma_start is used to trigger start of processing, 
			// which is implemented in the process idct_with_dma()
			idct_with_dma_start.notify(sc_time(ceil(length/4)*BUS_CLK_PERIOD, SC_NS));

			break;
		case TLM_READ_COMMAND: // will not be required in DMA_MODE
			trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
			if(LOG)
			  cout <<sc_time_stamp()<<" " \
			     << name()<<": No READ command in DMA_MODE. Will be ignored..."<< endl;
			break;
		default:	
			trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
			if(LOG)
			  cout <<sc_time_stamp()<<" " \
			     << name()<<": invalid command. We should have never reached this line..."<< endl;
			break;
	    } // wswitch(command)
	} // IF DMA MODE is true

	return;
	
} //b_transport


void accelerator::idct_with_dma()
{

	tlm_generic_payload trans;
	tlm_response_status gp_status;
	sc_time transaction_delay;
	sc_time transfer_start_time;


	// fill in here......



    	return;
	
} //idct_with_dma


void accelerator::output_load()
{
   if(LOG)
   {
	cout <<name()<<" total processing time: " << total_processing_time <<endl;
	cout <<name()<<" total transfer time  : " << total_transfer_time <<endl;
   }
   cout <<name()<<fixed<<setprecision(1)<<" load: processing " << (total_processing_time)/(sc_time_stamp())*100 \
        << "%, transfering "<< (total_transfer_time)/(sc_time_stamp())*100<< "%, in sum: "\
	<< (total_transfer_time+total_processing_time)/(sc_time_stamp())*100<< "%."<< endl;
  }


