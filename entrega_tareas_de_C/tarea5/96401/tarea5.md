#Tarea 5

a) La diferencia es el lugar donde el compilador busca los headers, al hacer uso de los parentesis, el compilador buscará los archivos en el mismo directorio donde ocurre la compilación. Por otro lado los símbolos < y > se usan para headers del sistema. Usualmente los paréntesis se usarán cuando sean headers definidos por el usuario.

b) El modificador static hace referencia a variables cuyo valor va a mantenerse entre llamadas.

c) Salida de programa.out:

'''
Matriz1
matriz1[0][0]=0.00  matriz1[0][1]=1.50
matriz1[1][0]=4.00  matriz1[1][1]=-5.00
matriz1[2][0]=-1.00 matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00  matriz2[0][1]=0.00  matriz2[0][2]=0.00
matriz2[1][0]=0.00  matriz2[1][1]=-1.00 matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00   matriz_res[0][1]=-1.50  matriz_res[0][2]=1.50
matriz_res[1][0]=4.00   matriz_res[1][1]=5.00   matriz_res[1][2]=-5.00
matriz_res[2][0]=-1.00  matriz_res[2][1]=-2.50  matriz_res[2][2]=2.50
'''

d) Salida de programa2.out:

'''
Matriz1
matriz1[0][0]=0.00  matriz1[0][1]=1.50
matriz1[1][0]=4.00  matriz1[1][1]=-5.00
matriz1[2][0]=-1.00 matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00  matriz2[0][1]=0.00  matriz2[0][2]=0.00
matriz2[1][0]=0.00  matriz2[1][1]=-1.00 matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00   matriz_res[0][1]=1.50   matriz_res[0][2]=4.00
matriz_res[1][0]=0.00   matriz_res[1][1]=0.00   matriz_res[1][2]=0.00
matriz_res[2][0]=-5.00  matriz_res[2][1]=-2.50  matriz_res[2][2]=-1.50
'''

El resultado no es el mismo debido a la forma en que la función de fortran espera el arreglo de la matriz. En fortran se usa la configuración Column Major mientras que en C se usa la configuración Row Major.

## LAPACK

LAPack (Linear Algebra PACKage) es una biblioteca de algebra lineal escrita en Fortran 90. Proporciona rutinas para resolver sistemas de ecuaciones lineales, soluciones de mínimos cuadrados, valores singulares. También permite descomposiciones comunes de matrices como LU, Cholesky, QR, SVD y Schur. Mientras que provee utilidades para matrices densas, las matrices ralas no son consideradas. La idea original era permitir el uso de estas rutinas en arquitecturas de memoria compartida y procesadores en paralelo. Bibliotecas que proveían estas utilidades como LINPACK y EISPACK no contemplaban estas arquitecturas y esto provocacba pérdida de eficiencia. En el fondo, LAPACK usa la biblioteca BLAS para implementar las rutinas.

## BLAS

BLAS (Basic Linear Algebra Subprograms) es una biblioteca para proveer de las operaciones básicas de algebra lineal como multiplicación de vectores y matrices. Existen tres niveles de funciones y se detallan a continuación:

- Nivel 1: Operaciones vectoriales y de vector por un escalar.
- Nivel 2: Operaciones matriz-vector.
- Nivel 3: Operaciones matriz-matriz.

La biblioteca BLAS se usa como insumo de otras bibliotecas como LAPACK.

## ATLAS

ATLAS (Automatically Tuned Linear Algebra Software) es una biblioteca que resulta del intento de generar implementaciones portables de funciones de BLAS y LAPACK aplicando técnicas empíricas para mejorar el desempeño.

## dgemm

Dgemm es una implementaciónd de la multiplicación matricial del paquete BLAS. Cuenta con parametros para considerar la matriz transpuesta. También se tiene que indicar explícitamente los tamaños de las matrices así como el factor escalar por el cual se puede multiplicar cada una de las matrices. La implementación toma en cuenta que las matrices se guardan en formato Column Major, y Fortran considera como primer elemento de un vector al 1.



