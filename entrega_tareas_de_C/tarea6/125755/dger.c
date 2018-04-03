#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Nx1
#define r_vector "r.txt" //de tamaño Nx1
// extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A, A_resultado;
	arreglo_1d_T v, r;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	int incy=1;
	int lda = M;
	double ALPHA;
    ALPHA = 1.0;
    
	A=malloc(sizeof(*A));
	A_resultado=malloc(sizeof(*A_resultado));
	v=malloc(sizeof(*v));
	r=malloc(sizeof(*r));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=M;
	renglones_vector(r) = N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(M*sizeof(double));
	inicializa_vector(v,v_vector);

	entradas_vector(r)=malloc(N*sizeof(double));
	inicializa_vector(r, r_vector);
	
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector x:\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector y:\n");
	imprime_vector(r);
	printf("------------\n");
	printf("matriz resultado:\n");

	//dgemv_("No transpose", &M, &N, &ALPHA, entradas(A), &M, entradas_vector(v), &incx, &BETA, entradas_vector(r),&incx);
	dger_(&M, &N, &ALPHA, entradas_vector(v), &incx, entradas_vector(r), &incy, entradas(A), &lda);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(r));
	free(r);
	return 0;
}
