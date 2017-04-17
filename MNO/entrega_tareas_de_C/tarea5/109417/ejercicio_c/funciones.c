#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de variables que sern externas
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;

void aloja_espacio_e_incializa_matrices(void){
double  **mat1 = malloc(NUM_REN_MAT1 * sizeof(double*));
size_t i;
for (i = 0; i < NUM_REN_MAT1; i ++)
	mat1[i] = malloc(NUM_COL_MAT1 * sizeof(double));
mat1[0][0]= 0;
mat1[0][1]=1.5;
mat1[1][0]=4;
mat1[1][1]=-5;
mat1[2][0]=-1;
mat1[2][1]=2.5;
double **mat2 = malloc(NUM_REN_MAT2 * sizeof(double*));
for (i = 0; i< NUM_REN_MAT2; i ++)
	mat2[i] = malloc(NUM_COL_MAT2 * sizeof(double));
mat2[0][0]=1;
mat2[0][1]=0;
mat2[0][2]=0;
mat2[1][0]=0;
mat2[1][1]=-1;
mat2[1][2]=1;

double **mat_res = malloc(NUM_REN_MAT1 * sizeof(double*));
for (i = 0; i<NUM_REN_MAT1; i++)
	mat_res[i] = malloc(NUM_COL_MAT2 * sizeof(double));

matriz1=mat1;
matriz2=mat2;
matriz_resultado=mat_res;

}


void imprime_matrices(void){
printf("Matriz1\n");
for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 est definido en "definiciones.h"
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
