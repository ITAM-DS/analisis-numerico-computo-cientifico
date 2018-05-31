#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define x_vector "x.txt" //de tamaño Mx1
#define y_vector "y.txt" //de tamaño Nx1

extern void dger_( int *m, int *n, double *alpha,double *x, int *incx,double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){

	arreglo_2d_T A;
	arreglo_1d_T v_x, v_y;

	int M=atoi(argv[1]);
	int N=atoi(argv[2]);

	int incx=1;
	int incy=1;

	double ALPHA;
    ALPHA = 1.0;

	A=malloc(sizeof(*A));
	v_x=malloc(sizeof(*v_x));
	v_y=malloc(sizeof(*v_y));

	renglones(A)=M;
	columnas(A)=N;


	renglones_vector(v_x)=M;
	renglones_vector(v_y)=N;


	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));

	inicializa_matriz(A,A_matriz);

	entradas_vector(v_x)=malloc(M*sizeof(double));
	entradas_vector(v_y)=malloc(N*sizeof(double));

	inicializa_vector(v_x,x_vector);
	inicializa_vector(v_y,y_vector);

	printf("escalar :\n");
	printf("%f",ALPHA);
	printf("------------\n");

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");

	printf("vector x :\n");
	imprime_vector(v_x);
	printf("------------\n");

	printf("vector y :\n");
	imprime_vector(v_y);
	printf("------------\n");


	printf("matriz resultado:\n");

	dger_(&M, &N, &ALPHA, entradas_vector(v_x), &incx,  entradas_vector(v_y), &incy  , entradas(A), &M);

	imprime_matriz(A);

	free(entradas(A));
	free(A);


	free(entradas_vector(v_x));
	free(v_x);

	free(entradas_vector(v_y));
	free(v_y);


	return 0;
}
