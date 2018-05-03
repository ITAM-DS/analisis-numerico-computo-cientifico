CC=nvcc
GCC=gcc
CFLAGS=--compiler-options -Wall
GCCFLAGS=-Wall -c
CLIBS=-lcublas -lcusolver
CINCLUDE=-I/usr/local/cuda/include

compila:
	$(CC) $(CFLAGS) $(CINCLUDE) SolverQr.cu -o SolverQr.out $(CLIBS)

compila_gcc:
	$(GCC) $(GCCFLAGS) definiciones.h funciones.c 

ejecuta: compila   
	./SolverQr.out 

clean:
	-rm -f *.out

