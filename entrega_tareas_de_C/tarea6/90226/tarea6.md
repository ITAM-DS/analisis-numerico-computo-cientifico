Dirígite a la rama de master a la ruta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/.

#Investiga* sobre la subrutina de Fortran dgemv (parámetros que recibe y la salida).

#R=Realiza cualquier de las siguientes operaciones de matrices:

#y := alpha*A*x + beta*y,   or   y := alpha*A'*x + beta*y,
#donde alfa y beta son escalares, x y y son vectores y A es una matriz de mxn.

Recibe los parámetros:
TRANS: Es la operación que se va a realizar
M: El número de renglones en la matriz A
N: El número de columnas de la matriz A
ALPHA: El escalar alfa
A: La matriz de coeficientes
LDA:La primera dimensión de la matriz A
X:Vector de cierta dimensión
INCX: El incremento de los números en el vector X
BETA: El escalar beta
Y: Vector de cierta dimensión
INCY: El incremento de los números en el vector Y

En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level2/ ejecuta el programa dgemv_mult_mat_vec.c y realiza pruebas con diferentes matrices y vectores definidos por ti.
R= Se utiliza la matriz del archivo A(A1.txt) y el vector del archivo v(v1.txt) y corremos la rutina correspondiente.

Haz un programa que utilice la subrutina dger de Fortran.
R=En el programa3.out podemos ver las soluciones del programa.

Después de haber estudiado y entendido los archivos de definiciones.h y funciones.c y realizado los puntos anteriores y la tarea 5 responde: ¿cómo fue que pudimos llamar a las rutinas de Fortran (que almacena en una forma column-major order los arreglos de dos dimensiones) para operaciones con arreglos 2-dimensionales sin haber instalado CBLAS, si en clase se dijo que almacenar arreglos de dos dimensiones en C es en un row-major order?
R= En la línea 8 del archivo de definiciones.h se cambia por column-major order.

Investiga* sobre la subrutina de Fortran dgemm (parámetros que recibe y la salida).

R=Es una rutina para multiplicar matrices de la forma C := alpha * op( A ) * op( B ) + beta * C que recibe los siguientes parámetros:
TRANS A= Especifica la forma del operador A que se utiizará en la multiplicación de matrices.
TRANS B= Especifica la forma del operador B que se utiizará en la multiplicación de matrices.
TRANS C= Especifica la forma del operador C que se utiizará en la multiplicación de matrices.
M= El número de renglones en la matriz op(A) y de la matriz C
N= El número de columnas en la matriz op(A) y de la matriz C
K= Especifica el número de columnas de la matriz op(A) y el número de renglones de la matriz op(B).
ALPHA = un escalar
A= Un arreglo de dimensiones (LDA,KA) donde KA es K cuando TRANSA= "N"
LDA= Especifica la primer dimensión de A.
B=Un arreglo de dimensiones (LDB,KB) donde KB es K cuando TRANSB= "N"
LDB= Especifica la primer dimensión de B.
BETA= Un escalar
C= Un arreglo de dimensiones (LDC, N)
LDC= Especifica la primer dimensión de C.


En la carpeta analisis-numerico-computo-cientifico/C/BLAS/ejemplos/level3/ ejecuta el programa dgemm_mult_mat.c y realiza pruebas con diferentes matrices definidas por ti.
R= En el programa4.out podemos ver los resultados. Incluí la matriz B como la identidad negativa para probar esto.

En la carpeta del punto anterior encuentras la sección Multiplicación matriz-matriz con trick. Ejecuta el programa de esta sección con diferentes matrices definidas por ti y resuelve la pregunta ¿por qué funciona este trick?.
R=Funciona ya que se modifican algunas deifiniciones en el archivo definiciones.h

Haz un programa que utilice la subrutina dsymm de Fortran.
