/*
Descenso en Gradiente Estocástico Secuencial
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"definiciones.h"
// Lectura de las tablas de datos
#define X_matriz "X_ent.txt" //de tamaño MxN
#define X_v_matriz "X_valida.txt" //de tamaño MxN
#define b_vector "b_bh.txt" //de tamaño Nx1
#define y_vector "y_train.txt" //de tamaño Mx1
#define y_v_vector "y_val.txt" //de tamaño Mx1

// Prototipos para las funciones de FORTRAN que se utilizaron para la multiplicación de matrices
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void daxpy_(int *n, double *a, double *x, int *incx, double *y, int *incy);

int main(int argc, char const *argv[]) {

  // Definición de estructuras que almacenarán los datos
  arreglo_2d_T X, X_v, batch;
	arreglo_1d_T y, y_v, b, g, y_b, rmse, rmse_v;

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

// Asignar la memoria requerida para cada uno
	entradas(X)=malloc(renglones(X)*columnas(X)*sizeof(double));
	inicializa_matriz(X,X_matriz);

  entradas(X_v)=malloc(renglones(X_v)*columnas(X_v)*sizeof(double));
  inicializa_matriz(X_v,X_v_matriz);

	entradas_vector(b)=malloc(N*sizeof(double));
	inicializa_vector(b,b_vector);

  entradas_vector(y)=malloc(M*sizeof(double));
  inicializa_vector(y,y_vector);

  entradas_vector(y_v)=malloc(M_v*sizeof(double));
  inicializa_vector(y_v,y_v_vector);

	entradas_vector(g)=malloc(N*sizeof(double));

  entradas(batch)=malloc(renglones(batch)*columnas(batch)*sizeof(double));
  //inicializa_batch(batch, X, y_b, y);

  entradas_vector(y_b)=malloc(batch_size*sizeof(double));

  entradas_vector(rmse)=malloc(iter*sizeof(double));
  entradas_vector(rmse_v)=malloc(iter*sizeof(double));

//srand(1882);
// Se inicia el ciclo de las iteraciones de descenso
for(int it = 0; it < iter; it++){ 
// Se reestablece el valor para y al principio de cada iteración
  inicializa_vector(y,y_vector);
  inicializa_vector(y_v,y_v_vector);
  
  // Se inicializa la matriz de covariables y vector de variable respuesta del batch en cada iteración
  inicializa_batch(batch, X, y_b, y);

// Cálculo del error de predicción: e = - X %*% b + y
// Por las características de la función dgemv, el vector y se sobreescribe con el valor de 'e'
  ALPHA = -1.0;
  BETA = 1.0;
	dgemv_("No transpose", &batch_size, &N, &ALPHA, entradas(batch), &batch_size, entradas_vector(b), &incx, &BETA, entradas_vector(y_b),&incx);
  dgemv_("No transpose", &M, &N, &ALPHA, entradas(X), &M, entradas_vector(b), &incx, &BETA, entradas_vector(y),&incx);
  dgemv_("No transpose", &M_v, &N, &ALPHA, entradas(X_v), &M_v, entradas_vector(b), &incx, &BETA, entradas_vector(y_v),&incx);

// Se calcula la suma de cuadrados de los residuales para los datos de entrenamiento y de prueba
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
  printf("Iteración %d/%d RSS train: %lf -- RSS val: %lf \n", it+1, iter, acum, acum_v);
  printf("------------\n");
// Cálculo del gradiente: g = -X^t %*% e
  ALPHA = -1.0;
  BETA = 0.0;
  dgemv_("Transpose", &batch_size, &N, &ALPHA, entradas(batch), &batch_size, entradas_vector(y_b), &incx, &BETA, entradas_vector(g),&incx);
// ahora 'g' toma el valor del gradiente

// Actualización de los coeficientes: b = b - lr * g
  daxpy_(&N, &lr,entradas_vector(g), &incx, entradas_vector(b), &incx);
}

printf("----- Coeficientes finales -----\n");
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

	return 0;

}
