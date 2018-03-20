# Tarea 5

## Rafael Larrazolo, 118426

```
analisis-numerico-computo-cientifico/MNO/entrega_tareas_de_C/tarea5
```

1) Estudia y entiende los archivos ```definiciones.h``` y ```funciones.c``` de ahí, en particular investiga por qué se usan `""` en la línea que tiene `#include` en `funciones.c` en lugar de usar `< >`. Investiga el uso de `static` en la definición de variables externas de `funciones.c` .

En el archivo ```funciones.c``` se utiliza `" "` en `#include"definiciones.h"` ya que estamos "invocando" una "librería" que definimos por nuestra cuenta. Al usar comillas le indicamos al programa que busque dicha librería definida/ESCRITA por nosotros. Cuando el preprocesador encuentra la línea #include "definiciones.h", entonces reemplaza esta línea por el fichero incluido. Lo que sucede es que se interrumpe la compilación del programa actual, `funciones.c`, se compila `definiciones.h` y, tras compilarlo, se continúa con el primero.

El uso de `static` dentro de `funciones.c` permite que las variables definidas de tal modo, `i` y `j`,  mantengan su valor cada vez que sean invocadas/llamadas. Por lo que entiendo,
estas variables conservarán su valor aunque se salga y entre la función dentro la cual están definidas, i.e., permanecen en memoria mientras el programa esté corriendo y no se inicializan de nuevo.

2) Investiga\* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigación que realizas. Es una investigación que contiene principalmente una descripción sobre los paquetes y niveles anteriores.

BLAS (Basic Linear Algebra Subprograms) son rutinas que proveen bloques para realizar operaciones básicas de vectores y matrices; éste consta de 3 niveles explicados más adelante.
Al ser BLAS eficiente y disponible ampliamente, es comúnmente usado para desarrollo de software de álgebra lineal como LAPACK.

CBLAS es una interfaz del tipo C de las rutinas BLAS. Se pueden hacer uso de las rutinas CBLAS usando los llamados usuales de C.

LAPACK es un software escrito en Fortran 90 que provee rutinas para resolver sistemas de ecuaciones, problemas de mínimos cuadrados, valores propios, valores singulares, factorizaciones de matrices como LU, Cholesky, QR, SVD, entre otros. LAPACK está diseñado con la visión de explotar el Nivel 3 de las rutinas BLAS.

ATLAS (Automatically Turned Lineal Algebra Software) es una librería de software que provee implementacion de BLAS para lenguaje C. 

Operaciones de nivel de BLAS:

```
Nivel 1
Son operaciones de escalares, vector, y vector-vector vectores como producto interior, normas, valor absoluto.
```
 
```
Nivel 2
Rutinas que realizan operaciones matriz-vector. Por ejemplo multiplicación matriz-vector, solución del sistema Tx=y donde T es una matriz triangular.
```

```
Nivel 3
Rutinas que realizan operaciones matriz-matriz.
```


3) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level1) ejecuta el programa `dot_product.c` y realiza pruebas con diferentes vectores definidos por ti.

Probé con 3 pares difentes de vectores:

Primer Par:

Lo ejecuté con el comando
```
./programa.out 5
```

|   V1      |    V2     |  
|:---------:|:---------:|
|14         |   15      |
|-4         |   1       |
|5          |   3       |
|0          |   0       |
|10         |   -3      |

Output:

```
------------
vector :
vector[0]=14.00000
vector[1]=-4.00000
vector[2]=5.00000
vector[3]=0.00000
vector[4]=10.00000
------------
vector :
vector[0]=15.00000
vector[1]=1.00000
vector[2]=3.00000
vector[3]=0.00000
vector[4]=-3.00000
------------
resultado: 191.000000
```



Segundo Par:
```
./programa.out 7
```


|   V1      |    V2     |
|:---------:|:---------:|
|1          |   -1      |
|-4         |   1       |
|5          |   -1      |
|0          |   1       |
|9          |   -1      |
|17         |   1       |
|20         |   -1      |

