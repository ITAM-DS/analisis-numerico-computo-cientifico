Avance\_08\_05\_2017
================

Integrantes
-----------

-   Mónica Ballesteros
-   Ariana López
-   Fabiola Cerón

Trabajo:
--------

### Individual:

**Mónica Ballesteros**
* Leí el artículo [A Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures. 2009](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf); sin embargo, sólo el apartado apartado 3.2.1 se refiere a Factorización QR con Reflexiones HH.

* Investigué las funciones dlarfp, dlarf y dlarft de LAPACK. 

	+ dlarfp: Genera un reflector H de orden n.

	+ dlarf: Aplica un reflector elemental a una matriz rectangular.

	+ dlarft: Forma el factor triangular T de un reflector de bloque H=I-vtvH

**Ariana López**
* Leí el artículo [Parallel tiled QR factorization for multicore architectures](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view?usp=sharing) que explica de manera muy clara la transición del algoritmo secuencial al paralelo.

* Investigué las funciones dlarfb, dgeqrt y pdgeqr2 de LAPACK.

	+ dlarfb: Aplica un reflector de bloque o su transpuesta a una matriz rectangular.

	+ dgeqrt: Calcula la factorización QR por bloques de una matriz A de mxn usando una representación WY Compacta.

	+ pdgeqr2: Toma la columna actual y hace la factorización QR en una matriz A panel de mxn.

**Fabiola Cerón**

* Leí el artículo [A Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures 2008](https://drive.google.com/file/d/0BxMtevFKwTW_b0UwVDh6bGx4Y3c/view?usp=sharing) enfocándome en el apartado 2 que describe los dos pasos principales del algoritmo: panel factorization y trailing submatrix update.

* Investigué las funciones dgeqrf, dgeqr2 y dgemqrt de LAPACK.

	+ dgeqrf: Calcula la factorización QR de una matriz A de mxn con A = QR.

	+ dgeqr2: Calcula la factorización QR de una matriz A de mxn con A = QR no usando un algoritmo de bloques.

	+ dgemqrt: Sobre escribe una matriz general C de mxn.

### Equipo:

* Repasamos las notas del profesor [2.4 Sistemas de memoria compartida en OpenMP](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0) con el fin de interpretar cómo adaptar los conceptos vistos en clase al caso específico de la factorización QR.

* Estudiamos el modelo de programación fork-join multithreading.

* Revisamos las referencias sugeridas; sin embargo, en el caso de [M. Costnard, J.M. Muller, Y. Robert.](https://drive.google.com/file/d/0BxMtevFKwTW_UjA5UFdFVmd1S00/view?usp=sharing) habla sobre la factorización QR utilizando Rotaciones de Givens.  F. T. Luk. no nos fue posible localizarlo de manera gratuita.  Finalmente en el caso de [D. P. O'Leary, P. Whitman](https://www.researchgate.net/publication/222459558_Parallel_QR_factorization_by_Householder_and_modified_Gram-Schmidt_algorithms) se refiere a paralelización de factorización QR enfocada en memoria distribuida.

* Por lo anterior, buscamos más referencias encontrando dos artículos adicionales de Buttari: [Parallel tiled QR factorization for multicore architectures](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view?usp=sharing) y [A Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures 2008](https://drive.google.com/file/d/0BxMtevFKwTW_b0UwVDh6bGx4Y3c/view?usp=sharing).  De la lectura de los tres artículos concluimos que son más o menos lo mismo, por lo que utilizaremos como base [Parallel tiled QR factorization for multicore architectures](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view?usp=sharing) puesto que nos pareció más claro y completo.

* Identificamos las funciones de OpenMP relacionadas con factorización QR que podrían ser utilizadas para implementar el código en paralelo.

* Tenemos duda sobre cuáles, de las funciones investigadas, son las adecuadas para nuestro problema.

* La transformación utilizada por LAPACK se obtiene en dos pasos: 

	+ El primero se llama panel factorization y produce los refectores de Householder.
	+ En el segundo se aplican las transformaciones calculadas durante la fase de panel factorizacion al resto de la matriz A.  A esta fase se le llama Trailing submatrix update.

* Entendimos que no todo el proceso de factorización es paralelizable, sólo la actualización de la sub-matriz, por lo que la secuencia de statements que ejecutará el programa en paralelo se referirán sólo a la fase de Trailing Submatrix Update.