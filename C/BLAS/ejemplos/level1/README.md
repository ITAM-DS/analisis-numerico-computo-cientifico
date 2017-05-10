Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.h` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev`.

Información sobre operaciones [level1](http://www.netlib.org/blas/#_level_1).

# Dot product:

Código que realiza el producto punto entre los vectores almacenados en los archivos:

`v1.txt`:

```
1
0
-3
```

`v2.txt`:

```
5
8
9
```

Se deben tener los archivos `v1.txt` y `v2.txt`en el directorio de compilación y ejecución.

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define v1_vector "v1.txt" //de tamaño Nx1
#define v2_vector "v2.txt" //de tamaño Nx1
extern double ddot_(int *n, double *x, int *incx, double *y, int *incy);
int main(int argc, char *argv[]){
	arreglo_1d_T v1, v2;
	double resultado;
	int N=atoi(argv[1]);

	v1=malloc(sizeof(v1));
	v2=malloc(sizeof(v2));

	renglones_vector(v1)=N;
	renglones_vector(v2)=N;

	entradas_vector(v1)=malloc(N*sizeof(double));
	inicializa_vector(v1,v1_vector);
	entradas_vector(v2)=malloc(N*sizeof(double));
	inicializa_vector(v2,v2_vector);


	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v1);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v2);
	printf("------------\n");

	int incx=1;

	resultado=ddot_(&N, entradas_vector(v1), &incx, entradas_vector(v2), &incx);
	printf("resultado: %lf\n", resultado);
	free(v1);
	free(v2);
	return 0;
}

```

Compilamos:

```
$gcc -Wall dot_product.c funciones.c -o programa.out -lblas
```

Ejecutamos:

```
$./programa.out 3
```
