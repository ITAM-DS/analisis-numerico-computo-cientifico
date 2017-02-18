#include<stdio.h>

// Variables Globales
int a[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
int *p;
int i;

int unadimension(){
  a;
  p = a;

  int length_of = sizeof(a)/sizeof(a[0]);

  printf("\nLas entradas impares del vector, son:\n");

  for(i=0;i<length_of;i++){
    if(i%2 != 0)printf("p[%d] = %d\n", i, a[i]);
  }

  printf("\nLas direcciones de las entradas impares del vector, son:\n");
  for(i=0;i<length_of;i++){
    if(i%2 != 0)printf("p[%d] = %p\n", i, &a[i]);
  }
}

int main(){
  int dim;
  printf("¿Quieres tu arreglo de 1 o 2 dimensiones?\n");
  dim = getchar();
  if(dim != 1){
    unadimension(a,p);
  }
  else printf("Todavía no hago esta función");
}
