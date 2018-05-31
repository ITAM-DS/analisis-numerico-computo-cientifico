CC=gcc
CFLAGS=-Wall
CLIBS=-lblas

compila: 
	$(CC) $(CFLAGS) dot_product.c definiciones.h funciones.c -o programa.out $(CLIBS)

compila_daxpy:
	$(CC) $(CFLAGS) programa_daxpy.c definiciones.h funciones.c -o programa_daxpy.out $(CLIBS)

ejecuta: compila
	./programa.out 3 v1.txt v2.txt 1

ejecuta1: compila
	./programa.out 20 v3.txt v4.txt 1

ejecuta2: compila
	./programa.out 100 v5.txt v6.txt 0

ejecuta_daxpy: compila_daxpy
	./programa_daxpy.out 3 v1.txt v2.txt 1 3

clean:
	-rm -f *.out
