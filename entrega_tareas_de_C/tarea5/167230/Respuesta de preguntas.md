# Investigación

1. Investiga por que se usan "" en la línea que tiene include en main.c y en funciones.c en lugar de usar <>

La variante donde se usa <> es utilizada headers files del sistema. Busca el archivo entre <> en una lista estadar de directorios. Por el otro lado, el uso de "" busca headers files creados por el usuario, buscando el archivo en el directorio donde se encuentra el archivo donde se utiliza la sintáxis.

2. Investiga el uso de "static" en la definición de variables externas de funciones.c

El uso de "static" en la definición de variables externas delimita el scope de la variable o función solo en el archivo en el que fue declarado.

3. Modifica el archivo funciones.c para que alojes e inicialices a las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. Modifica main.c para que llame a una función dentro del archivo funciones.c que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa free):

Los archivos definiciones, funciones y main se modificaron correspondientemente.

4. Compara tu resultado usando la subrutina de FORTRAN dgemm y los siguientes archivos definiciones2.h, main2.c, funciones2.c

Al utilizar los cambios realizados observamos los mismos resultados que en la implementación anterior.

5. Investiga sobre LAPACK, BLAS, ATLAS y la subrutina de Fortran dgemm y reporta sobre la investigación que realizas. Una descripción corta.

LAPACK: Linear Algrebra PACKage, es una libreria estandar para algebra lineal numérica. Provee de rutinas para resolver sistemas de ecuaciones lineales, problemas de eigenvalores y descomposición en valores singulares, factorización de matrices, etc. Esta enfocado en la resolución de ecuaciones lineales

BLAS: Basic Linear Algebra Subprograms, Es una especificación que provee de una serie de funciones de bajo nivel para realizar operaciones basicas de algebra lineal como addición de vectores, multiplicación escalar, productos punto, combinaciones lineales y multiplicación de matrices. Funciones optimizadas para realizar diversos tipos de mulitiplicaciones de matrices

ATLAS: Es tanto el proyecto de investigación como una librería de C, la cual significa  Automatically Tuned Linear Algebra Software. Este paquete esta orientado a ofrecer un software optimo para aplicaciones de algebra lineal. Este paquete provee de una API de estilo BLAS y un subset pequeño de la API de LAPLACK.

Subrutina dgem: Realiza la operación de matrices-> alpha*A*B + beta*C, donde alpha y beta son escalares, A,B y C son matrices 