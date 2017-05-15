XCC = arm-linux-gnueabihf-gcc
XAS = arm-linux-gnueabihf-gcc
XAR = arm-linux-gnueabihf-gcc-ar
XOBJDUMP = arm-linux-gnueabihf-objdump -d -l -S
XOBJCOPY = arm-linux-gnueabihf-objcopy
#XCFLAGS = -O2 -g
#XCFLAGS = -std=c99 -O2
XCFLAGS = -O2
XLDFLAGS = -lm

SOURCES = sobel_sw.c

APPLICATIONS = $(SOURCES:%.c=%)

.PHONY : all

all: $(APPLICATIONS)

%: %.c
	$(XCC) $(XCFLAGS) $< $(XLDFLAGS) -o $@

clean:
	-rm -rf *.o $(APPLICATIONS)
