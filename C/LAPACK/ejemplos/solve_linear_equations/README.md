Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.c` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev` y `liblapack-dev`.

Información sobre resolver sistemas de ecuaciones lineales con LAPACK: [driver routines](http://www.netlib.org/lapack/lug/node25.html) y [computational routines](http://www.netlib.org/lapack/lug/node37.html).

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

`solve_linear_equations.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño NxN
#define v_vector "v.txt" //de tamaño Nx1
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
	free(entradas(A));
	free(A);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector_entero(pivotes));
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
./programa.out 4 1
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

## Sistema tridiagonal:

Código que resuelve un sistema de ecuaciones lineales con una matriz tridiagonal y un vector almacenados en los archivos:

`b.txt`:

```
1
2
3
2
1
```


`d.txt`:

```
2
2
3
3
1
```

`dl.txt`:

```
-1
-2
-1
-1

```

`du.txt`:

```
-1
-1
-1
-2
```


Se deben tener los archivos b.txt, d.txt, dl.txt, du.txt en el directorio de compilación y ejecución. dl.txt, du.txt y d.txt contienen la diagonal inferior, superior y la diagonal de la matriz del sistema respectivamente.


`tridiagonal_linear_equations.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define b_vector "b.txt" //de tamaño Nx1
#define dl_vector "dl.txt" //de tamaño Nx1
#define d_vector "d.txt" //de tamaño Nx1
#define du_vector "du.txt" //de tamaño Nx1

extern void dgtsv_(int *n, int *nrhs, double *dl, double *d, double *du, double *b, int *ldb, int *info);
int main(int argc, char *argv[]){
	arreglo_1d_T dl,d,du, b;
	int info;
	int N=atoi(argv[1]);
	int NRHS = atoi(argv[2]);

	b=malloc(sizeof(*b));
	dl=malloc(sizeof(*dl));
	d=malloc(sizeof(*d));
	du=malloc(sizeof(*du));

	renglones_vector(b)=N;
	renglones_vector(dl)=N-1;
	renglones_vector(d)=N;
	renglones_vector(du)=N-1;

	entradas_vector(b)=malloc(renglones_vector(b)*sizeof(double));
	inicializa_vector(b,b_vector);

	entradas_vector(dl)=malloc(renglones_vector(dl)*sizeof(double));
	inicializa_vector(dl,dl_vector);

	entradas_vector(d)=malloc(renglones_vector(d)*sizeof(double));
	inicializa_vector(d,d_vector);	

	entradas_vector(du)=malloc(renglones_vector(du)*sizeof(double));
	inicializa_vector(du,du_vector);	

	printf("------------\n");
	printf("vector b :\n");
	imprime_vector(b);
	printf("------------\n");
	printf("vector dl :\n");
	imprime_vector(dl);
	printf("------------\n");
		printf("vector d :\n");
	imprime_vector(d);
	printf("------------\n");
		printf("vector du :\n");
	imprime_vector(du);
	printf("------------\n");

	printf("vector resultado:\n");
	dgtsv_(&N,&NRHS, entradas_vector(dl), entradas_vector(d), entradas_vector(du), entradas_vector(b), &N, &info);

	imprime_vector(b);
	printf("----------------\n");

	free(entradas_vector(b));
	free(b);
	free(entradas_vector(dl));
	free(dl);
	free(entradas_vector(d));
	free(d);
	free(entradas_vector(du));
	free(du);
	return 0;
}

```

Compilamos:

```
$gcc -Wall tridiagonal_linear_equations.c funciones.c -o programa.out -llapack
```

Ejecutamos:

```
$./programa.out 5 1
```

Resultado:

```
------------
vector b :
vector[0]=1.00000
vector[1]=2.00000
vector[2]=3.00000
vector[3]=2.00000
vector[4]=1.00000
------------
vector dl :
vector[0]=-1.00000
vector[1]=-2.00000
vector[2]=-1.00000
vector[3]=-1.00000
------------
vector d :
vector[0]=2.00000
vector[1]=2.00000
vector[2]=3.00000
vector[3]=3.00000
vector[4]=1.00000
------------
vector du :
vector[0]=-1.00000
vector[1]=-1.00000
vector[2]=-1.00000
vector[3]=-2.00000
------------
vector resultado:
vector[0]=6.50000
vector[1]=12.00000
vector[2]=15.50000
vector[3]=19.50000
vector[4]=20.50000
----------------
```


