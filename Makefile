# Makefile for ODF983

# Objects
OBJS :=  cgm_ds.o\
	 sor_ds.o\
	 main_testing.o\
	aux.c

# C-compiler
CC = gcc

# Compiler options
CFLAGS = -O2 -I/usr/include/goto/

# Libraries
LIBS = -lm -lgoto2

a.out: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f a.out *.o
