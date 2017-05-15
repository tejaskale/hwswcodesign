// processor.cpp

#include "processor.h"

void processor::software_code ()
{

    sc_time transfer_start_time = SC_ZERO_TIME;

    gp_status = TLM_INCOMPLETE_RESPONSE;
    transaction_delay = SC_ZERO_TIME;

    // do some initial processing
    wait(sc_time(CPU_INITIAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS));
    total_processing_time += sc_time(CPU_INITIAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS);
    if(LOG)
      cout<<sc_time_stamp()<<" "<<name()<<": initial processing done." << endl;

    while(true){

    for(int i=0; i<N_BLOCKS; i++)
    {
	// read data from memory
	// setup the generic payload
	trans.set_command(TLM_READ_COMMAND);
	trans.set_address(0);
	trans.set_data_length(128);
	trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
	// call transacion
	// make transaction until it is successfull
	transfer_start_time = sc_time_stamp();
	do
	{
    	//init transaction_delay
    	transaction_delay = SC_ZERO_TIME;

		processor_socket->b_transport(trans, transaction_delay);
	
		wait(transaction_delay);
		
		// evaluate return status of transaction
		gp_status = trans.get_response_status();
		      
		switch (gp_status) 
		{
		case TLM_OK_RESPONSE:  
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": memory read successful." << endl;   
			break;
		default:
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": memory read failed." <<endl;
			wait(sc_time(BACKOFF_LATENCY*PROCESSOR_CLK_PERIOD,SC_NS));
			break;
		}
	}
	while(gp_status != TLM_OK_RESPONSE);

	// account for transfer time
	total_transfer_time += sc_time_stamp()- transfer_start_time;

	if(ACCEL_PROC)
	{    // process data in accelerator
	        // write data to be processed to accelerator

		// setup the generic payload
		trans.set_command(TLM_WRITE_COMMAND);
		trans.set_address(1);
		trans.set_data_length(128);   // amount of encoded data is 128 bytes
		trans.set_response_status(TLM_INCOMPLETE_RESPONSE);

		// make transaction until it is successfull
		transfer_start_time = sc_time_stamp();
		do
		{
        	//init transaction_delay
        	transaction_delay = SC_ZERO_TIME;

			processor_socket->b_transport(trans, transaction_delay);
	
			wait(transaction_delay);
	
			// evaluate return status of transaction
			gp_status = trans.get_response_status();
     	
			switch (gp_status) 
			{
			case TLM_OK_RESPONSE:  
				if(LOG)
				  cout<<sc_time_stamp()<<" "<<name()<<": accelerator write successful." << endl;   
				break;
			default:
				if(LOG)
				  cout<<sc_time_stamp()<<" "<<name()<<": accelerator write failed." <<endl;
				wait(sc_time(BACKOFF_LATENCY*PROCESSOR_CLK_PERIOD,SC_NS));
				break;
			}
		}
		while(gp_status != TLM_OK_RESPONSE);

		// account for transfer time
		total_transfer_time += sc_time_stamp()- transfer_start_time;

		// read processed data back; 
		// read will return when processing is done in accelerator. until then CPU is blocked
		// setup the generic payload
		trans.set_command(TLM_READ_COMMAND);
		trans.set_address(1);
		trans.set_data_length(64);   // amount of decoded data is 64 bytes
		trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
	
		// make transaction until it is successfull
		transfer_start_time = sc_time_stamp();
		do
		{
        	//init transaction_delay
        	transaction_delay = SC_ZERO_TIME;

			processor_socket->b_transport(trans, transaction_delay);
	
			wait(transaction_delay);
	
			// evaluate return status of transaction
			gp_status = trans.get_response_status();
	
			switch (gp_status) 
			{
			case TLM_OK_RESPONSE:
				if(LOG)
				  cout<<sc_time_stamp()<<" "<<name()<<": accelerator read successful." << endl;   
				break;
			default:
				if(LOG)
				  cout<<sc_time_stamp()<<" "<<name()<<": accelerator read failed." <<endl;
				wait(sc_time(BACKOFF_LATENCY*PROCESSOR_CLK_PERIOD,SC_NS));
				break;
			}
		}
		while(gp_status != TLM_OK_RESPONSE);

		// account for transfer time
		total_transfer_time += sc_time_stamp()- transfer_start_time;

	}
	else
	{	// process data in CPU
		wait(sc_time(CPU_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS));
		total_processing_time += sc_time(CPU_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS);
		if(LOG)
		  cout<<sc_time_stamp()<<" "<<name()<<": processing done." << endl;
	}

	// write processed data back to memory
	// setup the generic payload
	trans.set_command(TLM_WRITE_COMMAND);
	trans.set_address(0);
	trans.set_data_length(64);
	trans.set_response_status(TLM_INCOMPLETE_RESPONSE);

	// make transaction until it is successfull
	transfer_start_time = sc_time_stamp();
	do
	{
    	//init transaction_delay
    	transaction_delay = SC_ZERO_TIME;

		processor_socket->b_transport(trans, transaction_delay);
		
		wait(transaction_delay);
		
		// evaluate return status of transaction
		gp_status = trans.get_response_status();
		
		switch (gp_status) 
		{
		case TLM_OK_RESPONSE:  
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": memory write successful." << endl;   
			break;
		default:
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": memory write failed." <<endl;
			wait(sc_time(BACKOFF_LATENCY*PROCESSOR_CLK_PERIOD,SC_NS));
			break;
		}
	}
	while(gp_status != TLM_OK_RESPONSE);

	// account for transfer time
	total_transfer_time += sc_time_stamp()- transfer_start_time;

    } // for loop	

    // do some final processing
    wait(sc_time(CPU_FINAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS));
    total_processing_time += sc_time(CPU_FINAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS);
    if(LOG)
	cout<<sc_time_stamp()<<" "<<name()<<": final processing done." << endl;

    break;	

    } // while true

    sc_stop();	// we are done. Stop simulation

    return;
	
}


