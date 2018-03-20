#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño Nx1
#define v2_vector "v2.txt" //de tamaño Nx1

//Definiendo el prototipo de la funcion daxpy y sus parametros 
extern double daxpy_(int *no_elementos, double *escalar, double *vector_x, int *incremento_x, double *vector_y, int *incremento_y);

int main(int argc, char *argv[]){
  arreglo_1d_T v1, v2;
  int incx=1;
  int N=atoi(argv[1]);
  double escalar = atoi(argv[2]);
  
  v1=malloc(sizeof(*v1));
  v2=malloc(sizeof(*v2));
  
  renglones_vector(v1)=N;
  renglones_vector(v2)=N;
  
  entradas_vector(v1)=malloc(N*sizeof(double));
  inicializa_vector(v1,v1_vector);
  entradas_vector(v2)=malloc(N*sizeof(double));
  inicializa_vector(v2,v2_vector);
  
  printf("------------\n");
  printf("vector :\n");
  imprime_vector(v1);
  printf("------------\n");
  printf("vector :\n");
  imprime_vector(v2);
  printf("------------\n");
  
  //Utilizamos daxpy para realizar 1) multiplicacion escalar-vector y 2) resultado multiplicado por un segundo vector
  daxpy_(&N, &escalar, entradas_vector(v1), &incx, entradas_vector(v2), &incx);
  printf("El resultado de daxpy es: \n");
  imprime_vector(v2);
  free(entradas_vector(v1));
  free(v1);
  free(entradas_vector(v2));
  free(v2);
  return 0;
}
