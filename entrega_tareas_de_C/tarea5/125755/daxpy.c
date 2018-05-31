#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño Nx1
// Como el resultado se guarda en el vector 2,
// utilizamos un archivo diferente al de dot_product.c.
#define v2_vector "v2_d.txt" //de tamaño Nx1
// Agregamos el parámetro alpha para cumplir con la descripción de
// la subrutina daxpy.
extern void daxpy_(int *n, double *alpha, double *x, int *incx, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_1d_T v1, v2;
	int incx = 1;
	int incy = 1;
	int N=atoi(argv[1]);
	double alpha=atof(argv[2]); //tenemos que convertir a float

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

	daxpy_(&N, &alpha,entradas_vector(v1), &incx, entradas_vector(v2), &incy);
	printf("%s\n", "resultado:");
	imprime_vector(v2); // aquí se imprime el vector resultante
	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
	return 0;
}
