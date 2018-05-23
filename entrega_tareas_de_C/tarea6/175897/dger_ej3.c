#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define y_vector "y.txt" //de tamaño Nx1
#define x_vector "x.txt" //de tamaño Mx1

extern void dger_(int *M, int *N, double *ALPHA, double *X, int *INCX, double *Y, int *INCY, double *A, int *LDA);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T y, x;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	double ALPHA;

	printf("Ingresa el valor de alpha (escalar):");
 	scanf("%lf", &ALPHA);
     
   	
	A=malloc(sizeof(*A));
	y=malloc(sizeof(*y));
	x=malloc(sizeof(*x));
	

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(y)=N;
	renglones_vector(x) = M;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(y)=malloc(N*sizeof(double));
	inicializa_vector(y,y_vector);

	entradas_vector(x)=malloc(M*sizeof(double));
	inicializa_vector(x,x_vector);

	printf("matriz A:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector x:\n");
	imprime_vector(x);
	printf("------------\n");
	printf("vector y:\n");
	imprime_vector(y);
	

	printf("------------\n");
	printf("matriz resultado:\n");

	dger_(&M, &N, &ALPHA, entradas_vector(x), &incx, entradas_vector(y), &incx,entradas(A), &M);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(y));
	free(y);
	free(entradas_vector(x));
	free(x);
	return 0;
}
