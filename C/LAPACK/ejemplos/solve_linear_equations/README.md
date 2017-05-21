Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.h` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev` y `liblapack-dev`.

Información sobre resolver sistemas de ecuaciones lineales: [driver routines](http://www.netlib.org/lapack/lug/node25.html) y [computational routines](http://www.netlib.org/lapack/lug/node37.html).

## Sistema denso:

Código que resuelve un sistema de ecuaciones lineales con una matriz y un vector almacenados en los archivos:

`b.txt`:

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


```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño NxN
#define v_vector "b.txt" //de tamaño Nx1
extern void dgesv_(int *n, int *nrhs, double *a, int *lda, int *pivotes, double *b, int *ldb, int *info);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T v, pivotes;
	int info;
	int N=atoi(argv[1]);
	int NRHS = atoi(argv[2]);

	A=malloc(sizeof(A));
	v=malloc(sizeof(v));
	pivotes=malloc(sizeof(pivotes));

	renglones(A)=N;
	columnas(A)=N;
	renglones_vector(v)=N;
	renglones_vector(pivotes)=N;

	entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
	inicializa_matriz(A,A_matriz);

	entradas_vector(v)=malloc(N*sizeof(double));
	inicializa_vector(v,v_vector);
	entradas_vector_entero(pivotes)=malloc(N*sizeof(int));
	
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector resultado:\n");
	dgesv_(&N, &NRHS, entradas(A), &N, entradas_vector_entero(pivotes), entradas_vector(v), &N, &info);	
	imprime_vector(v);
	printf("----------------\n");
	printf("pivotes:\n");
	imprime_vector_entero(pivotes);
	printf("matriz 1 con factores L,U:\n");
	imprime_matriz(A);
	free(A);
	free(v);
	free(pivotes);
	return 0;
}


```

Compilamos:

```
$gcc -Wall solve_linear_equations.c funciones.c -o programa.out -lblas -llapack
```

Ejecutamos:

```
./programa.out 3 2
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
matriz 1 con factores L,U:
matriz[0][0]=2.00000	matriz[0][1]=3.00000	matriz[0][2]=-2.00000	matriz[0][3]=1.00000
matriz[1][0]=1.00000	matriz[1][1]=-5.00000	matriz[1][2]=2.00000	matriz[1][3]=0.00000
matriz[2][0]=0.50000	matriz[2][1]=-0.30000	matriz[2][2]=3.60000	matriz[2][3]=-1.50000
matriz[3][0]=-0.50000	matriz[3][1]=-0.50000	matriz[3][2]=0.27778	matriz[3][3]=0.91667

```
