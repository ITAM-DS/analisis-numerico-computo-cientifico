
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;

void aloja_espacio_e_inicializa_matrices(void){
	matriz1 = malloc(NUM_REN_MAT1*sizeof(double*));
	matriz2 = malloc(NUM_REN_MAT2*sizeof(double*));
	matriz_resultado = malloc(NUM_COL_MAT1 * sizeof(double*));

	for (i = 0; i<NUM_REN_MAT1; i++){
		matriz1[i] = malloc(NUM_COL_MAT1 * sizeof(double));
	}
	for (i = 0; i<NUM_REN_MAT2; i++){
		matriz2[i] = malloc(NUM_COL_MAT2 * sizeof(double));
	}
	for (i = 0; i<NUM_REN_MAT1; i++){
		matriz_resultado[i] = malloc(NUM_COL_MAT2 * sizeof(double));
	}

	matriz1[0][0] = 0;
	matriz1[0][1] = 1.5;
	matriz1[1][0] = 4;
	matriz1[1][1] = -5;
	matriz1[2][0] = -1;
	matriz1[2][1] = 2.5;
	matriz2[0][0] = 1;
	matriz2[0][1] = 0;
	matriz2[0][2] = 0;
	matriz2[1][0] = 0;
	matriz2[1][1] = -1;
	matriz2[1][2] = 1;
	/*
	for (int l = 0; l < NUM_REN_MAT1; ++l)
	{
		for (int m = 0; m < NUM_COL_MAT1; ++m)
		{
			*(matriz1+l+m)=mat1[l*NUM_REN_MAT1+m];
		}
	}

	for (int l = 0; l < NUM_REN_MAT2; ++l)
	{
		for (int m = 0; m < NUM_COL_MAT2; ++m)
		{
			*(matriz2+l+m)=mat2[l*NUM_REN_MAT2+m];
		}
	}*/
}

void libera_espacio(void){
	for (i = 0; i<NUM_REN_MAT1; i++){
		free(matriz1[i]);
	}
	for (i = 0; i<NUM_REN_MAT2; i++){
		free(matriz2[i]);
	}
	for (i = 0; i<NUM_REN_MAT1; i++){
		free(matriz_resultado[i]);
	}
	free(matriz1);
	free(matriz2);
	free(matriz_resultado);
}
/*
static double matriz1[NUM_REN_MAT1][NUM_COL_MAT1]={
        {0, 1.5},
        {4, -5},
        {-1, 2.5}
    };

static double matriz2[NUM_REN_MAT2][NUM_COL_MAT2]={
        {1, 0, 0},
        {0, -1, 1}
    };
static double matriz_resultado[NUM_REN_MAT1][NUM_COL_MAT2];
*/
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