//traffic_generator.h


#ifndef __TGEN_H__
#define __TGEN_H__


#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"

#include "global_definitions.h"

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;      
              
#define SC_INCLUDE_DYNAMIC_PROCESSES
   
SC_MODULE(traffic_generator) 
{
	public:
  	simple_initiator_socket<traffic_generator> generator_socket;

	private:
	void gen_traffic();

	public:
	SC_CTOR(traffic_generator):generator_socket("generator_socket")
  	{
	    SC_THREAD(gen_traffic);
	}
};

#endif

