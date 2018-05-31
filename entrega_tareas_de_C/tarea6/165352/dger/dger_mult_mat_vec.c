#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Nx1
#define u_vector "u.txt" //de tamaño Mx1
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, u, v_resultado;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	int incy=1;
	double ALPHA;
    	ALPHA = 1.0;
	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	u=malloc(sizeof(*u));
	v_resultado=malloc(sizeof(*v_resultado));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(u)=M;
	renglones_vector(v_resultado) = M;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);

	entradas_vector(u)=malloc(M*sizeof(double));
	inicializa_vector(u,u_vector);

	entradas_vector(v_resultado)=calloc(M,sizeof(double));
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(u);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("matriz resultado:\n");

	dger_(&M, &N, &ALPHA, entradas_vector(u), &incx, entradas_vector(v), &incy, entradas(A), &M);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(u));
	free(u);
	return 0;
}
