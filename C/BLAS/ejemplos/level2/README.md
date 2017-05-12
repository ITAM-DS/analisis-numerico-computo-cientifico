Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.h` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev`.

Información sobre operaciones [level1](http://www.netlib.org/blas/#_level_2).

# Multiplicación matriz-vector:

Código que realiza la multiplicación matriz-vector con una matriz y un vector almacenados en el archivo:

`v.txt`:

```
1
0
```

`A.txt`:

```
0 1.5
4 -5
-1 2.5
```

Se deben tener los archivos `v.txt` y `A.txt` en el directorio de compilación y ejecución.

`dgemv_mult_mat_vec.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxN
#define v_vector "v.txt" //de tamaño Nx1
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, v_resultado;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 0.0;
	A=malloc(sizeof(A));
	v=malloc(sizeof(v));
	v_resultado=malloc(sizeof(v_resultado));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(v_resultado) = M;
	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);

	entradas_vector(v_resultado)=malloc(M*sizeof(double));

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector resultado:\n");
	int val=1;
	dgemv_("No transpose", &M, &N, &ALPHA, entradas(A), &M, entradas_vector(v), &val, &BETA, entradas_vector(v_resultado),&val);
	imprime_vector(v_resultado);
	free(A);
	free(v);
	free(v_resultado);
	return 0;
}

```

Compilamos:

```
$gcc -Wall dgemv_mult_mat_vec.c funciones.c -o programa.out -lblas
```

Ejecutamos:

```
./programa.out 3 2
```

Resultado:

```
matriz 1:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000
------------
vector :
vector[0]=1.0000000000000000
vector[1]=0.0000000000000000
------------
vector resultado:
vector[0]=0.0000000000000000
vector[1]=4.0000000000000000
vector[2]=-1.0000000000000000
```







