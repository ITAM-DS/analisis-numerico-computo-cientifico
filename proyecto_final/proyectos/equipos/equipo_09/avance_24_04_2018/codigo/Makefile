CC=nvcc
CFLAGS=--compiler-options -Wall
CLIBS=-lcublas -lcusolver
CINCLUDE=-I/usr/local/cuda/include

compila:
	$(CC) $(CFLAGS) $(CINCLUDE) Qr.cu -o Qr.out $(CLIBS)

ejecuta: compila   
	./Qr.out 

clean:
	-rm -f *.out
