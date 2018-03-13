#include"stdafx.h"
#pragma warning(disable : 4996)






#define v1_vector "v1.txt" //de tama�o Nx1
#define v2_vector "v2.txt" //de tama�o Nx1



extern double ddot_(int *n, double *x, int *incx, double *y, int *incy);


int fun_3(char *filename) {
	char c;
	int lines = 0;
	FILE *fp = fopen("v1.txt", "r");
	if (fp == NULL) { printf("NULL"); }
	while ( c = fgetc(fp) != EOF) {
		++lines;

	}
	printf("dimension del vector: %d \n", lines/2);
	return lines/2;
}

int main(int argc, char *argv[]) {
	
	printf("1. entro a main \n");
	double alpha = 2.0;
	arreglo_1d_T v1, v2;
	double resultado;
	
	int incx = 1;
	// llamamos a la funci�n para definir a N:
	char *file = v1_vector;
	int N = fun_3(file);
	//

	//int N = 3;
	
	v1 = malloc(sizeof(*v1));
	v2 = malloc(sizeof(*v2));

	renglones_vector(v1) = N;
	renglones_vector(v2) = N;

	entradas_vector(v1) = malloc(N * sizeof(double));
	
	inicializa_vector(v1, v1_vector);
	entradas_vector(v2) = malloc(N * sizeof(double));
	inicializa_vector(v2, v2_vector);

	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v1);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v2);
	printf("------------\n");

	resultado = ddot_(&N, entradas_vector(v1), &incx, entradas_vector(v2), &incx);
	printf("resultado: %lf\n", resultado);

	printf("\n\n");
	printf(" -------ejercicio 2 DAXPY -------\n\n");
	printf("alpha es: %f \n", alpha);
	double resultado2[4];
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v1);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v2);
	printf("------------\n");
	daxpy_(&N, &alpha ,entradas_vector(v1), &incx, entradas_vector(v2), &incx);
	printf("el vector resultado se almacena en v2: \n");
	imprime_vector(v2);
	printf("\n\n");
	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
	return 0;
}
