/* 
Arturo Gonzalez Bencomo 172906

Tarea3

Instrucciones:
Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.
*/

#include <stdio.h>

int main()
{

	int vector[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int matriz[2][3] = {
		{-1,-2,-3},
		{-4,-5,-6}
	};	
	printf("\nDatos vector: \n");	
	printf("Contenido \n");
	impresion_contenido(vector, (sizeof(vector)/sizeof(vector[0]))*(sizeof(vector[0])/sizeof(int)));
	printf("Referencias de memoria \n");
	impresion_direcciones_memoria(vector, (sizeof(vector)/sizeof(vector[0]))*(sizeof(vector[0])/sizeof(int)));
	printf("\nDatos matriz: \n");
	printf("Contenido \n");
	impresion_contenido(matriz, (sizeof(matriz)/sizeof(matriz[0]))*(sizeof(matriz[0])/sizeof(int)));
	printf("Referencias de memoria \n");
	impresion_direcciones_memoria(matriz, (sizeof(matriz)/sizeof(matriz[0]))*(sizeof(matriz[0])/sizeof(int)));
	
	return 0;
}


void impresion_contenido(int *vector,int size)
{	
	for(int x=1; x<size; x=x+2){
		printf("vec[%d] = %d\n",x,vector[x]);
	}
}

void impresion_direcciones_memoria(int *vector,int size)
{		
	for(int x=1; x<size; x=x+2){
		printf("&vec[%d] = %p\n",x,&vector[x]);
	}
}