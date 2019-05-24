Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.c` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu el toolkit de cuda (ver [aquí](/C/extensiones_a_C/CUDA/instalacion/
) para su instalación).

Información sobre operaciones [level2](http://www.netlib.org/blas/#_level_2).

Lo siguiente se basa en el trabajo con el [equipo 1 del 2018](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01).

# Multiplicación matriz-vector:

Código que realiza la multiplicación matriz-vector con una matriz y un vector almacenados en los archivos:

`v.txt`:

```
1
0
-2
-1
1
```

`A.txt`:

```
0 1.5 4.3 2.1 9.4
4 -5 0 1 0
-1 2.5 -1 1 1
0 1.5 4.3 2.1 9.4
4 -5 0 1 0
-1 2.5 -1 1 0
0 1.5 4.3 2.1 9.4
0 -5 0 1 0
```

Se deben tener los archivos `v.txt` y `A.txt` en el directorio de compilación y ejecución.

`dgemv_mult_mat_vec_cublas.c`:


```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#include<time.h>
// Importamos las librerías para trabajar con CUDA y cuBLAS
#include<cuda_runtime.h>
#include"cublas_v2.h"
// Lectura de las tablas de datos
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Nx1

int main(int argc, char *argv[]){
	cudaError_t cudastat;//cudaMalloc status
	cublasStatus_t stat;//CUBLAS functions status
	cublasHandle_t handle;// CUBLAS context
	arreglo_2d_T A;
	arreglo_1d_T v, v_resultado;
	double *d_A, *d_v, *d_v_resultado;
	double time_spent;
	int incx=1;
	double ALPHA, BETA;
	ALPHA = 1.0;
	BETA = 0.0;

	//dimensiones
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);

	A=malloc(sizeof(*A));
	v=malloc(sizeof(*v));
	v_resultado=malloc(sizeof(*v_resultado));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(v_resultado) = M;


	// Definimos entorno de CUDA para ejecución
	stat = cublasCreate(& handle);

	//Alojamiento y lectura de datos:
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas_vector(v)=malloc(renglones_vector(v)*sizeof(double));
	inicializa_vector(v,v_vector);
	entradas_vector(v_resultado)=calloc(renglones_vector(v_resultado),sizeof(double));

	// Definimos espacio en GPU y copiamos los valores a través de las funciones 'set' de CUBLAS para cada uno

	cudastat = cudaMalloc((void **)&d_A , renglones(A) * columnas(A) * sizeof (*d_A));
	stat = cublasSetMatrix (renglones(A),columnas(A), sizeof(double),entradas(A),renglones(A),d_A,renglones(A));

	cudastat = cudaMalloc((void **)&d_v,renglones_vector(v) * sizeof(*d_v));
	stat = cublasSetVector(renglones_vector(v), sizeof(double),entradas_vector(v),1,d_v,1);
	
	cudastat = cudaMalloc((void **)&d_v_resultado,renglones_vector(v_resultado) * sizeof(*d_v_resultado));
	stat = cublasSetVector(renglones_vector(v_resultado), sizeof(double),entradas_vector(v_resultado),1,d_v_resultado,1);

	//CUBLAS_OP_N no transpose
	clock_t begin = clock();
	stat=cublasDgemv(handle,CUBLAS_OP_N,renglones(A),columnas(A),&ALPHA,d_A,renglones_vector(v_resultado),d_v,incx,&BETA,d_v_resultado,incx);
	clock_t end = clock();
	//Copiamos el valor de los vectores y de la GPU  a la CPU
	stat = cublasGetVector(renglones_vector(v_resultado),sizeof(double), d_v_resultado,incx,entradas_vector(v_resultado),incx);

	//imprimir resultado:
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector resultado:\n");
	imprime_vector(v_resultado);

	//tiempo de cálculo:
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de cálculo en la gpu %.5f\n", time_spent);

	// Liberamos la memoria utilizada
	cudaFree(d_A);
	cudaFree(d_v);
	cudaFree(d_v_resultado);
	cublasDestroy(handle);

	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(v_resultado));
	free(v_resultado);

	return 0;
}

```


Compilamos:

```
$nvcc dgemv_mult_mat_vec_cublas.c funciones.c -o dgemv_mult_mat_vec_cublas.out -lcublas
```

Ejecutamos:


```
./dgemv_mult_mat_vec_cublas.out <numero de renglones de A> <número de entradas de v>
```



```
./dgemv_mult_mat_vec_cublas.out 8 5
```

Resultado:

```
matriz 1:
matriz[0][0]=0.00000	matriz[0][1]=1.50000	matriz[0][2]=4.30000	matriz[0][3]=2.10000	matriz[0][4]=9.40000
matriz[1][0]=4.00000	matriz[1][1]=-5.00000	matriz[1][2]=0.00000	matriz[1][3]=1.00000	matriz[1][4]=0.00000
matriz[2][0]=-1.00000	matriz[2][1]=2.50000	matriz[2][2]=-1.00000	matriz[2][3]=1.00000	matriz[2][4]=1.00000
matriz[3][0]=0.00000	matriz[3][1]=1.50000	matriz[3][2]=4.30000	matriz[3][3]=2.10000	matriz[3][4]=9.40000
matriz[4][0]=4.00000	matriz[4][1]=-5.00000	matriz[4][2]=0.00000	matriz[4][3]=1.00000	matriz[4][4]=0.00000
matriz[5][0]=-1.00000	matriz[5][1]=2.50000	matriz[5][2]=-1.00000	matriz[5][3]=1.00000	matriz[5][4]=0.00000
matriz[6][0]=0.00000	matriz[6][1]=1.50000	matriz[6][2]=4.30000	matriz[6][3]=2.10000	matriz[6][4]=9.40000
matriz[7][0]=0.00000	matriz[7][1]=-5.00000	matriz[7][2]=0.00000	matriz[7][3]=1.00000	matriz[7][4]=0.00000
------------
vector :
vector[0]=1.00000
vector[1]=0.00000
vector[2]=-2.00000
vector[3]=-1.00000
vector[4]=1.00000
------------
vector resultado:
vector[0]=-1.30000
vector[1]=3.00000
vector[2]=1.00000
vector[3]=-1.30000
vector[4]=3.00000
vector[5]=0.00000
vector[6]=-1.30000
vector[7]=-1.00000
Tiempo de cálculo en la gpu 0.00003
```



