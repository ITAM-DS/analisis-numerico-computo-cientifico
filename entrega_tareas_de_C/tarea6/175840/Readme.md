## Tarea 6
### Miguel Rodrigo Castañeda Santiago
### CU 175840


Dirígite a la rama de master a la ruta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos).

1) Investiga\* sobre la subrutina de Fortran `dgemv` (parámetros que recibe y la salida). 

La subrutina `dgemv` realiza una de las siguientes operaciones:

1.  y := alpha*A*x + beta*y,   o   
2.  y := alpha*A**T*x + beta*y

donde 
alpha y beta son escalares
x, y son vectores 
A es una matriz de m x n

Los parámetros que recibe son

`
subroutine dgemv 	( 	character  	TRANS,
                        integer  	M,
                        integer  	N,
                        double precision  	ALPHA,
                        double precision, dimension(lda,*)  	A,
                        integer  	LDA,
                        double precision, dimension(*)  	X,
                        integer  	INCX,
                        double precision  	BETA,
                        double precision, dimension(*)  	Y,
                        integer  	INCY 
                    ) 
`

Parámetro | Descripción 
--- | ---
TRANS|Especifica el tipo de operación: `TRANS = 'N' o 'n'   y := alpha*A*x + beta*y, TRANS = 'T' o 't'   y := alpha*A**T*x + beta*y, TRANS = 'C' o 'c'   y := alpha*A**T*x + beta*y`   
M|Número de renglones de la matriz A debe ser diferente de cero 
N|Número de columnas de la matriz A debe ser diferente de cero 
ALPHA|El valor del escalar alfa
A|Un arreglo de doble precisión de dimensiones (LDA, N)
LDA|Es la rimera dimensión de A, debe ser al menos max(1,m)
X|Arreglo de doble precisión de dimensión `( 1 + ( n - 1 )*abs( INCX ) )` si TRANS es N y `( 1 + ( m - 1 )*abs( INCX ) )` en otro caso
INCX|Icremento de los elementos de X, diferente de cero
BETA|El valor del escalar beta
Y|Arreglo de doble precisión de dimensión `( 1 + ( n - 1 )*abs( INCY ) )` si TRANS es N y `( 1 + ( m - 1 )*abs( INCY ) )` en otro caso
INCY|Icremento de los elementos de Y, diferente de cero

El resultado es el vector `y`

2) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level2/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level2) ejecuta el programa `dgemv_mult_mat_vec.c` y realiza pruebas con diferentes matrices y vectores definidos por ti.


Hice una modificación al programa [`dgemv_mult_mat_vec.c`](src/dgemv_mult_mat_vec.c) para que reciba como parametros los nombres de los archivos de la matriz y el vector.

Para compilar y ejecutar el primer ejercicio, se debe ejecutar desde la carpeta `src`:

```
make clean 
make ejecuta_dgemv
```
Archivos de entrada: 

[A](src/A.txt) , [v](src/v.txt)

[Resultado](src/resultado_1.txt)

Para compilar y ejecutar el segundo ejercicio:
```
make clean 
make ejecuta_dgemv_1
```
Archivos de entrada: 

[A1](src/A1.txt) , [v1](src/v1.txt)

[Resultado](src/resultado_2.txt)

[Makefile](src/Makefile)


3) Haz un programa que utilice la subrutina `dger` de Fortran.

La subrutina `dger` realiza la operación  `A := alpha*x*y**T + A`, donde 
- alpha es un escalar
- x es un vector de m elementos
- y es un vector de n elementos 
- A es una matriz de m x n


Para compilar y ejecutar el primer ejercicio:

```
make clean 
make ejecuta_dger
```
Archivos de entrada: 

[A](src/A.txt) , [v](src/v.txt) , [w](src/w.txt)

[Resultado](src/resultado_3.txt)

[Makefile](src/Makefile)

Código fuente [`dger_mult_mat_vec.c`](src/dger_mult_mat_vec.c)


4) Después de haber estudiado  y entendido los archivos de `definiciones.h` y `funciones.c` y realizado los puntos anteriores y la tarea 5 responde: ¿cómo fue que pudimos llamar a las rutinas de Fortran (que almacena en una forma column-major order los arreglos de dos dimensiones) para operaciones con arreglos 2-dimensionales sin haber instalado CBLAS, si en clase se dijo que almacenar arreglos de dos dimensiones en C es en un row-major order? 

En el archivo `definiciones.h` está definida la entrada como column major y el archivo que se encarga de hacer la lectura de los datos en el formato que lo esperan las rutinas de Fortran es `funciones.c`


5) Investiga\* sobre la subrutina de Fortran `dgemm` (parámetros que recibe y la salida).

