#1.- Estudia y entiende los archivos definiciones.h y funciones.c de ahí, en particular investiga por qué se usan "" en la línea que tiene #include en funciones.c en lugar de usar < >. Investiga el uso de static en la definición de variables externas de funciones.c
R= De acuerdo con el libro C Programming Absolute Beginner's Guide, de Perry y Miller, en el capítulo 7 se menciona que cuando se usan comillas, el programa C primero busca en el directorio en el que el programa está guardado y después busca en el directorio #include construido. Por el contrario, al usar < > se hace una búsqueda más en general en todos los directorios. 

El comando static se utiliza con variables tanto como con funciones para controlar la visibilidad y el "tiempo de vida" de las mismas. Este comando resulta útil en casos en los que una función/variable necesita permanecer igual (en el mismo estado) ante distintas invocaciones sin la necesidad de utilizar variables globales dentro del programa.En ese sentido, las funciones/variables sólo permanecerán visibles para la ejecución presente del programa.


#2.- 2) Investiga sobre BLAS, CBLAS, LAPACK, ATLAS y las operaciones de nivel 1, nivel 2 y nivel 3 de BLAS.
R= BLAS (Basic Linear Algebra Subprograms) son rutinas que proveen los bloques básicos para realizar operaciones de vectores y matrices. Cuenta con 3 niveles que van incrementando su complejidad:

Nivel 1: (incluye rutinas de: Single [SROTG, ISAMAX, etc], Double[DROTG, DAXPY, etc], Complex[CROTG, CSSCAL, etc.] y Double Complex[ZROTG, ZSCAL, etc.]) = Se usa para hacer operaciones escalares y vector-vector.

Nivel 2: (incluye rutinas de: Single [SGEMV, DSBMV, etc], Double[DGEMV, DTRSV, etc], Complex[CGEMV, CTRSV, etc.] y Double Complex[ZGEMV, ZTBMV, etc.]) = Se usa para hacer operaciones matriz-vector

Nivel 3: (incluye rutinas de: Single [SGEMM, SSYMM, etc], Double[DGEMM, DSYMM, etc], Complex[CGEMM, CHERK, etc.] y Double Complex[ZGEMM, ZSYMM, etc.]) = Se usa para hacer operaciones matriz-matriz

CBLAS
Es la interface que permite ejecutar las rutinas BLAS. Por ejemplo para las computadores APPLE existe la iinterface para la implementación (localizada en: https://developer.apple.com/documentation/accelerate/blas).

LAPACK
Es un paquete escrito en Fortran 90 que ofrece rutinas para resolver sistemas de ecuaciones simultaneas, mínimos cuadrados, problemas de eigenvalores y valor singular. También se incluye distintas factorizaciones de matrices como LU, Cholesky, QR, SVD, Schur, Schur generalizada.

ATLAS
El software ATLAS (Automatically Tuned Linear Algebra Software), actualmente es un proyecto que se enfoca en aplicar técnicas empíricas para proveer interfaces de C y Fortran77 para eficientizar las implementaciones de BLAS principalmente y algunas de LAPACK


Fuente:http://www.netlib.org/blas/#_level_2, http://www.netlib.org/lapack/, http://math-atlas.sourceforge.net/

#3.- En la carpeta [analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level1/](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/BLAS/ejemplos/level1) ejecuta el programa `dot_product.c` y realiza pruebas con diferentes vectores definidos por ti.
R= Con los vectores contenidos en los archivos .txt se mandó llamar la rutina dot_producto. Para empezar se hizo un ejercicio simple con tres números en cada posición y el resultado se muestra a continuación.

comando: ./programa.out 3
salida:
------------
vector :
vector[0]=1.00000
vector[1]=2.00000
vector[2]=3.00000
------------
vector :
vector[0]=1.00000
vector[1]=0.00000
vector[2]=17.00000
------------
resultado: 52.000000

También se probó con vectores de distintas dimensiones (el primer vector con 4 dimensiones y el segundo con 9)

------------
vector :
vector[0]=1.00000
vector[1]=6.00000
vector[2]=7.00000
vector[3]=8.00000
vector[4]=0.00000
vector[5]=0.00000
vector[6]=0.00000
vector[7]=0.00000
vector[8]=0.00000
------------
vector :
vector[0]=1.00000
vector[1]=0.00000
vector[2]=17.00000
vector[3]=89.00000
vector[4]=11.00000
vector[5]=5.00000
vector[6]=6.00000
vector[7]=98.00000
vector[8]=21.00000
------------
resultado: 832.000000

Se observa que si el programa dectecta que hay diferencias en las dimensiones, automáticamente rellena con ceros las posiciones faltantes.

#4.- Investiga* sobre la subrutina de Fortran ddot (parámetros que recibe y la salida)
Es una rutina que nos permite obetener el producto punto de vectores. Los parámetros que utiliza son los siguientes:
 N= número de elementos en los vectores de entrada
 DX= vector de doble precisión con n elementos
 INCX= Espacio de almacenamiento entre los elementos de DX
 DY= vector de doble precisión con n elementos
 INCY= Espacio de almacenamiento entre los elementos de DY

La salida es la siguiente:
El producto punto de los vectores (double precision dot product)


Fuente: https://projects.coin-or.org/CoinBazaar/browser/projects/f2cAD/trunk/fortran/ddot.f

#5.- Haz un programa que utilice la subrutina daxpy de Fortran.
La función daxpy multiplica un vector por un escalar y lo suma a un segundo vector asignando el resultado a ese segundo vector. Se corrió el programa que se adjunta en la entrega con el siguiente resultado:

./programa.out 3 5
------------
vector :
vector[0]=1.00000
vector[1]=6.00000
vector[2]=7.00000
------------
vector :
vector[0]=1.00000
vector[1]=0.00000
vector[2]=17.00000
------------
El resultado de daxpy es: 
vector[0]=6.00000
vector[1]=30.00000
vector[2]=52.00000
