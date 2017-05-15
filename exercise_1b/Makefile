
MODULE_2 = sim_2

SRCS_2 = prod_2.cpp consum_2.cpp fifo_2.cpp main_2.cpp
OBJS_2 = $(SRCS_2:.cpp=.o)


## Variable that points to SystemC installation path
##SYSTEMC = /nfs/lis/tools/systemc/2.3.1
##TLM = /nfs/lis/tools/systemc/2.3.1

SHELL  = /bin/sh

CC     = g++
OPT    = -O3
DEBUG  = -g
OTHER  = -Wno-deprecated `pkg-config --cflags systemc`
CFLAGS = $(DEBUG) $(OTHER)
LIBS   = `pkg-config --libs systemc`

EXE_2  = $(MODULE_2).x

.SUFFIXES: .cc .cpp .o .x

$(EXE_2): $(OBJS_2)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $(OBJS_2) 2>&1 | c++filt

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.cc.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_2) *~ $(EXE_2) core
	makedepend --clean

depend:
	makedepend $(CFLAGS) $(SRCS_2) > /dev/null 2>&1

