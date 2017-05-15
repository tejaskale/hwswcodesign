// global_definitions.h
//
// file for storing global defines
//

#ifndef __GDEFS_H__
#define __GDEFS_H__

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// number of clock cycles a bus master waits in an unsuccessful bus access
// before traying again
// original value 5
#define BACKOFF_LATENCY 5

// number of clock cycles the bus needs for arbitration
// original value 1
#define BUS_ARBITRATION_LATENCY 1


// memory related definitions

// number of memory clock cycles needed for first access
// original value 2
#define MEM_ACCESS_LATENCY 2

// width of memory in bits
// original value 32
#define MEMORY_WIDTH 32



// durations of processing 
// number of CPU clock cycles for dequant and IDCT on CPU
// original value 500
#define CPU_PROCESSING 500
// original value 1000
#define CPU_INITIAL_PROCESSING 1000
// original value 1000
#define CPU_FINAL_PROCESSING 1000

// number of Accel clock cycles for dequant and IDCT on Accel
// original value 150
#define ACCEL_PROCESSING 150

// number of blocks to be processed
// original value 16
#define N_BLOCKS 16


// background traffic
// original value 1000
#define INTERARRIVAL_DELAY_MAX_LATENCY 1000
// original value 256
#define MAX_DATA_LENGTH 256
// original value 10
#define RG_CLOCK_PERIOD 10

// a global variable that controls whether verbosity messages are generated
extern bool LOG;


//
extern string masters[3];
extern string slaves[2];

#endif

