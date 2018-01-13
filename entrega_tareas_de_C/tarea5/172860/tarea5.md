# Tarea 5
a) Investiga por qué se usan "" en la línea que tiene include en main.c y en funciones.c en lugar de usar < >.

Cuando se escribe entre comillas un archivo con #include, el preprocesador busca el archivo etre las comillas en el mismo directorio donde se encuentra el archivo que se está leyendo, luego en los directorios entrecomillados y finalmente en los directorios cuando se usa <>, mientras que en el caso cuando se escribe entre <> el preprocesador busca el archivo en una lista estándar de los directorios del sistema.

b) Investiga el uso de static en la definición de variables externas de funciones.c.

Para variables estáticas globales, static se usa cuando se quiere que la variable solo se pueda ver en el archivo donde es declarada. Se dice que esta variable tiene file scope.

e) Investiga sobre ```LAPACK```, ```BLAS``` y ```ATLAS``` y la subrutina de Fortran ```dgemm``` y reporta sobre esta investigación que realizas. Es una investigación corta que contiene principalmente una descripción sobre los paquetes anteriores y la subrutina.

```LAPACK``` (Linear Algebra Package) es una librería estándar para algebra lineal numérica. Está escrito en Fortran 90 y provee rutinas para resolver sistemas de ecuaciones lineales simultáneas, soluciones de mínimos cuadrados de ecuaciones de sistemas lineales, problemas de eigenvalores y valores singulares, así como también factorización de matrices (LU, Cholesky, QR, SVD, Schur y Schur generalizada). También se manejan matrices densas y de banda. Todo estó soporta matrices reales y complejas en precisión sencilla y doble. Además ```LAPACK``` se ha extendido para correr en sistemas de memoria distribuida en paquetes posteriores como ```ScaLAPACK``` y ```PLAPACK```.

```BLAS``` (Basic Linear Algebra Subprograms) es una especificación que prescribe un conjunto de rutinas de bajo nivel para realizar operaciones de álgebra lineal como suma de vectores, multiplicación por un escalar, productos punto, combinaciones lineales y multiplicacion de matrices. Estas rutinas tienen enlaces para C y Fortran. La mayoría de las bibliotecas que ofrecen rutinas de álgebra lineal se ajustan a la interfaz BLAS como ACML, ATLAS, MKL y OpenBLAS. Muchas aplicaciones de software numérico utilizan bibliotecas compatibles con BLAS para hacer cálculos de álgebra lineal, incluyendo Armadillo, LAPACK, LINPACK, GNU Octave, Mathematica, MATLAB, NumPy y R.

```ATLAS``` (Automatically Tuned Linear Algebra Software) es una librería portable para álgebra lineal que se optimiza automáticamente para una arquitectura arbitraria. Esta librería corre en casi todos los sistemas operativos Unix y en Microsoft Windows utilizando Cygwin.

```dgemm``` es una subrutina que realiza una de las operaciones matriz-matriz

```
C := alpha*op( A )*op( B ) + beta*C,
```

donde  op( X ) es una de

```
    op( X ) = X   o   op( X ) = X',
```

donde alpha y beta son escalares, A,B y C son matrices con op( A ) como una matriz mxk, op( B ) como una matriz kxn y C es una matriz mxn.


