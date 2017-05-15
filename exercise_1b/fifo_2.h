// fifo_2.h

// preprocessor macro needed to avoid problems with sc_spawn
#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

// to make things easier readable ...
using namespace sc_core;
using namespace tlm;
using namespace tlm_utils;

SC_MODULE(fifo_2)
{

	// *******========================================*******
	// *******             Member Variables           *******
	// *******========================================*******
	public:
	simple_target_socket<fifo_2>  fifo2consum_socket;	//  target socket for consum
	simple_target_socket<fifo_2>  fifo2prod_socket;	//  target socket for prod
	
	private:
	unsigned char *fifo_data;
	int write_addr, read_addr;
	int fill_level;
	unsigned char *data;
	const int fifo_size;  // in multiples of unsigned char


	// b_transport() - Blocking Transport
	
	public:
	void                                     // returns nothing 
	b_transport
	( tlm_generic_payload  &payload,         // ref to payload 
	  sc_time          &delay_time           // ref to delay time 
	);

	private:
	void output_fifo_status();  // function to output FIFO content in a text line
	
	// *******=================================================*******
	// *******                    Constructor                  *******
	// *******=================================================*******
	public:
	SC_CTOR(fifo_2): 
		fifo2prod_socket("fifo2prod_socket"),      // call cunstructors of sockets
		fifo2consum_socket("fifo2consum_socket"),
		fifo_size(40)				   // initialize FIFO size
	{
		// register b_transport function with sockets
		fifo2prod_socket.register_b_transport(this, &fifo_2::b_transport);
		fifo2consum_socket.register_b_transport(this, &fifo_2::b_transport);

		// initialization of member variables
		fifo_data = new unsigned char[fifo_size];
	
		write_addr = 0;
		read_addr  = 0;
		fill_level = 0;
	}
};