La subrutina `dgemm` realiza una de las siguientes operaciones:

C := alpha*op( A )*op( B ) + beta*C,

donde op (x) puede ser 

op( X ) = X  o 
op( X ) = X**T


donde:

alpha y beta son escalares
A, B y C son matrices 

Los parámetros que recibe son

`
subroutine dgemm 	( 	character  	TRANSA,
		character  	TRANSB,
		integer  	M,
		integer  	N,
		integer  	K,
		double precision  	ALPHA,
		double precision, dimension(lda,*)  	A,
		integer  	LDA,
		double precision, dimension(ldb,*)  	B,
		integer  	LDB,
		double precision  	BETA,
		double precision, dimension(ldc,*)  	C,
		integer  	LDC 
	) 	
`

Parámetro | Descripción 
--- | ---
TRANSA|Especifica op(A) , puede ser   `TRANSA = 'N' or 'n',  op( A ) = A`,  `TRANSA = 'T' or 't',  op( A ) = A**T` ,   `TRANSA = 'C' or 'c',  op( A ) = A**T`
TRANSB|Especifica op(B) , puede ser   ` TRANSB = 'N' or 'n',  op( B ) = B`,  `TRANSB = 'T' or 't',  op( B ) = B**T` ,   `TRANSB = 'C' or 'c',  op( B ) = B**T`
M|Número de renglones de la matriz op(A).
N|Número de columnas de la matriz op(B).
K|Número de columnas de la matriz op(A) más el número de renglones de la matriz op(B), K debe ser al menos cero.
ALPHA|Escalar alfa
A|Arreglo de doble precisión
LDA|La primera dimensión de A
B|Arreglo de dimensión(LDB, kb)
LDB|La primera dimensión de B
BETA|Escalar beta
C|Arreglo de dimensión (LDC, N)
LDC|La primera dimensión de C

Salida el arreglo `C`


6) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level3/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level3) ejecuta el programa `dgemm_mult_mat.c` y realiza pruebas con diferentes matrices definidas por ti.


Para compilar y ejecutar el primer ejercicio:

```
make clean 
make ejecuta_dgemm
```
Archivos de entrada: 

[A](src/AA.txt) , [B](src/B.txt)

[Resultado](src/resultado_4.txt)

Para compilar y ejecutar el segundo ejercicio con dos matrices de 10 x 10 :
```
make clean 
make ejecuta_dgemm_1
```
Archivos de entrada: 

[A](src/AA1.txt) , [B](src/BB1.txt)

[Resultado](src/resultado_5.txt)

[Makefile](src/Makefile)

Código fuente [`dgemm_mult_mat.c`](src/dgemm_mult_mat.c)


7) En la carpeta del punto anterior encuentras la sección **Multiplicación matriz-matriz con trick**. Ejecuta el programa de esta sección con diferentes matrices definidas por ti y resuelve la pregunta **¿por qué funciona este trick?**.

Para compilar y ejecutar el primer ejercicio:

```
make clean 
make ejecuta_dgemm_trick
```
Archivos de entrada: 

[A](src/AA.txt) , [B](src/B.txt)

[Resultado](src/resultado_6.txt)

Para compilar y ejecutar el segundo ejercicio con dos matrices de 10 x 10 :
```
make clean 
make ejecuta_dgemm_trick_1
```
Archivos de entrada: 

[A](src/AA1.txt) , [B](src/BB1.txt)

[Resultado](src/resultado_7.txt)

[Makefile](src/Makefile)

Código fuente [`dgemm_mult_mat.c`](src/dgemm_mult_mat.c) , [`definiciones_trick.c`](src/definiciones_trick.c)

el archivo `definiciones.h` hace el cambio de column major a row major y también se cambió la definición del llamado a la subrutina en el archivo `dgemm_mult_mat_trick.c` por lo que el truco funciona.

8) Haz un programa que utilice la subrutina `dsymm` de Fortran.

La rutina `dsymm` realiza alguna de las siguientes operaciones nivel 3 


- C := alpha*A*B + beta*C,
- C := alpha*B*A + beta*C

donde alpha, beta son escalares, A es una matriz simétrica, B y C son matrices de m x n 


Para compilar y ejecutar

```
make clean 
make ejecuta_dsymm
```
Archivos de entrada: 

[A](src/A_sym.txt) , [B](src/B_sym.txt) , [C](src/C_sym.txt)

[Resultado](src/resultado_8.txt)

[Makefile](src/Makefile)

Código fuente [`dsymm_mat_mat.c`](src/dsymm_mat_mat.c) 

Para borrar los archivos .out generados en la tarea ejecutar 

```
make clean 
```

[Makefile](src/Makefile)
