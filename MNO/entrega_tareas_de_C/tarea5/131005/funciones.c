#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;

void aloja_inicia_matrices(void){
	double **m1=malloc(NUM_REN_MAT1 * sizeof(double*));
	size_t i;
	for(i=0; i<NUM_REN_MAT1; i++)
		m1[i]=malloc(NUM_COL_MAT1 * sizeof(double));
	m1[0][0]=0;
	m1[0][1]=1.5;
	m1[1][0]=4;
	m1[1][1]=-5;
	m1[2][0]=-1;
	m1[2][1]=2.5;

	double **m2=malloc(NUM_REN_MAT2 * sizeof(double*));
	for(i=0; i<NUM_REN_MAT2; i++)
		m2[i]=malloc(NUM_COL_MAT2 * sizeof(double));
	m2[0][0]=1;
	m2[0][1]=0;
	m2[0][2]=0;
	m2[1][0]=0;
	m2[1][1]=-1;
	m2[1][2]=1;

	double **mres=malloc(NUM_REN_MAT1 * sizeof(double*));
	for(i=0; i<NUM_REN_MAT1; i++)
		mres[i]=malloc(NUM_COL_MAT2 * sizeof(double));

	matriz1=m1;
	matriz2=m2;
	matriz_resultado=mres;
}

void imprime_matrices(void){
	printf("Matriz1\n");
		for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
			for(j=0;j<NUM_COL_MAT1;j++){
				if(j<NUM_COL_MAT1-1)
				printf("matriz1[%d][%d]=%4.2f\t",i,j,matriz1[i][j]);
				else
				printf("matriz1[%d][%d]=%4.2f\n",i,j,matriz1[i][j]);
			}
		}
	printf("\n");
	printf("Matriz2\n");
		for(i=0;i<NUM_REN_MAT2;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz2[%d][%d]=%4.2f\t",i,j,matriz2[i][j]);
				else
				printf("matriz2[%d][%d]=%4.2f\n",i,j,matriz2[i][j]);
			}
		}
	printf("\n");
}

void imprime_matriz_resultado(void){
	printf("Matriz resultado\n");
		for(i=0;i<NUM_REN_MAT1;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz_res[%d][%d]=%4.2f\t",i,j,matriz_resultado[i][j]);
				else
				printf("matriz_res[%d][%d]=%4.2f\n",i,j,matriz_resultado[i][j]);
			}
		}

	printf("\n");

}

void multiplica_matrices(void){
	for(i=0;i<NUM_REN_MAT1;i++){
		for(k=0;k<NUM_COL_MAT2;k++){
	 		matriz_resultado[i][k]=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
  				matriz_resultado[i][k]=matriz_resultado[i][k]+matriz1[i][j]*matriz2[j][k];
		}
	}
}

void libera_espacio(void){
	free(matriz1);
	free(matriz2);
	free(matriz_resultado);
}
