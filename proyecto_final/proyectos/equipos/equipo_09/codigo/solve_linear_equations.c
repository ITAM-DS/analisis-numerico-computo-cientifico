#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño NxN
#define v_vector "B.txt" //de tamaño Nx1
extern void dgesv_(int *n, int *nrhs, double *a, int *lda, int *pivotes, double *b, int *ldb, int *info);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, pivotes;
	int info;
	int N=atoi(argv[1]);
	int NRHS = atoi(argv[2]);

	A=malloc(sizeof(A));
	v=malloc(sizeof(v));
	pivotes=malloc(sizeof(pivotes));

	renglones(A)=N;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(pivotes)=N;

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);
	entradas_vector_entero(pivotes)=malloc(N*sizeof(int));
	
	//printf("matriz 1:\n");
	//imprime_matriz(A);
	//printf("------------\n");
	//printf("vector :\n");
	//imprime_vector(v);
	//printf("------------\n");
	//printf("vector resultado:\n");
	dgesv_(&N, &NRHS, entradas(A), &N, entradas_vector_entero(pivotes), entradas_vector(v), &N, &info);	
	//imprime_vector(v);
	//printf("----------------\n");
	//printf("pivotes:\n");
	//imprime_vector_entero(pivotes);
	//printf("matriz 1 con factores L,U:\n");
	//imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector_entero(pivotes));
	free(pivotes);
	return 0;
}
