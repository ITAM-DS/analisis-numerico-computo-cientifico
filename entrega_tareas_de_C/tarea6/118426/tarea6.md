# Tarea 6
# RAFAEL LARRAZOLO, 118426


1) Investiga\* sobre la subrutina de Fortran `dgemv` (parámetros que recibe y la salida). 

La subrutina `dgemv` puede realizar una de las siguientes operaciones matriz-vector:

```
y = alpha*A*x + beta*y  ó
y = alpha*A**T*x + beta*y,

donde alpha y beta son escalares; x e y son vectores; A es una matriz de dimensión mxn.
```

Los parámetros de entrada son:

| PARÁMETRO |  TIPO  	  				|   DESCRIPCIÓN  | 
|-----------|---------------------------|----------------|
|  TRANS	|	caracter   				| Qué operación realizar|
|  	M  		|   entero     				| Filas de la matriz A |
|  	N  		|   entero     				| Columnas de la matriz A |
|  	alpha  	|   doble prec.     		| Valor del escalar |
|  	A  		|   arreglo doble prec.    	| Matriz |
|  	LDA  	|   entero     				| Indica la primer dimensión de A |
|  	X  		|   arreglo doble prec.    	| Vector para la operación|
|  	INCX  	|   entero    				| Incrementos para los elementos de X |
|  	beta  	|   doble prec.    			| Valor del escalar |
|  	Y  		|   arreglo doble prec.    	| Vector para la operación|
|  	INCY  	|   entero    				| Incrementos para los elementos de Y |

La salida es el vector `y`, que es sobre-escrito después de ser parámetro de entrada:

```
y = alpha*A*x + beta*y cuando TRANS = 'N' ó 'n'
y = alpha*A**T*x + beta*y cuando TRANS = 'T' ó 't'

```


2) Ejecuta el programa `dgemv_mult_mat_vec.c` y realiza pruebas con diferentes matrices y vectores definidos por ti.

Para este ejercicio hice dos pruebas.

En la primera definí la siguiente matriz y vector:

```
A1.txt
-1 3
2 -5
7 -11
9 4

v1.txt
5
-2
8
9
```

Ejecutando con el siguiente comando:

```
./ejercicio2.out 2 4
```

Y se obtuvo como salida:

```
matriz 1:
matriz[0][0]=-1.00000	matriz[0][1]=3.00000	matriz[0][2]=2.00000	matriz[0][3]=-5.00000
matriz[1][0]=7.00000	matriz[1][1]=-11.00000	matriz[1][2]=9.00000	matriz[1][3]=4.00000
------------
vector :
vector[0]=5.00000
vector[1]=-2.00000
vector[2]=8.00000
vector[3]=9.00000
------------
vector resultado:
vector[0]=-40.00000
vector[1]=165.00000

```

En un segundo ejemplo, definí la siguiente matriz y vector:

```
A2.txt
10 9 8 
7 6 5
5 4 3
2 1 0
-1 -3 -5
-7 -9 -10

v2.txt
1
0
-1
2
-2
5
```

Ejecutando con el siguiente comando:

```
./ejercicio2.out 5 3
```

Y se obtuvo como salida:

```
matriz 1:
matriz[0][0]=10.00000	matriz[0][1]=9.00000	matriz[0][2]=8.00000
matriz[1][0]=7.00000	matriz[1][1]=6.00000	matriz[1][2]=5.00000
matriz[2][0]=5.00000	matriz[2][1]=4.00000	matriz[2][2]=3.00000
matriz[3][0]=2.00000	matriz[3][1]=1.00000	matriz[3][2]=0.00000
matriz[4][0]=-1.00000	matriz[4][1]=-3.00000	matriz[4][2]=-5.00000
------------
vector :
vector[0]=1.00000
vector[1]=0.00000
vector[2]=-1.00000
------------
vector resultado:
vector[0]=2.00000
vector[1]=2.00000
vector[2]=2.00000
vector[3]=2.00000
vector[4]=4.00000
```

Por lo que vemos que los parámetros definidos determinan el número de filas y columnas de la matriz respectivamente. El programa realiza la operación `y = A*x` donde `A` es matriz y `x` e `y` son vectores.


3) Haz un programa que utilice la subrutina `dger` de Fortran.

Hice el programa `ejercicio3.c` el cual toma como input el archivo `B.txt` (que será la matriz). La forma del archivo la hice de manera intensional para ver cómo se comportaría el programa y de qué manera acomodaría dichos datos en una matriz.

```
B.txt
1 2 3 4 5 6 7 8 9
10 11 12
```

y los archivos `v1.txt`, `v2.txt` que contienen:

```
v1.txt
1
0
-3

v2.txt
5
8
9
``` 

