#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt"
#define v_vector "v.txt"
#define w_vector "w.txt" 

extern void dger_( int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *transpose_a, int *lda) ;

int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, w;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	int incy=1;
	int lda=M;
	double ALPHA;
    ALPHA = 2.0;
   	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	w=malloc(sizeof(*w));
	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=M;
	renglones_vector(w)=N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(M*sizeof(double));
	inicializa_vector(v,v_vector);

	// vector A := alpha*x*y' + A,
    entradas_vector(w)=malloc(N*sizeof(double));
	inicializa_vector(w,w_vector);

	printf("matriz A:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector v :\n");
	imprime_vector(v);
	printf("vector w:\n");
	imprime_vector(w);
	
	dger_(&M, &N, &ALPHA, entradas_vector(v), &incx, entradas_vector(w), &incy, entradas(A), &lda);

	printf("resultado 1:\n");
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(entradas_vector(w));
	free(v);
	free(w);
	return 0;
}
