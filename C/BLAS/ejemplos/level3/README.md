Para los siguientes ejemplos es necesario tener en la carpeta en la que se compilará y ejecutará los siguientes códigos, los archivos `definiciones.h` y `funciones.c` los cuales los encuentran [aquí](../) y se debe tener instalado en sus sistemas ubuntu `libblas-dev` y `liblapack-dev`.

Información sobre operaciones [level3](http://www.netlib.org/blas/#_level_3).

# Multiplicación matriz-matriz:

Código que realiza la multiplicación matriz-matriz con matrices almacenadas en los archivos:

`A.txt`:

```
0 1.5
4 -5
-1 2.5
```

`B.txt`:

```
1 0 0
0 -1 1
``` 

Se deben tener los archivos `A.txt` y `B.txt` en el directorio de compilación y ejecución.

`dgemm_mult_mat.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxK
#define B_matriz "B.txt" //de tamaño KxN
extern void dgemm_(char *transposeA, char *transposeB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
	int K=atoi(argv[2]);
	int N=atoi(argv[4]);
	double ALPHA, BETA;
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
	printf("matriz resultado:\n");
	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));
	dgemm_("No transpose", "No transpose", &M, &N, &K, &ALPHA, entradas(A), &M, entradas(B), &K, &BETA, entradas(C), &M);
	imprime_matriz(C);
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
$gcc -Wall dgemm_mult_mat.c funciones.c -o programa.out -lblas
```

Ejecutamos:

```
./programa.out 3 2 2 3
```

Resultado:

```
matriz 1:
matriz[0][0]=0.00000	matriz[0][1]=1.50000
matriz[1][0]=4.00000	matriz[1][1]=-5.00000
matriz[2][0]=-1.00000	matriz[2][1]=2.50000
------------
matriz 2:
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=-1.00000	matriz[1][2]=1.00000
------------
matriz resultado:
matriz[0][0]=0.00000	matriz[0][1]=-1.50000	matriz[0][2]=1.50000
matriz[1][0]=4.00000	matriz[1][1]=5.00000	matriz[1][2]=-5.00000
matriz[2][0]=-1.00000	matriz[2][1]=-2.50000	matriz[2][2]=2.50000
```

# Multiplicación matriz-matriz con trick:

Podemos hacer un trick si usamos el siguiente archivo de definiciones:

`definiciones.h`:

```
typedef struct{
int m, n;
#define renglones(arreglo) ((arreglo)->m)
#define columnas(arreglo) ((arreglo)->n)
double *arr;
#define entradas(arreglo) ((arreglo)->arr)
#define entrada(arreglo,i,j) ((arreglo)->arr[i*columnas(arreglo)+j]) //almacenamos row major
}arreglo_2d;
typedef arreglo_2d *arreglo_2d_T;
typedef struct{
int n;
#define renglones_vector(arreglo) ((arreglo)->n)
double *arr;
int *arr_int;
#define entradas_vector(arreglo) ((arreglo)->arr)
#define entrada_vector(arreglo,i) ((arreglo)->arr[i])
#define entradas_vector_entero(arreglo) ((arreglo)->arr_int)
#define entrada_vector_entero(arreglo,i) ((arreglo)->arr_int[i])
}arreglo_1d;
typedef arreglo_1d *arreglo_1d_T;
void imprime_vector(arreglo_1d_T);
void imprime_matriz(arreglo_2d_T);
void inicializa_matriz(arreglo_2d_T, char *);
void inicializa_vector(arreglo_1d_T, char *);
void imprime_vector_entero(arreglo_1d_T);
```

Observa que la diferencia con el archivo de definiciones de [aquí](../) es que en este caso estamos almacenando row major. Entonces la multiplicación de matrices se realiza con el código:

`dgemm_mult_mat_trick.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño MxK
#define B_matriz "B.txt" //de tamaño KxN
extern void dgemm_(char *transposeA, char *transposeB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	int M=atoi(argv[1]);
	int K=atoi(argv[2]);
	int N=atoi(argv[4]);
	double ALPHA, BETA;
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
	printf("matriz 3:\n");
	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));
	dgemm_("No transpose", "No transpose", &N, &M, &K, &ALPHA, entradas(B), &N, entradas(A), &K, &BETA, entradas(C), &N);
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	return 0;
}

```

Compilamos: **(en una carpeta coloca los archivos de `definiciones.h` anterior, `funciones.c` de [aquí](../) y `dgemm_mult_mat_trick.c`)**

```
$gcc -Wall dgemm_mult_mat_trick.c funciones.c -o programa.out -lblas
```

Ejecutamos:

```
./programa.out 3 2 2 3
```

Resultado:

```
matriz 1:
matriz[0][0]=0.00000	matriz[0][1]=1.50000
matriz[1][0]=4.00000	matriz[1][1]=-5.00000
matriz[2][0]=-1.00000	matriz[2][1]=2.50000
------------
matriz 2:
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=-1.00000	matriz[1][2]=1.00000
matriz 3:
matriz[0][0]=0.00000	matriz[0][1]=-1.50000	matriz[0][2]=1.50000
matriz[1][0]=4.00000	matriz[1][1]=5.00000	matriz[1][2]=-5.00000
matriz[2][0]=-1.00000	matriz[2][1]=-2.50000	matriz[2][2]=2.50000
```

Pregunta: ¿Por qué funciona este trick?


# Multiplicación matriz-matriz block-based versión i,j,k :

Código que realiza la multiplicación matriz-matriz block-based versión i, j, k con matrices almacenadas en los archivos:

`A_block.txt`:

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

`B_block.txt`:

```
0 1.5 4.3 2.1 9.4 0 1 -1
4 -5 0 1 0 2 -3 2
-1 2.5 -1 1 1 4 0 1
0 1.5 4.3 2.1 9.4 2 3.1 -1.1
1 2 -1 0 1.1 0 -1 3
``` 

Se deben tener los archivos `A_block.txt` y `B_block.txt` en el directorio de compilación y ejecución.

`dgemm_mult_mat_blocks.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A_block.txt" //de tamaño MxK
#define B_matriz "B_block.txt" //de tamaño KxN
#define A(ind1,ind2) (entradas(A)+(ind1)+(ind2)*renglones(A))
#define B(ind1,ind2) (entradas(B)+(ind1)+(ind2)*renglones(B))
#define C(ind1,ind2) (entradas(C)+(ind1)+(ind2)*renglones(C))
extern void dgemm_(char *transposeA, char *transposeB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
extern void dlacpy_(char *part_of_matrix_a, int *m, int *n, double *a, int *lda, double *b, int *ldb);
void inicializa_vectores_de_bloques(arreglo_1d_T arreglo, int dimension_ren_o_cols,int nb_blocks);
int main(int argc, char *argv[]){
	arreglo_2d_T A, B, C;
	arreglo_2d_T A_block, B_block;
	arreglo_1d_T m_a;
	arreglo_1d_T n_b;
	arreglo_1d_T k_a_b;
	int M=atoi(argv[1]);
	int K=atoi(argv[2]);
	int N=atoi(argv[4]);
	int nb_rows_A=atoi(argv[5]);//numero de renglones en un bloque de A
	int nb_columns_A_rows_B=atoi(argv[6]);//numero de columnas en un bloque de A (análogamente número de
						//renglones en un bloque de B) 
	int nb_columns_B=atoi(argv[7]);
	int ii,jj,kk;
	int i,j,k;
	double ALPHA, BETA;
    ALPHA = 1.0;
    BETA = 1.0;
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
	
	entradas(C)=calloc(renglones(C)*columnas(C),sizeof(double));
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
	printf("matriz 2:\n");
	imprime_matriz(B);

	A_block=malloc(sizeof(*A_block));
	B_block=malloc(sizeof(*B_block));
	
	m_a=malloc(sizeof(*m_a));
	k_a_b=malloc(sizeof(*k_a_b));
	n_b=malloc(sizeof(*n_b));

	inicializa_vectores_de_bloques(m_a, renglones(A), nb_rows_A);
	inicializa_vectores_de_bloques(k_a_b, columnas(A), nb_columns_A_rows_B);
	inicializa_vectores_de_bloques(n_b, columnas(B), nb_columns_B);

	ii=0;
	for(i=0;i<renglones_vector(m_a);i++){
		renglones(A_block)=entrada_vector(m_a,i);
		jj=0;
		for(j=0;j<renglones_vector(n_b);j++){
			columnas(B_block)=entrada_vector(n_b,j);
			kk=0;
			for(k=0;k<renglones_vector(k_a_b);k++){
				columnas(A_block)=entrada_vector(k_a_b,k);
				renglones(B_block)=entrada_vector(k_a_b,k);
				entradas(A_block)=(i==0)?malloc(renglones(A_block)*columnas(A_block)*sizeof(double)):realloc(entradas(A_block), renglones(A_block)*columnas(A_block)*sizeof(double));
				entradas(B_block)=(j==0)?malloc(renglones(B_block)*columnas(B_block)*sizeof(double)):realloc(entradas(B_block), renglones(B_block)*columnas(B_block)*sizeof(double));
				dlacpy_("General", &renglones(A_block), &columnas(A_block),A(ii,kk), &renglones(A), entradas(A_block), &renglones(A_block));
				dlacpy_("General", &renglones(B_block), &columnas(B_block),B(kk,jj), &renglones(B), entradas(B_block), &renglones(B_block));
				dgemm_("No transpose", "No transpose", &renglones(A_block), &columnas(B_block), &columnas(A_block), &ALPHA, entradas(A_block), &renglones(A_block), entradas(B_block), &columnas(A_block), &BETA, C(ii,jj), &renglones(C));
				kk+=entrada_vector(k_a_b,k);
			}
			jj+=entrada_vector(n_b,j);
		}
		ii+=entrada_vector(m_a,i);

	}
	printf("------------\n");
	printf("resultado:\n");
	imprime_matriz(C);
	free(entradas(A));
	free(A);
	free(entradas(B));
	free(B);
	free(entradas(C));
	free(C);
	free(entradas(A_block));
	free(A_block);
	free(entradas(B_block));
	free(B_block);
	free(entradas_vector(m_a));
	free(m_a);
	free(entradas_vector(k_a_b));
	free(k_a_b);
	free(entradas_vector(n_b));
	free(n_b);

	return 0;
}

void inicializa_vectores_de_bloques(arreglo_1d_T p, int dimension, int nb){
	int indice;
	renglones_vector(p)=(dimension%nb != 0)?dimension/nb+1:dimension/nb;
	entradas_vector(p) = malloc(renglones_vector(p)*sizeof(double));

	for(indice=0;indice<renglones_vector(p)-1;indice++)
		entrada_vector(p,indice)=nb;
		entrada_vector(p,indice)=(dimension%nb!= 0)?dimension-(dimension/nb*nb):nb;
}
```

Compilamos:

```
$gcc -Wall dgemm_mult_mat_blocks.c funciones.c -o programa.out -lblas -llapack
```


Ejecutamos:

```
./programa.out 8 5 5 8 2 3 2
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
resultado:
matriz[0][0]=11.10000	matriz[0][1]=25.20000	matriz[0][2]=-4.67000	matriz[0][3]=10.21000	matriz[0][4]=34.38000	matriz[0][5]=24.40000	matriz[0][6]=-7.39000	matriz[0][7]=33.19000
matriz[1][0]=-20.00000	matriz[1][1]=32.50000	matriz[1][2]=21.50000	matriz[1][3]=5.50000	matriz[1][4]=47.00000	matriz[1][5]=-8.00000	matriz[1][6]=22.10000	matriz[1][7]=-15.10000
matriz[2][0]=12.00000	matriz[2][1]=-13.00000	matriz[2][2]=0.00000	matriz[2][3]=1.50000	matriz[2][4]=0.10000	matriz[2][5]=3.00000	matriz[2][6]=-6.40000	matriz[2][7]=6.90000
matriz[3][0]=11.10000	matriz[3][1]=25.20000	matriz[3][2]=-4.67000	matriz[3][3]=10.21000	matriz[3][4]=34.38000	matriz[3][5]=24.40000	matriz[3][6]=-7.39000	matriz[3][7]=33.19000
matriz[4][0]=-20.00000	matriz[4][1]=32.50000	matriz[4][2]=21.50000	matriz[4][3]=5.50000	matriz[4][4]=47.00000	matriz[4][5]=-8.00000	matriz[4][6]=22.10000	matriz[4][7]=-15.10000
matriz[5][0]=11.00000	matriz[5][1]=-15.00000	matriz[5][2]=1.00000	matriz[5][3]=1.50000	matriz[5][4]=-1.00000	matriz[5][5]=3.00000	matriz[5][6]=-5.40000	matriz[5][7]=3.90000
matriz[6][0]=11.10000	matriz[6][1]=25.20000	matriz[6][2]=-4.67000	matriz[6][3]=10.21000	matriz[6][4]=34.38000	matriz[6][5]=24.40000	matriz[6][6]=-7.39000	matriz[6][7]=33.19000
matriz[7][0]=-20.00000	matriz[7][1]=26.50000	matriz[7][2]=4.30000	matriz[7][3]=-2.90000	matriz[7][4]=9.40000	matriz[7][5]=-8.00000	matriz[7][6]=18.10000	matriz[7][7]=-11.10000
```

Sólo para verificar con los archivos:

`A_block.txt`:

```
0 1.5
4 -5
-1 2.5
```


`B_block.txt`:

```
1 0 0
0 -1 1
```

Ejecutamos:

```
./programa.out 3 2 2 3 2 2 1
```

Resultado:

```
matriz 1:
matriz[0][0]=0.00000	matriz[0][1]=1.50000
matriz[1][0]=4.00000	matriz[1][1]=-5.00000
matriz[2][0]=-1.00000	matriz[2][1]=2.50000
------------
matriz 2:
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=-1.00000	matriz[1][2]=1.00000
------------
resultado:
matriz[0][0]=0.00000	matriz[0][1]=-1.50000	matriz[0][2]=1.50000
matriz[1][0]=4.00000	matriz[1][1]=5.00000	matriz[1][2]=-5.00000
matriz[2][0]=-1.00000	matriz[2][1]=-2.50000	matriz[2][2]=2.50000
```
