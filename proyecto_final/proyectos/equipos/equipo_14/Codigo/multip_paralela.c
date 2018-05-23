#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxK
#define B_matriz "B.txt" //de tamaño KxN

void main(int argc, char *argv[]){
  arreglo_2d_T A, B,C;
  int M=atoi(argv[1]);
  int K=atoi(argv[2]);
  int N=atoi(argv[4]);
  A=malloc(sizeof(*A));
  B=malloc(sizeof(*B));
  C=malloc(sizeof(*C));
  renglones(A)=M;
  columnas(A)=K;
  renglones(B)=K;
  columnas(B)=N;
  renglones(C) = K;
  columnas(C) = M;
  entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
  inicializa_matriz(A,A_matriz);
  entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
  inicializa_matriz(B,B_matriz);
  //imprime_matriz(A);
  //imprime_matriz(B);
  entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));
  int conteo_threads;
  conteo_threads = strtol(argv[5], NULL, 10);
  struct timeval t0,t1;
  gettimeofday(&t0,0);
  int i,j,k;
#pragma omp parallel for num_threads(conteo_threads) private(i,j,k) shared(A,B,C)
    for(i=0;i<M;i++){
      for(j=0;j<N;j++){
	//entrada(C,i,j) = 0.0;
	for(k=0;k<K;k++){
	  entrada(C,i,j,M) = entrada(C,i,j,M) + entrada(A,i,k,M)*entrada(B,k,j,M);
	}
      }
    }
    //}
  gettimeofday(&t1,0);
  //imprime_matriz(C);
  double elapsed = (t1.tv_sec-t0.tv_sec)*1.0f+(t1.tv_usec-t0.tv_usec)/1000000.0f;
  //printf("\nTiempo: %f \n",elapsed);
  printf("\n%f,%d,%d,%d",elapsed,renglones(C),columnas(C),conteo_threads);
  free(entradas(A));
  free(A);
  free(entradas(B));
  free(B);
  free(entradas(C));
  free(C);
  return 0;

}
