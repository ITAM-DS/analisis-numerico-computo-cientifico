# Ejemplos con openmpi y BLAS

Para los siguientes ejemplos, se supone que se ha [levantado un cluster de forma pseudo distribuida con openMPI y docker](/C/extensiones_a_C/MPI/openMPI/
) o bien se siguió el [tutorial de uso de AWS con OpenMPI](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) ambos enfoques para un sistema ubuntu. De acuerdo a las arquitecturas anteriores compilar y ejectuar los siguientes programas ejemplo.

Es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos los archivos `definiciones.h` y `funciones.h` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev`.

Información sobre operaciones [level1](http://www.netlib.org/blas/#_level_1) de BLAS. 

## Scatter, Reduce y dot product:

Código que distribuye entradas de un vector entre los procesos lanzados por el usuario de manera que cada proceso realice un producto punto "local" y finalmente el proceso con rank 0 haga un reduce con `MPI_SUM` para calcular el producto punto entre dos vectores almacenados en los archivos:

`x.txt`:

```
1
0
-1
0
0
0
1
0
0
0
1
1
-1
```

`y.txt`:

```
2
8
-1
0
3
4
5
-2
3
-7
10
0
1
```

Se deben tener los archivos `x.txt` y `y.txt` en el directorio de compilación y ejecución.

`scatter_reduce_dot_product_example.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define x_vector "x.txt"
#define y_vector "y.txt"
extern double ddot_(int *n, double *x, int *incx, double *y, int *incy);
void inicializa_parametros_vector_mpi(arreglo_1d_T a, int dimension);
void free_vector_mpi(arreglo_1d_T a);
int main(int argc, char *argv[]){
	arreglo_1d_T x_local, y_local;
	double resultado_dot_product=0, local_dot_product=0;
	int n=atoi(argv[1]);
	int incx=1;//para la rutina ddot de BLAS
	MPI_Comm comm=MPI_COMM_WORLD;
	MPI_Init(&argc,&argv);
	x_local=malloc(sizeof(*x_local));
	y_local=malloc(sizeof(*y_local));
	Comm_pointer_vector(x_local)=&comm;
	Comm_pointer_vector(y_local)=&comm;
	inicializa_parametros_vector_mpi(x_local, n);
	inicializa_parametros_vector_mpi(y_local, n);
	inicializa_vector_mpi(x_local, x_vector);
	inicializa_vector_mpi(y_local, y_vector);

	MPI_Scatter(entradas_vector(x_local),renglones_vector_local(x_local),MPI_DOUBLE,entradas_vector_local(x_local),renglones_vector_local(x_local),MPI_DOUBLE,0,Comm_vector(x_local));
	MPI_Scatter(entradas_vector(y_local),renglones_vector_local(y_local),MPI_DOUBLE,entradas_vector_local(y_local),renglones_vector_local(y_local),MPI_DOUBLE,0,Comm_vector(y_local));
	if(Comm_rank_vector(x_local)==0)
		printf("vector x_local:\n");
	imprime_entradas_almacenadas_en_procesos(x_local);
	local_dot_product=ddot_(&renglones_vector_local(x_local), entradas_vector_local(x_local), &incx, entradas_vector_local(y_local), &incx);
	MPI_Reduce(&local_dot_product, &resultado_dot_product, 1, MPI_DOUBLE, MPI_SUM, 0, Comm_vector(x_local));
	if(Comm_rank_vector(x_local)==0)
		printf("resultado del producto punto entre x y: %lf\n", resultado_dot_product);
	
	free_vector_mpi(x_local);
	free_vector_mpi(y_local);
	MPI_Finalize();
	return 0;
}

void inicializa_parametros_vector_mpi(arreglo_1d_T a, int n){
	MPI_Comm_size(Comm_vector(a), &Comm_size_vector(a));//Comm_size representa para este ejemplo
								//el número de procesadores y por tanto
								//número de bloques para dividir los datos
	MPI_Comm_rank(Comm_vector(a), &Comm_rank_vector(a));
	if(Comm_rank_vector(a)==0){
		renglones_vector(a)=n;
		incrementa_size_array(a);
		renglones_vector_local(a)=renglones_vector_added_ceros(a)/Comm_size_vector(a);
	}
	MPI_Bcast(&renglones_vector(a),1,MPI_INT,0,Comm_vector(a));
	MPI_Bcast(&renglones_vector_added_ceros(a),1,MPI_INT,0,Comm_vector(a));
	MPI_Bcast(&renglones_vector_local(a),1,MPI_INT,0,Comm_vector(a));
	entradas_vector_local(a)=malloc(renglones_vector_local(a)*sizeof(double));
	inicializa_vector_local_ceros(a);
}

void free_vector_mpi(arreglo_1d_T a){
	if(Comm_rank_vector(a)==0)
		free(entradas_vector(a));
	free(entradas_vector_local(a));
	free(a);
}

```

Compilamos:

```
$mpicc -g -Wall scatter_reduce_dot_product_example.c funciones.c -o programa.out -lblas

```

Ejecutamos:

```
$mpiexec -n 4 programa.out 13

```

Resultado:

```
vector x_local:
arreglo_local[0] = 1.00000
arreglo_local[1] = 0.00000
arreglo_local[2] = -1.00000
arreglo_local[3] = 0.00000
arreglo_local[4] = 0.00000 recibido de 1
arreglo_local[5] = 0.00000 recibido de 1
arreglo_local[6] = 1.00000 recibido de 1
arreglo_local[7] = 0.00000 recibido de 1
arreglo_local[8] = 0.00000 recibido de 2
arreglo_local[9] = 0.00000 recibido de 2
arreglo_local[10] = 1.00000 recibido de 2
arreglo_local[11] = 1.00000 recibido de 2
arreglo_local[12] = -1.00000 recibido de 3
arreglo_local[13] = 0.00000 recibido de 3
arreglo_local[14] = 0.00000 recibido de 3
arreglo_local[15] = 0.00000 recibido de 3
resultado del producto punto entre x y: 17.000000
```

Obsérvese que no es necesario que el número de entradas de los vectores sea divisible por el número de procesos lanzados y es posible lanzar a lo más 13 procesos:

```
$mpiexec -n 13 programa.out 13
```

Resultado:

```
vector x_local:
arreglo_local[0] = 1.00000
arreglo_local[1] = 0.00000 recibido de 1
arreglo_local[2] = -1.00000 recibido de 2
arreglo_local[3] = 0.00000 recibido de 3
arreglo_local[4] = 0.00000 recibido de 4
arreglo_local[5] = 0.00000 recibido de 5
arreglo_local[6] = 1.00000 recibido de 6
arreglo_local[7] = 0.00000 recibido de 7
arreglo_local[8] = 0.00000 recibido de 8
arreglo_local[9] = 0.00000 recibido de 9
arreglo_local[10] = 1.00000 recibido de 10
arreglo_local[11] = 1.00000 recibido de 11
arreglo_local[12] = -1.00000 recibido de 12
resultado del producto punto entre x y: 17.000000
```
