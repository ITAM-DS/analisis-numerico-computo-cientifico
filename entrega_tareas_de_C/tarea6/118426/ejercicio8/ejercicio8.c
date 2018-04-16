#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt"
#define B_matriz "B.txt"
#define C_matriz "C.txt"

extern double dsymm_(char *t1, char *t2, int *m, int *n, double *alpha, double *A, int *lda, double *B, int *ldb, double *beta, double *C, int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int N=atoi(argv[2]);
	int M=atoi(argv[1]);
	char t1='L';
	char t2='U'; 
	double alpha = atoi(argv[3]);
	double beta = atoi(argv[4]);

	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));

	renglones(A) = M;
	columnas(A) = M;
	renglones(B) = M;
	columnas(B) = N;
	renglones(C) = M;
	columnas(C) = N;

	entradas(A)=malloc(N*N*sizeof(double));
	inicializa_matriz(A, A_matriz);
	entradas(B)=malloc(M*N*sizeof(double));
	inicializa_matriz(B, B_matriz);
	entradas(C)=malloc(M*N*sizeof(double));
	inicializa_matriz(C, C_matriz);


	printf("------------\n");
	printf("alpha :\n");
	printf("%lf\n", alpha);

	printf("------------\n");
	printf("beta :\n");
	printf("%lf\n", beta);

	printf("------------\n");
	printf("matriz A:\n");
	imprime_matriz(A);

	printf("------------\n");
	printf("matriz B:\n");
	imprime_matriz(B);

	printf("------------\n");
	printf("matriz C:\n");
	imprime_matriz(C);

	printf("-------------\n");
	dsymm_(&t1, &t2, &M, &N, &alpha, entradas(A), &M, entradas(B), &M, &beta, entradas(C), &M);
	printf("Matriz resultado : \n");
	imprime_matriz(C);
	printf("-------------\n");

	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);

	return 0;

}