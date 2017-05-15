//system.cpp

#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
#include "tlm.h"                              

#include "memory.h"                     
#include "processor.h"                 
#include "bus.h"     
#include "accelerator.h"
#include "traffic_generator.h"
      
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>

//  command line parsing
#include "argvparser.h"
using namespace CommandLineProcessing;

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;
using namespace std;


bool LOG = false;
string masters[3] = {"processor", "traffic generator", "accelerator"};
string slaves[2] = {"memory", "accelerator"};



int                                     // return status
sc_main                                // SystemC entry point
  (int   argc,                          // argument count
   char  *argv[]                        // argument vector
)
{

int mem_bus_clk_period = 10;
int cpu_clk_period = 5;
int acc_clk_period = -1;
bool acc_present = false;
bool acc_with_dma = false;

int nr_of_masters = 2;
int nr_of_slaves = 1;


///////////////////////////////////// Parsing the command line.... /////////////
// you can ignore this section, it is used to read in the required parameters // 
// from the command line                                                      //
////////////////////////////////////////////////////////////////////////////////
ArgvParser cmd;

// init
cmd.setIntroductoryDescription("You can set the simulation parameters on the command line with the following switches.");

//define error codes
cmd.addErrorCode(0, "Success");
cmd.addErrorCode(1, "Error");

cmd.setHelpOption("h", "help", "Print this help");

cmd.defineOption("verbose", "Output log infomration", ArgvParser::NoOptionAttribute);
cmd.defineOptionAlternative("verbose","v");

cmd.defineOption("cpu", "CPU clock period [ns]. Default value: 5", ArgvParser::OptionRequiresValue);
cmd.defineOptionAlternative("cpu","c");

cmd.defineOption("b", "Bus and memory clock period [ns]. Default value: 10", ArgvParser::OptionRequiresValue);
cmd.defineOptionAlternative("b","bus");

cmd.defineOption("a", "Accelerator clock period [ns]. If option is omitted accel will not be instanitated", ArgvParser::OptionRequiresValue);
cmd.defineOptionAlternative("a","accel");

cmd.defineOption("D", "Accelerator with DMA feature (only in conjunction with a)", ArgvParser::NoOptionAttribute);


// finally parse and handle return codes (display help etc...)
int result = cmd.parse(argc, argv);

if (result != ArgvParser::NoParserError){
   cout << cmd.parseErrorDescription(result)<<endl;
   cout << "Use "<< argv[0] << " --help    to get on the command line parameters"<<endl;
   exit(1);
}

if(cmd.foundOption("verbose"))
	LOG=true;
if(cmd.foundOption("cpu"))
	cpu_clk_period=atoi(cmd.optionValue("c").c_str());
if(cmd.foundOption("bus"))
	mem_bus_clk_period=atoi(cmd.optionValue("b").c_str());
if(cmd.foundOption("accel")){
	acc_present=true;
	nr_of_slaves=2;
	nr_of_masters=3;
	acc_clk_period=atoi(cmd.optionValue("a").c_str());
	if(cmd.foundOption("D")){
		acc_with_dma = true;
	}
}

///////////////////////////////////// end command line parsing ////////////////



  sc_signal<bool> interrupt;
  accelerator           *acceli;   // accelerator is not present in all cases
				   // therefore instantiation is done via pointer

  srand(2315);   // initialize random generator

  // instatiations 
  bus 			busi("bus", mem_bus_clk_period, nr_of_masters, nr_of_slaves);                 
  memory 		memi("mem", mem_bus_clk_period);   
  processor 		proci("proc", cpu_clk_period, acc_present, acc_with_dma);  
  traffic_generator 	tgen("tgen");
  if(acc_present)
	  acceli= new accelerator ("acc", acc_clk_period, mem_bus_clk_period, acc_with_dma);

  
  // interconnection
  proci.processor_socket.bind(busi.bus_target_socket[0]);
  proci.interrupt(interrupt);
  busi.bus_initiator_socket[0].bind(memi.memory_socket);
  tgen.generator_socket.bind(busi.bus_target_socket[1]);
  

  if(acc_present){
	busi.bus_initiator_socket[1].bind(acceli->accelerator_socket);
	acceli->interrupt(interrupt);
	acceli->accelerator_master_socket.bind(busi.bus_target_socket[2]);
  }


  sc_start();   // start the simulation, here without sc_time argument
  		// would run forever.... 
		// We will stop the simulation in the CPU using sc_stop()

  // output load values of instantiated modules
  cout<<endl<<"Total run time: "<<sc_time_stamp()<<endl;
  proci.output_load();		
  busi.output_load();		
  if(acc_present)
	acceli->output_load();		
  cout << endl;

  return 0;      // return okay status

}