Output:

```
------------
vector :
vector[0]=1.00000
vector[1]=-4.00000
vector[2]=5.00000
vector[3]=0.00000
vector[4]=9.00000
vector[5]=17.00000
vector[6]=-20.00000
------------
vector :
vector[0]=-1.00000
vector[1]=1.00000
vector[2]=-1.00000
vector[3]=1.00000
vector[4]=-1.00000
vector[5]=1.00000
vector[6]=-1.00000
------------
resultado: 18.000000
```

Tercer Par:

En este caso definí vectores de diferentes tamaños para ver lo que hacía la función.

|   V1      |    V2     |
|:---------:|:---------:|
|1          |   8       |
|2          |   7       |
|3          |   6       |
|4          |   5       |
|5          |   4       |
|           |   3       |
|           |   2       |
|           |   1       |

Con 
```
./programa.out 7
```
A pesar de ser los vectores de distinto tamaño, al más chico (V1 en este caso) lo 'completa' con ceros
hasta alcanzar a ser del mismo tamaño que V2. En este caso se obtuvo:

```
------------
vector :
vector[0]=1.00000
vector[1]=2.00000
vector[2]=3.00000
vector[3]=4.00000
vector[4]=5.00000
vector[5]=0.00000
vector[6]=0.00000
------------
vector :
vector[0]=8.00000
vector[1]=7.00000
vector[2]=6.00000
vector[3]=5.00000
vector[4]=4.00000
vector[5]=3.00000
vector[6]=2.00000
------------
resultado: 80.000000
```

Ahora, usando 
```
./programa.out 2
```

Por lo que se aprecia, el programa 'trunca' la longitud de los vectores para después realizar la operación correspondiente.

```
------------
vector :
vector[0]=1.00000
vector[1]=2.00000
------------
vector :
vector[0]=8.00000
vector[1]=7.00000
------------
resultado: 22.000000

```

Se apreció que el programa obtiene el producto punto de dos vectores. Si éstos son de diferente dimensión,
al menor de estos le agrega entradas con 0's hasta llegar a ser de la misma dimensión que el otro vector.

4) Investiga sobre la subrutina de Fortran `ddot` (parámetros que recibe y la salida).

Los parámetros de entrada de la función `ddot` son los siguientes:

+ `N` entero; número de elementos del vector input.

+ `DX` arreglo de doble precisión de dimension ( 1 + ( N - 1 ) * abs( INCX ) ).

+ `INCX` entero; espacio de almacenamiento entre los elementos de DX.

+ `DY` arreglo de doble precisión de dimension ( 1 + ( N - 1 ) * abs( INCY ) ).

+ `INCY` entero; espacio de almacenamiento entre los elementos de DY.

La salida de `ddot` es el producto punto de los vectores.


5) Haz un programa que utilice la subrutina `daxpy` de Fortran.

La rutina `daxpy` realiza la operación `ax * y` donde a es un escalar (tipo `double`) y `x` e `y` son vectores de la misma dimensión.
El output de la rutina se guarda en el segundo vector, esto es, la operación realizada es: `y = ax * y`.

Para el programa realizado, me basé en el programa del ejercicio anterior.

Para ejecutarlo, necesitamos poner como parámetros el número de elementos a considerar en los vectores `x`, `y`, y el valor de `alpha`.

Como ejemplo, se ejecutó el programa considerando la dimensión de los vectores igual a 3 y el valor de alpha = 9.

```
./ejercicio5.out 3 9
```


Obteniendo como salida:

```
------------
alpha :
9.000000 
------------
vector 1 :
vector[0]=1.00000
vector[1]=0.00000
vector[2]=-3.00000
------------
vector 2 :
vector[0]=5.00000
vector[1]=8.00000
vector[2]=9.00000
------------
vector resultado :
vector[0]=14.00000
vector[1]=8.00000
vector[2]=-18.00000
------------

```









