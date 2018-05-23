#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define X_matriz "Adger.txt" //de tamaño MxN
#define v_vector "xdger.txt" //de tamaño MxN
#define y_vector "ydger.txt" //de tamaño Nx1

extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
extern void dlacpy_(char *part_of_a, int *m, int *n, double *a, int *lda, double *b, int *ldb);

int main(int argc, char *argv[]){
	arreglo_2d_T X;
	arreglo_1d_T y, v;

	int incx=1;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	//int nb=atoi(argv[3]); //numero de columnas en un bloque
	double ALPHA = 1.0;

	X=malloc(sizeof(*X));

	v=malloc(sizeof(*v));
	y=malloc(sizeof(*y));

	renglones(X)=M;
	columnas(X)=N;
	renglones_vector(v)=N;
	renglones_vector(y) = M;

	entradas(X)=malloc(renglones(X)*columnas(X)*sizeof(double));
	inicializa_matriz(X,X_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);
	entradas_vector(y)=malloc(M*sizeof(double));
	inicializa_vector(y,y_vector);

	dger_( &renglones(X), &columnas(X), &ALPHA,  
		entradas_vector(y), &incx, entradas_vector(v),
		 &incx, entradas(X) , &renglones(X));


	printf("matriz X:\n");
	imprime_matriz(X);
	printf("------------\n");

	printf("------------\n");
	printf("vector v :\n");
	imprime_vector(v);
	printf("------------\n");

	printf("vector y :\n");
	imprime_vector(y);
	printf("------------\n");


	free(entradas(X));
	free(X);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(y));
	free(y);
	
	return 0;
}
