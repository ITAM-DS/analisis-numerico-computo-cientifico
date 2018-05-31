# Tarea 5
### Elizabeth Solis Díaz

Se entrega el 14 de marzo. De forma individual crear una carpeta con 
nombre igual a su clave única, debajo del nivel: 

```
analisis-numerico-computo-cientifico/MNO/entrega_tareas_de_C/tarea5
```

Dirígite a la rama de master a la ruta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos).

### 1) Estudia y entiende los archivos ```definiciones.h``` y ```funciones.c``` 
### De ahí, en particular investiga por qué se usan `""` en la línea que tiene `#include` en `funciones.c` en lugar de usar `< >`. 

+ Si usamos `< >` el compilador busca el archivo en *todos* los directorios. En cambio, con las
comillas el compilador empieza buscando el archivo en el directorio actual.

### Investiga el uso de `static` en la definición de variables externas de `funciones.c` .

+ Se usa con variables globales y funciones para restringir su ámbito al 
archivo donde se definen

+ Se usa con variables locales para almacenar la variable en la memoria 
asignada de forma estática en lugar de en la memoria asignada de forma automática

+ El valor de las variables `static` no se pierde aunque se haya salido de la función

+ Estas variables existen durante toda la ejecución del programa

### 2) Investiga sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS.

### a) BLAS (Basic Linear Algebra Subprograms) 

+ Rutinas para realizar operaciones básicas de vectores y matrices. 

+ Existen 3 distintos niveles de BLAS, dependiendo de las operaciones a realizar

+ Ventajas: 

    + Portabilidad
    
    + Eficiencia
    
    + Disponibilidad

### a.1) Level 1 BLAS

+ Para realizar operaciones entre escalares, vectores y vector-vector

### a.2) Level 2 BLAS

+ Para realizar operaciones matriz-vector

### a.3) Level 3 BLAS

+ Para realizar operaciones matriz-matriz

### b) CBLAS

+ En lugar de llamar rutinas BLAS desde C, se puede utilizar una interfaz CBLAS

+ Es un *C-style* interfaz a las rutinas de BLAS

### c) LAPACK (Linear Algebra PACKage)

+ Escrito en Fortran 90

+ La mayor cantidad  posible de los cálculos serán realizados mediante llamados a BLAS 

+ Rutinas para solución de

    + problemas de ecuaciones lineales (simultaneas)
    
    + mínimos cuadrados (para sistema de ecuaciones)
    
    + problemas de valores propios y valores singulares
    
    + factorización de matrices (LU, Cholesky, etc)
    
    

### d) ATLAS (Automatically Tuned Linear Algebra Software

+ Es una biblioteca para álgebra lineal

+ E una forma de generar automáticamente una biblioteca optimizada BLAS. 

+ Es una mejora con respecto a BLAS genérico disponible en Netlib


### 3) En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level1) ejecuta el programa `dot_product.c` y realiza pruebas con diferentes vectores definidos por ti.

+ Compilamos

```
gcc -Wall dot_product.c funciones.c -o dot_product.out -lblas
```

+ Ejecutamos

```
./dot_product.out 3
```

+ Para correr con otros vectores:

    + En la consola ejecutamos:    
    `echo "1 \n1 \n1" > v1.txt`      
    `echo "3 \n4 \n5" > v2.txt` 
    
    + Para mostrar los vectores recien creados:     
    `cat v1.txt`    
    `cat v2.txt`
    
    + Volvemos a compliar y ejecutar
    
    + En la consola ejecutamos, compilamos y volvemos a ajecutar el programa con otros vectores:       
    `echo "1 \n9 \n5" > v1.txt`      
    `echo "7 \n4 \n8" > v2.txt`

### 4) Investiga\* sobre la subrutina de Fortran `ddot` (parámetros que recibe y la salida).

+ Función de doble precisión ddot()

+ Es el producto punto de dos vectores

+ Usa loops con incrementos de uno en uno

+ Parámetros:

    + N es entero, número de elemntos en el vector
    
    + DX es un arreglo de doble precision, de dimensiones ( 1 + ( N - 1 )*abs( INCX ) )
    
    + INCX es entero, storage spacing between elements of DX
    
    + DY es un arreglo de doble precisiony, de dimensiones ( 1 + ( N - 1 )*abs( INCY ) )
    
    + INCY es entero, storage spacing between elements of DY
    
+ referencia: http://www.netlib.org/lapack/explore-html/de/da4/group__double__blas__level1_ga75066c4825cb6ff1c8ec4403ef8c843a.html#ga75066c4825cb6ff1c8ec4403ef8c843a
    
    
**\*Para sus investigaciones utilicen las referencias de los README's:**

[analisis-numerico-computo-cientifico/C/BLAS/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS)

[analisis-numerico-computo-cientifico/C/LAPACK/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/LAPACK)

### 5) Haz un programa que utilice la subrutina `daxpy` de Fortran.

+ Multiplica un vector pos una constante y le suma otro vector

+ Parámetros:

    + N es entero, número de elemntos en el vector
    
    + DA is de doble precisión, especofa la constante o escalara alpha

    + DX es un arreglo de doble precision, de dimension ( 1 + ( N - 1 )*abs( INCX ) )
    
    + INCX es entero, storage spacing between elements of DX
    
    + DY es un arreglo de doble precision, de dimension ( 1 + ( N - 1 )*abs( INCY ) )
    
    + INCY es entero, storage spacing between elements of DY
    
+ Ejemplo:

+ Compilamos

```
gcc -Wall ej_daxpy.c funciones.c -o ej_daxpy.out -lblas
```

+ Ejecutamos

```
./ej_daxpy.out 3
```
**La tarea se hace de forma individual y personal.**
