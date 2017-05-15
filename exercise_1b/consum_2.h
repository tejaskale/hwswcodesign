// consum_2.h

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"

// to make things easier readable ...
using namespace sc_core;
using namespace tlm_utils;


SC_MODULE(consum_2)
{
	public:
	// socket to interconnect with FIFO

	// fill in

	
	private:
	// event for communication between consumer() and fetch_trigger()
	sc_event fetch_event;


	// *******===============================================================******* //
	// *******                      member_functions, processes              ******* //
	// *******===============================================================******* //
	
	private:
	void consumer();
	void fetch_trigger();


	// *******===============================================================*******
	// *******                             constructor                       *******
	// *******===============================================================*******

	public:

	// fill in
	
	
};

