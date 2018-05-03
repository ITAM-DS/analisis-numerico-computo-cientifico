# Proyecto Final: Factorización Cholesky
## Cómputo en paralelo.
## Objetivo: 
### Realizar una implementación de la factorización de cholesky en alguna de las tecnologías de cómputo distribuido o compartido visto en clase.

### Teoría de Cholesky:

Hector:

En este avance se comenzó con la escritura del trabajo escrito, del libro de Golub y Van Loan se realizó la introducción al tema de la factorización de Cholesky. Algunas aplicaciones se mencionan de esto y se usan las notas 2.4 para una pequeña introducción a openMP.

Se seguirá con la lectura del libro recomendado para más, mejores y posibles implementaciones de otros algoritmos como los citados en el libro de Stephen Boyd y Lieven Vandenberghe en sus capítulos 9, 10 y 11

Alejandro:

Dado el problema del filtro de Kalman en el cual se quiere utilizar la factorización Cholesky, se requiere implementar un algoritmo de optimización para encontrar los estimadores máximo verosímiles de la distribución que se utilice, hasta ahora consierando que será una distribución normal.

La paquetería que parece razonable es ['SCS'](https://github.com/cvxgrp/scs) (splitting conic solver), paquetería utilizada para resolver problemas convexos de gran escala basado en el paper: [Conic Optimization via Operator Splitting and Homogeneous Self-Dual Embedding](https://web.stanford.edu/~boyd/papers/scs.html).

Es una paquetería escrita en C que puede ser utilizada en C, C++, Python, Matlab y R.

Resuelve problemas convexosusando el método de dirección alternante de multiplicadores [(ADMM)](http://web.stanford.edu/~boyd/papers/admm_distr_stats.html) regresando las soluciones de los problemas primales y duales qsi es que el problema es resoluble.

Desde elpunto de vista de la verosimilitud normalpuede utilizarce la paquetería [liknorm](https://github.com/limix/liknorm), librería escrita en C para calcular los momentos de distribución normal.

Aunque el objetivo de esta librerñia será la aplicación en Python, el repositorio nos permite observar el código para calcular la verosimilitud normal en un repositorio de [github](https://github.com/limix/liknorm/blob/master/src/liknorm.c).



Uriel:

Después de investigar diferentes aproximaciones y formas de desarrollar la factorización de Cholesky, así como su implementación, se decidió paralelizar con base en el cálculo de filas. Para esto lo más importante a considerar es el orden en que se realizan los cálculos.

(La versión de este avance con notación se encuentra en el archivo de Google Docs que compone el avance del trabajo escrito).

Regresando al algoritmo original de la factorización de Cholesky se tienen dos fórmulas, una para los elementos en la diagonal y otra para los elementos bajo la diagonal.

El algoritmo para realizar el proceso de manera paralela se deriva de la forma y dependencia de los elementos que se requieren para realizar el cálculo de cada factor en L.

Iniciando por el elemento l11 de la diagonal y comparando con el cálculo de los factores en L de la misma columna no requiere dependencia de ningún otro elemento, por lo cual se puede realizar en paralelo.

Se realizó el comparativo para la columna del siguiente elemento en la diagonal y se revisaron las dependencias para poder definir los procesos y el orden requerido para hacer el cálculo en paralelo

Con los ejemplos anteriores podemos ver que solamente se requiere el cálculo de los elementos de la fila (anteriores a la columna del elemento que se desea calcular) y el elemento que cruza con la diagonal de la misma columna.

El algoritmo para el cálculo en paralelo será:

Se calcula el elemento de la diagonal.
Se calculan en paralelo los elementos para cada i con la j fija.
Se repite para toda k <=n donde n es la dimensión de la matriz, dado que es simétrica tendremos matrices de nxn.

Con las bases anteriores se desarrolló la implementación en c utilizando OpenMP que se encuentra en el directorio de el presente avance.
Para compilar se utiliza el comando: 

gcc -Wall -fopenmp cholesky.c -o cholesky.out -lm

Con -fopenmp indicamos que requerimos las librerías para compilat, de la misma manera se indica el uso de la librería math.h mediante -lm.

A continuación se encuentran algunas notas y precisiones sobre la implementación.

      +Se utilizaron valores dummy para realizar las pruebas de funcionamiento pertinentes; el siguiente paso del desarrollo será poder introducir de manera eficiente la matriz a realizar el cálculo, en este caso se dejó una matriz de 5x5.
      
      +La función printm se encarga de imprimir la matriz en un formato fácil de ver ya que, con la finalidad de hacer más eficiente el programa, se aprovecha la forma en que C acomoda los valores de la matriz en memoria (rows) para realizar los cálculos.
      
      +Se hace uso de doble apuntador con la finalidad de que las funciones trabajen sobre los datos y no se haga una copia de los mismos, debido a esto se optó por utilizar la lectura/escritura en los arreglos mediante recorrer la memoria.
      
      +La función void cholesky recibe los apuntadores dobles a la matriz A y a la matriz resultado L así como el tamaño n. Dado que son matrices cuadradas el valor n sirve para definir columnas y filas.
      
      +Para hacer uso de OpenMP y paralelizar en threads, se colocó la porción de código que calcula cada elemento de la columna (desde j+1 ya que los valores superiores ya se habrán calculado) en paralelo con el uso de la directiva:  #pragma omp parallel for num_threads(thr) private(i,l). El número de threads se define en función de los elementos que se van a calcular para que puedan ser distribuidos y se hizo uso de la opción private para aislar las variables i y l, evitando así que el proceso pueda ser afectado por su uso fuera del proceso en paralelo.

Fuentes:

Golub, G., Van Loan, C.. (2013). 4.2 Positive Definite Systems. In Matrix Computations(159-188). USA: The Johns Hopkins University Press.


Equipo:

En esta fase el equipo se dedicó a la realización del trabajo escrito, una implementación en C de un algoritmo.


El trabajo escrito también cooperativo está [aquí](https://docs.google.com/document/d/1rZKXnf_56cQ0r0dyJ_M_H3khKhs_tSdgW3_IPnS2EfI/edit)

En la carpeta [Referencias](https://www.dropbox.com/home/Cholesky-Theory) tenemos los artículos escritos.
