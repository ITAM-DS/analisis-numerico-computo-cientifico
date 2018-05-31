#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño Nx1
#define v2_vector "v2.txt" //de tamaño Nx1
extern void daxpy_(int *n, double *a, double *x, int *incx, double *y, int *incy);

void imprime_resultado(arreglo_1d_T arreglo, int N){
	printf("Resultado:\n");
	for(int i = 0; i<N; i++)
		printf("%lf\n", entradas_vector(arreglo)[i]);
}

int main(int argc, char *argv[]){

	arreglo_1d_T v1, v2;
	
	int incx=1;

	int N=atoi(argv[1]);
	double a = atof(argv[2]);

	v1=malloc(sizeof(*v1));
	v2=malloc(sizeof(*v2));

	renglones_vector(v1)=N;
	renglones_vector(v2)=N;

	entradas_vector(v1)=malloc(N*sizeof(double));
	inicializa_vector(v1,v1_vector);
	entradas_vector(v2)=malloc(N*sizeof(double));
	inicializa_vector(v2,v2_vector);

	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v1);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v2);
	printf("------------\n");
	printf("Escalar : %f\n",a);
	printf("------------\n");

	daxpy_(&N, &a, entradas_vector(v1), &incx, entradas_vector(v2), &incx);
	
	imprime_resultado(v2,N);

	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
	return 0;
}

