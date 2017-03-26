Alumno: 116754

# Tarea 5

## a) Investiga por qué se usan comillas en lugar de ```<>``` para el include.
El usar ```""``` nos permite utilizar librerías localmente definidas, es decir, el archivo desde donde importemos
va a incluir las funciones definidas en el archivo ```#include"archivo.h"``` que se encuentre en la misma carpeta que el primero o en otra si añadimos la ruta del segundo. Cuando usamos ```<>``` lo que hacemos es decirle al compilador que busque dicha librería en el directorio por default.

## b) Investiga el uso de ```static``` en la definición de variables externas de ```funciones.c```.
Una variable estática mantiene su valor cada vez que se invoca y además dicha variable (o función) sólo es "vista" en el archivo en el que es declarada. Es decir, aunque se haga un ```include``` de dicho archivo, no se ```importarán``` los valores de dichas variables estáticas.

## Investiga y reporta sobre ```LAPACK```, ```BLAS``` Y ```ATLAS``` y la subrutina de Fortran ```dgemm```.
```LAPACK```
Es un acrónimo de Linear Algebra PACKage, está escrito en Fortran 90 y es un clásico de las librerías de álgebra, es tan bueno que de hecho muchos lenguajes modernos como Julia lo incorporan en lugar de escribir dichas funciones. Nos otorga rutinas para resolver sistemas de ecuaciones lineales, problemas de eigenvalores, mínimos cuadrados y SVD, por ejemplo. También tiene rutinas de factorización matricial como LU, QR, Cholesky y Schur. Se pueden utilizar en matrices reales y complejas.

```BLAS```
Es un acrónimo de Basic Linear Algebra Subprograms, la cual contiene rutinas de bajo nivel para realizar operaciones comunes de álgebra lineal como suma de vectores, multiplicación de escalares, producto punto, combinaciones lineales, multiplicación de matrices y demás. Está altamente optimizado y realiza las operaciones muy rápidamente.

```ATLAS```
Es un acrónimo de Automatically Turned Linear Algebra Software y es una implementación ```oper source``` de ```BLAS``` para C y Fortran. Es una forma de generar automáticamente una librería BLAS optimizada y aunque suele no ser tan buena en performance como las librerías escritas para un hardware en particular es usualmente la primera y tal vez única implementación que podemos encontrar para sistemas nuevos y es utilizada como benchmark para productos nuevos.

```dgemm```
Es una de las subrutinas que realizan operaciones matriz-matriz generales (GEneral Matrix-Matrix computations), en particular es la que se utiliza para hacer las operaciones con tipos de datos reales de doble precisión, en comparación con ```sgemm``` para short-precision y  ```CGEMM```-``` ZGEMM``` para complejos. Todas estas realizan cualquiera de las siguientes operaciones (o sus análogos complejos) matriciales combinadas, usando escalares $\alpha$ y $\beta$, matrices *A* y *B* junto con sus transpuestas y la matriz *C*. 

*C* $leftarrow \alpha$ *AB* + $\beta$ *C*.
*C* $leftarrow \alpha$ *AB*$\text{}^T$ + $\beta$*C*.
*C* $leftarrow \alpha$ *A*$\text{}^T$*B* + $\beta$*C*.
*C* $leftarrow \alpha$ *A*$\text{}^T$*B*$\text{}^T$ + $\beta$*C*.

```latex
\alpha
```
