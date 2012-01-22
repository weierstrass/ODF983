# Makefile for ODF983

# Objects
OBJS := ssor.o

# C-compiler
CC = gcc

# Compiler options
CFLAGS = -O2

# Libraries
LIBS = -lm

a.out: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f a.out *.o
