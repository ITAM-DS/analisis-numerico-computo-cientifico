/*
Descenso en Gradiente Estocástico, ADAM, AMSGrad
Es posible cambiar entre estos algorítmos a través de la llamada al programa con el parámetro de optimizador
- SGD - optimizador 1
- ADAM - optimizador 2
- AMSGrad - optimizador 3

El programa se compila con la siguiente instrucción:

  nvcc SGD_cuda.c funciones.c -o programa.out -lcublas

El programa se ejecuta con la siguiente instruccion:

./programa.out <renglones_entrenamiento> <columnas_entrenamiento> <renglones_validación> <tamaño_del_batch> <iteraciones> <optimizador> <beta1> <beta2> <epsilon>

Si se elige el optimizador 1 (SGD) los parámetros de beta1, beta2 y epsilon se ignoran, pero si se requieren para su ejecución


*/
#define MAX(X, Y) (((X) >= (Y)) ? (X) : (Y))
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

// Función que ejecutará el descenso
double sgd(int M, int N, int M_v, int batch_size, int iter, double lr, double tolerancia_gradiente,FILE *f, int optimizador, double beta_adam_1, double beta_adam_2, double epsilon) {
  // Declaración de los elementos necesarios para utilizar CUDA
  cudaError_t cudastat ;
  // cudaMalloc status
  cublasStatus_t stat ;
  // CUBLAS functions status
  cublasHandle_t handle ;
  // Definición de estructuras que almacenarán los datos
  arreglo_2d_T X, X_v, batch;
  arreglo_1d_T y, y_v, b, g, y_b, mt, vt, tmp1, tmp2, y_static, y_v_static, rmse, rmse_v, vt_hat, tiempo;
  // Definición de los elementos donde almacenaremos los elementos en la GPU
  double *d_batch, *d_X, *d_X_v, *d_y, *d_y_v, *d_b, *d_g, *d_y_b, *d_mt, *d_vt, *d_tmp1, *d_tmp2;

	int incx=1;
  double ALPHA, BETA;

  double beta_inv_1 = 1-beta_adam_1;
  double beta_inv_2 = 1-beta_adam_2;

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
  mt=malloc(sizeof(*mt));
  vt=malloc(sizeof(*vt));
  tmp1=malloc(sizeof(*tmp1));
  tmp2=malloc(sizeof(*tmp2));
  vt_hat=malloc(sizeof(*vt_hat));
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
  renglones_vector(mt)=N;
  renglones_vector(vt)=N;
  renglones_vector(tmp1)=N;
  renglones_vector(tmp2)=N;
  renglones_vector(vt_hat)=N;
  renglones_vector(tiempo)=iter;
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

  entradas_vector(mt)=malloc(N*sizeof(double));
  inicializa_ceros(mt,N);

  cudastat = cudaMalloc (( void **)&d_mt , N * sizeof (*d_mt )); // device
  stat = cublasSetVector (N , sizeof (double ) ,mt->arr ,1 , d_mt ,1); 

  entradas_vector(vt)=malloc(N*sizeof(double));
  inicializa_ceros(vt,N);

  cudastat = cudaMalloc (( void **)&d_vt , N * sizeof (*d_vt )); // device
  stat = cublasSetVector (N , sizeof (double ) ,vt->arr ,1 , d_vt ,1);
  
  entradas_vector(tmp1)=malloc(N*sizeof(double));
  inicializa_ceros(tmp1,N);

  cudastat = cudaMalloc (( void **)&d_tmp1 , N * sizeof (*d_tmp1 )); // device
  stat = cublasSetVector (N , sizeof (double ) ,tmp1->arr ,1 , d_tmp1 ,1);

  entradas_vector(tmp2)=malloc(N*sizeof(double));
  inicializa_ceros(tmp2,N);

  cudastat = cudaMalloc (( void **)&d_tmp2 , N * sizeof (*d_tmp2 )); // device
  stat = cublasSetVector (N , sizeof (double ) ,tmp2->arr ,1 , d_tmp2 ,1);

  entradas_vector(y_static)=malloc(M*sizeof(double));
  entradas_vector(y_v_static)=malloc(M_v*sizeof(double));
  inicializa_vector(y_static,y_vector);
  inicializa_vector(y_v_static,y_v_vector);

  entradas_vector(vt_hat)=malloc(N*sizeof(double));
  inicializa_ceros(vt_hat,N);

  entradas_vector(tiempo)=malloc(iter*sizeof(double));
  
  // Declaramos seed para tener repetibilidad
  srand(1882);
  double acum = 0;
  int it = 1;
  double grad_norm = 1e9;
  double neg_lr = -1.0*lr;

  clock_t begin = clock();

  // Verificamos si el tamaño del batch es igual al número de datos de entrenamiento, para evitar hacer procesos innecesarios con los datos
  if(batch_size == M){
  stat = cublasSetMatrix (batch_size ,N , sizeof (double ) ,X->arr ,batch_size , d_batch , batch_size ); // cp a - > d_a
  stat = cublasSetVector (batch_size , sizeof (double ) ,y->arr ,1 , d_y_b ,1); // cp x - > d_x
  }
// Se inicia el ciclo de las iteraciones de descenso
// Condiciones de paro: que se cumpla el número de iteraciones, que la norma del gradiente sea mayor a un límite definido que el error cuadrático medio sea menor a 10000
while(it <= iter && grad_norm > tolerancia_gradiente && acum/M <10000){ 

// Se reestablece el valor para y al principio de cada iteración
  stat = cublasSetVector (M , sizeof (double ) ,y_static->arr ,1 , d_y ,1); // cp x - > d_x
  stat = cublasSetVector (M_v , sizeof (double ) ,y_v_static->arr ,1 , d_y_v ,1); // cp x - > d_x
  if(batch_size == M){
  stat = cublasSetVector (M , sizeof (double ) ,y_static->arr ,1 , d_y_b ,1); // cp x - > d_x
  }
  
  inicializa_ceros(tmp1,N);
  inicializa_ceros(tmp2,N);

  stat = cublasSetVector (N , sizeof (double ) ,tmp1->arr ,1 , d_tmp1 ,1);
  stat = cublasSetVector (N , sizeof (double ) ,tmp2->arr ,1 , d_tmp2 ,1);

  // Se inicializa la matriz de covariables y vector de variable respuesta del batch en cada iteración (únicamente si el tamaño de batch es menor a registros en M)
if(batch_size != M){
    inicializa_batch(batch, X, y_b, y);
    stat = cublasSetMatrix (batch_size ,N , sizeof (double ) ,batch->arr ,batch_size , d_batch , batch_size ); // cp a - > d_a
    stat = cublasSetVector (batch_size , sizeof (double ) ,y_b->arr ,1 , d_y_b ,1); // cp x - > d_x
}
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
  stat=cublasDgemv(handle,CUBLAS_OP_T,batch_size,N,&ALPHA,d_batch,batch_size,d_y_b,1,&BETA,d_g,1);
  double inv_batch = 1.0/batch_size;
  stat=cublasDscal(handle, N, &inv_batch, d_g, 1);
  // ahora 'g' toma el valor del gradiente
  //Calculamos la norma del gradiente:
  stat=cublasDnrm2(handle,N,d_g,1,&grad_norm);
  printf("Norma del gradiente: %f\n", grad_norm);

  // Si el optimizador es SGD
  if(optimizador == 1){
    //Actualización de los coeficientes: b = b - lr * g
    neg_lr = -1.0*lr;
    stat=cublasDaxpy(handle,N,&neg_lr,d_g,1,d_b,1);
    // Si el optimizador es ADAM o AMSGrad
   }else if(optimizador == 2 | optimizador == 3){
    // Calculo de la mt = B1*mt-1 + (1-B1)*gt
            // Se calcula primera sección B1*mt-1
        stat = cublasDaxpy(handle, N, &beta_adam_1, d_mt, 1, d_tmp1, 1);
            // Se calcula segunda sección (1-Bt)*gt
        stat = cublasDaxpy(handle, N, &beta_inv_1, d_g, 1, d_tmp1, 1); 
        // mt esta en tmp 1
        stat = cublasDcopy(handle, N, d_tmp1, 1, d_mt, 1);
        // Calculo de la vt = B2*vt-1 + (1-B2)*gt^2
            // Primera sección (B2*vt-1) 
        stat = cublasDaxpy(handle, N, &beta_adam_2,d_vt, 1, d_tmp2, 1);
            // En el vector auxiliar guardamos los valores de gt^2
        //squareElements<<<(N+255)/256, 256>>>(d_g, d_tmp1, N);
        stat = cublasGetVector (N , sizeof (double ) , d_g ,1 ,g->arr ,1);
        for(int i =0; i<N; i++){
            entrada_vector(tmp1,i) = entrada_vector(g,i)*entrada_vector(g,i);
        }
        stat = cublasSetVector (N , sizeof (double ) ,tmp1->arr ,1 , d_tmp1 ,1);
        // Calculamos la segunda sección
        stat = cublasDaxpy(handle, N, &beta_inv_2,d_tmp1, 1, d_tmp2, 1);
        // Asignamos los valores del vector auxiliar al de vt para utilizarlo después
        //entradas_vector(vt) = entradas_vector(tmp2);
        stat = cublasDcopy(handle, N, d_tmp2, 1, d_vt, 1);
        // Actualizamos coeficientes con bt+1 = bt - lr*mt/(sqrt(vt_hat)+epsilon)
        // En esta, se toman en cuenta los ajustes para vt_hat = vt/(1-B1^t) y mt_hat = mt/(1-B2^t)
        stat = cublasGetVector (N , sizeof (double ) , d_mt ,1 ,mt->arr ,1);
        stat = cublasGetVector (N , sizeof (double ) , d_vt ,1 ,vt->arr ,1);
          // Si el optimizador es AMSgrad
         if(optimizador ==2){
          for(int i =0; i< N; i++){
            double mt_gorro = entrada_vector(mt,i)/(1.0-pow(beta_adam_1,it));
            double vt_gorro = entrada_vector(vt,i)/(1.0-pow(beta_adam_2,it));
            entrada_vector(b,i) = entrada_vector(b,i) - lr*mt_gorro/(sqrt(vt_gorro)+epsilon);
           }  
        }
        else{
          for(int i=0; i<N; i++){
            entrada_vector(vt_hat,i) = MAX(entrada_vector(vt,i), entrada_vector(vt_hat,i));
          }
          for(int i =0; i< N; i++){
            entrada_vector(b,i) = entrada_vector(b,i) - lr*entrada_vector(mt,i)/(sqrt(entrada_vector(vt_hat,i))+epsilon);
          }
        }
        stat = cublasSetVector (N , sizeof (double ) ,b->arr ,1 , d_b ,1);
      }


  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  entrada_vector(tiempo, it) = time_spent;
  printf("Tiempo de ejecución de la iteración: %f\n", time_spent);
  printf("------------\n");
  fprintf(f, "%d,%d, %f, %f, %f ,%f, %f\n", it, iter, acum/M, acum_v/M_v,grad_norm, lr, time_spent);
  it++;
  // Agregamos un componente de 'decay' a las iteraciones
  lr = lr * 0.999;
  
}
printf("----- Fin con learning rate de %lf -----\n", lr);

// Liberamos la memoria utilizada por nuestras estructuras
  cudaFree(d_X);
  cudaFree(d_X_v);
  cudaFree(d_b);
  cudaFree(d_y);
  cudaFree(d_y_v);
  cudaFree(d_g);
  cudaFree(d_batch);
  cudaFree(d_y_b);
  cudaFree(d_mt);
  cudaFree(d_vt);
  cudaFree(d_tmp1); 
  cudaFree(d_tmp2);
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
  free(entradas_vector(tmp1));
  free(tmp1);
  free(entradas_vector(tmp2));
  free(tmp2);
  free(entradas_vector(mt));
  free(mt);
  free(entradas_vector(vt));
  free(vt);
  free(entradas_vector(vt_hat));
  free(vt_hat);
  free(entradas_vector(tiempo));
  free(tiempo);
  free(entradas_vector(rmse));
  free(rmse);
  free(entradas_vector(rmse_v));
  free(rmse_v);

  free(entradas_vector(y_static));
  free(y_static);
  free(entradas_vector(y_v_static));
  free(y_v_static);
  
	return acum/M;

}


