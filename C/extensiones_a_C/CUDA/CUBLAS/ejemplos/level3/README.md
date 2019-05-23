Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.c` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu el toolkit de cuda (ver [aquí](/C/extensiones_a_C/CUDA/instalacion/
) para su instalación).


Información sobre operaciones [level3](http://www.netlib.org/blas/#_level_3).

Lo siguiente se basa en el trabajo con el [equipo 1 del 2018](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_01).

# Multiplicación matriz-matriz:

Código que realiza la multiplicación matriz-matriz con matrices almacenadas en los archivos:

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

`B.txt`:

```
0 1.5 4.3 2.1 9.4 0 1 -1
4 -5 0 1 0 2 -3 2
-1 2.5 -1 1 1 4 0 1
0 1.5 4.3 2.1 9.4 2 3.1 -1.1
1 2 -1 0 1.1 0 -1 3
``` 

Se deben tener los archivos `A.txt` y `B.txt` en el directorio de compilación y ejecución.

`dgemm_mult_mat_cublas.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#include <time.h>
// Importamos las librerías para trabajar con CUDA y cuBLAS
# include <cuda_runtime.h>
# include "cublas_v2.h"
// Lectura de las tablas de datos
#define A_matriz "A.txt" //de tamaño MxK
#define B_matriz "B.txt" //de tamaño KxN

int main(int argc, char *argv[]){
	cudaError_t cudastat;//cudaMalloc status
	cublasStatus_t stat;//CUBLAS functions status
	cublasHandle_t handle;// CUBLAS context
	arreglo_2d_T A, B, C;
	double ALPHA, BETA;

	double *d_A, *d_B, *d_C;
	double time_spent;

	int M=atoi(argv[1]);
	int K=atoi(argv[2]);
	int N=atoi(argv[4]);
	ALPHA = 1.0;
	BETA = 0.0;
	A=malloc(sizeof(*A));
	B=malloc(sizeof(*B));
	C=malloc(sizeof(*C));

	renglones(A)=M;
	columnas(A)=K;
	renglones(B)=K;
	columnas(B)=N;
	renglones(C) = M;
	columnas(C) = N;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);
	entradas(B)=malloc(renglones(B)*columnas(B)*sizeof(double));
	inicializa_matriz(B,B_matriz);
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(B);
	printf("------------\n");

	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));

	// Definimos entorno de CUDA para ejecución
	stat = cublasCreate(& handle);

	// Definimos espacio en GPU y copiamos los valores a través de las funciones 'set' de CUBLAS para cada uno

	cudastat = cudaMalloc((void **)&d_A , renglones(A) * columnas(A) * sizeof (*d_A));
	stat = cublasSetMatrix (renglones(A),columnas(A), sizeof(double),entradas(A),renglones(A),d_A,renglones(A));

	cudastat = cudaMalloc((void **)&d_B , renglones(B) * columnas(B) * sizeof (*d_B));
	stat = cublasSetMatrix (renglones(B),columnas(B), sizeof(double),entradas(B),renglones(B),d_B,renglones(B));

	cudastat = cudaMalloc((void **)&d_C , renglones(C) * columnas(C) * sizeof (*d_C));
	stat = cublasSetMatrix (renglones(C),columnas(C), sizeof(double),entradas(C),renglones(C),d_C,renglones(C));

	//CUBLAS_OP_N no transpose
	clock_t begin = clock();
	stat=cublasDgemm(handle,CUBLAS_OP_N,CUBLAS_OP_N,renglones(A),columnas(B),columnas(A),&ALPHA,d_A,renglones(A),d_B,columnas(A),&BETA,d_C,renglones(A));
	clock_t end = clock();

	//Copiamos el valor de los vectores y de la GPU  a la CPU
	stat = cublasGetMatrix(renglones(C),columnas(C),sizeof(double), d_C, renglones(C),entradas(C),renglones(C));

	//imprimir resultado:
	printf("matriz resultado:\n");
	imprime_matriz(C);
	
	//tiempo de cálculo:
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de cálculo en la gpu %.5f\n", time_spent);

	// Liberamos la memoria utilizada 
	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);
	cublasDestroy(handle);

	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);

	return 0;
}
```

Compilamos:

```
$nvcc dgemm_mult_mat_cublas.c funciones.c -o dgemm_mult_mat_cublas.out -lcublas
```

Ejecutamos:

```
./dgemm_mult_mat_cublas.out <renglones de A> <columnas de A> <renglones de B> <columnas de B> 

