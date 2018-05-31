# Preguntas

1. Estudia y entiende los archivos definiciones.h y funciones.c de ahí, en particular investiga por qué se usan "" en la línea que tiene #include en funciones.c en lugar de usar < >. Investiga el uso de static en la definición de variables externas de funciones.c.
  * Las comillas dobles (") se usan para indicar que nuevas funciones, estructuras de datos, constantes, macros o variables estan definidas en uno o más archivos de un proyecto en particular. Como reglas generales para las cabeceras locales, deben usarse rutas relativas durante su invocación, es decir, los archivos del propio proyecto se incluyen con comillas y las cabeceras de bibliotecas estándar o de terceros con paréntesis angulares (<>), y así marcar la diferencia entre "cabecera_propia" , \<standard\> y/o \<thid_party\>.
  * La palabra clave o keyword "static" sirve para preservar el valor de las variables despues de que la función o ámbito en donde son utilizadas se termina.

2. Investiga* sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS y reporta sobre esta investigación que realizas. Es una investigación que contiene principalmente una descripción sobre los paquetes y niveles anteriores.
  * BLAS, CBLAS, LAPACK, ATLAS 
    + BLAS: (Basic Linear Algebra Subprograms) es un grupo de funciones que permiten realizar operaciones algebraicas básicas entre vectores, matrices y vectores, y matrices contra matrices.
    + CBLAS: CBLAS es una interfaz para invocar las funciones de BLAS desde C, el header de CBLAS especifica valores predefinidos y los prototipos de todas las funciones de BLAS.
    + LAPACK: Esta es una bibloteca que esta basada en BLAS y se usa para realizar operaciones algebraicas de alto nivel que impliquen resolver valores de eigen-valores, factorizacion de matrices, sistemas de ecuaciones simultaneas, etc
    + ATLAS: Automatically Tuned Linear Algebra para pretende ofrecer un funciones de algebra lineal para ofrecer portabilidad y desempeño a traves de la de interfaces de C y Fortran hacia las bibliotecas BLAS y LAPACK.
  * Niveles de BLAS 
    + BLAS-1 sirve para operaciones vector-vector (normas, productos punto, multiplicaciones, etc.).
      Las operaciones de este nivel son menos eficientes en arquitecturas cache-based, donde el ancho de banda del bus entre la DRAM y la CPU tienden a ser un cuello de botella.
      [Referencia](https://projects.ncsu.edu/hpc/Courses/16blas.html#BLAS-1)
    + BLAS-2, Operaciones entre matriz-vector (multiplicaciones, resolver matrices triangulares, etc.)
    + BLAS-3, Operaciones  entre matriz-matriz (multiplicacion, resolución de matrices, clasificación, etc.)

3. En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/ ejecuta el programa dot_product.c y realiza pruebas con diferentes vectores definidos por ti.
  ```
      gcc -Wall dot_product.c funciones.c -o dot_product.out -lblas
  ```
  El programa inicializa dos vectores, leyendo su tamaño como argumento y cargando su contenido desde 2 archivos, calcula el producto punto de los dos vectores usando la funcion ddot e imprime sus resultados.
  * Como compilar el programa?
    ```
      gcc -Wall dot_product.c funciones.c -o dot_product.out -lblas
    ```
  * Como ejecutar el programa?
    ```
      ./dot_product.out dot_product.txt
    ```
  * Resultados en el archivo dot_product.txt

4. Investiga* sobre la subrutina de Fortran ddot (parámetros que recibe y la salida).
  * La funcion ddot recibe 5 parametros:
    + El primer parametro (N) se usa para especificar el numero de elementos en X y Y.
    + El segundo parametro es un vector (X) con una dimension de al menos (1 + (N-1) * abs(INCX))
    + El tercer parametro (INCX) sirve para especificar el incremento de los elementos del vector X.
    + El cuarto parametro es un vector (Y) con una dimension de al menos (1 + (N-1) * abs(INCY))
    + El quinto parametro (INCY) sirve para especificar el incremento de los elementos del vector Y.
  * El resultado o salida es el producto punto de los dos vectores.

5. Haz un programa que utilice la subrutina daxpy de Fortran.
  * Como compilar el programa?
    ```
      gcc -Wall daxpy_product.c funciones.c -o daxpy_product.out -lblas
    ```
  * Como ejecutar el programa?
    ```
      ./daxpy_product.out 5 4.5
    ```
  * Resultados en el archivo daxpy_product.txt
  
