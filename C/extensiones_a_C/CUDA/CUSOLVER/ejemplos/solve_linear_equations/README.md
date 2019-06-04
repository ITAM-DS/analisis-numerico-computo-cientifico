Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.c` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu el toolkit de cuda (ver [aquí](/C/extensiones_a_C/CUDA/instalacion/
) para su instalación).


## Sistema denso:

Código que resuelve un sistema de ecuaciones lineales con una matriz y un vector almacenados en los archivos:

`v.txt`:

```
0
-2
2
1
```


`A.txt`:

```
2 3 -2 1
1 3 2 -1
2 -2 0 1
-1 1 1 0
```

`solve_linear_equations_cusolver.c`:


```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#include<time.h>
// Importamos las librerías para trabajar con CUDA y cuBLAS
#include<cuda_runtime.h>
#include<cublas_v2.h>
// Importamos la librería para trabajar con CUSOLVER
#include <cusolverDn.h>
// Lectura de las tablas de datos
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Nx1

int main(int argc, char *argv[]){
	cudaError_t cudaStatus;//cudaMalloc status
	cusolverStatus_t  cusolverStatus;
	cusolverDnHandle_t  handle;
	arreglo_2d_T A;
	arreglo_1d_T v, v_resultado, pivotes;
	double *d_A, *d_v;
	int *d_pivot , *d_info , Lwork;   // pivots , info , worksp. size
	double *d_work; //workspace
	double time_spent;
	int info_gpu=0;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);

	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	v_resultado=malloc(sizeof(*v_resultado));
	pivotes=malloc(sizeof(*pivotes));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(v_resultado) = M;
	renglones_vector(pivotes)=N;

	// Definimos entorno de CUDA para ejecución
	cusolverStatus = cusolverDnCreate (& handle );

	//Alojamiento y lectura de datos:
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas_vector(v)=malloc(renglones_vector(v)*sizeof(double));
	inicializa_vector(v,v_vector);
	entradas_vector(v_resultado)=calloc(renglones_vector(v_resultado),sizeof(double));
	entradas_vector_entero(pivotes)=calloc(renglones_vector(pivotes),sizeof(int));

	// Definimos espacio en GPU y copiamos del host a la GPU

	cudaStatus = cudaMalloc((void **)&d_A , renglones(A) * columnas(A) * sizeof (*d_A));
	cudaStatus = cudaMemcpy(d_A , entradas(A), renglones(A)*columnas(A)*sizeof(double),cudaMemcpyHostToDevice);

	cudaStatus = cudaMalloc((void **)&d_v,renglones_vector(v) * sizeof(*d_v));
	cudaStatus = cudaMemcpy(d_v , entradas_vector(v), renglones_vector(v)*sizeof(double),cudaMemcpyHostToDevice);

	cudaStatus = cudaMalloc ((void **)& d_pivot , renglones_vector(pivotes)*sizeof(int));
	cudaStatus = cudaMalloc ((void **)& d_info , sizeof(int));

	//compute  buffer  size  and  prep.memory
	cusolverStatus = cusolverDnDgetrf_bufferSize(handle, renglones(A), columnas(A), d_A ,renglones(A), &Lwork);
	cudaStatus=cudaMalloc ((void **)& d_work ,Lwork*sizeof(double));

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");

	clock_t begin = clock();
	//LU  factorization  of d_A , with  partial  pivoting  and  row
	//interchanges; row i is  interchanged  with  row  d_pivot(i);

	cusolverStatus = cusolverDnDgetrf(handle,renglones(A),columnas(A),d_A,renglones(A),d_work,d_pivot, d_info);

	// use  the LU  factorization  to  solve  the  system  d_A*x=d_v;
	// the  solution  overwrites  d_v
	
	cusolverStatus = cusolverDnDgetrs(handle, CUBLAS_OP_N, renglones(A), 1,d_A, renglones_vector(pivotes), d_pivot, d_v, renglones_vector(v), d_info);

	cudaStatus = cudaDeviceSynchronize();

	clock_t end = clock();

	// d_info  -> info_gpu
	cudaStatus = cudaMemcpy (&info_gpu , d_info , sizeof(int),cudaMemcpyDeviceToHost );
	
	printf("después de getrf+getrs: info_gpu = %d\n", info_gpu );

	// copiar d_v -> v_resultado, d_A -> A, d_pivot -> pivotes
	cudaStatus = cudaMemcpy(entradas_vector(v_resultado), d_v , renglones_vector(v_resultado)*sizeof(double),cudaMemcpyDeviceToHost );

	cudaStatus = cudaMemcpy(entradas(A), d_A , renglones(A)*columnas(A)*sizeof(double),cudaMemcpyDeviceToHost);

	cudaStatus = cudaMemcpy(entradas_vector_entero(pivotes), d_pivot , renglones_vector(pivotes)*sizeof(int),cudaMemcpyDeviceToHost);

	//imprimir resultado:
	printf("----------------\n");
	printf("vector resultado:\n");
	imprime_vector(v_resultado);
	printf("----------------\n");
	printf("pivotes:\n");
	imprime_vector_entero(pivotes);
	printf("----------------\n");
	printf("matriz 1 con factores L,U:\n");
	imprime_matriz(A);

    printf("----------------\n");
	//tiempo de cálculo:
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de cálculo en la gpu %.5f\n", time_spent);

	// free memory
	cudaStatus = cudaFree(d_A);
	cudaStatus = cudaFree(d_v);
	cudaStatus = cudaFree(d_pivot );
	cudaStatus = cudaFree(d_info );
	cudaStatus = cudaFree(d_work );
	
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(v_resultado));
	free(v_resultado);
	free(entradas_vector_entero(pivotes));
	free(pivotes);

	cusolverStatus = cusolverDnDestroy(handle );
	cudaStatus = cudaDeviceReset ();

	return 0;
}

