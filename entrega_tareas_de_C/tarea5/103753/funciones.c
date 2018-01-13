#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;
  
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
	 		//matriz_resultado[i][k]=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
  				matriz_resultado[i][k]=matriz_resultado[i][k]+matriz1[i][j]*matriz2[j][k];
		}
	}
}

void inicia_matriz(double ***data_ptr, int dim_x, int dim_y, double vector[]){
  int i,j,k;
  double **data;
  data = (double **) malloc(sizeof(double *) * dim_x);
  for (k = 0; k < dim_x; k++) {
      data[k] = (double *) malloc(sizeof(double) * dim_y);
  }

  for (i = 0; i < dim_x; i++) {
      for (j = 0; j < dim_y; j++) {
          data[i][j] = vector[i*dim_y+j];
      }
  }
  *data_ptr = data;
}

void aloja_espacio_e_inicializa_matrices(void){
  double vector_mult[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  double vector1[] = {0, 1.5, 4, -5, -1, 2.5};
  double vector2[] = {1, 0, 0, 0, -1, 1};
  inicia_matriz(&matriz1, NUM_REN_MAT1, NUM_COL_MAT1, vector1);
  inicia_matriz(&matriz2, NUM_REN_MAT2, NUM_COL_MAT2, vector2);
  inicia_matriz(&matriz_resultado, NUM_REN_MAT1, NUM_COL_MAT2, vector_mult);
}

void libera_espacio(void){
	free(matriz1);
    free(matriz2);
    free(matriz_resultado);
}     
