## Tarea 5 
#### Estudiante *167398*

### Ejercicio 1

#### a) Investiga por qué se usan `""` en la línea que tiene `include` en `main.c` y en `funciones.c` en lugar de usar `< >`.

Ambas formas lo que hacen es importar el texto de otros archivos, que suelen contener información relevante para la correcta compliación del resto del programa, por lo que suelen incorporarse al princio del programa, de allí su nombre: headers.h. La diferencia, grosso modo, es que la tradicional forma <> importa desde carpetas de la aplicación, mientras que " " importa desde el sistema de archivos del usuario.


#### b) Investiga el uso de `static` en la definición de variables externas de `funciones.c`.

Al definir **static** *variable* dentro de una función e invocarla en el *main* varias veces, sucede que el valor de *variable* nunca se resetea, conserva su último valor, por lo cual es ideoneo para concatenar operaciones como lo son, por ejemplo, las potencias de matrices.

#### c) Modifica el archivo `funciones.c` para que alojes e inicialices a las matrices `matriz1`, `matriz2` y `matriz_resultado` con `malloc` y apuntadores. Modifica `main.c` para que llame a una función dentro del archivo `funciones.c` que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa `free`).

Los cambios al código de funciones.c más relevantes son:

```
double (*matriz1)[NUM_COL_MAT1];
double (*matriz2)[NUM_COL_MAT2];
double (*matriz_resultado)[NUM_COL_MAT2]; 

void aloja_espacio_e_incializa_matrices(void){

	matriz1 = malloc(NUM_REN_MAT1*NUM_COL_MAT1*sizeof(double));
	matriz2 = malloc(NUM_REN_MAT2*NUM_COL_MAT2*sizeof(double));
	matriz_resultado = malloc(NUM_REN_MAT1*NUM_COL_MAT2*sizeof(double));
}

void libera_espacio(void){

    free(matriz1);
    free(matriz2);
    free(matriz_resultado);
}

```  

#### d. Compara tu resultado usando la subrutina de Fortran dgemm y los siguientes archivos definiciones2.h, main2.c, funciones2.c .

Se observa que los resultados son los mismos (los correctos).

#### e. Investiga sobre LAPACK, BLAS y ATLAS y la subrutina de Fortran dgemm y reporta sobre esta investigación que realizas. Es una investigación corta que contiene principalmente una descripción sobre los paquetes anteriores y la subrutina.

**BLAS**
Los subprogramas de álgebra lineal básica (BLAS) son una especificación que prescribe un conjunto de rutinas de bajo nivel para realizar operaciones de álgebra lineal comunes tales como adición de vectores, multiplicación escalar, productos de puntos, combinaciones lineales y multiplicación matricial. Son las rutinas estándar de facto de bajo nivel para bibliotecas de álgebra lineal; Las rutinas tienen enlaces para C y Fortran. Aunque la especificación BLAS es general, las implementaciones BLAS a menudo se optimizan para la velocidad en una máquina en particular, por lo que su uso puede aportar beneficios de rendimiento sustanciales. Las implementaciones de BLAS se aprovecharán del hardware de punto flotante especial, como registros vectoriales o instrucciones SIMD.
https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms

**LAPACK**
LAPACK (Linear Algebra Package) es una biblioteca de software estándar para álgebra lineal numérica. Proporciona rutinas para resolver sistemas de ecuaciones lineales y mínimos cuadrados lineales, problemas de valores propios y descomposición de valores singulares. También incluye rutinas para implementar las factorizaciones de matriz asociadas tales como LU, QR, Cholesky y descomposición de Schur. LAPACK fue originalmente escrito en FORTRAN 77.
https://en.wikipedia.org/wiki/LAPACK


**ATLAS**
El software de álgebra lineal sintonizado automáticamente (ATLAS) es una biblioteca de software para álgebra lineal. Proporciona una implementación madura de código abierto de las API de BLAS para C y Fortran77.
https://en.wikipedia.org/wiki/Automatically_Tuned_Linear_Algebra_Software


**DGEMM**  
Operación Matrix-matrix:

    C := alpha*op( A )*op( B ) + beta*C,

 where  op( X ) is one of

    op( X ) = X   or   op( X ) = X**T,

 alpha and beta are scalars, and A, B and C are matrices, with op( A )
 an m by k matrix,  op( B )  a  k by n matrix and  C an m by n matrix.