Suponemos un sistema ubuntu y que está instalado libblas-dev y liblapack-dev.

En la carpeta [solve_linear_equations](solve_linear_equations/) se tienen códigos que utilizan los archivos `definiciones.h` y `funciones.c` siguiente:

* `definiciones.h`:

```
//arreglo2d:
typedef struct{
int m, n;
#define renglones(arreglo) ((arreglo)->m)
#define columnas(arreglo) ((arreglo)->n)
double *arr;
#define entradas(arreglo) ((arreglo)->arr)
#define entrada(arreglo,i,j) ((arreglo)->arr[j*m+i]) //almacenamos column major
}arreglo_2d;
typedef arreglo_2d *arreglo_2d_T;

//arreglo1d
typedef struct{
int n;
#define renglones_vector(arreglo) ((arreglo)->n)
double *arr;
int *arr_int;
#define entradas_vector(arreglo) ((arreglo)->arr)
#define entrada_vector(arreglo,i) ((arreglo)->arr[i])
#define entradas_vector_entero(arreglo) ((arreglo)->arr_int)
#define entrada_vector_entero(arreglo,i) ((arreglo)->arr_int[i])
}arreglo_1d;
typedef arreglo_1d *arreglo_1d_T;

//funciones
void imprime_vector(arreglo_1d_T);
void imprime_matriz(arreglo_2d_T);
void inicializa_matriz(arreglo_2d_T, char *);
void inicializa_vector(arreglo_1d_T, char *);
void inicializa_matriz_ceros(arreglo_2d_T);
void inicializa_vector_ceros(arreglo_1d_T);
void imprime_vector_entero(arreglo_1d_T);
```

* `funciones.c`:

```
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
void inicializa_matriz_ceros(arreglo_2d_T p){
	int m = renglones(p);
	int n = columnas(p);
  	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			entrada(p,i,j)=0;
}
void inicializa_vector_ceros(arreglo_1d_T p){
	int n = renglones_vector(p);
	for(j=0;j<n;j++)
		entrada_vector(p,j)=0;
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
```

