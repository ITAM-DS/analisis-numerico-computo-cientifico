#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño Nx1
#define v2_vector "v2.txt" //de tamaño Nx1
extern double daxpy_(int *n, double *a, double *x, int *incx, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_1d_T v1, v2;
	double resultado;
	int incx=1;
	int N=atoi(argv[1]);

    double a=atof(argv[1]);  // para realizar la operación aX + y
                             // en el que a es un  escalar
                             // X e Y son vectores
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

	resultado = daxpy_(&N, &a, entradas_vector(v1), &incx, entradas_vector(v2), &incx);
    printf("resultado: %lf\n", resultado);
	//printf("%s\n", "resultado" );
    //for(int i = 0; i<N; i++)
        //printf("%lf\n", entradas_vector(v2)[i]);
	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
	return 0;
}