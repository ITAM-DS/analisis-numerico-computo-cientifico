# Tarea 5

## 1. Observa los resultados al ejecutar el programa.out y realiza lo siguiente:

### a) Investiga por qué se usan "" en la línea que tiene include en main.c y en funciones.c en lugar de usar < >.

Al usar las comillas el compilador busca el archivo primero en el mismo directorio donde corremos el programa. Al usar < > busca los archivos en todos los directorios. 

### b) Investiga el uso de static en la definición de variables externas de funciones.c.

La variable estática no se pierde aunque el programa haya salido de la función en que la variable fue definida. En funciones.c se definen las variables estaticas para poderlas usarlas en el main.c 

### c) Modifica el archivo funciones.c para que alojes e inicialices a las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. Modifica main.c para que llame a una función dentro del archivo funciones.c que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa free):

funciones.c

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;
    
void aloja_espacio_e_incializa_matrices(void){

    matriz1 = malloc(NUM_REN_MAT1*sizeof(double));
    for(i=0; i<NUM_REN_MAT1; i++)
        *(matriz1 + i) = malloc(NUM_COL_MAT1  * sizeof(double));

    *(*(matriz1+0)+0)=0;
    *(*(matriz1+0)+1)=1.5;
    *(*(matriz1+1)+0)=4;
    *(*(matriz1+1)+1)=-5;
    *(*(matriz1+2)+0)=-1;
    *(*(matriz1+2)+1)=2.5;

    matriz2 = malloc(NUM_REN_MAT2*sizeof(double));
    for(i=0; i<NUM_REN_MAT2; i++)
        *(matriz2+i) = malloc(NUM_COL_MAT2*sizeof(double));

    *(*(matriz1+0)+0)=1;
    *(*(matriz1+0)+1)=0;
    *(*(matriz1+0)+2)=0;
    *(*(matriz1+1)+0)=0;
    *(*(matriz1+1)+1)=-1;
    *(*(matriz1+1)+2)=1;

    matriz_resultado = malloc(NUM_REN_MAT1*sizeof(double));
    for(i=0; i<NUM_REN_MAT1; i++)
        *(matriz_resultado+i) = malloc(NUM_COL_MAT2*sizeof(double));
}

void libera_espacio(void){

    free(matriz1);
    free(matriz2);
    free(matriz_resultado);
}

void imprime_matrices(void){
...
}

void imprime_matriz_resultado(void){
...
}

void multiplica_matrices(void){
...
}
```

main.c:

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

### d) Compara tu resultado usando la subrutina de Fortran dgemm y los siguientes archivos definiciones2.h, main2.c, funciones2.c:

El resultado debería ser el mismo, pero no me sale la matriz resultado.

Cambíe las variables externas de la función2.c

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones2.h" 
//definiciones de variables que serán externas
static int i=0,j=0, k=0;
double **matriz1;
double **matriz2;
double **matriz_resultado;

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


#### Investiga sobre LAPACK, BLAS y ATLAS y la subrutina de Fortran dgemm 

##### LAPACK

Esta escrito en Fortran 90 y contiene rutinas para resolver sistemas de ecuaciones lineales simultáneas, soluciones de mínimos cuadrados de sistemas lineales, problemas de valores propios y problemas de valores singulares. También se proporcionan las factorizaciones de matriz asociadas (LU, Cholesky, QR, SVD, ...) así como cálculos relacionados como el reordenamiento de las factorizaciones de Schur y la estimación de números de condición. Matrices densas y con bandas son manejadas, pero no matrices dispersas generales. En todas las áreas, se proporciona una funcionalidad similar para matrices reales y complejas, tanto en simple como en doble precisión.

LAPACK reorganiza los algoritmos para utilizar las operaciones de matrices de bloques, como la multiplicación matricial, en los bucles más internos. Estas operaciones de bloques se pueden optimizar para que cada arquitectura tenga en cuenta la jerarquía de memoria, y así proporcionar una forma transportable para lograr una alta eficiencia en diversas máquinas modernas.

Las rutinas de LAPACK se escriben de modo que todo lo posible de la computación se realice mediante llamadas a los Subprogramas de Álgebra Lineal Básica (BLAS). Las implementaciones altamente específicas de la BLAS están disponibles para muchas computadoras modernas de alto rendimiento. 

##### BLAS

BLAS (Basic Linear Algebra Subprograms) son rutinas que proveen son rutinas que proporcionan bloques de construcción estándar para realizar operaciones básicas de vector y matriz. BLAS de nivel 1 realizan operaciones vector-matriz y el nivel 3 de BLAS realiza operaciones matriz-matriz. Debido a que BLAS es eficiente, portátil y está ampliamente disponible, se utiliza comúnmente en el desarrollo de software de álgebra lineal de alta calidad, LAPACK, por ejemplo.

##### ATLAS

ATLAS (Automatically Tuned Linear Algebra Software) es una biblioteca de software para álgebra lineal. Proporciona una implementación madura de código abierto de las API de BLAS para C y Fortran77.

ATLAS es a menudo recomendado como una forma de generar automáticamente una biblioteca optimizada BLAS. A pesar de que su rendimiento suele superar el de las bibliotecas especializadas escritas para una plataforma de hardware específica, a menudo es la primera o incluso optimizada implementación de BLAS disponible en nuevos sistemas y es una gran mejora con respecto al BLAS genérico disponible en Netlib. Por esta razón, ATLAS se utiliza a veces como una base de referencia de rendimiento para la comparación con otros productos.

También proporciona una implementación para LAPACK.

##### Subrutina Fortran dgemm

DGEMM es un simple multi-threaded, realiza oerpaciones matriz-matriz densas de un punto de referencia. El código está diseñado para medir la tasa de computación sostenida de punto flotante de un único nodo.
El punto de referencia DGEMM se utilizará para comparar cada tipo de nodo destinado al cálculo en el sistema propuesto. Si un nodo dado tiene opciones configurables, el punto de referencia se utilizará para informar el rendimiento de cada configuración.