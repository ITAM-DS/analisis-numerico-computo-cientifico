# Tarea 5

Se entrega. De forma individual crear una carpeta con nombre igual a su clave única, debajo del nivel: 

```
analisis-numerico-computo-cientifico/MNO/entrega_tareas_de_C/tarea5
```

Considera el programa formado por los archivos:

`definiciones.h` :

```
#define NUM_REN_MAT1 3
#define NUM_COL_MAT1 2
#define NUM_REN_MAT2 2
#define NUM_COL_MAT2 3 
void imprime_matrices(void);
void imprime_matriz_resultado(void);
void multiplica_matrices(void);
```

`funciones.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double matriz1[NUM_REN_MAT1][NUM_COL_MAT1]={
        {0, 1.5},
        {4, -5},
        {-1, 2.5}
    };
static double matriz2[NUM_REN_MAT2][NUM_COL_MAT2]={
        {1, 0, 0},
        {0, -1, 1}
    };
static double matriz_resultado[NUM_REN_MAT1][NUM_COL_MAT2];

void imprime_matrices(void){
	printf("Matriz1\n");
		for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
			for(j=0;j<NUM_COL_MAT1;j++){
				if(j<NUM_COL_MAT1-1)
				printf("matriz1[%d][%d]=%4.2f\t",i,j,matriz1[i][j]);
				else
				printf("matriz1[%d][%d]=%4.2f\n",i,j,matriz1[i][j]);
			}
		}
	printf("\n");
	printf("Matriz2\n");
		for(i=0;i<NUM_REN_MAT2;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz2[%d][%d]=%4.2f\t",i,j,matriz2[i][j]);
				else
				printf("matriz2[%d][%d]=%4.2f\n",i,j,matriz2[i][j]);
			}
		}
	printf("\n");
}

void imprime_matriz_resultado(void){
	printf("Matriz resultado\n");
		for(i=0;i<NUM_REN_MAT1;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
				printf("matriz_res[%d][%d]=%4.2f\t",i,j,matriz_resultado[i][j]);
				else
				printf("matriz_res[%d][%d]=%4.2f\n",i,j,matriz_resultado[i][j]);
			}
		}

	printf("\n");

}

void multiplica_matrices(void){
	for(i=0;i<NUM_REN_MAT1;i++){
		for(k=0;k<NUM_COL_MAT2;k++){
	 		matriz_resultado[i][k]=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
  				matriz_resultado[i][k]=matriz_resultado[i][k]+matriz1[i][j]*matriz2[j][k];
		}
	}
}

```

`main.c`:

```
#include"definiciones.h"
int main(void){
    imprime_matrices();
    multiplica_matrices();
    imprime_matriz_resultado();
return 0;
}
```

Compila teniendo los tres archivos en una carpeta con la línea:

```
$gcc main.c funciones.c -o programa.out
```

Observa los resultados al ejecutar el `programa.out` y realiza lo siguiente:

a) Investiga por qué se usan `""` en la línea que tiene `include` en `main.c` y en `funciones.c` en lugar de usar `< >`. 

b) Investiga el uso de `static` en la definición de variables externas de `funciones.c`.

c) Modifica el archivo `funciones.c` para que alojes e inicialices a las matrices `matriz1`, `matriz2` y `matriz_resultado` con `malloc` y apuntadores. Modifica `main.c` para que llame a una función dentro del archivo `funciones.c` que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa `free`): 

```
#include"definiciones.h"
int main(void){
    aloja_espacio_e_incializa_matrices();
    imprime_matrices();
    multiplica_matrices();
    imprime_matriz_resultado();
    libera_espacio();
return 0;
}

```

d) Compara tu resultado usando la subrutina de Fortran `dgemm` y los siguientes archivos `definiciones2.h`, `main2.c`, `funciones2.c`:

`definiciones2.h`:

```
#define NUM_REN_MAT1 3
#define NUM_COL_MAT1 2
#define NUM_REN_MAT2 2
#define NUM_COL_MAT2 3 
void imprime_matrices(void);
void imprime_matriz_resultado(void);
void aloja_espacio_e_incializa_matrices(void);
void libera_espacio(void);
```


`main2.c`:

```
#include"definiciones2.h"
extern void dgemm_(char *transaA, char *transaB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
extern double (*matriz1)[], (*matriz2)[], (*matriz_resultado)[];
int main(void){
    char TRANSA, TRANSB;
    int M = NUM_REN_MAT1;
    int K = NUM_COL_MAT1;
    int N = NUM_COL_MAT2;
    double ALPHA, BETA;
    TRANSA = 'N';
    TRANSB = 'N';
    ALPHA = 1.0;
    BETA = 0.0;
    aloja_espacio_e_incializa_matrices();
    imprime_matrices();
    dgemm_(&TRANSA, &TRANSB, &N, &M, &K, &ALPHA, *matriz2, &N, *matriz1, &K, &BETA, *matriz_resultado, &N);
    imprime_matriz_resultado();
    libera_espacio();
return 0;
}
```

`funciones2.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones2.h" 
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
double (*matriz1)[NUM_COL_MAT1];
double (*matriz2)[NUM_COL_MAT2];
double (*matriz_resultado)[NUM_COL_MAT2];

void aloja_espacio_e_incializa_matrices(void){
...
}
void libera_espacio(void){
... 
}
void imprime_matrices(void){
...
}
void imprime_matriz_resultado(void){
...
}

```


Compila (debe estar instalado `libblas-dev` en sus sistemas):

```
$gcc main2.c funciones2.c -o programa2.out -lblas
```

Ejecuta:

```
./programa2.out
```

Investiga sobre `LAPACK`, `BLAS` y `ATLAS` y la subrutina de Fortran `dgemm` y reporta sobre esta investigación que realizas. Es una investigación corta que contiene principalmente una descripción sobre los paquetes anteriores y la subrutina.

