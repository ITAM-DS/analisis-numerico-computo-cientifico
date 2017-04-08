README

Integrantes:

-José Carlos Castro
-Walter Martínez Santana
-Norma Verónica

Título del proyecto: Implementación en paralelo (CUDA) del método iterativo de Jacobi

Objetivo: Implementar el método de Jacobi en una arquitectura CUDA con el propósito de llevar a cabo una implementación alternativa que ofrezca un mejor performance de manera general, y que atienda la necesidad de tener un algoritmo robusto y confiable que optimize los recursos computacionales y que se pueda usar como una pieza clave en un proceso computacional más complejo.


En la carpeta avances describimos nuestras investigaciones personales y grupales. Además hemos sostenido un diálogo abierto con Erick acerca de nuestras ideas sobre lo quq queremos o pretendemos hacer, además de platicarle nuestras razones y ambiciones por las cuales queremos llevarlo a cabo. Sin embargo hemos encontrado algunos obstáculos que en un inicio eran impercetibles. POr lo que también hemos comentado con Erick la posibilidad de un cambio de proyecto.
   



CARPETA AVANCES



Integrantes:

-José Carlos Castro
-Walter Martínez Santana
-Norma Verónica



Trabajo Individual:

José Carlos:

Escribimos el pseudocódigo de Jacobi y con Walter lo analisámos para ver como lo podíamos paralelizar, nos dimos cuenta que era casi totalmente paralelizable, salvo que había que esperar a que se actualizara todo el vector x_i que vamos proponiendo en cada iteración como solución de la ecuación Ax=b, por lo que era sencillo de dar una instrucción para OpenMP, pero en CUDA era diferente ya que teníamos mas nodos y estar verificando complicaba el computo y alentaba el proceso. Una posible alternativa era realizar computo "stencil" que es como agregar un factor de memoria en cada iteración, y así no era necesario esperar la actualización. Sin embargo era un poco como forzar el algoritmo ya que incrementaba el número de operaciones por un factor de n. Entonces estamos considerando cambiar el proyecto por una factorización cholesky paralelizada en CUDA para matrices densas.

Walter:
En mi caso leí varias referencias que pondré al final. En particular, estuve estudiando  desde una perspectiva computacional la implemetación del algoritmo "secuencial" del método iterativo de Jacobi para poder proponer un algoritmo "paralelo" del mismo implementado en una arquitectura CUDA. 
Estuvimos, mis compañeros y yo, diseccionando el algoritmo en cada una de sus etapas. Este primer análisis nos dio la posibilidad de poder detectar las diferentes etapas que se podían paralelizar y cuáles no.

En un segundo análisis propusimos una forma diferente de representar la matriz A, que consistió en verla como una partición formada por una matriz triangular inferior, L, una matriz diagonal D y una matriz triangular superior U, y obtener la forma A= L+D+U. Esta aproximación me llevo a la conclusión de que hay una "dependencia fuerte" entre una iteración y la que sigue, de manera general, en el algoritmo. Y por lo tanto, de que "al parecer" el método de Jacobi no es un algoritmo que se preste para llevar a cabo una implementación de manera paralela en CUDA con mejores resultados que una implementación del mismo en forma secuencial. Las diferencias, en mi opinión, son marginales y no sustantivas, por lo que, en mi parecer, no es algo viable para implementarlo en CUDA.

Vero:

referencias:
-Ford,William. Numerical Linear Algebra with Applications. Elsevier.2015.
-Skiba,Yuri. Introducción a los Métodos Numéricos.UNAM.2001.
-Ascher,U.M. A first course in numerical methods. SIAM. 2011.
-Stewart, G.W. Matrix Algorithms Volume 1. SIAM.1998.


