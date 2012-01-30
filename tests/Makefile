# Makefile for test suite
# Andreas Bülling, 2011

#Settings
CBLAS_HEADERS_PATH = /usr/include/goto/
TOPDIR = ..
#include $(TOPDIR)/linsys/Makefile

# Objects
common = $(TOPDIR)/aux/timing.o 

grdm_ds_objs = grdm_ds_test.o $(TOPDIR)/linsys/grdm_ds.o 

# C-compiler
CC = gcc

# Compiler options
CFLAGS = -O2 -I$(CBLAS_HEADERS_PATH) -I..

# Libraries
LIBS = -lm -lgoto2

all: grdm_ds.out

grdm_ds.out: $(grdm_ds_objs) $(common)
	$(CC) -o $@ $(CFLAGS) $(grdm_ds_objs) $(common) $(LIBS)

clean:
	rm -f *.out *.o
