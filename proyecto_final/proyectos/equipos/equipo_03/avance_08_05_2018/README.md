# Avance 08/05/2018

## Integrantes:

* Diego Alejandro Estrada Rivera    

* Rafael Larrazolo de la Cruz       

* Victor Quintero Mármol González   

## Título del proyecto: Factorización de Matriz usando factorización QR

### Individual

Diego: 

Para este avance empecé revisando nuevamente las [notas de clase sobre OpenMP](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/openMP/ejemplos) así como ejecutar todos los ejemplos que vimos; esto para familiarizarme más con sus ventajas y empezar a paralelizar la implementación secuencial que tenemos del algoritmo de rotaciones de Givens. Incorporé el código realizado por Victor en el avance pasado para copiar matrices utilizando *pragma omp parallel for* y paralelicé otros pasos del código, como las multiplicaciones de matrices (Q = QG y R = t(G)R)  y generación de matrices identidad. Así también incorporé el código realizado por Victor en este avance para leer una matriz desde un .txt para evitarnos la molestia de introducir elemento por elemento en cada prueba y adecué el código para que leyerá el nombre del .txt y así no tener que estar compilandolo cada vez que deseemos factorizar una matriz diferente. Agrego aquí un [link](https://www.dropbox.com/s/9lbk3lh0z0auafw/givens_copia.c?dl=0) al código con las modificaciones que se acaban de mencionar, así como varias [pruebas](https://www.dropbox.com/s/x1t67c0dmmzqgpa/pruebasQRconGivensCopia.txt?dl=0) que se llevaron a cabo con tres matrices: [A](https://www.dropbox.com/s/1tj9utzot202lgq/A.txt?dl=0), [B](https://www.dropbox.com/s/41ohvtnh3s4uto3/B.txt?dl=0) y [C](https://www.dropbox.com/s/nyxeb7uxtwsq6lw/C.txt?dl=0). Para el siguiente avance planeó leer más sobre OpenMP, sobre todo la clausula *ordered*, para saber si nos sería de ayuda para paralelizar la multiplicación de matrices G, que tiene que ser en orden. También me gustaría empezar a realizar un diagrama sobre como se van separando los threads para realizar las operaciones que hemos paralelizado y realizar pruebas con matrices lo más grandes posibles, y así comparar la velocidad con el código secuencial.

Rafael:

En este avance continué con el trabajo escrito. Principalmente modifiqué algunas cuestiones de la versión anterior del trabajo, agregando comentarios o notación matemática. De igual modo agregué el ejemplo y marco teórico del método de Rotaciones de Givens. También incluí los algoritmos o pseudo-códigos de los métodos que investigamos en las referencias (Gram-Schmidt, Householder, Givens). Para los pseudocódigos me basé principalmente en las notas del repositorio, así como de las referencias que habíamos investigado en las primeras semanas del proyecto. De igual modo encontré este [paper](https://www.inf.ethz.ch/personal/gander/papers/qrneu.pdf) que me fue muy ilustrativo tanto para el algoritmo empleado para Gram-Schmidt como el de Householder. También esta [referencia](https://classes.soe.ucsc.edu/ams213a/Winter17/lecturenotes/l8.pdf) fue de gran utilidad. Para el siguiente avance quiero agregar al trabajo escrito lo que hemos implementado como equipo. De igual modo me gustaría con Diego y Victor seguir con las pruebas paralelizando el algoritmo de Givens e incorporar nuestros avances al trabajo. Avance [trabajo](https://www.dropbox.com/s/d2gkj7jc06d7mzn/trabajo_escrito.pdf?dl=0) escrito.


Victor:

Para este avance revisé a detalle el código de rotaciones de Givens que implementó Diego para el avance pasado con el objetivo de entenderlo bien y ver que partes se podían paralelizar. Junto con Diego, adaptamos el código de copiar matrices en paralelo que implementamos para el avance anterior al de rotaciones de givens y usamos estructuras similares para paralelizar más partes del código. También realicé un código para leer matrices desde un archivo de texto para no tener que introducir toda la matriz al monento de la ejecución.  Agrego [link](https://www.dropbox.com/s/9lbk3lh0z0auafw/givens_copia.c?dl=0) al código con las modificaciones que se acaban de mencionar, así como de [pruebas](https://www.dropbox.com/s/x1t67c0dmmzqgpa/pruebasQRconGivensCopia.txt?dl=0) que se llevaron a cabo con tres matrices: [A](https://www.dropbox.com/s/1tj9utzot202lgq/A.txt?dl=0), [B](https://www.dropbox.com/s/41ohvtnh3s4uto3/B.txt?dl=0) y [C](https://www.dropbox.com/s/nyxeb7uxtwsq6lw/C.txt?dl=0).

Para el siguiente avance creo más conveniente empezar a enfocarme en la presentación y ayudar a terminar el trabajo escrito.

### Equipo  

Consideramos que para las siguientes semanas los avances se centrarán más en labor en conjunto ya que pensamos trabajar en la paralelización del algoritmo y realizar pruebas del mismo. Buscamos en la medida de lo posible hacer un comparativo de cómo cambia en cuestión de tiempo la ejecución en paralelo con el algoritmo secuencial. También queremos continuar con el trabajo escrito, al cual le faltaría incluir la parte de la implementación de nuestro código, y de igual modo comenzar con la presentación.