```

```
./dgemm_mult_mat_cublas.out 8 5 5 8
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
matriz 2:
matriz[0][0]=0.00000	matriz[0][1]=1.50000	matriz[0][2]=4.30000	matriz[0][3]=2.10000	matriz[0][4]=9.40000	matriz[0][5]=0.00000	matriz[0][6]=1.00000	matriz[0][7]=-1.00000
matriz[1][0]=4.00000	matriz[1][1]=-5.00000	matriz[1][2]=0.00000	matriz[1][3]=1.00000	matriz[1][4]=0.00000	matriz[1][5]=2.00000	matriz[1][6]=-3.00000	matriz[1][7]=2.00000
matriz[2][0]=-1.00000	matriz[2][1]=2.50000	matriz[2][2]=-1.00000	matriz[2][3]=1.00000	matriz[2][4]=1.00000	matriz[2][5]=4.00000	matriz[2][6]=0.00000	matriz[2][7]=1.00000
matriz[3][0]=0.00000	matriz[3][1]=1.50000	matriz[3][2]=4.30000	matriz[3][3]=2.10000	matriz[3][4]=9.40000	matriz[3][5]=2.00000	matriz[3][6]=3.10000	matriz[3][7]=-1.10000
matriz[4][0]=1.00000	matriz[4][1]=2.00000	matriz[4][2]=-1.00000	matriz[4][3]=0.00000	matriz[4][4]=1.10000	matriz[4][5]=0.00000	matriz[4][6]=-1.00000	matriz[4][7]=3.00000
------------
matriz resultado:
matriz[0][0]=11.10000	matriz[0][1]=25.20000	matriz[0][2]=-4.67000	matriz[0][3]=10.21000	matriz[0][4]=34.38000	matriz[0][5]=24.40000	matriz[0][6]=-7.39000	matriz[0][7]=33.19000
matriz[1][0]=-20.00000	matriz[1][1]=32.50000	matriz[1][2]=21.50000	matriz[1][3]=5.50000	matriz[1][4]=47.00000	matriz[1][5]=-8.00000	matriz[1][6]=22.10000	matriz[1][7]=-15.10000
matriz[2][0]=12.00000	matriz[2][1]=-13.00000	matriz[2][2]=0.00000	matriz[2][3]=1.50000	matriz[2][4]=0.10000	matriz[2][5]=3.00000	matriz[2][6]=-6.40000	matriz[2][7]=6.90000
matriz[3][0]=11.10000	matriz[3][1]=25.20000	matriz[3][2]=-4.67000	matriz[3][3]=10.21000	matriz[3][4]=34.38000	matriz[3][5]=24.40000	matriz[3][6]=-7.39000	matriz[3][7]=33.19000
matriz[4][0]=-20.00000	matriz[4][1]=32.50000	matriz[4][2]=21.50000	matriz[4][3]=5.50000	matriz[4][4]=47.00000	matriz[4][5]=-8.00000	matriz[4][6]=22.10000	matriz[4][7]=-15.10000
matriz[5][0]=11.00000	matriz[5][1]=-15.00000	matriz[5][2]=1.00000	matriz[5][3]=1.50000	matriz[5][4]=-1.00000	matriz[5][5]=3.00000	matriz[5][6]=-5.40000	matriz[5][7]=3.90000
matriz[6][0]=11.10000	matriz[6][1]=25.20000	matriz[6][2]=-4.67000	matriz[6][3]=10.21000	matriz[6][4]=34.38000	matriz[6][5]=24.40000	matriz[6][6]=-7.39000	matriz[6][7]=33.19000
matriz[7][0]=-20.00000	matriz[7][1]=26.50000	matriz[7][2]=4.30000	matriz[7][3]=-2.90000	matriz[7][4]=9.40000	matriz[7][5]=-8.00000	matriz[7][6]=18.10000	matriz[7][7]=-11.10000
Tiempo de cálculo en la gpu 0.00003
```

