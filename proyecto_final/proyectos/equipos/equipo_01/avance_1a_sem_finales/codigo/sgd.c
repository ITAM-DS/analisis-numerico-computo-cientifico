/*
Descenso en Gradiente Estocástico Secuencial
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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
extern double dnrm2_(int *n, double *x, int *incx);
extern double dscal_(int *n, double *a, double *x, int *incx);

double sgd(int M, int N, int M_v, int batch_size, int iter, double lr, FILE *f, double tolerancia_gradiente) {

  // Definición de estructuras que almacenarán los datos
  arreglo_2d_T X, X_v, batch;
	arreglo_1d_T y, y_v, b, g, y_b, rmse, rmse_v, y_static, y_v_static, tiempo;

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
  tiempo=malloc(sizeof(*tiempo));

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
  renglones_vector(tiempo)=iter;

	renglones_vector(y_static)=M;
  renglones_vector(y_v_static)=M_v;

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
  entradas_vector(tiempo)=malloc(iter*sizeof(double));

  entradas_vector(y_static)=malloc(M*sizeof(double));
  entradas_vector(y_v_static)=malloc(M_v*sizeof(double));
  inicializa_vector(y_static,y_vector);
  inicializa_vector(y_v_static,y_v_vector);

  srand(1882);
  double acum = 0;
  int it = 1;
  double grad_norm = 1e9;

// Se inicia el ciclo de las iteraciones de descenso
clock_t begin = clock();
while(it <= iter && grad_norm > tolerancia_gradiente){ 
   
// Se reestablece el valor para y al principio de cada iteración
  memcpy(y->arr,y_static->arr,M*sizeof(double));
  memcpy(y_v->arr,y_v_static->arr,M_v*sizeof(double));
  
  if(batch_size != M){
    // Se inicializa la matriz de covariables y vector de variable respuesta del batch en cada iteración
    inicializa_batch(batch, X, y_b, y);
  }else{
    memcpy(y_b->arr,y->arr,M*sizeof(double));
    memcpy(batch->arr,X->arr,M*N*sizeof(double));
  }
// Cálculo del error de predicción: e = - X %*% b + y
// Por las características de la función dgemv, el vector y se sobreescribe con el valor de 'e'
  ALPHA = -1.0;
  BETA = 1.0;
	dgemv_("No transpose", &batch_size, &N, &ALPHA, entradas(batch), &batch_size, entradas_vector(b), &incx, &BETA, entradas_vector(y_b),&incx);
  dgemv_("No transpose", &M, &N, &ALPHA, entradas(X), &M, entradas_vector(b), &incx, &BETA, entradas_vector(y),&incx);
  dgemv_("No transpose", &M_v, &N, &ALPHA, entradas(X_v), &M_v, entradas_vector(b), &incx, &BETA, entradas_vector(y_v),&incx);
// Se calcula la suma de cuadrados de los residuales para los datos de entrenamiento y de prueba
  acum = 0;
  for(int i = 0; i < M; i++){
    acum += pow(entradas_vector(y)[i],2);
  }
  double acum_v = 0;
  for(int i = 0; i < M_v; i++){
    acum_v += pow(entradas_vector(y_v)[i],2);
  }
  entrada_vector(rmse,it) = acum/M;
  entrada_vector(rmse_v,it) = acum_v/M_v;
  printf("Iteración %d/%d RSS train: %lf -- RSS val: %lf \n", it, iter, acum/M, acum_v/M_v);
    

// Cálculo del gradiente: g = -X^t %*% e
  ALPHA = -1.0;
  BETA = 0.0;
  dgemv_("Transpose", &batch_size, &N, &ALPHA, entradas(batch), &batch_size, entradas_vector(y_b), &incx, &BETA, entradas_vector(g),&incx);
  double inv_batch = 1.0/batch_size;
  dscal_(&N, &inv_batch, entradas_vector(g), &incx);
// ahora 'g' toma el valor del gradiente
  double grad_norm = dnrm2_(&N,entradas_vector(g),&incx);
  printf("Norma del gradiente: %f\n", grad_norm);
// Actualización de los coeficientes: b = b - lr * g
  daxpy_(&N, &lr,entradas_vector(g), &incx, entradas_vector(b), &incx);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  entrada_vector(tiempo, it) = time_spent;
  printf("Tiempo de ejecución de la iteración: %f\n", time_spent);
  printf("------------\n");
  it++;
  lr *= 0.999;
  fprintf(f, "%d,%d, %lf, %lf, %e, %f, %f \n", it, iter, acum/M, acum_v/M_v, lr, time_spent, grad_norm);
}
//printf("----- Fin con learning rate de %lf -----\n", lr);

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
  free(entradas_vector(rmse));
  free(rmse);
  free(entradas_vector(rmse_v));
  free(rmse_v);
  free(entradas_vector(tiempo));
  free(tiempo);
  free(entradas_vector(y_static));
  free(y_static);
  free(entradas_vector(y_v_static));
  free(y_v_static);

	return acum/M;

}


int main(int argc, char const *argv[]) {
    // Guardar csv
    FILE *f = fopen("error_sgd_sec.csv", "w");
    FILE *f2 = fopen("error_sgd_sec_summary.csv", "w");

    //Dimensiones de los datos de las covariables
    int M=atoi(argv[1]);
    int N=atoi(argv[2]);
    int M_v=atoi(argv[3]);
    // Lectura del parámetro para el tamaño del batch
    int batch_size=atoi(argv[4]);
    // Lectura de stdin del número de interaciones
    int iter=atoi(argv[5]);
    double tolerancia_gradiente = 1e-12;

    // Comentar dos líneas siguientes para hacer grid search
    //double lrs[10] = {-0.0000000001, -0.000000001, -0.00000001, -0.0000001, -0.000001, -0.00001, -0.0001, -0.001, -0.01, -0.1};
    //double loss[10] = {0};
    // Asignar tasa de aprendizaje deseada a continuación.
    double lrs[1] = {-0.1};
    double loss[10] = {0};
    
    
    fprintf(f2, "learning_rate, loss\n");
    fprintf(f, "iteracion, tot_iter, rss_train, rss_val, lr, tiempo, grad_norm\n");
    for(int i = 0; i<sizeof(lrs)/sizeof(lrs[0]); i++){
        loss[i] = sgd(M, N, M_v, batch_size, iter, lrs[i],f, tolerancia_gradiente);
    }

    for(int i = 0; i<sizeof(lrs)/sizeof(lrs[0]); i++){
        fprintf(f2, "%lf, %lf \n", lrs[i], loss[i]);
    }
  fclose(f);
fclose(f2);
    return 0;
}
