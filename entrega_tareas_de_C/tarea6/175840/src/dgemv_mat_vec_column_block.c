#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_block_column.txt" //de tamaño MxN
#define v_vector "v_block_column.txt" //de tamaño Nx1
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void dlacpy_(char *part_of_a, int *m, int *n, double *a, int *lda, double *b, int *ldb);
int main(int argc, char *argv[]){
	arreglo_2d_T A, A_block;
	arreglo_1d_T v, v_resultado;
	arreglo_1d_T n_a;
	int j;
	int jj;
	int incx=1;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int nb=atoi(argv[3]); //numero de columnas en un bloque
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 1.0;
	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	v_resultado=malloc(sizeof(*v_resultado));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(v_resultado) = M;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);

	entradas_vector(v_resultado)=calloc(M,sizeof(double));

	n_a=malloc(sizeof(*n_a));
	renglones_vector(n_a)=(N%nb != 0)?N/nb+1:N/nb;
	entradas_vector_entero(n_a) = malloc(renglones_vector(n_a)*sizeof(int));

	for(j=0;j<renglones_vector(n_a)-1;j++)
		entrada_vector_entero(n_a,j)=nb;
		entrada_vector_entero(n_a,j)=(N%nb != 0)?N-(N/nb*nb):nb;

	A_block=malloc(sizeof(*A_block));

	printf("matriz block:\n");
	imprime_matriz(A_block);
	printf("------------\n");

	renglones(A_block)=renglones(A);
	jj=0;
	for(j=0;j<renglones_vector(n_a);j++){
		columnas(A_block)=entrada_vector_entero(n_a,j);
		entradas(A_block)=(j==0)?malloc(renglones(A)*columnas(A_block)*sizeof(double)):realloc(entradas(A_block), renglones(A)*columnas(A_block)*sizeof(double));
		dlacpy_("General", &renglones(A), &columnas(A_block),entradas(A)+jj*renglones(A), &renglones(A), entradas(A_block), &renglones(A_block));	
		printf("matriz block:\n");
		imprime_matriz(A_block);
		printf("------------\n");
		dgemv_("No transpose", &renglones(A), &columnas(A_block), &ALPHA, entradas(A_block), &renglones(A), entradas_vector(v)+jj, &incx, &BETA, entradas_vector(v_resultado),&incx);
		jj+=entrada_vector_entero(n_a,j);
	}


	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector resultado by blocks:\n");
	imprime_vector(v_resultado);

	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(v_resultado));
	free(v_resultado);
	free(entradas(A_block));
	free(A_block);
	free(entradas_vector_entero(n_a));
	free(n_a);
	return 0;
}