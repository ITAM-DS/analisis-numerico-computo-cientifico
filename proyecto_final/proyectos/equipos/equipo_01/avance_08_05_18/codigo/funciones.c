#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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

void inicializa_batch(arreglo_2d_T b, arreglo_2d_T X, arreglo_1d_T y_b, arreglo_1d_T y){
	int m_b = renglones(b);
	int m = renglones(X);
	int n = columnas(b);
	int r;
	for(i=0; i<m_b; i++){
		r = rand() % m;
		entrada_vector(y_b,i)=entrada_vector(y, r);
		for(j=0; j<n; j++){
			entrada(b,i,j) = entrada(X,r,j);
		}
	}
}

void inicializa_ceros(arreglo_1d_T a, int cols){
	for(i=0; i<cols; i++){
		entrada_vector(a,i)=0;
		}
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
