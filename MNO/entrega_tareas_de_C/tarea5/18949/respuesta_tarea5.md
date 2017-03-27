# Tarea 5

- Autor: Javier Quiroz

Se entrega el lunes 27 de marzo. De forma individual crear una carpeta con nombre igual a su clave única, debajo del nivel: 

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

```
Observa los resultados al ejecutar el `programa.out` y realiza lo siguiente:

a) Investiga por qué se usan `""` en la línea que tiene `include` en `main.c` y en `funciones.c` en lugar de usar `< >`. 
```
***Respuesta:*** 

Cuando se utilizan los caracteres '< >' es cuando se quieren usar los header files parte de la libreria del lenguaje c. En este caso definciones.h es parte del programa que estamos construyendo. definiciones.h nos permite simplificar el proceso de dividir un programa en varios archivos fuente y comunicar definicioes de funciones o variables. Es una facilidad del compilador del lenguaje C. 

```
b) Investiga el uso de `static` en la definición de variables externas de `funciones.c`.
```
***Respuesta:***

Las variables declaradas con static:

1) Conservan su valor entre invocaciones si son definidas desde en una función. Se comportan como globales pero solo son visibles dentro de la funcion en la que fueron definidas.

2) Cuando son declarados como globales en un archivo c. Solo son visibles dentro de ese archivo.

3) Cuando se usan con una declaracion de funcion, tienen el efecto de que la funcion no es visible fuera del archivo c donde fue definida.

```
c) Modifica el archivo `funciones.c` para que alojes e inicialices a las matrices `matriz1`, `matriz2` y `matriz_resultado` con `malloc` y apuntadores. Modifica `main.c` para que llame a una función dentro del archivo `funciones.c` que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa `free`): 
```
***Respuesta:***
```
Se han modificado los programas funciones1.c y main1.c. Se muestra el código a continuacion. La salida en la ejecucion de estos nuevos progrmas es identica.

```
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
```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double matriz1_init[NUM_REN_MAT1][NUM_COL_MAT1]={
        {0, 1.5},
        {4, -5},
        {-1, 2.5}
    };
static double matriz2_init[NUM_REN_MAT2][NUM_COL_MAT2]={
        {1, 0, 0},
        {0, -1, 1}
    };

static double (*matriz1)[NUM_COL_MAT1];
static double (*matriz2)[NUM_COL_MAT2];
static double (*matriz_resultado)[NUM_COL_MAT2];

void  aloja_espacio_e_incializa_matrices(){
    
	matriz1 = malloc(NUM_REN_MAT1 * NUM_COL_MAT1 * sizeof(double  ));
	for(i=0;i<NUM_REN_MAT1;i++) {//el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
		for(j=0;j<NUM_COL_MAT1;j++)
			matriz1[i][j] = matriz1_init[i][j];
	}
	
	matriz2 =   malloc(NUM_REN_MAT2 * NUM_COL_MAT2* sizeof(double ) );
	for(i=0;i<NUM_REN_MAT2;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
		for(j=0;j<NUM_COL_MAT2;j++)
			matriz2[i][j] = matriz2_init[i][j];	
    }
    
	matriz_resultado = malloc(NUM_REN_MAT1 * NUM_COL_MAT2 * sizeof(double) );
}

void imprime_matrices(void){
	printf("Matriz1\n");
		for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
		for(j=0;j<NUM_COL_MAT1;j++){
			if(j<NUM_COL_MAT1-1)
				printf("matriz1[%d][%d]=%4.2f\t",i,j, matriz1[i][j] )  ;
			else
				printf("matriz1[%d][%d]=%4.2f\n",i,j, matriz1[i][j]); 
		}
	}
	printf("\n");

	printf("Matriz2\n");
		for(i=0;i<NUM_REN_MAT2;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
					printf("matriz2[%d][%d]=%4.2f\t",i,j,matriz2[i][j] );
				else
					printf("matriz2[%d][%d]=%4.2f\n",i,j, matriz2[i][j] );
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

void  libera_espacio(void){
	free(matriz1);
	free(matriz2);
	free(matriz_resultado);
}
```
```
d) Compara tu resultado usando la subrutina de Fortran `dgemm` y los siguientes archivos `definiciones2.h`, `main2.c`, `funciones2.c`:
```
***Respuesta***
Al modifcarse los programas y usar la version de funciones1.c (sin el uso de static para que puedan ser usadads desde main2.c), la salida fue identica.Al medir la ejecucion de los programas con el comando time de ubuntu se obtuvo la siguiente salida. En ella se puede ver que los tiempos de ejecucion fueron identicos, pero con variaciones utilizacion de CPU. El tamaño de las matrices no es muy util para poder ahondar en el tema