Compilé el programa y ejecuté el mismo:

```
gcc -Wall ejercicio3.c funciones.c -o ejercicio3.out -lblas
./ejercicio3.out 2 4 5 6
```

Los parámetros tienen las siguientes interpretaciones:

```
2 : Número de filas de la matriz; número de elementos del vector y. 
4 : Número de columnas de la matriz; número de elementos del vector x.
5 : valor de alpha.
6 : valor de beta.
```

El programa ejecuta la operación `y:=alpha*A*x + beta*y`, obteniendo el siguiente output:

```
------------
alpha :
5.000000
------------
beta :
6.000000
------------
vector 1:
vector[0]=1.00000
vector[1]=0.00000
vector[2]=-3.00000
vector[3]=0.00000
------------
vector 2:
vector[0]=5.00000
vector[1]=8.00000
------------
matriz :
matriz[0][0]=1.00000	matriz[0][1]=2.00000	matriz[0][2]=3.00000	matriz[0][3]=4.00000
matriz[1][0]=5.00000	matriz[1][1]=6.00000	matriz[1][2]=7.00000	matriz[1][3]=8.00000
-------------
-------------
Matriz resultado : 
vector[0]=-10.00000
vector[1]=-32.00000
-------------
```

4) Después de haber estudiado  y entendido los archivos de `definiciones.h` y `funciones.c` y realizado los puntos anteriores y la tarea 5 responde: ¿cómo fue que pudimos llamar a las rutinas de Fortran (que almacena en una forma column-major order los arreglos de dos dimensiones) para operaciones con arreglos 2-dimensionales sin haber instalado CBLAS, si en clase se dijo que almacenar arreglos de dos dimensiones en C es en un row-major order? 

Fue gracias al cambio hecho en el archivo `definiciones.h` donde se usa **column_major order** para realizar la lectura de la matriz.

5) Investiga\* sobre la subrutina de Fortran `dgemm` (parámetros que recibe y la salida).

La subrutina `dgemm` puede realizar una de las siguientes operaciones matriz-matriz:

```
C := alpha*op( A )*op( B ) + beta*C,

donde op(X) puede ser:

    op( X ) = X   ó   op( X ) = X**T,

	alpha y beta son escalares,
	A, B y C son matrices, con 
		op( A ) una matriz (m,k), 
		op( B ) una matriz (k,n), y
		C una matriz (m,n).

```

Los parámetros de entrada son:

| PARÁMETRO |  TIPO  	  				|   DESCRIPCIÓN  | 
|-----------|---------------------------|----------------|
|  TRANSA	|	caracter   				| Especifica la forma de op(A)|
|  TRANSB	|	caracter   				| Especifica la forma de op(B)|
|  	M  		|   entero     				| Filas de A y C |
|  	N  		|   entero     				| Columnas de B y C |
|  	K  		|   entero     				| Columnas de op(A) y filas de op(B) |
|  	alpha  	|   doble prec.     		| Valor del escalar |
|  	A  		|   arreglo doble prec.    	| Matriz |
|  	LDA  	|   entero     				| Indica la primer dimensión de A |
|  	B  		|   arreglo doble prec.    	| Matriz |
|  	LDB  	|   entero     				| Indica la primer dimensión de B |
|  	beta  	|   doble prec.    			| Valor del escalar |
|   C  		|   arreglo doble prec.    	| Matriz |
|  	LDC  	|   entero     				| Indica la primer dimensión de C |

La salida es la matriz `C`, que es sobre-escrita después de ser parámetro de entrada:

```
C := alpha*op( A )*op( B ) + beta*C, donde

	          op( A ) = A , si TRANSA = 'N' ó 'n'.

              op( A ) = A**T, si TRANSA = 'T' ó 't'.

              op( A ) = A**T, si TRANSA = 'C' ó 'c'.
 y

 	          op( B ) = B , si TRANSB = 'N' ó 'n'.

              op( B ) = B**T, si TRANSB = 'T' ó 't'.

              op( B ) = B**T, si TRANSB = 'C' ó 'c'.

```


6) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level3/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level3) ejecuta el programa `dgemm_mult_mat.c` y realiza pruebas con diferentes matrices definidas por ti.

Para este ejercicio realicé tres corridas distintas:

+ En la primera, utilicé las matrices originales del ejercicio:

```
A.txt

0 1.5
4 -5
-1 2.5

B.txt

1 0 0
0 -1 1
```

Ejecuté el programa utilizando:

```
./programa.out 1 2 1 3
```

Obteniendo como salida:

