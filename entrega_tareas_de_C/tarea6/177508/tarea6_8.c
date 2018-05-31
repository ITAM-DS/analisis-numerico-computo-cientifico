#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A3.txt" //de tamaño MxK
#define B_matriz "B3.txt" //de tamaño KxN
#define C_matriz "C3.txt" //de tamaño KxN

extern void dsymm_(char *side, char *uplo,int *m,int *n,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int lda=atoi(argv[3]);
	int ldb=atoi(argv[4]);
	int ldc=atoi(argv[5]);

	double ALPHA, BETA;
        ALPHA = 2.0;
	BETA = 1.0;
	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));
	renglones(A)=8;
	columnas(A)=M;
	renglones(B)=6;
	columnas(B)=N;
	renglones(C) = M;
	columnas(C) = N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);
	entradas(C)=malloc(renglones(C)*columnas(C)*sizeof(double));
        inicializa_matriz(C,C_matriz);
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(B);
	printf("------------\n");
	printf("matriz resultado:\n");
	dsymm_("L", "U", &M, &N, &ALPHA, entradas(A), &lda, entradas(B),&ldb,&BETA, entradas(C), &ldc);
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	return 0;
}

