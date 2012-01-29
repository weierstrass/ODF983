# Makefile for ODF983
# Andreas Bülling, 2011

#Settings
CBLAS_HEADERS_PATH = /usr/include/goto/

# Objects
OBJS :=  cgm_ds.o\
	 sor_ds.o\
	 main_testing.o\
	aux.c

# C-compiler
CC = gcc

# Compiler options
CFLAGS = -O2 -I$(CBLAS_HEADERS_PATH)

# Libraries
LIBS = -lm -lgoto2

a.out: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f a.out *.o
