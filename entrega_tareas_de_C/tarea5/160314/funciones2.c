#include<stdio.h>
#include<stdlib.h>
#include"definiciones2.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;

double **matriz1;
double **matriz2;
double **matriz_resultado;
	

void aloja_espacio_e_incializa_matrices(void){

	matriz1 = (double **)malloc(NUM_REN_MAT1*sizeof(double*));
        matriz2 = (double **)malloc(NUM_REN_MAT2*sizeof(double*));
        matriz_resultado=(double **)malloc(NUM_REN_MAT1*sizeof(double*));
        
        double matriz1valores[NUM_REN_MAT1][NUM_COL_MAT1]={{0, 1.5},{4, -5},{-1, 2.5}};
        double matriz2valores[NUM_REN_MAT2][NUM_COL_MAT2]={{1, 0, 0},{0, -1, 1}}; 
        
        for (i=0;i<NUM_REN_MAT1;i++) 
		matriz1[i] = (double*)malloc(NUM_COL_MAT1*sizeof(double)); 

        for (i=0;i<NUM_REN_MAT2;i++) 
		matriz2[i] = (double*)malloc(NUM_COL_MAT2*sizeof(double)); 
        
        for (i=0;i<NUM_REN_MAT1;i++) 
		matriz_resultado[i] = (double*)malloc(NUM_COL_MAT2*sizeof(double)); 
         
	for(i=0;i<NUM_REN_MAT1;i++){
		for(j=0;j<NUM_COL_MAT1;j++){
				matriz1[i][j] = matriz1valores[i][j];
				
		}
}
             
        
        for(i=0;i<NUM_REN_MAT2;i++){
		for(j=0;j<NUM_COL_MAT2;j++){
			matriz2[i][j] = matriz2valores[i][j];
			
		}
	}	
}


void libera_espacio(void)
{
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

void multiplica_matrices(void){
	for(i=0;i<NUM_REN_MAT1;i++){
		for(k=0;k<NUM_COL_MAT2;k++){
	 		matriz_resultado[i][k]=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
  				matriz_resultado[i][k]=matriz_resultado[i][k]+matriz1[i][j]*matriz2[j][k];
		}
	}
}
