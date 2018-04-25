#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_.txt" //de tamaño MxM
#define B_matriz "B.txt" //de tamaño MxN
#define C_matriz "C.txt" // de tamaño MxN
//extern void dsymm_(char *transposeA, char *transposeB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
extern void dsymm_(char* side, char* uplo, int* M, int* N, double* alpha, double* A, int* lda, double* B, int*ldb, double* beta, double* C, int* ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
//	int K=atoi(argv[2]);
	int N=atoi(argv[2]);
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 1.0;
  char SIDE = 'L';
  char UPLO = 'U';
	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));
	renglones(A)=M;
	columnas(A)=M;
	renglones(B)=M;
	columnas(B)=N;
	renglones(C) = M;
	columnas(C) = N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);
	entradas(C)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(C,C_matriz);
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(B);
	printf("------------\n");
	printf("matriz 3:\n");
	imprime_matriz(C);
	printf("------------\n");
	printf("matriz resultado:\n");
	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));
	dsymm_(&SIDE, &UPLO, &M, &N, &ALPHA, entradas(A), &M, entradas(B), &M, &BETA, entradas(C), &N);
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	return 0;
}