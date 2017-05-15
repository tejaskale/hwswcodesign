// consum_2.cpp

#include "consum_2.h"
#include "tlm.h"
#include "systemc.h"


#include <iostream>
#include <iomanip>

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;

//*******===============================================================*******
//*******                             consumer                          *******
//*******===============================================================*******
void consum_2::consumer(){

	tlm_generic_payload trans;
	tlm_response_status gp_status;
	sc_time delay = SC_ZERO_TIME;
	int data_length;                 // number of data to be read [1; 16]
	unsigned char* consum_data = new unsigned char[16];  // buffer for read data
 
	while(true){

		// generate read request of random lenght between 1 and 16 bytes

		// fill in

		// setup the generic payload

		// fill in

		// wait on trigger to read the data

		// fill in

		// output message 
		cout<<endl<<sc_time_stamp()<<" consumer wants to read "<<data_length<<" bytes."<<endl;

		// call transacion

		// fill in


		wait(delay);

		// evaluate return status of transaction
		gp_status = trans.get_response_status();
		data_length = trans.get_data_length();
        
		switch (gp_status) {
		case TLM_OK_RESPONSE:  
			cout<<endl<<sc_time_stamp()<<" consumer read successful: 0x ";
			cout << hex;               // switch to hexadecimal mode;
			for(int i=0;i<data_length;i++)
				cout << std::setw(2) << std::setfill('0') << (int)*(consum_data+i)<<" ";
			cout << dec  << " read." << endl;   
			break;		
		case TLM_INCOMPLETE_RESPONSE:  
			cout<<endl<<sc_time_stamp()<<" consumer read partially successful: 0x";
			cout << hex;               // switch to hexadecimal mode;
			for(int i=0;i<data_length;i++)
				cout << std::setw(2) << std::setfill('0') << (int)*(consum_data+i);
			cout << dec  << " read." << endl;   
			break;		
		default:
			cout<<endl<<sc_time_stamp()<<" consumer read failed."<<endl;
			break;
		}

    } // end while true
} // end consumer



//*******===============================================================*******
//*******                            fetch_trigger                      *******
//*******===============================================================*******

void consum_2::fetch_trigger(){

  while(true){
    wait(1200, SC_NS);
    fetch_event.notify(0, SC_NS);
    wait(800, SC_NS);
    fetch_event.notify(0, SC_NS);
    wait(1000, SC_NS);
    fetch_event.notify(0, SC_NS);
    wait(800, SC_NS);
    fetch_event.notify(0, SC_NS);
    wait(600, SC_NS);
    fetch_event.notify(0, SC_NS);
    wait(1200, SC_NS);
    fetch_event.notify(0, SC_NS); 
  }
}

