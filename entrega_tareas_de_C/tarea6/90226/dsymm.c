#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A1.txt" //de tamaño MxK
#define B_matriz "B.txt" //de tamaño KxN
#define C_matriz "C.txt"
//Definimos prototipo de la función dsymm llamanado con la propiedad extern ya que está definida en el paquete BLAS.
extern void dsymm_(char *SIDE, char *UPLO, int *M, int *N, double *ALPHA, double *matrizA, int *LDA, double *matrizB, int *LDB, double *BETA,double *matrizC, int *LDC );
// Definimos alfa y beta
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
	int K=atoi(argv[2]);
	int N=atoi(argv[3]);
	double ALPHA, BETA;
        char SIDE,UPLO;
        SIDE= 'L';
        UPLO = 'U';
        ALPHA = 5.0;
        BETA = -7.0;
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
        entradas(C)=malloc(renglones(C)*columnas(C)*sizeof(double));
        inicializa_matriz(C,C_matriz);
//Se imprime el resultado
  printf("A:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("B:\n");
	imprime_matriz(B);
	printf("------------\n");
	printf("El resultado es:\n");
	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));

	dsymm_(&SIDE, &UPLO, &M, &N, &ALPHA, entradas(A), &M, entradas(B), &K, &BETA, entradas(C), &M);
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	return 0;
}