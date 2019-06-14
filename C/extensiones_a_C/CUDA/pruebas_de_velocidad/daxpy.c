//gcc -Wall daxpy.c funciones.c -o daxpy.out -lblas
//./daxpy.out 6

#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#include<time.h>
extern double daxpy_(int *n, double *alpha, double *x,int *incx, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_1d_T v1, v2;
	int incx=1;
	int i;
	double alpha=3.5;
	int N=atoi(argv[1]);
	double time_spent;

	v1=malloc(sizeof(*v1));
	v2=malloc(sizeof(*v2));

	renglones_vector(v1)=N;
	renglones_vector(v2)=N;

	entradas_vector(v1)=calloc(N,sizeof(double));
	entradas_vector(v2)=calloc(N,sizeof(double));

	for(i=0;i<N;i++){
		entrada_vector(v1,i) = i;
		entrada_vector(v2,i) = i*i;
	}

	
	clock_t begin = clock();
	daxpy_(&N, &alpha, entradas_vector(v1), &incx, entradas_vector(v2), &incx);
	clock_t end = clock();
	//tiempo de cálculo:
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de cálculo en la gpu %.5f\n", time_spent);

	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
	return 0;
}
