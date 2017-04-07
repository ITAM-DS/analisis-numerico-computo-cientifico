#include<stdio.h>
#include<stdlib.h>
#include"definiciones2.h" 
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
double (*matriz1)[NUM_COL_MAT1];
double (*matriz2)[NUM_COL_MAT2];
double (*matriz_resultado)[NUM_COL_MAT2];

//static double **matriz1;
//static double **matriz2;
//static double **matriz_resultado; EVIDENTEMENTE ESTE NO ES EL CAMINO

static double matriz_1[NUM_REN_MAT1][NUM_COL_MAT1]={
        {0, 1.5},
        {4, -5},
        {-1, 2.5}
    };
static double matriz_2[NUM_REN_MAT2][NUM_COL_MAT2]={
        {1, 0, 0},
        {0, -1, 1}
    };
static double matrizresultado[NUM_REN_MAT1][NUM_COL_MAT2];

void aloja_espacio_e_inicializa_matrices(void){
	matriz1=matriz_1;
	matriz2=matriz_2;
	matriz_resultado=matrizresultado;
}

void libera_espacio(void){
	free(matriz1);
	free(matriz2);
	free(matriz_resultado);
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