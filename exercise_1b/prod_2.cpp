// prod_2.cpp

#include "prod_2.h"
#include "tlm.h"
#include "systemc.h"

#include <iostream>
#include <iomanip>

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;

// *******===============================================================******* //
// *******                             producer                          ******* //
// *******===============================================================******* //

 void prod_2 :: producer2 () {
  
    tlm_generic_payload trans;
    tlm_response_status gp_status;
    sc_time delay = SC_ZERO_TIME;
    int data_length;
    unsigned char* prod_data = new unsigned char[16];

    while(true){

	// generate random data of random lenght between 1 and 16 bytes
	data_length = 1+rand()%16;
	for(int i=0;i<data_length;i++)
		*(prod_data+i) = rand()%256;

	// setup the generic payload
	trans.set_command(TLM_WRITE_COMMAND);
	trans.set_data_length(data_length);
	trans.set_data_ptr(prod_data);
	trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
    
	wait(send_event);

	// output message 
	cout<<endl<<sc_time_stamp()<<" producer wants to write "<<data_length<<" bytes: 0x ";
	cout << hex;                     // switch to hexadecimal mode
	for(int i=0;i<data_length;i++)
		cout << std::setw(2) << std::setfill('0') << (int)*(prod_data+i)<<" ";
	cout << dec << endl;             // switch back to decimal mode
	
	// call transacion
	prod2fifo_socket->b_transport(trans, delay);

	wait(delay);

	// evaluate return status of transaction
	gp_status = trans.get_response_status();
	data_length = trans.get_data_length();   // actually number of written data
      
	switch (gp_status) 
	{
	case TLM_OK_RESPONSE:  
		cout<<endl<<sc_time_stamp()<<" producer write successful." << endl;   
		break;
	case TLM_INCOMPLETE_RESPONSE:  
		cout<<endl<<sc_time_stamp()<<" producer write partially successful." << endl;   
		break;
	default:
		cout<<endl<<sc_time_stamp()<<" producer write failed."<<endl;
		break;
	}

    }  // end while true
}  // end producer2 



// *******===============================================================******* //
// *******                             send_trigger                      ******* //
// *******===============================================================******* //

void prod_2::send_trigger() {

  while(true){
    wait(300, SC_NS);
    send_event.notify(0, SC_NS);
    wait(800, SC_NS);
    send_event.notify(0, SC_NS);
    wait(200, SC_NS);
    send_event.notify(0, SC_NS);
    wait(200, SC_NS);
    send_event.notify(0, SC_NS);
    wait(200, SC_NS);
    send_event.notify(0, SC_NS);
    wait(400, SC_NS);
    send_event.notify(0, SC_NS);
    wait(1000, SC_NS);
    send_event.notify(0, SC_NS);
    wait(1000, SC_NS);
    send_event.notify(0, SC_NS);
    wait(400, SC_NS);
    send_event.notify(0, SC_NS);
  }
}
