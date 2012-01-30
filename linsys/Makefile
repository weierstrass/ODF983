# Makefile for compiling linsys solvers
# Andreas Bülling, 2011

#Settings
CBLAS_HEADERS_PATH = /usr/include/goto/

TOPDIR = ..
DIR = $(TOPDIR)/linsys

# C-compiler
CC = gcc

# Compiler options
CFLAGS = -O2 -I$(CBLAS_HEADERS_PATH)

# Libraries
LIBS = -lm -lgoto2


SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
foo: $(OBJS)
	#LINSYS COMPILED: $(OBJS)

%.o: %.C
	$(CC) $(CFLAGS) -c $< $(LIBS)