void processor::hardware_code()
{

    sc_time transfer_start_time = SC_ZERO_TIME;

    // do some initial processing
    wait(sc_time(CPU_INITIAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS));
    total_processing_time += sc_time(CPU_INITIAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS);
    if(LOG)
      cout<<sc_time_stamp()<<" "<<name()<<": initial processing done." << endl;

    while(true)
    {
	// write address data to accelerator with DMA feature
	// setup the generic payload
	trans.set_command(TLM_WRITE_COMMAND);
	trans.set_address(1);
	trans.set_data_length(4*3); // we assume that two 32 bit addresses have to be transferred
				    // indicating the buffers of en/de-coded data and one integer indicating
				    // the number of blocks
	trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
	// call transacion
	// make transaction until it is successfull
	transfer_start_time = sc_time_stamp();
	do
	{
    	//init transaction_delay
    	transaction_delay = SC_ZERO_TIME;

		processor_socket->b_transport(trans, transaction_delay);
		
		wait(transaction_delay); // the accel should start working after transaction_delay
		
		// evaluate return status of transaction
		gp_status = trans.get_response_status();
		
		switch (gp_status) 
		{
		case TLM_OK_RESPONSE:  
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": accelerator DMA setup successful." << endl;   
			break;
		default:
			if(LOG)
			  cout<<sc_time_stamp()<<" "<<name()<<": accelerator DMA setup failed." <<endl;
			wait(sc_time(BACKOFF_LATENCY*PROCESSOR_CLK_PERIOD,SC_NS));
			break;
		}
	}
	while(gp_status != TLM_OK_RESPONSE);

	// account for transfer time
	total_transfer_time += sc_time_stamp()- transfer_start_time;

	wait(); // wait until accel has done its job and issues interrupt
		// wait according to sensitivity specification in Constructor

	if(LOG)
	  cout<<endl<<sc_time_stamp()<<" "<<name()<<": accelerator has issued interrupt." <<endl;

	// do some final processing
	wait(sc_time(CPU_FINAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS));
	total_processing_time += sc_time(CPU_FINAL_PROCESSING*PROCESSOR_CLK_PERIOD,SC_NS);
	if(LOG)
	  cout<<sc_time_stamp()<<" "<<name()<<": final processing done." << endl;

	break;
	
	} // while true

	sc_stop();  // processing is done, stop the simulation

}


void processor::output_load()
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

