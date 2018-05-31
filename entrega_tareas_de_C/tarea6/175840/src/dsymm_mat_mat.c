#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//#define A_matriz "A.txt" //de tamaño MxN
//#define v_vector "v.txt" //de tamaño Nx1

extern void dsymm_(char *side, char *uplo,int *m,int *n,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);

int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	char* A_matriz = argv[3];
    char* B_matriz = argv[4];
    char* C_matriz = argv[5];
	
	double ALPHA, BETA;
    ALPHA = 1.0;
   	BETA = 0.0;
	
	A=malloc(sizeof(*A));
    B=malloc(sizeof(*B));
    C=malloc(sizeof(*C));	

	renglones(A)= M;
	columnas(A) = M;
    renglones(B)= M;
	columnas(B) = N;
    renglones(C)= M;
	columnas(C) = N;

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

    entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);

    entradas(C)=malloc(renglones(C)*columnas(C)*sizeof(double));
	inicializa_matriz(C,C_matriz);


	printf("matriz A:\n");
	imprime_matriz(A);
	printf("------------\n");

    printf("matriz B:\n");
	imprime_matriz(B);
	printf("------------\n");

    printf("matriz C:\n");
	imprime_matriz(C);
	printf("------------\n");

	
	dsymm_("L", "U", &M, &N, &ALPHA, entradas(A), &M, entradas(B), &M, &BETA, entradas(C), &M);
	
    printf("Resultado \n");
    imprime_matriz(C);
	
    free(entradas(A));
	free(A);
	
    free(entradas(B));
	free(B);

    free(entradas(C));
	free(C);
	
	return 0;
}