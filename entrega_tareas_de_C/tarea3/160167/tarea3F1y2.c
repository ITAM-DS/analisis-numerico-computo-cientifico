//Tarea 3  by Ricardo Lastra
//Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.
//Funcion 1. Imprime solo entradas nones
//Funcion 2. Imprime direcciones nones

#include<stdio.h>
void main(){
    int arreglo[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int i,j;
    int arreglom[2][3] = {{-1,-2,-3},{-4,-5,-6}};
    /* imprimiendo las entradas de 1 dim*/

    printf("----todas las entradas----\n");
    for(i=0;i<sizeof(arreglo)/sizeof(arreglo[0]);i++)
        printf("arreglo[%d]=%d\n", i,arreglo[i]);
    printf("----direccion de memoria----\n");
    for(i=0;i<sizeof(arreglo)/sizeof(arreglo[0]);i++)
        printf("posicion arreglo %d, memoria: %p\n", i, arreglo+i);
    printf("----solo entradas impares----\n");
    /* imprimiendo solo las entradas nones */
    for (i=0; i<sizeof(arreglo)/sizeof(arreglo[0]); i++) {
	if (i % 2 != 0)
		printf("arreglo[%d]=%d\n", i,arreglo[i]);
	}
    printf("----solo posiciones impares----\n");
    for(i=0;i<sizeof(arreglo)/sizeof(arreglo[0]);i++) {
	if (i % 2 != 0)
		printf("posicion %d, memoria: %p\n", i, arreglo+i);
	}
    /* imprimiendo las entradas de dos dim */

    printf("----todas las entradas dos dim----\n");
    for(i=0;i<sizeof(arreglom)/sizeof(arreglom[0]);i++){
	for(j=0;j<sizeof(arreglom[0])/sizeof(arreglom[0][0]);j++)
		printf("arreglom[%d][%d] = %d\n", i,j, arreglom[i][j]);
	}
    printf("----direccion de memoria dos dim----\n");
    for(i=0;i<sizeof(arreglom)/sizeof(arreglom[0][0]);i++)
        printf("posicion arreglo dos dim %d, memoria: %p\n", i,arreglom+i);
    /* imprimiendo solo las posiciones nones de dos dim*/
    printf("----solo entradas impares dos dim----\n");
    for(i=0; i<sizeof(arreglom)/sizeof(arreglom[0]);i++){
	for(j=0; j<sizeof(arreglom[0])/sizeof(arreglom[0][0]);j++){
		if ((i+j) % 2 == 1){
		printf("arreglom[%d][%d] = %d\n", i,j,arreglom[i][j]);
		}
	}
	}
    printf("----solo posiciones impares dos dim----\n");
    for(i=0;i<sizeof(arreglom)/sizeof(arreglom[0][0]);i++) {
	if (i % 2 != 0)
		printf("posicion %d, memoria: %p\n", i, arreglom+i);
	}
}
