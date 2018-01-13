CFLAGS = -O
CC = gcc
LIBS = -lm -lgsl -lgslcblas

matriz_ady:matriz_ady.o leergml.o
	$(CC) $(CFLAGS) -o matriz_ady matriz_ady.o leergml.o $(LIBS)

matriz_ady.o:matriz_ady.c red.h leergml.h Makefile
	$(CC) $(CFLAGS) -c matriz_ady.c

leergml.o:leergml.c leergml.h red.h
	$(CC) $(CFLAGS) -c leergml.c
