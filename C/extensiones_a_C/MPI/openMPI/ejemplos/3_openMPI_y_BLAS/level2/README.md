# Ejemplos con openmpi y BLAS

Para los siguientes ejemplos, se supone que se ha [levantado un cluster de forma pseudo distribuida con openMPI y docker](/C/extensiones_a_C/MPI/openMPI/
) o bien se siguió el [tutorial de uso de AWS con OpenMPI](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) ambos enfoques para un sistema ubuntu. De acuerdo a las arquitecturas anteriores compilar y ejectuar los siguientes programas ejemplo.

Es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos los archivos `definiciones.h` y `funciones.h` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev`.

Información sobre operaciones [level2](http://www.netlib.org/blas/#_level_2) de BLAS. 

## Distribuye block-row una matriz y dgemv:

Código que lee una matriz de un archivo y distribuye en una forma block-row order entre los procesos lanzados por la usuaria de modo que cada proceso llama a dgemv para realizar el producto matriz-vector. Se usa `MPI_Gather` para colectar el resultado en el proceso con rank 0. Este ejemplo además muestra cómo crear un communicator y un grupo con openMPI.

Los siguientes archivos deben estar en la carpeta en la que se compila:

`A_block_row.txt`:

```
0 1.5 4.3 2.1 9.4
4 -5 0 1 0
-1 2.5 -1 1 1
0 1.5 4.3 2.1 9.4
4 -5 0 1 0
-1 2.5 -1 1 10
0 1.5 4.3 2.1 9.4
0 -5 0 1 -3
8 3 -1 0 8
4 2 7 1.1 -3
0 1 -1 0 1
```

`v_block_row.txt`:

```
1
0
-1
0
1
```

Programa:

`distribute_matrix_by_block_rows_and_dgemv.c`:


```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_block_row.txt" //de tamaño MxN
#define v_vector "v_block_row.txt" //de tamaño Nx1
#define min(a,b) ((a)<(b)?(a):(b))
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
void inicializa_parametros_matriz_mpi(arreglo_2d_T matriz, int num_ren, int num_col);
void inicializa_vector_m_a(arreglo_2d_T matriz, arreglo_1d_T vector);
void inicializa_parametros_vectores_mpi(arreglo_2d_T matriz, arreglo_1d_T a, arreglo_1d_T a_resultado, arreglo_1d_T a_resultado_local, int n_a, int n_a_resultado);
void crea_grupo_y_communicator_para_gather_y_dgemv(arreglo_1d_T a, int *process_gather, MPI_Group *grupo_world, MPI_Group *grupo_gather, MPI_Comm *comu_gather);
void free_vector_local_mpi(arreglo_1d_T a);
void free_vector_mpi(arreglo_1d_T a);
void free_matriz_local_mpi(arreglo_2d_T matriz);

