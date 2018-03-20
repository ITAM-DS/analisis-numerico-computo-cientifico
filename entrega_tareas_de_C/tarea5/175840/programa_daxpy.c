#include<stdio.h>
#include<stdlib.h>

#include"definiciones.h"

extern void daxpy_(int *n, double* alpha, double *x, int *incx, double *y, int *incy);

int main(int argc, char *argv[]){
	arreglo_1d_T v1, v2;	
	int incx=1;
	int N=atoi(argv[1]);
	char* v1_vector = argv[2];
	char* v2_vector = argv[3];
	int imprime = atoi(argv[4]);
    double alpha = atof(argv[5]);
    

	v1=malloc(sizeof(*v1));
	v2=malloc(sizeof(*v2));    

	renglones_vector(v1)=N;
	renglones_vector(v2)=N;

	entradas_vector(v1)=malloc(N*sizeof(double));
	inicializa_vector(v1,v1_vector);
	entradas_vector(v2)=malloc(N*sizeof(double));
	inicializa_vector(v2,v2_vector);

	if(imprime == 1) {
		printf("------------\n");
		printf("vector 1:\n");
		imprime_vector(v1);
		printf("------------\n");
		printf("vector 2:\n");
		imprime_vector(v2);
		printf("------------\n");
	}

    printf("Valor alpha : %f\n",alpha);
	
    daxpy_(&N, &alpha, entradas_vector(v1), &incx, entradas_vector(v2), &incx);

    // Imprime el resultado
    imprime_vector(v2);

	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);
    
	return 0;
}