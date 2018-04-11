#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño Nx1
#define v2_vector "v2.txt" //de tamaño Nx1
#define A_matriz "B.txt" //de tamaño Nx1

//extern double ddot_(int *n, double *x, int *incx, double *y, int *incy);
extern double dgemv_(char *t, int *m, int *n, double *alpha, double *A, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_1d_T v1, v2;
	arreglo_2d_T A;
	//double resultado;
	int incx=1;
	int incy=1;
	int N=atoi(argv[2]);
	int M=atoi(argv[1]);
	char t='N'; 
	double alpha = atoi(argv[3]);
	double beta = atoi(argv[4]);

	v1=malloc(sizeof(*v1));
	v2=malloc(sizeof(*v2));
	A=malloc(sizeof(*A));

	renglones_vector(v1)=N;
	renglones_vector(v2)=M;
	renglones(A) = M;
	columnas(A) = N;

	entradas_vector(v1)=malloc(M*sizeof(double));
	inicializa_vector(v1,v1_vector);
	entradas_vector(v2)=malloc(N*sizeof(double));
	inicializa_vector(v2,v2_vector);
	entradas(A)=malloc(N*M*sizeof(double));
	inicializa_matriz(A, A_matriz);


	printf("------------\n");
	printf("alpha :\n");
	printf("%lf\n", alpha);

	printf("------------\n");
	printf("beta :\n");
	printf("%lf\n", beta);

	printf("------------\n");
	printf("vector 1:\n");
	imprime_vector(v1);

	printf("------------\n");
	printf("vector 2:\n");
	imprime_vector(v2);

	printf("------------\n");
	printf("matriz :\n");
	imprime_matriz(A);

	printf("-------------\n");
	dgemv_(&t, &M, &N, &alpha, entradas(A), &M, entradas_vector(v1), &incx, &beta, entradas_vector(v2), &incy);
	printf("-------------\n");
	printf("Matriz resultado : \n");
	imprime_vector(v2);
	printf("-------------\n");
	//printf("resultado: %lf\n", resultado);

	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
	free(entradas(A));
	free(A);
	return 0;

}