int main(int argc, char *argv[]){
	arreglo_2d_T A_block_local;
	arreglo_1d_T m_a;
	arreglo_1d_T v, v_resultado, v_resultado_local;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	double ALPHA, BETA;
	int incx=1;
	int *process_gather;
	MPI_Comm comm=MPI_COMM_WORLD;
	MPI_Group group_world;
	MPI_Group group_gather;
	MPI_Comm comm_gather;
	
    ALPHA = 1.0;
    BETA = 0.0;
	MPI_Init(&argc,&argv);
	//alojar espacio para todos los structs que se usarán:
	A_block_local=malloc(sizeof(*A_block_local));
	m_a=malloc(sizeof(*m_a));
	v=malloc(sizeof(*v));
	v_resultado=malloc(sizeof(*v_resultado));
	v_resultado_local = malloc(sizeof(*v_resultado_local));

	//inicializa parametros matriz mpi
	Comm_pointer_matriz(A_block_local)=&comm;
	inicializa_parametros_matriz_mpi(A_block_local, M, N);

	//inicializa vector m_a
	inicializa_vector_m_a(A_block_local, m_a);

	//lee y distribuye matriz
	entradas_local(A_block_local) = calloc(renglones_local(A_block_local)*columnas_local(A_block_local),sizeof(double));
	lee_entradas_matriz_distribuye_block_row(A_block_local, A_matriz, m_a);

	//inicializa parametros vector mpi
	inicializa_parametros_vectores_mpi(A_block_local, v,v_resultado, v_resultado_local, N, M);


	//crea grupo de procesos que realizarán dgemv y gather
	process_gather=malloc(renglones_vector(m_a)*sizeof(int));
	crea_grupo_y_communicator_para_gather_y_dgemv(m_a, process_gather, &group_world, &group_gather, &comm_gather);
	
	//dgemv y gather:
	if((Comm_rank_matriz(A_block_local)+1)*renglones_local(A_block_local)<=renglones(A_block_local)){
		dgemv_("No transpose", &renglones_local(A_block_local), &columnas(A_block_local), &ALPHA, entradas_local(A_block_local), &renglones_local(A_block_local), entradas_vector(v), &incx, &BETA, entradas_vector_local(v_resultado_local),&incx);
		MPI_Gather(entradas_vector_local(v_resultado_local), renglones_vector_local(v_resultado_local), MPI_DOUBLE, entradas_vector(v_resultado), renglones_vector_local(v_resultado_local), MPI_DOUBLE, 0, comm_gather);
	}

	//imprime resultado
	if(Comm_rank_matriz(A_block_local)==0){
		printf("vector resultado by blocks:\n");
		imprime_vector(v_resultado);

	}

	//free:
	if(Comm_rank_matriz(A_block_local)==0){
		free(entradas_vector_entero(m_a));
		free(m_a);
	}

	free_vector_mpi(v);
	free_vector_mpi(v_resultado);
	free_vector_local_mpi(v_resultado_local);
	free_matriz_local_mpi(A_block_local);


	MPI_Finalize();
	return 0;
}

void inicializa_parametros_matriz_mpi(arreglo_2d_T matriz, int num_ren, int num_col){
	renglones(matriz)=num_ren;
	columnas(matriz)=num_col;
	MPI_Comm_size(Comm_matriz(matriz), &Comm_size_matriz(matriz));
	MPI_Comm_rank(Comm_matriz(matriz), &Comm_rank_matriz(matriz));
	if(Comm_rank_matriz(matriz)==0){	
		incrementa_size_array_2d(matriz);
		renglones_local(matriz)=renglones_added_ceros(matriz)/Comm_size_matriz(matriz);
	}
	MPI_Bcast(&renglones_local(matriz), 1 , MPI_INT, 0, Comm_matriz(matriz));
	columnas_local(matriz)=num_col;

}
void inicializa_vector_m_a(arreglo_2d_T matriz, arreglo_1d_T vector){
	int suma=0;
	int i;
	MPI_Status status;
	if(Comm_rank_matriz(matriz)==0){
		renglones_vector(vector)=Comm_size_matriz(matriz);
		entradas_vector_entero(vector) = calloc(renglones_vector(vector),sizeof(int));
		for(i=0;i<renglones_vector(vector) && renglones(matriz)-suma>0;i++){
			entrada_vector_entero(vector,i)=min(renglones_local(matriz),renglones(matriz)-suma);
			suma+=entrada_vector_entero(vector,i);
		}
		printf("Vector\n");
		imprime_vector_entero(vector);
		printf("resizing vector, número de renglones : %d\n",i);
		renglones_vector(vector)=i;
		entradas_vector_entero(vector) = realloc(entradas_vector_entero(vector),i*sizeof(int));
		imprime_vector_entero(vector);
		MPI_Send(&entrada_vector_entero(vector,i-1),1,MPI_INT, i-1, 0, Comm_matriz(matriz));
	}
	MPI_Bcast(&renglones_vector(vector), 1 , MPI_INT, 0, Comm_matriz(matriz));

	if(renglones_vector(vector)-1==Comm_rank_matriz(matriz)){
		MPI_Recv(&renglones_local(matriz), 1, MPI_INT, 0,0, Comm_matriz(matriz), &status);
	}
}

