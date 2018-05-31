## Reporte del módulo de cómputo matricial

#### Motivación
En mi caso dicidí leer el paper "A singular value decomposition on GPU using CUDA", ya que me parece que lo relacionado con procesamiento en la GPU es un tema que hoy en día esta teniendo un gran auge en el campo de la ciencia de datos.

Los autores del paper comienzan explicando que los algoritmos que implementan *SVD* son sumamente valiosos no sólo porque es un resultado de gran poder, ya que las operaciones de matrices utilizando *SVD* son más robustas antes errores numéricos; sino que también porque a lo largo del tiempo se han venido desarrollando más y más aplicaciones donde *SVD* es parte fundamental de su éxito, algunas de ellas son:

- Cálculo de la pseudoinversa de una matriz
- Análisis de componentes principales
- Procesamiento de señales
- Reconocimiento de patrones

No entraré tan a detalle en cuanto al desarrollo de cada uno de los algoritmos que toca el paper, sin embargo sí me parece relevante recordar en qué consiste *SVD*. La *SVD* de una matriz <a href="https://www.codecogs.com/eqnedit.php?latex=A" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A" title="A" /></a> de <a href="https://www.codecogs.com/eqnedit.php?latex=m\times&space;n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?m\times&space;n" title="m\times n" /></a>, es cualquier factorización  de la forma

<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=A&space;=&space;U\Sigma&space;V^{T}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A&space;=&space;U\Sigma&space;V^{T}" title="A = U\Sigma V^{T}" /></a>
</p>

donde <a href="https://www.codecogs.com/eqnedit.php?latex=U" target="_blank"><img src="https://latex.codecogs.com/gif.latex?U" title="U" /></a> es una matriz ortogonal de <a href="https://www.codecogs.com/eqnedit.php?latex=m&space;\times&space;m" target="_blank"><img src="https://latex.codecogs.com/gif.latex?m&space;\times&space;m" title="m \times m" /></a>, <a href="https://www.codecogs.com/eqnedit.php?latex=V" target="_blank"><img src="https://latex.codecogs.com/gif.latex?V" title="V" /></a> es una matriz ortogonal de <a href="https://www.codecogs.com/eqnedit.php?latex=n&space;\times&space;n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n&space;\times&space;n" title="n \times n" /></a> y <a href="https://www.codecogs.com/eqnedit.php?latex=\Sigma" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\Sigma" title="\Sigma" /></a> es una matriz diagonal de <a href="https://www.codecogs.com/eqnedit.php?latex=m&space;\times&space;n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?m&space;\times&space;n" title="m \times n" /></a>.

La rapidez con la que ha aumentado el performance del hardware de gráficos ha convertido a la GPU en una excelente herramienta a explotar para tareas que requieren un trabajo de cómputo intensivo.

Los autores presentan una implementación de *SVD* para matrices densas en la GPU usando CUDA, utilizan la librera de NVIDIA, CUBLAS y CUDAkernels. Su propuesta de implementación logra calcular la *SVD* de matrices muy grandes, la cual en CPU es imposible de calcular por cuestiones de memoria. Los autores destacan que gracias a las librerías de CUDA creadas para el proceso de operaciones matemáticamente complejas, es sencillo programar su algoritmo.

#### Algoritmo

Con base a lo que aborda el texto respecto a distintos *"approaches"* que recientemente se han tenido para implementaciones en la GPU, podemos confirmar una vez más que es un tema que está y ha estado tomando mucha relevancia.

Para la implementación propuesta por los autores ellos utilizan el método de Golub-Reinsch ya que este es simple y compacto, además de que se adapta bien a la arquitectura SIMD GPU. Este método es usado en la paquetería de LAPACK y es un algoritmo de dos pasos, primero la matriz original es reducida a una matriz bidiagonal mediante una serie de transformaciones "householder" (es una transformación lineal del espacio que consiste en una reflexión pura con respecto a un plano, fuente:Wikipedia); posteriormente la matriz bidiagonal resultante es diagonalizada utilizando iteraciones de factorización QR.

#### Sección de bidiagonalización

A continuación el paper presenta una explicación del algoritmo para transformar una matriz en otra bidiagonal, con algunas mejoras, creo que los puntos más importantes de esta explicación son: la idea de romper en bloques las operaciones y por otro lado la explicación de la comunicación entre la GPU y CPU, ya que de ahí se observa el área de oportunidad para mejorar las implementaciones que ya existían.

En lo que se refiere ya a la parte de bidiagonalizar en la GPU, los autores explican que con CUBLAS y matrices cuyas dimensiones son múltiplos de 32 se obtiene el mejor performance, por lo que justamente en su implementación llenan de ceros conforme sea necesario para llevar las matrices y vectores a la dimensión superior ms cercana que sea múltiplo de 32. Mencione anteriormente que los comentarios acerca de la interacción en cuestión de memoria entre la GPU y CPU me parece muy interesante y los autores justamente explotan esto al evitar transferencias pesadas que alentarían los procesos.

#### Sección de diagonalización de una matriz bidiagonal

