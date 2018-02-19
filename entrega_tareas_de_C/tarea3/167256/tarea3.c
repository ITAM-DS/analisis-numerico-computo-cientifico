#include<stdio.h>

void entradas_impares(int *p,int dim){
  int j;
  for(j=0;j<dim;j++){
    if(j%2!=0)
      printf("Valor de p[%d] = %d\n",j,*(p+j));
  }
}

void direccion_memoria(int *p,int dim){
  int j;
  for(j=0;j<dim;j++){
    if(j%2!=0)
      printf("Dirección de memoria de p[%d] = %p\n",j,(p+j));
  }
}

  main(){
    int arr1[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int arr2[2][3]={{-1,-2,-3},{-4,-5,-6}};
    int renglones,columnas,dimension,i,j;
    int *apuntador;

    apuntador=arr1;
    dimension=(sizeof(arr1)/sizeof(arr1[0]));
    printf("Se corre el programa para el arreglo:\n");
    for(i=0;i<dimension;i++)
      printf("p[%d] = %d\n",i,arr1[i]);
    printf("\nCorremos la primer funcion, imprime valores de entradas impares:\n");
    entradas_impares(apuntador,dimension);
    printf("\nAhora corremos la segunda funcion, imprime las direcciones de memoria de las entradas impares:\n");
    direccion_memoria(apuntador,dimension);
    printf("\nSe corre el programa para el arreglo multidimensional:\n");
    renglones=(sizeof(arr2)/sizeof(arr2[0]));
    columnas=(sizeof(arr2[0])/sizeof(arr2[0][0]));
    dimension=renglones*columnas;
    apuntador=arr2;
    for(i=0;i<renglones;i++)
      for(j=0;j<columnas;j++)
	printf("matriz[%d][%d] = %d\n",i,j,arr2[i][j]);
    printf("\nPor lo que para este arreglo la funcion 1 imprime:\n");
    entradas_impares(apuntador,dimension);
    printf("\nLa función 2 imprime:\n");
    direccion_memoria(apuntador,dimension);
  }
