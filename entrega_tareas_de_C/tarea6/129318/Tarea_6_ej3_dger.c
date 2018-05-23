#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"

#define v_vector "v.txt" //de tamaño Nx1
#define u_vector "u.txt" //de tamaño Mx1
//extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);

extern void dger_(int *m, int *n, double *alpha, 	double *x, int *incx, double *y, int *incy, double *a, int *lda);

int main(int argc, char *argv[]){
	arreglo_2d_T A_resultado;
	arreglo_1d_T v, u;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
  int incy=1;
	int incx=1;
	double ALPHA; //, BETA;
    ALPHA = 1.0;
   	//BETA = 0.0;
	A_resultado=malloc(sizeof(*A_resultado));
	v=malloc(sizeof(*v));
  u=malloc(sizeof(*u));
	//v_resultado=malloc(sizeof(*v_resultado));

	renglones(A_resultado)=M;
	columnas(A_resultado)=N;
	renglones_vector(v)=M;
  renglones_vector(u)=N;
	//renglones_vector(v_resultado) = M;
	entradas(A_resultado)=malloc(renglones(A_resultado)*columnas(A_resultado)*sizeof(double));
	//inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);
  entradas_vector(u)=malloc(M*sizeof(double));
  inicializa_vector(u,u_vector);

	//entradas_vector(v_resultado)=calloc(M,sizeof(double));
	//printf("matriz:\n");
	//imprime_matriz(A);
	//printf("------------\n");
	printf("vector v:\n");
	imprime_vector(v);
	printf("------------\n");
  printf("vector u:\n");
	imprime_vector(u);
	printf("------------\n");
	printf("matriz resultado:\n");

//	y := alpha*A*x + beta*y
// dgemv_("No transpose", &M, &N, &ALPHA, entradas(A), &M, entradas_vector(v),
//   &incx, &BETA, entradas_vector(v_resultado),&incx);
//A := alpha*x*y**T + A,
  dger_(&M, &N, &ALPHA, entradas_vector(v), &incx, entradas_vector(u), &incy, //
  entradas(A_resultado), &M);
  imprime_matriz(A_resultado);
	free(entradas(A_resultado));
	free(A_resultado);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(u));
	free(u);
	return 0;
}
