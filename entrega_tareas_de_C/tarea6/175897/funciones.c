#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
static int i,j;
void inicializa_matriz(arreglo_2d_T p, char *s){
	int m = renglones(p);
	int n = columnas(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			fscanf(pFile,"%lf", &entrada(p,i,j));
	fclose(pFile);
}
void inicializa_vector(arreglo_1d_T p, char *s){
	int m = renglones_vector(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
			fscanf(pFile,"%lf", &entrada_vector(p,i));
	fclose(pFile);
}
void imprime_matriz(arreglo_2d_T p){
	int m = renglones(p);
	int n = columnas(p);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(j<n-1)
				printf("matriz[%d][%d]=%.5f\t",i,j,entrada(p,i,j));
				else
				printf("matriz[%d][%d]=%.5f\n",i,j,entrada(p,i,j));
			}
		}
}
void imprime_vector_entero(arreglo_1d_T p){
	int m = renglones_vector(p);
		for(i=0;i<m;i++)
				printf("vector[%d]=%d\n",i,entrada_vector_entero(p,i));
}
void imprime_vector(arreglo_1d_T p){
	int m = renglones_vector(p);
			for(i=0;i<m;i++)
				printf("vector[%d]=%.5f\n",i,entrada_vector(p,i));
}
