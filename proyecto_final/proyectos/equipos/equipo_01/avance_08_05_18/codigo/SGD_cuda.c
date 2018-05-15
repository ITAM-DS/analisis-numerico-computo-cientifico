/*
Descenso en Gradiente Estocástico en CUDA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include"definiciones.h"
// Importamos las librerías para trabajar con CUDA y cuBLAS
# include <cuda_runtime.h>
# include "cublas_v2.h"
// Lectura de las tablas de datos
#define X_matriz "X_ent.txt" //de tamaño MxN
#define X_v_matriz "X_valida.txt" //de tamaño MxN
#define b_vector "b_bh.txt" //de tamaño Nx1
#define y_vector "y_train.txt" //de tamaño Mx1
#define y_v_vector "y_val.txt" //de tamaño Mx1

int main(int argc, char const *argv[]) {
  cudaError_t cudastat ;
  // cudaMalloc status
  cublasStatus_t stat ;
  // CUBLAS functions status
  cublasHandle_t handle ;
// CUBLAS context
  // Definición de estructuras que almacenarán los datos
  arreglo_2d_T X, X_v, batch;
	arreglo_1d_T y, y_v, b, g, y_b, rmse, rmse_v, y_static, y_v_static;
  // Definición de los elementos donde almacenaremos los elementos en la GPU
  double *d_X, *d_X_v, *d_batch, *d_y, *d_y_v, *d_b, *d_g, *d_y_b;

  //Dimensiones de los datos de las covariables
  int M=atoi(argv[1]);
  int N=atoi(argv[2]);
  int M_v=atoi(argv[3]);
  // Lectura del parámetro para el tamaño del batch
  int batch_size=atoi(argv[4]);
  // Lectura de stdin del número de interaciones
  int iter=atoi(argv[5]);
  // Lectura de stdin del valor para la tasa de aprendizaje
  double lr=atof(argv[6]);

	int incx=1;
  double ALPHA, BETA;

  // Arreglos para almacenar valores de RMSE entranamiento y validación

// Se aparta el espacio para las estructuras que utilizaremos
  X=malloc(sizeof(*X));
  X_v=malloc(sizeof(*X_v));
  y=malloc(sizeof(*y));
  y_v=malloc(sizeof(*y_v));
  b=malloc(sizeof(*b));
  g=malloc(sizeof(*g));
  batch=malloc(sizeof(*batch));
  y_b=malloc(sizeof(*y_b));
  rmse=malloc(sizeof(*rmse));
  rmse_v=malloc(sizeof(*rmse_v));

  y_static=malloc(sizeof(*y_static));
  y_v_static=malloc(sizeof(*y_v_static));

// Se asignan los valores necesarios a las estructuras que utilizaremos
	renglones(X)=M;
	columnas(X)=N;
  renglones(X_v)=M_v;
	columnas(X_v)=N;
  renglones_vector(b)=N;
	renglones_vector(y)=M;
  renglones_vector(y_v)=M_v;
  renglones_vector(g)=N;
  renglones(batch)=batch_size;
  columnas(batch)=N;
  renglones_vector(y_b)=batch_size;
  renglones_vector(rmse)=iter;
  renglones_vector(rmse_v)=iter;

	renglones_vector(y_static)=M;
  renglones_vector(y_v_static)=M_v;

  // Definimos entorno de CUDA para ejecución
  stat = cublasCreate (& handle );
// Asignar la memoria requerida para cada uno
	entradas(X)=malloc(renglones(X)*columnas(X)*sizeof(double));
	inicializa_matriz(X,X_matriz);

  // Definimos espacio en GPU y copiamos los valores a través de las funciones 'set' de CUBLAS para cada uno
  cudastat = cudaMalloc (( void **)&d_X , M * N * sizeof (*d_X)); // device
  stat = cublasSetMatrix (M ,N , sizeof (double ) ,X->arr ,M , d_X , M );

  entradas(X_v)=malloc(renglones(X_v)*columnas(X_v)*sizeof(double));
  inicializa_matriz(X_v,X_v_matriz);

  cudastat = cudaMalloc (( void **)&d_X_v , M_v * N * sizeof (*d_X_v)); // device
  stat = cublasSetMatrix (M_v ,N , sizeof (double ) ,X_v->arr ,M_v , d_X_v , M_v ); 

	entradas_vector(b)=malloc(N*sizeof(double));
	inicializa_vector(b,b_vector);

  cudastat = cudaMalloc (( void **)&d_b , N * sizeof (*d_b)); // device
  stat = cublasSetVector (N , sizeof (double ) ,b->arr ,1 , d_b ,1); 

  entradas_vector(y)=malloc(M*sizeof(double));
  inicializa_vector(y,y_vector);

  cudastat = cudaMalloc (( void **)&d_y , M * sizeof (*d_y)); // device
  stat = cublasSetVector (M , sizeof (double ) ,y->arr ,1 , d_y ,1);

  entradas_vector(y_v)=malloc(M_v*sizeof(double));
  inicializa_vector(y_v,y_v_vector);

  cudastat = cudaMalloc (( void **)&d_y_v , M_v * sizeof (*d_y_v)); // device
  stat = cublasSetVector (M_v , sizeof (double ) ,y_v->arr ,1 , d_y_v ,1); 

	entradas_vector(g)=malloc(N*sizeof(double));

  cudastat = cudaMalloc (( void **)&d_g , N * sizeof (*d_g )); // device
  stat = cublasSetVector (N , sizeof (double ) ,g->arr ,1 , d_g ,1); 

  entradas(batch)=malloc(renglones(batch)*columnas(batch)*sizeof(double));
  entradas_vector(y_b)=malloc(batch_size*sizeof(double));

  inicializa_batch(batch, X, y_b, y);
  cudastat = cudaMalloc (( void **)&d_batch , batch_size * N * sizeof (*d_batch)); // device
  cudastat = cudaMalloc (( void **)&d_y_b , batch_size * sizeof(*d_y_b)); // device

  entradas_vector(rmse)=malloc(iter*sizeof(double));
  entradas_vector(rmse_v)=malloc(iter*sizeof(double));

	entradas_vector(y_static)=malloc(M*sizeof(double));
  entradas_vector(y_v_static)=malloc(M_v*sizeof(double));
  inicializa_vector(y_static,y_vector);
  inicializa_vector(y_v_static,y_v_vector);
srand(1882);
// Se inicia el ciclo de las iteraciones de descenso
for(int it = 0; it < iter; it++){ 
  clock_t begin = clock();
  // Se reestablece el valor para y al principio de cada iteración
  
  stat = cublasSetVector (M , sizeof (double ) ,y_static->arr ,1 , d_y ,1); // cp x - > d_x
  
  stat = cublasSetVector (M_v , sizeof (double ) ,y_v_static->arr ,1 , d_y_v ,1); // cp x - > d_x
  
  // Se inicializa la matriz de covariables y vector de variable respuesta del batch en cada iteración
  inicializa_batch(batch, X, y_b, y); 
  stat = cublasSetMatrix (batch_size ,N , sizeof (double ) ,batch->arr ,batch_size , d_batch , batch_size ); // cp a - > d_a
  stat = cublasSetVector (batch_size , sizeof (double ) ,y_b->arr ,1 , d_y_b ,1); // cp x - > d_x
// Cálculo del error de predicción: e = - X %*% b + y
// Por las características de la función dgemv, el vector y se sobreescribe con el valor de 'e'
  ALPHA = -1.0;
  BETA = 1.0;
  //Para datos del batch
  stat=cublasDgemv(handle,CUBLAS_OP_N,batch_size,N,&ALPHA,d_batch,batch_size,d_b,1,&BETA,d_y_b,1);
  //Para datos de entrenamiento
  stat=cublasDgemv(handle,CUBLAS_OP_N,M,N,&ALPHA,d_X,M,d_b,1,&BETA,d_y,1);
  // Para datos de validación
  stat=cublasDgemv(handle,CUBLAS_OP_N,M_v,N,&ALPHA,d_X_v,M_v,d_b,1,&BETA,d_y_v,1);
// Se calcula la suma de cuadrados de los residuales para los datos de entrenamiento y de prueba
  // Copiamos el valor de los vectores y (que ahora representan el error) de la GPU  a la CPU
  stat = cublasGetVector (M , sizeof (double ) , d_y ,1 ,y->arr ,1);
  stat = cublasGetVector (M_v , sizeof (double ) , d_y_v ,1 ,y_v->arr ,1);

  double acum = 0;
  for(int i = 0; i < M; i++){
    acum += pow(entradas_vector(y)[i],2);
  }
  double acum_v = 0;
  for(int i = 0; i < M_v; i++){
    acum_v += pow(entradas_vector(y_v)[i],2);
  }
  entrada_vector(rmse,it) = acum/M;
  entrada_vector(rmse_v,it) = acum_v/M_v;
  printf("Iteración %d/%d RSS train: %lf -- RSS val: %lf \n", it+1, iter, entrada_vector(rmse,it), entrada_vector(rmse_v,it));
  printf("------------\n");
// Cálculo del gradiente: g = -X^t %*% e
  ALPHA = -1.0;
  BETA = 0.0;
  stat=cublasDgemv(handle,CUBLAS_OP_T,batch_size,N,&ALPHA,d_batch,batch_size,d_y_b,1,&BETA,d_g,1);
// ahora 'g' toma el valor del gradiente

// Actualización de los coeficientes: b = b - lr * g
  stat=cublasDaxpy(handle,N,&lr,d_g,1,d_b,1);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tiempo de ejecución de la iteración: %f\n", time_spent);
}

printf("----- Coeficientes finales -----\n");
stat = cublasGetVector (N , sizeof (double ) , d_b ,1 ,b->arr ,1);
imprime_vector(b);

// Escribimos RMSE y RMSEval a un archivo externo para análisis posterior
FILE *f = fopen("RMSE_SGD.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}
  fprintf(f, "iteracion,rmse_t,rmse_v\n");
  for(int i=0; i<iter; i++){
    fprintf(f, "%d,%f,%f\n", i, entrada_vector(rmse,i),entrada_vector(rmse_v,i));
  }
fclose(f);

// Liberamos la memoria utilizada por nuestras estructuras
  cudaFree(d_X);
  cudaFree(d_X_v);
  cudaFree(d_b);
  cudaFree(d_y);
  cudaFree(d_y_v);
  cudaFree(d_g);
  cudaFree(d_batch);
  cudaFree(d_y_b);
  cublasDestroy ( handle );

  free(entradas(X));
	free(X);
	free(entradas_vector(b));
	free(b);
  free(entradas_vector(y));
  free(y);
  free(entradas_vector(g));
  free(g);
  free(entradas(X_v));
  free(X_v);
  free(entradas_vector(y_v));
  free(y_v);
  free(entradas(batch));
  free(batch);
  free(entradas_vector(y_b));
  free(y_b);
  free(entradas_vector(y_static));
  free(y_static);
  free(entradas_vector(y_v_static));
  free(y_v_static);

  return 0 ;

}
