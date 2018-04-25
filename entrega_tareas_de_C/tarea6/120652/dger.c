#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_3.txt"
#define x_vector "x_3.txt"
#define y_vector "y_3.txt"
extern void dgemv_(int *m, int *n, double *alpha, double *x, int *incx, double *y, double *a, double *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T x, y;
	double ALPHA;
	
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	
	ALPHA = 1.0;
	A=malloc(sizeof(*A));
	x=malloc(sizeof(*x));
	y=malloc(sizeof(*y));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(x) = M;
	renglones_vector(y) = N;

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(x)=malloc(M*sizeof(double));
	inicializa_vector(x,x_vector);

	entradas_vector(y)=malloc(M*sizeof(double));
	inicializa_vector(y,y_vector);

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector x:\n");
	imprime_vector(x);
	printf("------------\n");
	printf("vector y:\n");
	imprime_vector(y);
	printf("------------\n");
	printf("Resultado\n");

	dger_(&M, &N, &ALPHA, entradas_vector(x), &incx, entradas_vector(y), &incx, entradas(A), &M);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(x));
	free(x);
	free(entradas_vector(y));
	free(y);
	return 0;
}
