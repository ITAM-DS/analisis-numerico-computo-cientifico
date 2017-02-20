#include<stdio.h>
// Definición de la función de impresión de arreglos
int imparreglos(int dimen){
  int i,j,filas,columnas;
  if(dimen == 1){
    int vector[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int *p;
    int i;
    filas = sizeof(vector)/sizeof(vector[0]);
      printf("\nLas entradas impares del vector, son:\n");
      for(i=0;i<filas;i++){
        if(i%2 != 0)printf("p[%d] = %d\n", i, vector[i]);
      }
  }
  else{
    int vector[][3] = {{-1,-2,-3},{-4,-5,-6}};
    int(*p)[][3];
    int i,j;
    filas = sizeof(vector)/sizeof(vector[0]);
    columnas = sizeof(vector[0])/sizeof(vector[0][0]);
    printf("\nLas entradas impares del vector, son:\n");
    for(i=0;i<filas;i++){
      for(j=0;j<columnas;j++){
        if((i+j)%2 != 0)printf("p[%d][%d] = %d\n", i, j, vector[i][j]);
      }
    }

  }
}
int imdireccion(int dimen){
  int i,j,filas,columnas;
  if(dimen == 1){
    int vector[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int *p;
    int i;
    filas = sizeof(vector)/sizeof(vector[0]);
    printf("\nLas direcciones de las entradas impares del vector, son:\n");
    for(i=0;i<filas;i++){
      if(i%2 != 0)printf("&p[%d] = %p\n", i, &vector[i]);
    }
  }
  else{
    int vector[][3] = {{-1,-2,-3},{-4,-5,-6}};
    int(*p)[][3];
    int i,j;
    filas = sizeof(vector)/sizeof(vector[0]);
    columnas = sizeof(vector[0])/sizeof(vector[0][0]);
    printf("\nLas direcciones de las entradas impares del vector, son:\n");
    for(i=0;i<filas;i++){
      for(j=0;j<columnas;j++){
        if((i+j)%2 != 0)printf("&p[%d] = %p\n", (i+j), &vector[i][j]);
      }
    }

  }
}
int main(){
  int dimen;
  printf("¿Quieres tu arreglo de 1 o 2 dimensiones?\n");
  scanf("%d",&dimen);
  imparreglos(dimen);
  imdireccion(dimen);
}
