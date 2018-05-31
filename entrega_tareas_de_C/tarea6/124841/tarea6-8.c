/*
 

  DSYMM  performs one of the matrix-matrix operations

     C := alpha*A*B + beta*C,

  or

     C := alpha*B*A + beta*C,
*/

#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A4.txt" //Symmetric matrix of m by m
#define B_matriz "B4.txt" // matrix of m by n 
//void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int dsymm_(char *side, char *uplo, int *m, int *n, double *alpha, double *a,  int *lda, double *b, int *ldb, double *beta, double *c, int * ldc);

int main (int argc, char *argv[]){

char side='L', uplo='U';
int m=atoi(argv[1]), n=atoi(argv[2]); 
int lda=m, ldb=m, ldc=m;
arreglo_2d_T A, B, C;
double alpha=2, beta=3;



A=malloc(sizeof(*A));
renglones(A)=m;
columnas(A)=m;
entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
inicializa_matriz(A, A_matriz);

B=malloc(sizeof(*B));
renglones(B)=m;
columnas(B)=n;
entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
inicializa_matriz(B, B_matriz);



C=malloc(sizeof(*C));
renglones(C)=m;
columnas(C)=n;
entradas(C)=calloc(renglones(C)*columnas(C), sizeof(double));





printf("\nParámetro alpha: %lf\n", alpha);

printf("\nParámetro beta: %lf\n", beta);


printf("matriz A:\n");
	imprime_matriz(A);
	printf("------------\n");

printf("matriz B:\n");
	imprime_matriz(B);
	printf("------------\n");


dsymm_(&side, &uplo, &m, &n, &alpha, entradas(A), &lda, entradas(B), &ldb, &beta, entradas(C), &ldc);

printf("\nResultado  C := alpha*A*B + beta*C\n");
imprime_matriz(C);
	printf("------------\n");


free(entradas(A));
	free(A);

free(entradas(B));
	free(B);

free(entradas(C));
	free(C);
return 0;
}

