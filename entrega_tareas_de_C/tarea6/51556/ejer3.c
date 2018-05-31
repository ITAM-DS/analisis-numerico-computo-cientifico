#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN 
#define v_vector "u.txt" //de tamaño Nx1 
#define w_vector "w.txt" //de tamaño Nx1
extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, v_resultado,w;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	double ALPHA;
    ALPHA = 1.0;

	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
        w=malloc(sizeof(*w));
        
	v_resultado=malloc(sizeof(*v_resultado));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=M;
	renglones_vector(v_resultado) = M;
	renglones_vector(w)=N;


	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);

	entradas_vector(w)=malloc(N*sizeof(double));
	inicializa_vector(w,w_vector);

	entradas_vector(v_resultado)=calloc(M,sizeof(double));
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector x:\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector y:\n");
        imprime_vector(w);

	dger_(&M, &N, &ALPHA, entradas_vector(v), &incx, entradas_vector(w), &incx, entradas(A), &M);
        printf("------------\n");
        printf("matriz final:\n");
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(v_resultado));
	free(v_resultado);
	return 0;
}
