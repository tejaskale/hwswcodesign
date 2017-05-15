// main.cpp

#include "consum_1.h"
#include "prod_1.h"
#include "fifo_1.h"

int sc_main(int argc, char *argv[]) {

	// signals for the connection of the modules
	sc_signal<int> dat1, dat2;
	sc_signal<bool> f_full, f_empty, put, get;

	sc_clock clk("clock", 100, SC_NS, 0.5, 50, SC_NS, false);

	// instances of the modules
	prod_1 pro("m1");
	fifo_1 fif("m2");
	consum_1 con("m3");

	// connect instances
	pro.clk(clk);
	pro.dat1(dat1);
	pro.put(put);
	pro.f_full(f_full);

	fif.clk(clk);
	fif.wr(put);
	fif.data_in(dat1);
	fif.rd(get);
	fif.data_out(dat2);
	fif.full(f_full);
	fif.empty(f_empty);

	con.clk(clk);
	con.dat2(dat2);
	con.get(get);
	con.f_empty(f_empty);

	// generate traces
	sc_trace_file *tf = sc_create_vcd_trace_file("traces_1");
	sc_trace(tf, clk, "clk");
	sc_trace(tf, dat1, "dat1");
	sc_trace(tf, put, "put");
	sc_trace(tf, f_full, "f_full");
	sc_trace(tf, dat2, "dat2");
	sc_trace(tf, get, "get");
	sc_trace(tf, f_empty, "f_empty");
	sc_trace(tf, fif.fill_level, "fifo_fill_level");

	// Trace internacl signals of producer and consumer. Therefore these 
	// signals have to be daclared public in the module declaration
	sc_trace(tf, pro.send, "prod.send");
	sc_trace(tf, con.fetch, "con.fetch");
	sc_trace(tf, con.data_valid, "con.data_valid");

	sc_time sim_dur = sc_time(5000, SC_NS);
	if (argc != 2) {
		cout << "Default simulation time = " << sim_dur << endl;
	} else {
		sim_dur = sc_time(atoi(argv[1]), SC_NS);
	}
	
	// start simulation
	sc_start(sim_dur);

	sc_close_vcd_trace_file(tf);

	return 0;
}

