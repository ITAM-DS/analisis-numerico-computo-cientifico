#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"

extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, v_resultado, w;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	char* A_matriz = argv[3];
	char* v_vector = argv[4];	
    char* w_vector = argv[5];	
	int incx=1;
	double ALPHA;
    ALPHA = 1.0;   	
	
	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
    w=malloc(sizeof(*w));
	v_resultado=malloc(sizeof(*v_resultado));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
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
	printf("vector v:\n");
	imprime_vector(v);
	printf("------------\n");
    printf("vector w:\n");
	imprime_vector(w);
	printf("------------\n");
	printf("vector resultado:\n");
	
    dger_(&M, &N, &ALPHA, entradas_vector(v), &incx, entradas_vector(w), &incx, entradas(A), &M);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(v_resultado));
	free(v_resultado);    
    free(entradas_vector(w));
	free(w);
	return 0;
}