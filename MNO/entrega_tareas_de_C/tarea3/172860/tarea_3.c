/*
Ixchel G. Meza Chávez
Tarea 3

Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.

*/

#include<stdio.h>

void imprimir_valores_impares(int *p, int longitud);
void imprimir_direcciones_impares(int *p, int longitud);

void imprimir_valores_impares(int *p, int longitud){
  for(int i=1;i<longitud;i=i+2)
    printf("Valor de arreglo[%d]. p[%d]: %d\n", i, i, *(p+i));
}

void imprimir_direcciones_impares(int *p, int longitud){
  for(int i=1;i<longitud;i=i+2)
    printf("Dirección de memoria del arreglo[%d]. &p[%d]: %p\n", i, i, p+i);
}

int main(){
  int arreglo1[10] = {1,2,3,4,5,6,7,8,9,10};
  int arreglo2[3][4] = {{-1,-2,-3,-4},{-5,-6,-7,-8},{-9,-10,-11,-12}};
  int *p;
  p = arreglo1;
  printf("Arreglo[10]:\n");
  imprimir_valores_impares(p, sizeof(arreglo1)/4);
  imprimir_direcciones_impares(p, sizeof(arreglo1)/4);
  p = arreglo2[0];
  printf("Arreglo[3][4]:\n");
  imprimir_valores_impares(p, sizeof(arreglo2)/4);
  imprimir_direcciones_impares(p, sizeof(arreglo2)/4);
  return 0;
}
