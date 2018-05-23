#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño nx1
#define v2_vector "v2.txt" //de tamaño nx1
extern double daxpy_(int *n, double *a, double *x, int *incx, double *y, int *incy);
extern double ddot_(int *n, double *x, int *incx, double *y, int *incy);
int main(){
	arreglo_1d_T v1, v2;
	double res;
	int n = 8;
//	double a = 2.5;
	int incx=1;
	int incy=1;

	v1=malloc(sizeof(*v1));
	v2=malloc(sizeof(*v2));

	renglones_vector(v1)=n;
	renglones_vector(v2)=n;

	entradas_vector(v1)=malloc(n*sizeof(double));
	inicializa_vector(v1,v1_vector);
	entradas_vector(v2)=malloc(n*sizeof(double));
	inicializa_vector(v2,v2_vector);

	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v1);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v2);

	printf("\n\nEste programa lee v1.txt y v2.txt para ejecutar: \n\t\t res=2.5*v1+v2 y deolver res.");
	printf("\nSe consideran ambos vectores de dimensiones 8 x 1");

	//res = daxpy_(&n, &a, entradas_vector(v1), &incx, entradas_vector(v2), &incy);
	res = ddot_(&n, entradas_vector(v1), &incx, entradas_vector(v2), &incy);
	printf("\n\nResultado:\n\n");
        printf("%lf \n\n\n ", res);
	return 0;
}
