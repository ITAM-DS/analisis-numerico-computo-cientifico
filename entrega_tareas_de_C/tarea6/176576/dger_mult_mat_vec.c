#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Nx1
#define z_vector "z.txt"
extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, z;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	double ALPHA;
    ALPHA = 1.0;
	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	z=malloc(sizeof(*z));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(z) = M;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);

	entradas_vector(z)=malloc(N*sizeof(double));
	inicializa_vector(z,z_vector);

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector v:\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector z:\n");
	imprime_vector(z);
	printf("------------\n");
	printf("matriz resultado:\n");

	dger_(&M, &N, &ALPHA, entradas_vector(v), &incx, entradas_vector(z),&incx, entradas(A), &M);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(z));
	free(z);
	return 0;
}

