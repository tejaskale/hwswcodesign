// main_2.cpp

// preprocessor macro needed to avoid problems with sc_spawn
#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "consum_2.h"
#include "prod_2.h"
#include "fifo_2.h"
#include "systemc.h"


int sc_main(int argc, char *argv[]){

  // instances of the modules

  // fill in

  // connect instances

  // fill in


  // simulation duration may be modified by command line parameter
  int sim_dur;
  if(argc != 2){
    cout << "default simulation time = 5000 SC_NS\n";
    sim_dur = 5000;
  }
  else
    sim_dur = atoi(argv[1]);

  // start simulation
  sc_start(sim_dur, SC_NS);

  // sc_close_vcd_trace_file(tf);

  return(0);

}

