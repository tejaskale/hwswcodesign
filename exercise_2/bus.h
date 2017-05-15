//bus.h

#ifndef __BUS_H__
#define __BUS_H__

#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc"
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"
#include "tlm_utils/simple_initiator_socket.h"

#include "global_definitions.h"

// to make things easier readable ...
using namespace std;
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;


SC_MODULE(bus)
{

public:
	// we have more trget and initiator sockets
	// number will be determined at instantiation of the bus via parameters to the constructor
	// therefore we use pointers to these sockets an instantiate them in the constructor
	// we use special versions of these sockets: tagged sockets allow to differentiate
	// via which socket the b_transport function has been called
	simple_target_socket_tagged<bus> *bus_target_socket;
	simple_initiator_socket_tagged<bus> *bus_initiator_socket;


private:
	sc_time bus_busy_end_time;  // stores time when the bus gets free
	sc_time total_busy_time;    // stores accumulated busy time
  
	bool ongoing_b_transport;  // helps to resolve blocking accesses
				   // where slave uses wait() 
	bool secondary_access_arbitrated; // indicates that secondary access has aleready been arbitrated
					  // te secondary will become active if the primary has finished
	sc_event primary_access_done; // used to trigger a potential secondary access
 
	unsigned int BUS_CLK_PERIOD;
	int NR_OF_MASTERS;
	int NR_OF_SLAVES;

public:
	// this version of b_transport has the additional parameter SocketId which identifies
	// the socket that called b_transport
	void b_transport(int SocketId, tlm_generic_payload& trans, sc_time& t);

	void output_load();

	// needed as we do not use SC_CTOR for the constructor
	SC_HAS_PROCESS(bus);

	public:
	// constructor with parameters /therefore we cannot use SC_CTOR()

	bus(sc_module_name name_, unsigned int bus_clk_p_, int nr_ma_, int nr_sl_):
		sc_module(name_),            // call constructor of sc_module 
		BUS_CLK_PERIOD(bus_clk_p_),  // set value for BUS_CLK_PERIOD
		NR_OF_MASTERS(nr_ma_),       // set value for NR_OF_MASTERS
		NR_OF_SLAVES(nr_sl_)         // set value for NR_OF_SLAVES
	{

		// instantiate the required number of sockets
		bus_target_socket = new simple_target_socket_tagged<bus>[NR_OF_MASTERS];
		bus_initiator_socket = new simple_initiator_socket_tagged<bus>[NR_OF_SLAVES];
		// notice: each bus slave is connected to an initiator socket of the bus
		//         each bus master is connected to a target of the bus


		for (unsigned int i = 0; i < NR_OF_MASTERS; ++i) 
			bus_target_socket[i].register_b_transport(this, &bus::b_transport, i);

		bus_busy_end_time = SC_ZERO_TIME; // bus is initially free
		total_busy_time = SC_ZERO_TIME;   // reset this value
		ongoing_b_transport = false;

		secondary_access_arbitrated = false;

	}

};

#endif