```
matriz 1:
matriz[0][0]=0.00000	matriz[0][1]=1.50000
------------
matriz 2:
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=-1.00000	matriz[1][2]=1.00000
------------
matriz resultado:
matriz[0][0]=0.00000	matriz[0][1]=-1.50000	matriz[0][2]=1.50000

```


Después lo ejecuté con:

```
./programa.out 2 4 1 2
```

Resultando:

```
matriz 1:
matriz[0][0]=0.00000	matriz[0][1]=1.50000	matriz[0][2]=4.00000	matriz[0][3]=-5.00000
matriz[1][0]=-1.00000	matriz[1][1]=2.50000	matriz[1][2]=0.00000	matriz[1][3]=0.00000
------------
matriz 2:
matriz[0][0]=1.00000	matriz[0][1]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=0.00000
matriz[2][0]=-1.00000	matriz[2][1]=1.00000
matriz[3][0]=0.00000	matriz[3][1]=0.00000
------------
matriz resultado:
matriz[0][0]=-4.00000	matriz[0][1]=4.00000
matriz[1][0]=-1.00000	matriz[1][1]=0.00000
```

Notando que el primer parámetro determina el número de filas para la matrices 1 y 3; el segundo parámetro indica el número de filas para la matriz 2 y las columnas de la matriz 1. El tercer parámetro, aparentemente, no influye en los cálculos; y el cuarto parámetro determina el número de columnas de las matrices 2 y 3.

+ En la segunda prueba, utilicé las matrices:

```
A1.txt

8 -1 4 -3
0 2 4 8
-1 -2 4 -6
0 1 -1 1

B1.txt
1 2
3 -4

```

Y corrí el programa con:
```
./programa.out 2 3 1 2

```

Obtiendo como salida:

```
matriz 1:
matriz[0][0]=8.00000	matriz[0][1]=-1.00000	matriz[0][2]=4.00000
matriz[1][0]=-3.00000	matriz[1][1]=0.00000	matriz[1][2]=2.00000
------------
matriz 2:
matriz[0][0]=1.00000	matriz[0][1]=2.00000
matriz[1][0]=3.00000	matriz[1][1]=-4.00000
matriz[2][0]=0.00000	matriz[2][1]=0.00000
------------
matriz resultado:
matriz[0][0]=5.00000	matriz[0][1]=20.00000
matriz[1][0]=-3.00000	matriz[1][1]=-6.00000
```

Con este ejemplo nos damos cuenta que el programa "lee" las matrices dato a dato y no como las visualizamos. Por ejemplo, el elemento [1][0] de la matriz 1 tiene valor -3, el cual en el archivo `A1.txt` estaba en otra posición aparentemente.

+ Como último ejemplo, utilicé los siguientes archivos para considerarse como matrices:

```
A2.txt
1 2 3 0 1 4
5 6 0

B2.txt
-24 18
5 20
-15 -4 -5
4 1

```

Y lo ejecuté con siguiente comando para que los datos en los archivos de entrada fueran considerados como matrices de dimensión 3x3. 

```
./ejercicio6.out 3 3 1 3
``` 

Obteniendo como salida:

```
matriz 1:
matriz[0][0]=1.00000	matriz[0][1]=2.00000	matriz[0][2]=3.00000
matriz[1][0]=0.00000	matriz[1][1]=1.00000	matriz[1][2]=4.00000
matriz[2][0]=5.00000	matriz[2][1]=6.00000	matriz[2][2]=0.00000
------------
matriz 2:
matriz[0][0]=-24.00000	matriz[0][1]=18.00000	matriz[0][2]=5.00000
matriz[1][0]=20.00000	matriz[1][1]=-15.00000	matriz[1][2]=-4.00000
matriz[2][0]=-5.00000	matriz[2][1]=4.00000	matriz[2][2]=1.00000
------------
matriz resultado:
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=1.00000	matriz[1][2]=0.00000
matriz[2][0]=0.00000	matriz[2][1]=0.00000	matriz[2][2]=1.00000
```

Con lo que observamos que el programa realiza una multiplicación de matrices y que las matrices ingresadas resultan ser la matriz inversa de la otra, obteniendo como resultado la identidad `I_3`.


7) En la carpeta del punto anterior encuentras la sección **Multiplicación matriz-matriz con trick**. Ejecuta el programa de esta sección con diferentes matrices definidas por ti y resuelve la pregunta **¿por qué funciona este trick?**.

Utilicé las mismas matrices e instrucciones que en el ejercicio anterior obteniendo los mismos resultados de salida. Únicamente para ejemplificar, incluyo el último ejemplo del ejercicio anterior:

```
A2.txt
1 2 3 0 1 4
5 6 0

B2.txt
-24 18
5 20
-15 -4 -5
4 1

```

Ejecuntándolo con el comando 

