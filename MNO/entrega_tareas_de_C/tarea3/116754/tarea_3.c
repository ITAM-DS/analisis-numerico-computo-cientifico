#include<stdio.h>

// Variables Globales
int a[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
int b[][3] = {{-1,-2,-3},{-4,-5,-6}};
int *p;
int (*pmul)[][3];
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

int muldimension(){
  b;
  pmul = &b;

  int length_of = sizeof(b)/sizeof(b[0][0]);

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
  int dimen;
  printf("¿Quieres tu arreglo de 1 o 2 dimensiones?\n");
  scanf("%d",&dimen);
  if(dimen == 1){
    unadimension(a,p);
  }
  else printf("Todavía no hago esta función\n");
}
