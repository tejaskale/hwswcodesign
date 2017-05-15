//processor.h

#ifndef __PROC_H__
#define __PROC_H__

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"

#include "global_definitions.h"

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;      
              
#define SC_INCLUDE_DYNAMIC_PROCESSES
   
SC_MODULE(processor) 
{
	public:
  	simple_initiator_socket<processor> processor_socket;

	sc_in<bool> interrupt;

	private:

	unsigned int PROCESSOR_CLK_PERIOD;
	bool ACCEL_PROC;
	bool ACCEL_DMA;

	tlm_generic_payload trans;
	tlm_response_status gp_status;
	sc_time transaction_delay;

	sc_time total_processing_time;
	sc_time total_transfer_time;


private: 
	void software_code();
	void hardware_code();

public:
	void output_load();

	// needed as we do not use SC_CTOR for the constructor
	SC_HAS_PROCESS(processor);

public:
	// constructor with parameters /therefore we cannot use SC_CTOR()
	processor(sc_module_name name_, unsigned int proc_clk_p_, bool accel_proc_=false, bool accel_dma_=false):\
		sc_module(name_),                  // call constructor of sc_module
		PROCESSOR_CLK_PERIOD(proc_clk_p_), // initialize member variables
		ACCEL_PROC(accel_proc_),
		ACCEL_DMA(accel_dma_)
	{
		if(ACCEL_PROC && ACCEL_DMA)
		{
			SC_THREAD(hardware_code);
			sensitive << interrupt.pos();
		}
		else
			SC_THREAD(software_code);
	
		total_processing_time = SC_ZERO_TIME;
		total_transfer_time = SC_ZERO_TIME;
  	} // constructor
};

#endif


