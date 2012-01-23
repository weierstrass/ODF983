# Makefile for ODF983

# Objects
OBJS := main_testing.o ssor.o

# C-compiler
CC = gcc

# Compiler options
CFLAGS =   -O2 -Wl,-rpath `pwd`

# Libraries
LIBS = -L. -lm -lgoto2

a.out: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f a.out *.o
