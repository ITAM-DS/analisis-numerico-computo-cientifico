#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"
#include <math.h>

#define A_matriz "A1.txt" //de tamaño MxN
#define b_vector "b.txt" //de tamaño M

// gcc mcqrhh.c funciones2.c -o mcqrhh.out -lm
// ./mcqrhh.out 4 3
double beta,v_1;

int main(int argc, char *argv[]){
	mat A;
	vect b;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	A=malloc(sizeof(*A));
	b=malloc(sizeof(*b));
	
	renglones(A)=M; // renglones
	columnas(A)=N; // columnas
	renglones_vector(b)=M; // renglones de b 

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	entradas_vector(b)=malloc(renglones_vector(b)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	inicializa_vector(b,b_vector);

	printf("Matriz A:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("Vector b:\n");
	imprime_vector(b);
	printf("\n------------\n");
	printf("Inicio del Algortitmo QR\n");
	printf("------------\n");
	
	int k,i;
	double *vhh=(double *)malloc(sizeof(double)*M);
	double *vectorc= (double *)malloc(sizeof(double)*M);
	int m = renglones(A);
	mat2 D;
	mat3 H;
	D=malloc(sizeof(*D));
	H=malloc(sizeof(*H));

//Algoritmo para calcular QR con Reflexiones de Householder
	for (k = 0; k < (*A).n; k++) {

		renglones_mr(D)=M-k; // renglones
		columnas_nr(D)=N-k; // columnas
		
		renglones_mh(H)=M-k; // renglones
		columnas_nh(H)=M-k; // columnas

		entradas2(D)=malloc(renglones_mr(D)*columnas_nr(D)*sizeof(double));
		entradas3(H)=malloc(renglones_mh(H)*columnas_nh(H)*sizeof(double));
		inicializa_submatriz(A,D,k);
		vectorc = realloc(vectorc,sizeof(double)*(M-k));
		vhh = realloc(vhh,sizeof(double)*(M-k));
		printf("\nCálculo del Vector de Householder, MU, SIGMA y V(1) (Evaluación del signo):\n");
		printf("\nVector columna: %d \n",k);
		for(i=0; i < M-k; i++) {
  			vectorc[i] = entrada(A,i+k,k);
  			vhh[i] = 0;
  			printf("Vector [%d]=%.5f\n",i,vectorc[i]);
		} 

		double mu[1] = {0},sigma[1] = {0};
		mcol(A,vectorc,M-k,mu,sigma);
		printf("MU: %8.3f \n", mu[0]);
		printf("SIGMA: %8.3f \n", sigma[0]);
		printf("\nVector de Householder:\n");
		vectorHH(A,vectorc,mu,sigma,vhh,M-k);
		printf("BETA: %f\n",beta); 
		printf("V_1: %f \n",v_1);
		I_Bvvt(vhh,beta,H);
		matrix_mul(A,H,D,k);
		factor_form_Q(A,vhh,M-k,k);
	}

	printf("\n------------\n");
	printf("Inicio del Algortitmo MC: Ax=b\n");
	printf("------------\n");
	
	MC(A,b);
	
	free(vectorc);
	free(vhh);
	free(entradas(A));
	free(A);
	free(entradas2(D));
	free(D);
	free(entradas3(H));
	free(H);
	free(b);

	return 0;
}
