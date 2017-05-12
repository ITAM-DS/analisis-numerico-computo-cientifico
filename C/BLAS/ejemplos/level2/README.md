Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.h` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev` y `liblapack-dev`.

Información sobre operaciones [level2](http://www.netlib.org/blas/#_level_2).

# Multiplicación matriz-vector:

Código que realiza la multiplicación matriz-vector con una matriz y un vector almacenados en los archivos:

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
	int incx=1;
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

	dgemv_("No transpose", &M, &N, &ALPHA, entradas(A), &M, entradas_vector(v), &incx, &BETA, entradas_vector(v_resultado),&incx);
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

# Multiplicación matriz-vector versión block-row-oriented:

Código que realiza la multiplicación matriz-vector versión block-row-oriented con una matriz y un vector almacenados en los archivos:

`v_block_row.txt`:

```
1
0
-1
0
1
```

`A_block_row.txt`:

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

Se deben tener los archivos `v_block_row.txt` y `A_block_row.txt` en el directorio de compilación y ejecución.

`dgemm_mult_mat_vec_row_block.c`:


```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_block_row.txt" //de tamaño MxN
#define v_vector "v_block_row.txt" //de tamaño Nx1
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void dlacpy_(char *part_of_a, int *m, int *n, double *a, int *lda, double *b, int *ldb);
int main(int argc, char *argv[]){
	arreglo_2d_T A, A_block;
	arreglo_1d_T v, v_resultado;
	arreglo_1d_T m_a;
	int i;
	int ii;
	int incx=1;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int nb=atoi(argv[3]); //numero de renglones en un bloque
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

	m_a=malloc(sizeof(m_a));
	renglones_vector(m_a)=(M%nb != 0)?M/nb+1:M/nb;
	entradas_vector(m_a) = malloc(renglones_vector(m_a)*sizeof(double));

	for(i=0;i<renglones_vector(m_a)-1;i++)
		entrada_vector(m_a,i)=nb;
		entrada_vector(m_a,i)=(M%nb != 0)?M-(M/nb*nb):nb;

	A_block=malloc(sizeof(A_block));

	columnas(A_block)=columnas(A);
	ii=0;
	for(i=0;i<renglones_vector(m_a);i++){
		renglones(A_block)=entrada_vector(m_a,i);
		entradas(A_block)=(i==0)?malloc(renglones(A_block)*columnas(A)*sizeof(double)):realloc(entradas(A_block), renglones(A_block)*columnas(A)*sizeof(double));
		dlacpy_("General", &renglones(A_block), &columnas(A),entradas(A)+ii, &renglones(A), entradas(A_block), &renglones(A_block));	
        printf("matriz block:\n");
        imprime_matriz(A_block);
        printf("------------\n");
		dgemv_("No transpose", &renglones(A_block), &columnas(A), &ALPHA, entradas(A_block), &renglones(A_block), entradas_vector(v), &incx, &BETA, entradas_vector(v_resultado)+ii,&incx);
		ii+=entrada_vector(m_a,i);
	}

	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector resultado by blocks:\n");
	imprime_vector(v_resultado);

	free(A);
	free(v);
	free(v_resultado);
	free(A_block);
	free(m_a);
	return 0;
}

```

Compilamos:

```
$gcc -Wall dgemm_mult_mat_vec_row_block.c funciones.c -o programa.out -llapack -lblas
```

Por ejemplo, si quisiéramos dividir en bloques de tamaño 2 x número de columnas de A (tenemos 4 bloques, todos de tamaño : 2 x número de columnas de A).

```
$./programa.out 8 5 2
```

Resultado:

```
matriz block:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
------------
matriz block:
matriz[0][0]=-1.0000000000000000	matriz[0][1]=2.5000000000000000	matriz[0][2]=-1.0000000000000000	matriz[0][3]=1.0000000000000000	matriz[0][4]=1.0000000000000000
matriz[1][0]=0.0000000000000000	matriz[1][1]=1.5000000000000000	matriz[1][2]=4.2999999999999998	matriz[1][3]=2.1000000000000001	matriz[1][4]=9.4000000000000004
------------
matriz block:
matriz[0][0]=4.0000000000000000	matriz[0][1]=-5.0000000000000000	matriz[0][2]=0.0000000000000000	matriz[0][3]=1.0000000000000000	matriz[0][4]=0.0000000000000000
matriz[1][0]=-1.0000000000000000	matriz[1][1]=2.5000000000000000	matriz[1][2]=-1.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
------------
matriz block:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=0.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
------------
matriz 1:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000	matriz[2][2]=-1.0000000000000000	matriz[2][3]=1.0000000000000000	matriz[2][4]=1.0000000000000000
matriz[3][0]=0.0000000000000000	matriz[3][1]=1.5000000000000000	matriz[3][2]=4.2999999999999998	matriz[3][3]=2.1000000000000001	matriz[3][4]=9.4000000000000004
matriz[4][0]=4.0000000000000000	matriz[4][1]=-5.0000000000000000	matriz[4][2]=0.0000000000000000	matriz[4][3]=1.0000000000000000	matriz[4][4]=0.0000000000000000
matriz[5][0]=-1.0000000000000000	matriz[5][1]=2.5000000000000000	matriz[5][2]=-1.0000000000000000	matriz[5][3]=1.0000000000000000	matriz[5][4]=0.0000000000000000
matriz[6][0]=0.0000000000000000	matriz[6][1]=1.5000000000000000	matriz[6][2]=4.2999999999999998	matriz[6][3]=2.1000000000000001	matriz[6][4]=9.4000000000000004
matriz[7][0]=0.0000000000000000	matriz[7][1]=-5.0000000000000000	matriz[7][2]=0.0000000000000000	matriz[7][3]=1.0000000000000000	matriz[7][4]=0.0000000000000000
------------
vector :
vector[0]=1.0000000000000000
vector[1]=0.0000000000000000
vector[2]=-1.0000000000000000
vector[3]=0.0000000000000000
vector[4]=1.0000000000000000
------------
vector resultado by blocks:
vector[0]=5.1000000000000005
vector[1]=4.0000000000000000
vector[2]=1.0000000000000000
vector[3]=5.1000000000000005
vector[4]=4.0000000000000000
vector[5]=0.0000000000000000
vector[6]=5.1000000000000005
vector[7]=0.0000000000000000
```

Obs: si quisiéramos dividir en bloques de tamaño 3 x número de columnas de A (tendríamos tres bloques, el primero de tamaño 3 x número de columnas de A, el segundo de tamaño 3 x número de columnas de A y el último de tamaño 2 x número de columnas de A) y ejecutamos como así:

```
$./programa.out 8 5 3
```

```
matriz block:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000	matriz[2][2]=-1.0000000000000000	matriz[2][3]=1.0000000000000000	matriz[2][4]=1.0000000000000000
------------
matriz block:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000	matriz[2][2]=-1.0000000000000000	matriz[2][3]=1.0000000000000000	matriz[2][4]=0.0000000000000000
------------
matriz block:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=0.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
------------
matriz 1:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000	matriz[2][2]=-1.0000000000000000	matriz[2][3]=1.0000000000000000	matriz[2][4]=1.0000000000000000
matriz[3][0]=0.0000000000000000	matriz[3][1]=1.5000000000000000	matriz[3][2]=4.2999999999999998	matriz[3][3]=2.1000000000000001	matriz[3][4]=9.4000000000000004
matriz[4][0]=4.0000000000000000	matriz[4][1]=-5.0000000000000000	matriz[4][2]=0.0000000000000000	matriz[4][3]=1.0000000000000000	matriz[4][4]=0.0000000000000000
matriz[5][0]=-1.0000000000000000	matriz[5][1]=2.5000000000000000	matriz[5][2]=-1.0000000000000000	matriz[5][3]=1.0000000000000000	matriz[5][4]=0.0000000000000000
matriz[6][0]=0.0000000000000000	matriz[6][1]=1.5000000000000000	matriz[6][2]=4.2999999999999998	matriz[6][3]=2.1000000000000001	matriz[6][4]=9.4000000000000004
matriz[7][0]=0.0000000000000000	matriz[7][1]=-5.0000000000000000	matriz[7][2]=0.0000000000000000	matriz[7][3]=1.0000000000000000	matriz[7][4]=0.0000000000000000
------------
vector :
vector[0]=1.0000000000000000
vector[1]=0.0000000000000000
vector[2]=-1.0000000000000000
vector[3]=0.0000000000000000
vector[4]=1.0000000000000000
------------
vector resultado by blocks:
vector[0]=5.1000000000000005
vector[1]=4.0000000000000000
vector[2]=1.0000000000000000
vector[3]=5.1000000000000005
vector[4]=4.0000000000000000
vector[5]=0.0000000000000000
vector[6]=5.1000000000000005
vector[7]=0.0000000000000000
```

# Multiplicación matriz-vector versión block-column-oriented:

Código que realiza la multiplicación matriz-vector versión block-column-oriented con una matriz y un vector almacenados en los archivos:

`v_block_column.txt`:

```
1
0
-1
0
1
-1
-1
0
```

`A_block_column.txt`:

```
0 1.5 4.3 2.1 9.4 0 1 -1
4 -5 0 1 0 2 -3 2
-1 2.5 -1 1 1 4 0 1
0 1.5 4.3 2.1 9.4 2 3.1 -1.1
```

Se deben tener los archivos `v.txt` y `A.txt` en el directorio de compilación y ejecución.

`dgemm_mult_mat_vec_column_block.c`:


```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_block_column.txt" //de tamaño MxN
#define v_vector "v_block_column.txt" //de tamaño Nx1
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void dlacpy_(char *part_of_a, int *m, int *n, double *a, int *lda, double *b, int *ldb);
int main(int argc, char *argv[]){
	arreglo_2d_T A, A_block;
	arreglo_1d_T v, v_resultado;
	arreglo_1d_T n_a;
	int j;
	int jj;
	int incx=1;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int nb=atoi(argv[3]); //numero de columnas en un bloque
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 1.0;
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

	n_a=malloc(sizeof(n_a));
	renglones_vector(n_a)=(N%nb != 0)?N/nb+1:N/nb;
	entradas_vector(n_a) = malloc(renglones_vector(n_a)*sizeof(double));

	for(j=0;j<renglones_vector(n_a)-1;j++)
		entrada_vector(n_a,j)=nb;
		entrada_vector(n_a,j)=(N%nb != 0)?N-(N/nb*nb):nb;
	printf("vector:\n");
	imprime_vector(n_a);

	A_block=malloc(sizeof(A_block));

	printf("matriz block:\n");
	imprime_matriz(A_block);
	printf("------------\n");*/

	renglones(A_block)=renglones(A);
	jj=0;
	for(j=0;j<renglones_vector(n_a);j++){
		columnas(A_block)=entrada_vector(n_a,j);
		entradas(A_block)=(j==0)?malloc(renglones(A)*columnas(A_block)*sizeof(double)):realloc(entradas(A_block), renglones(A)*columnas(A_block)*sizeof(double));
		dlacpy_("General", &renglones(A), &columnas(A_block),entradas(A)+jj*renglones(A), &renglones(A_block), entradas(A_block), &renglones(A_block));	
		printf("matriz block:\n");
		imprime_matriz(A_block);
		printf("------------\n");
		dgemv_("No transpose", &renglones(A), &columnas(A_block), &ALPHA, entradas(A_block), &renglones(A), entradas_vector(v)+jj, &incx, &BETA, entradas_vector(v_resultado),&incx);
		jj+=entrada_vector(n_a,j);
	}


	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("vector :\n");
	imprime_vector(v);
	printf("------------\n");
	printf("vector resultado by blocks:\n");
	imprime_vector(v_resultado);

	free(A);
	free(v);
	free(v_resultado);
	free(A_block);
	free(n_a);
	return 0;
}
```

Compilamos:

```
$gcc -Wall dgemm_mult_mat_vec_column_block.c funciones.c -o programa.out -llapack -lblas
```

Ejecutamos:

```
$./programa.out 4 8 3
```

Resultado:

```
vector:
vector[0]=3.0000000000000000
vector[1]=3.0000000000000000
vector[2]=2.0000000000000000
matriz block:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000	matriz[2][2]=-1.0000000000000000
matriz[3][0]=0.0000000000000000	matriz[3][1]=1.5000000000000000	matriz[3][2]=4.2999999999999998
------------
matriz block:
matriz[0][0]=2.1000000000000001	matriz[0][1]=9.4000000000000004	matriz[0][2]=0.0000000000000000
matriz[1][0]=1.0000000000000000	matriz[1][1]=0.0000000000000000	matriz[1][2]=2.0000000000000000
matriz[2][0]=1.0000000000000000	matriz[2][1]=1.0000000000000000	matriz[2][2]=4.0000000000000000
matriz[3][0]=2.1000000000000001	matriz[3][1]=9.4000000000000004	matriz[3][2]=2.0000000000000000
------------
matriz block:
matriz[0][0]=1.0000000000000000	matriz[0][1]=-1.0000000000000000
matriz[1][0]=-3.0000000000000000	matriz[1][1]=2.0000000000000000
matriz[2][0]=0.0000000000000000	matriz[2][1]=1.0000000000000000
matriz[3][0]=3.1000000000000001	matriz[3][1]=-1.1000000000000001
------------
matriz 1:
matriz[0][0]=0.0000000000000000	matriz[0][1]=1.5000000000000000	matriz[0][2]=4.2999999999999998	matriz[0][3]=2.1000000000000001	matriz[0][4]=9.4000000000000004	matriz[0][5]=0.0000000000000000	matriz[0][6]=1.0000000000000000	matriz[0][7]=-1.0000000000000000
matriz[1][0]=4.0000000000000000	matriz[1][1]=-5.0000000000000000	matriz[1][2]=0.0000000000000000	matriz[1][3]=1.0000000000000000	matriz[1][4]=0.0000000000000000	matriz[1][5]=2.0000000000000000	matriz[1][6]=-3.0000000000000000	matriz[1][7]=2.0000000000000000
matriz[2][0]=-1.0000000000000000	matriz[2][1]=2.5000000000000000	matriz[2][2]=-1.0000000000000000	matriz[2][3]=1.0000000000000000	matriz[2][4]=1.0000000000000000	matriz[2][5]=4.0000000000000000	matriz[2][6]=0.0000000000000000	matriz[2][7]=1.0000000000000000
matriz[3][0]=0.0000000000000000	matriz[3][1]=1.5000000000000000	matriz[3][2]=4.2999999999999998	matriz[3][3]=2.1000000000000001	matriz[3][4]=9.4000000000000004	matriz[3][5]=2.0000000000000000	matriz[3][6]=3.1000000000000001	matriz[3][7]=-1.1000000000000001
------------
vector :
vector[0]=1.0000000000000000
vector[1]=0.0000000000000000
vector[2]=-1.0000000000000000
vector[3]=0.0000000000000000
vector[4]=1.0000000000000000
vector[5]=-1.0000000000000000
vector[6]=-1.0000000000000000
vector[7]=0.0000000000000000
------------
vector resultado by blocks:
vector[0]=4.1000000000000005
vector[1]=5.0000000000000000
vector[2]=-3.0000000000000000
vector[3]=0.0000000000000004
```