void inicializa_parametros_vectores_mpi(arreglo_2d_T matriz, arreglo_1d_T a, arreglo_1d_T a_resultado, arreglo_1d_T a_resultado_local, int n_a, int n_a_resultado){
	renglones_vector(a)=n_a;
	renglones_vector(a_resultado) = n_a_resultado;
	entradas_vector(a)=malloc(renglones_vector(a)*sizeof(double));
	inicializa_vector(a,v_vector);
	entradas_vector(a_resultado)=calloc(renglones_vector(a_resultado),sizeof(double));
	renglones_vector_local(a_resultado_local)=renglones_local(matriz);
	entradas_vector_local(a_resultado_local)=calloc(renglones_vector_local(a_resultado_local),sizeof(double));
}
void crea_grupo_y_communicator_para_gather_y_dgemv(arreglo_1d_T a, int *procesos, MPI_Group *grupo_world, MPI_Group *grupo_gather, MPI_Comm *comu_gather){
	int i;
	for(i=0;i<renglones_vector(a);i++)
		procesos[i]=i;

	MPI_Comm_group(MPI_COMM_WORLD, grupo_world);
	MPI_Group_incl(*grupo_world, renglones_vector(a), procesos, grupo_gather);

	MPI_Comm_create(MPI_COMM_WORLD, *grupo_gather, comu_gather);
}
void free_vector_local_mpi(arreglo_1d_T a){
	free(entradas_vector_local(a));
	free(a);
}
void free_vector_mpi(arreglo_1d_T a){
	free(entradas_vector(a));
	free(a);
}
void free_matriz_local_mpi(arreglo_2d_T matriz){
	free(entradas_local(matriz));
	free(matriz);
}

```

Compilamos:

```
$mpicc -Wall funciones.c distribute_matrix_by_block_rows_and_dgemv.c -o programa.out -lblas

```

Ejecutamos:

```
mpiexec -n 8 programa.out 11 5
```

Resultado:

```
Vector
vector[0]=2
vector[1]=2
vector[2]=2
vector[3]=2
vector[4]=2
vector[5]=1
vector[6]=0
vector[7]=0
resizing vector, número de renglones : 6
vector[0]=2
vector[1]=2
vector[2]=2
vector[3]=2
vector[4]=2
vector[5]=1
vector resultado by blocks:
vector[0]=5.10000
vector[1]=4.00000
vector[2]=1.00000
vector[3]=5.10000
vector[4]=4.00000
vector[5]=10.00000
vector[6]=5.10000
vector[7]=-3.00000
vector[8]=17.00000
vector[9]=-6.00000
vector[10]=2.00000
```

Obsérvese que no es necesario que el número de de renglones de la matriz sea divisible por el número de procesos lanzados y es posible lanzar a lo más 11 procesos:

```
$mpiexec -n 11 programa.out 11 5

```

Resultado:

```
Vector
vector[0]=1
vector[1]=1
vector[2]=1
vector[3]=1
vector[4]=1
vector[5]=1
vector[6]=1
vector[7]=1
vector[8]=1
vector[9]=1
vector[10]=1
resizing vector, número de renglones : 11
vector[0]=1
vector[1]=1
vector[2]=1
vector[3]=1
vector[4]=1
vector[5]=1
vector[6]=1
vector[7]=1
vector[8]=1
vector[9]=1
vector[10]=1
vector resultado by blocks:
vector[0]=5.10000
vector[1]=4.00000
vector[2]=1.00000
vector[3]=5.10000
vector[4]=4.00000
vector[5]=10.00000
vector[6]=5.10000
vector[7]=-3.00000
vector[8]=17.00000
vector[9]=-6.00000
vector[10]=2.00000
```

