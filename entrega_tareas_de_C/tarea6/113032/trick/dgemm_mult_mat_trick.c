#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxK
#define B_matriz "B.txt" //de tamaño KxN
extern void dgemm_(char *transposeA, char *transposeB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
	int K=atoi(argv[2]);
	int N=atoi(argv[4]);
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 0.0;
	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));
	renglones(A)=M;
	columnas(A)=K;
	renglones(B)=K;
	columnas(B)=N;
	renglones(C) = M;
	columnas(C) = N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(B);
	printf("matriz 3:\n");
	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));
	dgemm_("No transpose", "No transpose", &N, &M, &K, &ALPHA, entradas(B), &N, entradas(A), &K, &BETA, entradas(C), &N);
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	return 0;
}
