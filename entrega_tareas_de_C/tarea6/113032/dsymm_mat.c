#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "Adger.txt" //de tamaño MxN
#define B_matriz "Adger.txt" //de tamaño MxN
#define C_matriz "Adger.txt" //de tamaño MxN

extern void dsymm_(char *side, char *uplo, int *m, int *n, double *alpha, 
	double *a,  int *lda, double *b, int *ldb, double *beta, double *c, int *ldc);

int main(int argc, char *argv[]){
	arreglo_2d_T A,B,C;

	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	//int nb=atoi(argv[3]); //numero de columnas en un bloque
	double ALPHA = 1.0;
	double BETA = 1.0;

	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));

	renglones(A)=M;
	columnas(A)=N;
	renglones(B)=M;
	columnas(B)=N;
	renglones(C)=M;
	columnas(C)=N;
	

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);
	entradas(C)=malloc(renglones(C)*columnas(C)*sizeof(double));
	inicializa_matriz(C,C_matriz);

	dsymm_("L", "L", &renglones(A), &columnas(A), &ALPHA,  
		entradas(A),&renglones(A), entradas(B), &renglones(B), 
		&BETA, entradas(C) , &renglones(C));


	printf("matriz A:\n");
	imprime_matriz(A);
	printf("------------\n");

	printf("------------\n");
	printf("matriz B :\n");
	imprime_matriz(B);
	printf("------------\n");

	printf("matriz C :\n");
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
