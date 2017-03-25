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