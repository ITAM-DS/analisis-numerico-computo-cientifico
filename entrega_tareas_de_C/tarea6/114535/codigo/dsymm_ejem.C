#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxM
#define V_matriz "v.txt" //de tamaño MxN
#define W_matriz "w.txt" //de tamaño MxN

extern void dsymm_(char *side, char *uplo,int *m,int *n,double *alpha,double *A,int *lda,double *V,int *ldb,double *beta,double *W,int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, V, W;
	int M=atoi(argv[1]);
//	int K=atoi(argv[2]);
	int N=atoi(argv[4]);
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 2.0;
	A=malloc(sizeof(*A));
	V=malloc(sizeof(*V));
	W=malloc(sizeof(*W));
	renglones(A)=M;
	columnas(A)=M;
	renglones(V)=M;
	columnas(V)=N;
	renglones(W) = M;
	columnas(W) = N;

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas(V)=malloc(renglones(V)*columnas(V)*sizeof(double));
	inicializa_matriz(V,V_matriz);
	entradas(W)=malloc(renglones(W)*columnas(W)*sizeof(double));
	inicializa_matriz(W,W_matriz);

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(V);
	printf("------------\n");
	printf("matriz 3:\n");
	imprime_matriz(W);
	printf("------------\n");
	printf("matriz resultado:\n");
	
    dsymm_("L", "U", &M, &N, &ALPHA, entradas(A), &M, entradas(V), &M, &BETA, entradas(W), &M);
	imprime_matriz(W);
	free(entradas(A));
	free(A);
	free(entradas(V));
	free(V);
	free(entradas(W));
	free(W);
	return 0;
}