```
➜  tarea5 time ./programa.out 
Matriz1
matriz1[0][0]=0.00	matriz1[0][1]=1.50
matriz1[1][0]=4.00	matriz1[1][1]=-5.00
matriz1[2][0]=-1.00	matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00	matriz2[0][1]=0.00	matriz2[0][2]=0.00
matriz2[1][0]=0.00	matriz2[1][1]=-1.00	matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00	matriz_res[0][1]=-1.50	matriz_res[0][2]=1.50
matriz_res[1][0]=4.00	matriz_res[1][1]=5.00	matriz_res[1][2]=-5.00
matriz_res[2][0]=-1.00	matriz_res[2][1]=-2.50	matriz_res[2][2]=2.50

./programa.out  0.00s user 0.00s system 77% cpu 0.001 total
➜  tarea5 time ./programa1.out
Matriz1
matriz1[0][0]=0.00	matriz1[0][1]=1.50
matriz1[1][0]=4.00	matriz1[1][1]=-5.00
matriz1[2][0]=-1.00	matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00	matriz2[0][1]=0.00	matriz2[0][2]=0.00
matriz2[1][0]=0.00	matriz2[1][1]=-1.00	matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00	matriz_res[0][1]=-1.50	matriz_res[0][2]=1.50
matriz_res[1][0]=4.00	matriz_res[1][1]=5.00	matriz_res[1][2]=-5.00
matriz_res[2][0]=-1.00	matriz_res[2][1]=-2.50	matriz_res[2][2]=2.50

./programa1.out  0.00s user 0.00s system 64% cpu 0.002 total
➜  tarea5 time ./programa2.out
Matriz1
matriz1[0][0]=0.00	matriz1[0][1]=1.50
matriz1[1][0]=4.00	matriz1[1][1]=-5.00
matriz1[2][0]=-1.00	matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00	matriz2[0][1]=0.00	matriz2[0][2]=0.00
matriz2[1][0]=0.00	matriz2[1][1]=-1.00	matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00	matriz_res[0][1]=-1.50	matriz_res[0][2]=1.50
matriz_res[1][0]=4.00	matriz_res[1][1]=5.00	matriz_res[1][2]=-5.00
matriz_res[2][0]=-1.00	matriz_res[2][1]=-2.50	matriz_res[2][2]=2.50

./programa2.out  0.00s user 0.00s system 75% cpu 0.002 total

```

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
#include"definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double matriz1_init[NUM_REN_MAT1][NUM_COL_MAT1]={
        {0, 1.5},
        {4, -5},
        {-1, 2.5}
    };
static double matriz2_init[NUM_REN_MAT2][NUM_COL_MAT2]={
        {1, 0, 0},
        {0, -1, 1}
    };

double (*matriz1)[NUM_COL_MAT1];
double (*matriz2)[NUM_COL_MAT2];
double (*matriz_resultado)[NUM_COL_MAT2];

void  aloja_espacio_e_incializa_matrices(){
    
	matriz1 = malloc(NUM_REN_MAT1 * NUM_COL_MAT1 * sizeof(double  ));
	for(i=0;i<NUM_REN_MAT1;i++) {//el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
		for(j=0;j<NUM_COL_MAT1;j++)
			matriz1[i][j] = matriz1_init[i][j];
	}
	
	matriz2 =   malloc(NUM_REN_MAT2 * NUM_COL_MAT2* sizeof(double ) );
	for(i=0;i<NUM_REN_MAT2;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
		for(j=0;j<NUM_COL_MAT2;j++)
			matriz2[i][j] = matriz2_init[i][j];	
    }
    
	matriz_resultado = malloc(NUM_REN_MAT1 * NUM_COL_MAT2 * sizeof(double) );
}

void imprime_matrices(void){
	printf("Matriz1\n");
		for(i=0;i<NUM_REN_MAT1;i++){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
		for(j=0;j<NUM_COL_MAT1;j++){
			if(j<NUM_COL_MAT1-1)
				printf("matriz1[%d][%d]=%4.2f\t",i,j, matriz1[i][j] )  ;
			else
				printf("matriz1[%d][%d]=%4.2f\n",i,j, matriz1[i][j]); 
		}
	}
	printf("\n");

	printf("Matriz2\n");
		for(i=0;i<NUM_REN_MAT2;i++){
			for(j=0;j<NUM_COL_MAT2;j++){
				if(j<NUM_COL_MAT2-1)
					printf("matriz2[%d][%d]=%4.2f\t",i,j,matriz2[i][j] );
				else
					printf("matriz2[%d][%d]=%4.2f\n",i,j, matriz2[i][j] );
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

void  libera_espacio(void){
	free(matriz1);
	free(matriz2);
	free(matriz_resultado);
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

***Respuesta***


LAPACK es una biblioteca de funciones para escrita para resolver problemas de algebra lineal numérica. Fue escrita originalmente en Fortran77 y ha ido evolucionando de forma que hoy explota las arquitecturas cache modernas de hardware. Entre las funciones que provee se encuentran: resolución de sistemas de ecuaciones lineales, mínimos cuadrados, eigenvalores y descomposición en valores singulares. Incluye, tambien, rutinas para resolver problemas de factorizaciones matriciales como LU, QR, Cholevsky y Schur. Las implementaciones modernas han sido alineadas siguiendo la especificación BLAS (Basic Linear ALgebra Subprograms).

BLAS es un estandard de factor que permite que programas que son escritos siguiendo la especificación pueden aprovechar las diferentes implementaciones. La estructura de BLAS refleja un grupo de funciones que cronologicamente se fueron implementando en niveles (Levels): En el nivel tres encontramos la multiplicacón matricial generalizada (General Matrix Multipication, gemm) y algunas otras operaciones similares.

En nuestro caso en programa2 utilizamos gemm de la implementacion de la biblioteca blas de Ubuntu para ejecutar una multiplicacion matricial.
