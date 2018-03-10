## Tarea 5
### Miguel Rodrigo Castañeda Santiago
### CU 175840


1) Estudia y entiende los archivos ```definiciones.h``` y ```funciones.c``` de ahí, en particular investiga por qué se usan `""` en la línea que tiene `#include` en `funciones.c` en lugar de usar `< >`. Investiga el uso de `static` en la definición de variables externas de `funciones.c` .

* El archivo ```definiciones.h```  contiene los prototipos de las functiones y estructuras usadas en el archivo ```funciones.c``` donde 
se encuentra la implementación de los protipos, la línea de `#include` en  `funciones.c` usa  `""` para indicar al preprocesador que debe buscar el archivo primero en la ruta actual y luego en la ruta definida por el compilador, esto se usa para incluir "header files" definidos por el usuario. El uso de `static` limita el alcance de un objeto al resto del archivo de código que será compilado, es una forma de encapsular el objeto. 


2) Investiga\* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigación que realizas. Es una investigación que contiene principalmente una descripción sobre los paquetes y niveles anteriores.

* *BLAS*, Basic Linear Algebra Subprograms en una biblioteca con rutinas escritas en Fortran que permiten realizar operaciones básicas de vectores y matrices. El nivel 1 BLAS realiza operaciones de escalares, vectores y vector - vector.
El nivel 2 BLAS realiza operaciones de matriz - vector. 
El nivel 3 BLAS realiza operaciones matriz - matriz.

* *CBLAS*, es una interfaz escrita en C para acceder a las rutinas de BLAS escritas en Fortran.

* *LAPACK*, Linar Algebra Package, es una biblioteca escrita en Fortran que provee rutinas para la solución de sistemas de ecuaciones lineales, mínimos cuadrados, problemas de eigenvalores y problemas de valores singulares, explota el nivel 3 de BLAS.

* *ATLAS*, Automatically Tuned Linear Algebra Software, provee rutinas optimizadas de la biblioteca BLAS y LAPACK. 


3) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level1) ejecuta el programa `dot_product.c` y realiza pruebas con diferentes vectores definidos por ti.


Se modificó el programa [dot_product.c](dot_product.c) para que reciba como parámetros desde la línea de comandos el tamño de los vectores, el nombre de los archivos de los vectores y una bandera si debe imprimir los vectores originales. 

Para las pruebas se usan

Para el ejemplo de un vector de dimensión = 3

```
make clean 
make ejecuta
```
[Makefile](Makefile)

Resultado 

[resultado1.txt](resultado1.txt)

Para el ejemplo de un vector de dimensión = 20

```
make clean 
make ejecuta1
```
[Makefile](Makefile)

Resultado 

[resultado2.txt](resultado2.txt)

Para el ejemplo de un vector de dimensión = 100, dado el tamaño de los vectores de entrada, en este caso se uso la bandera imprime = 0 para que solo mostrara el resultado

```
make clean 
make ejecuta2
```
[Makefile](Makefile)

Resultado 

[resultado3.txt](resultado3.txt)


4) Investiga\* sobre la subrutina de Fortran `ddot` (parámetros que recibe y la salida).

* La subrutina  `ddot` realiza el producto punto entre dos vectores, los parametros que recibe son: 

```
double precision function ddot 	( integer  	N,
		                          double precision, dimension(*)  	DX,
		                          integer  	INCX,
		                          double precision, dimension(*)  	DY,
		                          integer  	INCY 
	) 	

```
Entrada: 
* N      número de elementos de los vectores de entrada
* DX     Arreglo de tamaño al menos (1+(n-1)*abs(INCX))
* INCX   Especifica el incremento para los elementos de x
* DY     Arreglo de tamaño al menos (1+(n-1)*abs(INCY))
* INCY   Especifica el incremento para los elementos de y

Salida:
* Producto punto.


5) Haz un programa que utilice la subrutina `daxpy` de Fortran.

La subrutina `daxpy` calcula y := alpha * x + y

Programa
[programa_daxpy.c](programa_daxpy.c)

Para el ejemplo de un vector de dimensión = 3 se debe compilar con

```
make clean 
make ejecuta_daxpy
```
[Makefile](Makefile)

Resultado 

[resultado4.txt](resultado4.txt)