La matriz bidiagonal que en teoría ya tenemos, la podemos diagonalizar mediante varias iteraciones de factorización QR. Si la matriz resultante de la sección anterior es <a href="https://www.codecogs.com/eqnedit.php?latex=B" target="_blank"><img src="https://latex.codecogs.com/gif.latex?B" title="B" /></a>, entonces se puede descomponer como

<p align="center">
<a href="https://www.codecogs.com/eqnedit.php?latex=\Sigma&space;=&space;X^{T}BY" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\Sigma&space;=&space;X^{T}BY" title="\Sigma = X^{T}BY" /></a>
</p>

donde <a href="https://www.codecogs.com/eqnedit.php?latex=\Sigma" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\Sigma" title="\Sigma" /></a> es una matriz diagonal, <a href="https://www.codecogs.com/eqnedit.php?latex=X" target="_blank"><img src="https://latex.codecogs.com/gif.latex?X" title="X" /></a> y <a href="https://www.codecogs.com/eqnedit.php?latex=Y" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Y" title="Y" /></a> son matrices unitarias ortogonales.

Entrando un poco más a detalle respecto a esta parte del artículo, me parece que la explicación del porqué sólo requerimos acceso a un renglón y al anterior o al posterior dependiendo de qué metodologa adoptemos es importante porque nuevamente los autores sacan ventaja de esto para realizar la menor transferecia posible entre la GPU y CPU. También y complementando lo anterior la parte donde se explica que ellos limitan la cantidad de coeficientes en la memoria compartida para evitar sobrepasar su capacidad, y lo hacen procesando un determinado número de renglones a la vez creo que es importante para entender la implementación global.

Finalmente, el algoritmo es eficiente ya que ejecuta el mismo número de operaciones en la GPU, que el algoritmo secuencial. La capacidad total que requiere la implementación es de <a href="https://www.codecogs.com/eqnedit.php?latex=(6\times&space;min(m,n))\times&space;4" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(6\times&space;min(m,n))\times&space;4" title="(6\times min(m,n))\times 4" /></a> bytes en la CPU, mientras que en la GPU es de <a href="https://www.codecogs.com/eqnedit.php?latex=(m^{2}&plus;n^{2})\times&space;4" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(m^{2}&plus;n^{2})\times&space;4" title="(m^{2}+n^{2})\times 4" /></a> bytes.


#### Sección de resultados

Primero, los autores detallan las características del equipo en el cual corrieron su algoritmo para el cálculo de *SVD* en la GPU, una versión optimizada de MATLAB en la CPU y un último itento en LAPACK Intel MKL 10.0.4, permitiendo para este último threading dinámico. Posteriormente, se explica la metodología de prueba que se siguió.

Se generaron 10 matrices densas para cada grupo de dimensiones con el fin de correr las pruebas evitando comparar un *sample* muy bueno o muy malo en particular, y en cambio se tomaron los promedios. El algoritmo que proponen los autores en la GPU logra un *speed up* de 8.2 en comparación a un 3.04 de la implementación en Intel MKL y de 59.3 en comparación a un 3.32 de MATLAB. Es importante mencionar que los tiempos registrados para las corridas del cálculo de *SVD* incluyen los tiempos de bidiagonalización, diagonalización y el cálculo de las matrices ortogonales. Es interesante que para dimensiones relativamente pequeñas la CPU vence a la GPU, pero esto cambia conforme aumentamos las dimensiones.

Al comparar los tiempos de corrida sólo para la bidiagonalización parcial en la GPU y en Intel MKL, se observaron resultados de 16.5 en la GPU contra 1.58 en Intel MKL. El performance para matrices cuadradas incrementa conforme incrementa el tamaño de las matrices en cuestión. Los autores tomaron un *block size* de 1 para <a href="https://www.codecogs.com/eqnedit.php?latex=n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n" title="n" /></a> pequeñas en matrices de <a href="https://www.codecogs.com/eqnedit.php?latex=m&space;\times&space;n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?m&space;\times&space;n" title="m \times n" /></a> y de 16 para <a href="https://www.codecogs.com/eqnedit.php?latex=n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n" title="n" /></a> grande.

En la gráfica siguiente se nota un resumen muy claro de las mejoras que lograron los autores con su implementación:

<p align="center">
  <img src="https://github.com/patricio-hdz/Borrar/blob/master/Imagenes/Im1.png">
</p>

Finalmente, los autores resumen que han presentado una implementación de *SVD* en la GPU, logrando obtener un máximo performance, primero, para el proceso de bidiagonalización mediante el uso de la librería optimizada de CUBLAS; posteriormente, para el proceso de diagonalización mediante un híbrido el cual divide de manera eficiente los procesos a ejecutar por la CPU y la GPU. Lo anterior, permitió calcular *SVD* de matrices de dimensiones hasta del orden de 14k, lo cual sería imposible de lograr en la CPU. Aunque existen errores de precisión, al menos en las pruebas que se realizaron en el paper, dichos errores fueron marginales.

#### Referencia

http://www.academia.edu/2869751/Singular_value_decomposition_on_GPU_using_CUDA
