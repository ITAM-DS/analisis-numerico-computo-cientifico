#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Mx1
#define v2_vector "v2.txt" // de tamaño Nx1

//modificamos el programa que nos da el profesor, la diferencia esencialmente está en que debemos agregar un txt para definir explícitamente el segundo vector ya que en el caso anterior sólo teníamos 1 vector y 1 matriz, ahora tenemos 2
extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, v2;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	double ALPHA;
    ALPHA = 1.0;
   	
	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	v2=malloc(sizeof(*v2));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=M;
	renglones_vector(v2) = N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(M*sizeof(double));
	inicializa_vector(v,v_vector);

//Aquí es donde estamos agregando v2.txt
	entradas_vector(v2)=malloc(N*sizeof(double));
	inicializa_vector(v2,v2_vector);

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("vector 2 :\n");
	imprime_vector(v2);
	printf("------------\n");
	printf("matriz final:\n");

	dger_(&M, &N, &ALPHA, entradas_vector(v),&incx, entradas_vector(v2), &incx,entradas(A), &M);
	imprime_matriz(A);
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(v2));
	free(v2);
	return 0;
}
