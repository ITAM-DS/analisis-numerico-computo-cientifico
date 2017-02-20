//Tarea 3  by Ricardo Lastra
//Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.
//Funcion 1. Imprime solo entradas nones
//Funcion 2. Imprime direcciones nones

#include<stdio.h>
void main(){
    int arreglo[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int i,n;
    int arreglom[2][5] = {{-1,-2,-3,-4,-5},{-6,-7,-8,-9,-10}};
    printf("---todas las entradas---\n");
    for(i=0;i<sizeof(arreglo)/sizeof(arreglo[0]);i++)
        printf("arreglo[%d]=%d\n", i,arreglo[i]);
    printf("--------------------\n");
    for(i=0;i<sizeof(arreglo)/sizeof(arreglo[0]);i++)
        printf("posicion arreglo %d, memoria: %p\n", i, arreglo+i);
    printf("---solo entradas impares---\n");
    /* imprimiendo solo las entradas nones */
    for (i=0; i<sizeof(arreglo)/sizeof(arreglo[0]); i++) {
	if (i % 2 != 0)
		printf("arreglo[%d]=%d\n", i,arreglo[i]);
	}
    printf("------solo posiciones impares-----------\n");
    for(i=0;i<sizeof(arreglo)/sizeof(arreglo[0]);i++) {
	if (i % 2 != 0)
		printf("posicion %d, memoria: %p\n", i, arreglo+i);
	}
    printf("---todas las entradas dos dim---\n");
    for(i=0;i<sizeof(arreglom)/sizeof(arreglom[0][0]);i++)
        printf("arreglom[%d][%d]=%d\n", i,arreglom[i]);
    printf("--------------------\n");
    for(i=0;i<sizeof(arreglom)/sizeof(arreglom[0][0]);i++)
        printf("posicion arreglo dos dim %d, memoria: %p\n", i,arreglom+i);
    printf("---solo entradas impares dos dim---\n");
    /* imprimiendo solo las entradas nones */
    for (i=0; i<sizeof(arreglom)/sizeof(arreglom[0][0]); i++) {
	if (i % 2 != 0)
		printf("arreglom[%d][%d]=%d\n", i,arreglom[i]);
	}
    for(i=0;i<sizeof(arreglom)/sizeof(arreglom[0][0]);i++) {
	if (i % 2 != 0)
		printf("posicion %d, memoria: %p\n", i, arreglom+i);
	}
}
