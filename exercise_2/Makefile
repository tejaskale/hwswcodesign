
MODULE_3 = sim_3

SRCS_3 =   main.cpp processor.cpp memory.cpp bus.cpp accelerator.cpp traffic_generator.cpp argvparser.cpp
OBJS_3 = $(SRCS_3:.cpp=.o)


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

EXE_3  = $(MODULE_3).x

.SUFFIXES: .cc .cpp .o .x

$(EXE_3): $(OBJS_3)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $(OBJS_3) 2>&1 | c++filt

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.cc.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_3) *~ $(EXE_3) core
	makedepend --clean

depend:
	makedepend $(CFLAGS) $(SRCS_3) > /dev/null 2>&1

