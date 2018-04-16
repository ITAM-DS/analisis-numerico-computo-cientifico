#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxM
#define B_matriz "B.txt" //de tamaño MxN o NxM
extern void dsymm_(char *side, char *uplo,int *m,int *n,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 0.0;
	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));

//A debe ser una matriz simétrica
	renglones(A)=M;
	columnas(A)=M;

//Las dimensiones de B dependen de si A está a la derecha o a la izquierda, se controla con el parámetro side, voy a usar Right para cambiarle
	renglones(B)=N;
	columnas(B)=M;

//Las dimesiones de C coinciden con las de B
	renglones(C) = N;
	columnas(C) = M;

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(B);
	printf("------------\n");
	printf("matriz resultado:\n");

	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));

	dsymm_("R","L", &M, &N, &ALPHA, entradas(A), &M, entradas(B), &M, &BETA, entradas(C), &M);
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	return 0;
}