```

Compilamos:

```
$nvcc solve_linear_equations_cusolver.c funciones.c -o solve_linear_equations_cusolver.out -lcusolver -lcublas
```

Ejecutamos:

```
./solve_linear_equations_cusolver.out 4 4
```

Resultado:



```
matriz 1:
matriz[0][0]=2.00000	matriz[0][1]=3.00000	matriz[0][2]=-2.00000	matriz[0][3]=1.00000
matriz[1][0]=1.00000	matriz[1][1]=3.00000	matriz[1][2]=2.00000	matriz[1][3]=-1.00000
matriz[2][0]=2.00000	matriz[2][1]=-2.00000	matriz[2][2]=0.00000	matriz[2][3]=1.00000
matriz[3][0]=-1.00000	matriz[3][1]=1.00000	matriz[3][2]=1.00000	matriz[3][3]=0.00000
------------
vector :
vector[0]=0.00000
vector[1]=-2.00000
vector[2]=2.00000
vector[3]=1.00000
------------
después de getrf+getrs: info_gpu = 0
----------------
vector resultado:
vector[0]=-0.42424
vector[1]=-0.12121
vector[2]=0.69697
vector[3]=2.60606
----------------
pivotes:
vector[0]=1
vector[1]=3
vector[2]=3
vector[3]=4
----------------
matriz 1 con factores L,U:
matriz[0][0]=2.00000	matriz[0][1]=3.00000	matriz[0][2]=-2.00000	matriz[0][3]=1.00000
matriz[1][0]=1.00000	matriz[1][1]=-5.00000	matriz[1][2]=2.00000	matriz[1][3]=0.00000
matriz[2][0]=0.50000	matriz[2][1]=-0.30000	matriz[2][2]=3.60000	matriz[2][3]=-1.50000
matriz[3][0]=-0.50000	matriz[3][1]=-0.50000	matriz[3][2]=0.27778	matriz[3][3]=0.91667
----------------
Tiempo de cálculo en la gpu 0.00075

```
