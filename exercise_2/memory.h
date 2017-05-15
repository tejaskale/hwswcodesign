// memory.h

#ifndef __MEMORY_H__
#define __MEMORY_H__


#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

#include "global_definitions.h"


// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;


SC_MODULE(memory)          	
{

	public:  
	simple_target_socket<memory>  memory_socket;

	unsigned int  MEMORY_CLK_PERIOD;

	private:        
	void b_transport(tlm_generic_payload  &gp, sc_time &delay_time);
	
	
	// needed as we do not use SC_CTOR for the constructor
	SC_HAS_PROCESS(memory);
	

	public:
	// constructor with parameters /therefore we cannot use SC_CTOR()
	memory(sc_module_name name_, unsigned int mem_clk_period_):\
		sc_module(name_),                   // call constructor of sc_module,
		MEMORY_CLK_PERIOD(mem_clk_period_), // initialize member variable
		memory_socket("memory_socket")      // call constructor of memory socket
	{

		memory_socket.register_b_transport(this, &memory::b_transport);	
 
	} // constructor
};

#endif
