CC=nvcc
CFLAGS=--compiler-options -Wall
GCCFLAGS=-x cu -I. -dc
CLIBS=-lcublas -lcusolver
CINCLUDE=-I/usr/local/cuda/include

compila: compila_cc
	$(CC) $(CFLAGS) $(CINCLUDE) funciones.o MCQR.cu -o MCQR.out $(CLIBS)

compila_cc:
	$(CC) $(GCCFLAGS) funciones.c 

ejecuta: compila   
	./MCQR.out 

clean:
	-rm -f *.out *.o 