int main(int argc, char const *argv[]) {

  //Dimensiones de los datos de las covariables
  int M=atoi(argv[1]);
  int N=atoi(argv[2]);
  int M_v=atoi(argv[3]);
  // Lectura del parámetro para el tamaño del batch
  int batch_size=atoi(argv[4]);
  // Lectura de stdin del número máximo de interaciones
  int iter=atoi(argv[5]);
  

    // Valores sugeridos para un grid, si se prefiere ejecutar así es necesario descomentar estas líneas y comentar las siguientes
  //double lrs[10] = {0.000000001, 0.00000001, 0.0000001, 0.000001, 0.00001, 0.0001, 0.001, 0.01, 0.1, 1.0};
  //double loss[10] = {0};
   // Para asingar un valor específico a la tasa de aprendizaje
  double lrs[1] = {0.003};
  double loss[1] = {0};

  double tolerancia_gradiente = 1e-12;
  int optimizador=atoi(argv[6]);
  double beta_adam_1=atof(argv[7]);
  double beta_adam_2=atof(argv[8]);
  double epsilon=atof(argv[9]);
  // Guardar csv
  FILE *f = fopen("error_sgd_sec.csv", "w");
  FILE *f2 = fopen("error_sgd_sec_summary.csv", "w");
    
  fprintf(f2, "learning_rate, loss\n");
  fprintf(f, "iteracion, tot_iter, rss_train, rss_val, grad_norm, lr, tiempo\n");
  for(int i = 0; i<sizeof(lrs)/sizeof(lrs[0]); i++){
    loss[i] = sgd(M, N, M_v, batch_size, iter, lrs[i],tolerancia_gradiente,f, optimizador, beta_adam_1, beta_adam_2, epsilon);
  }

  for(int i = 0; i<sizeof(lrs)/sizeof(lrs[0]); i++){
    fprintf(f2, "%lf, %lf \n", lrs[i], loss[i]);
  }
  fclose(f);
  fclose(f2);
  return 0;
}