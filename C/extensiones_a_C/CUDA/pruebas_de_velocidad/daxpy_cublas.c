//nvcc --compiler-options -Wall daxpy_cublas.c funciones.c -o daxpy_cublas.out -lcublas
// ./daxpy_cublas.out <dimension de vectores>
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#include<time.h>
// Importamos las librerías para trabajar con CUDA y cuBLAS
#include<cuda_runtime.h>
#include"cublas_v2.h"


//se realiza v2 = alpha*v1 + v2

int main(int argc, char *argv[]){
	cudaError_t cudastat;//cudaMalloc status
	cublasStatus_t stat;//CUBLAS functions status
	cublasHandle_t handle;// CUBLAS context
	arreglo_1d_T v1, v2;
	double *d_v1, *d_v2;
	double incx=1;
	double alpha=3.5;
	double time_spent;
	int i;

	//dimensiones
	int N=atoi(argv[1]);

	v1=malloc(sizeof(*v1));
	v2=malloc(sizeof(*v2));

	renglones_vector(v1)=N;
	renglones_vector(v2)=N;

	// Definimos entorno de CUDA para ejecución
	stat = cublasCreate(& handle);

	//Alojamiento y lectura de datos:
	entradas_vector(v1)=calloc(renglones_vector(v1),sizeof(double));
	entradas_vector(v2)=calloc(renglones_vector(v2),sizeof(double));

	for(i=0;i<N;i++){
		entrada_vector(v1,i) = i;
		entrada_vector(v2,i) = i*i;
	}

	// Definimos espacio en GPU y copiamos los valores a través de las funciones 'set' de CUBLAS para cada uno


	cudastat = cudaMalloc((void **)&d_v1,renglones_vector(v1) * sizeof(*d_v1));
	stat = cublasSetVector(renglones_vector(v1), sizeof(double),entradas_vector(v1),1,d_v1,1);
	
	cudastat = cudaMalloc((void **)&d_v2,renglones_vector(v2) * sizeof(*d_v2));
	stat = cublasSetVector(renglones_vector(v2), sizeof(double),entradas_vector(v2),1,d_v2,1);

	clock_t begin = clock();
	stat=cublasDaxpy(handle,N, &alpha, d_v1, incx, d_v2, incx);
	clock_t end = clock();
	//Copiamos el valor de los vectores y de la GPU  a la CPU

	stat = cublasGetVector(renglones_vector(v2),sizeof(double), d_v2,incx,entradas_vector(v2),incx);

	//tiempo de cálculo:
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de cálculo en la gpu %.5f\n", time_spent);

	// Liberamos la memoria utilizada
	cudaFree(d_v1);
	cudaFree(d_v2);
	cublasDestroy(handle);

	free(entradas_vector(v1));
	free(v1);
	free(entradas_vector(v2));
	free(v2);

	return 0;
}