```
./ejercicio7.out 3 3 1 3
``` 

Obteniendo como salida:

```
matriz 1:
matriz[0][0]=1.00000	matriz[0][1]=2.00000	matriz[0][2]=3.00000
matriz[1][0]=0.00000	matriz[1][1]=1.00000	matriz[1][2]=4.00000
matriz[2][0]=5.00000	matriz[2][1]=6.00000	matriz[2][2]=0.00000
------------
matriz 2:
matriz[0][0]=-24.00000	matriz[0][1]=18.00000	matriz[0][2]=5.00000
matriz[1][0]=20.00000	matriz[1][1]=-15.00000	matriz[1][2]=-4.00000
matriz[2][0]=-5.00000	matriz[2][1]=4.00000	matriz[2][2]=1.00000
------------
matriz resultado:
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000
matriz[1][0]=0.00000	matriz[1][1]=1.00000	matriz[1][2]=0.00000
matriz[2][0]=0.00000	matriz[2][1]=0.00000	matriz[2][2]=1.00000
```

Efectivamente vemos que los resultados son iguales que en el ejercicio 6. Este **trick** funciona ya que en el archivo `definiciones.h` usado en esta ocasión tiene una modificación en donde se almacena por row-major; mientras tanto, en el programa `dgemm_mult_mat_trick.c` se invierten los llamados de las filas y columnas, i.e., en la línea:

`dgemm_("No transpose", "No transpose", &N, &M, &K, &ALPHA, entradas(B), &N, entradas(A), &K, &BETA, entradas(C), &N)`

usamos las columnas (N) en las filas (M) y viceversa a diferencia del ejercicio anterior donde se lee la matriz por column-major y se usan filas y columnas donde lo 'requiere' la función `dgemm`.

8) Haz un programa que utilice la subrutina `dsymm` de Fortran.

Hice el programa llamado `ejercicio8.c`. Este programa ejecuta la subrutina `dsymm`, el cual para este caso particular calcula:

```
C := alpha*A*B + beta*C, 

	donde A es una matriz MxM,
		  B es una matriz MxN,
		  C es una matriz MxN,
		  alpha y beta escalares.
```

Los archivos de entrada, que sirven para determinar las matrices necesarias, son:

```
A.txt
0 1 2 3 4 
5 6 7 8 9
9 8 7 6 5
4 3 2 1 0

B.txt
1 2 3
4 5 6
7 8 9

C.txt
-1 -2 5 6 10 -15 1
-3 2 3 6 9 11 13
0 1 2 4 8 -4 -1
```


Y lo ejecuté con el comando:

```
./ejercicio8.out 3 4 -1 2
```

Con tal instrucción determinamos el tamaño de las matrices A, B y C. En este caso, la matriz A es de dimensión 3x3, B y C de dimensión 3x4; mientras que alpha = -1 y beta = 2.

Se obtuvo de salida:

```
------------
alpha :
-1.000000
------------
beta :
2.000000
------------
matriz A:
matriz[0][0]=0.00000	matriz[0][1]=1.00000	matriz[0][2]=2.00000
matriz[1][0]=3.00000	matriz[1][1]=4.00000	matriz[1][2]=5.00000
matriz[2][0]=6.00000	matriz[2][1]=7.00000	matriz[2][2]=8.00000
------------
matriz B:
matriz[0][0]=1.00000	matriz[0][1]=2.00000	matriz[0][2]=3.00000	matriz[0][3]=4.00000
matriz[1][0]=5.00000	matriz[1][1]=6.00000	matriz[1][2]=7.00000	matriz[1][3]=8.00000
matriz[2][0]=9.00000	matriz[2][1]=0.00000	matriz[2][2]=0.00000	matriz[2][3]=0.00000
------------
matriz C:
matriz[0][0]=-1.00000	matriz[0][1]=-2.00000	matriz[0][2]=5.00000	matriz[0][3]=6.00000
matriz[1][0]=10.00000	matriz[1][1]=-15.00000	matriz[1][2]=1.00000	matriz[1][3]=-3.00000
matriz[2][0]=2.00000	matriz[2][1]=3.00000	matriz[2][2]=6.00000	matriz[2][3]=9.00000
-------------
Matriz resultado : 
matriz[0][0]=-25.00000	matriz[0][1]=-10.00000	matriz[0][2]=3.00000	matriz[0][3]=4.00000
matriz[1][0]=-46.00000	matriz[1][1]=-56.00000	matriz[1][2]=-29.00000	matriz[1][3]=-42.00000
matriz[2][0]=-95.00000	matriz[2][1]=-28.00000	matriz[2][2]=-29.00000	matriz[2][3]=-30.00000
-------------
```



