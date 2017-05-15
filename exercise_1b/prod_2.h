// prod_2.h

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"

// to make things easier readable ...
using namespace sc_core;
using namespace tlm_utils;

SC_MODULE(prod_2)
{
	public:
	// socket to interconnect with FIFO
	simple_initiator_socket<prod_2> prod2fifo_socket;
	
	private:
	// event for communication between producer() and send_trigger()
	sc_event send_event;

	// *******===============================================================******* //
	// *******                      member_functions, processes              ******* //
	// *******===============================================================******* //
	
	private:
	void producer2(); 
	void send_trigger();

	// *******===============================================================******* //
	// *******                             constructor                       ******* //
	// *******===============================================================******* //
	
	public:
	SC_CTOR(prod_2):
	  prod2fifo_socket("prod2fifo_socket")  // call constructor of prod2fifo_socket
	{
    
	// registration of processes
	SC_THREAD(producer2);
	SC_THREAD(send_trigger);

	} 

};
