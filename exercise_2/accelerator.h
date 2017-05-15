//accelerator.h

#ifndef __ACCEL_H__
#define __ACCEL_H__

#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"
#include "tlm_utils/simple_initiator_socket.h"

#include "global_definitions.h"

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;


SC_MODULE(accelerator)          	
{
	public:  
	simple_target_socket<accelerator>  accelerator_socket; 
  	simple_initiator_socket<accelerator> accelerator_master_socket; // only used in DMA mode

	// needed for DMA-mode
	sc_out<bool> interrupt;


	private:
	unsigned int data_length;

	bool DMA_MODE; 
	unsigned int ACCELERATOR_CLK_PERIOD;
	unsigned int BUS_CLK_PERIOD;

	// needed for non-DMA mode
	sc_time accel_busy_end_time, accel_busy_start_time;

	// needed for DMA-mode
	bool accel_busy;                 // used to indicate whether accelerator is busy
	sc_event idct_with_dma_start;    // to remember time when dequant and idct calculation started
	
	sc_time total_processing_time;   // used to sum up processing time for load calculation
	sc_time total_transfer_time;     // used to sum up transfer time for load calculation
	tlm_command command;


	private:
	void b_transport(tlm_generic_payload &trans, sc_time &delay_time);

	void idct_with_dma();

	public:
  	void output_load();

		
	// needed as we do not use SC_CTOR for the constructor
	SC_HAS_PROCESS(accelerator);

	public:
	// constructor with parameters /therefore we cannot use SC_CTOR()
	
	accelerator(sc_module_name name_, unsigned int acc_clk_p_, unsigned int bus_clk_p_, bool dma_mode_=false):
		sc_module(name_),                        // call constructor of sc_module 
		ACCELERATOR_CLK_PERIOD(acc_clk_p_),      // set value for ACCELERATOR_CLK_PERIOD
		BUS_CLK_PERIOD(bus_clk_p_),              // set value for BUS_CLK_PERIOD
		DMA_MODE(dma_mode_),                     // set value for DMA_MODE (if not set use default value false)
		accelerator_socket("accelerator_socket") // call constructor of accelerator_socket
	{ 
		accelerator_socket.register_b_transport(this, &accelerator::b_transport);
		
		interrupt.initialize(false);
		SC_THREAD(idct_with_dma);
	
		accel_busy_start_time = SC_ZERO_TIME;
		accel_busy_end_time = SC_ZERO_TIME;
		total_processing_time = SC_ZERO_TIME;
		total_transfer_time = SC_ZERO_TIME;
		accel_busy =false;
	
	}
};

#endif

