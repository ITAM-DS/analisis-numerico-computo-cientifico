#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_block_row.txt" //de tamaño MxN
#define v_vector "v_block_row.txt" //de tamaño Nx1
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void dlacpy_(char *part_of_a, int *m, int *n, double *a, int *lda, double *b, int *ldb);
int main(int argc, char *argv[]){
	arreglo_2d_T A, A_block;
	arreglo_1d_T v, v_resultado;
	arreglo_1d_T m_a;
	int i;
	int ii;
	int incx=1;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int nb=atoi(argv[3]); //numero de renglones en un bloque
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 0.0;
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


	m_a=malloc(sizeof(*m_a));
	renglones_vector(m_a)=(M%nb != 0)?M/nb+1:M/nb;
	entradas_vector_entero(m_a) = malloc(renglones_vector(m_a)*sizeof(int));

	for(i=0;i<renglones_vector(m_a)-1;i++)
		entrada_vector_entero(m_a,i)=nb;
		entrada_vector_entero(m_a,i)=(M%nb != 0)?M-(M/nb*nb):nb;
	printf("vector:\n");
	imprime_vector_entero(m_a);

	A_block=malloc(sizeof(*A_block));

	columnas(A_block)=columnas(A);
	ii=0;
	for(i=0;i<renglones_vector(m_a);i++){
		renglones(A_block)=entrada_vector_entero(m_a,i);
		entradas(A_block)=(i==0)?malloc(renglones(A_block)*columnas(A)*sizeof(double)):realloc(entradas(A_block), renglones(A_block)*columnas(A)*sizeof(double));
		dlacpy_("General", &renglones(A_block), &columnas(A),entradas(A)+ii, &renglones(A), entradas(A_block), &renglones(A_block));	
		printf("matriz block:\n");
		imprime_matriz(A_block);
		printf("------------\n");
		dgemv_("No transpose", &renglones(A_block), &columnas(A), &ALPHA, entradas(A_block), &renglones(A_block), entradas_vector(v), &incx, &BETA, entradas_vector(v_resultado)+ii,&incx);

		ii+=entrada_vector_entero(m_a,i);
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
	free(entradas_vector_entero(m_a));
	free(m_a);
	return 0;
}
