## Equipo 6

Integrantes:

* Ricardo Lastra

* Adrián Vázquez

__Título del proyecto:__ `Plataforma Hibrida de Procesamiento Paralelo` (**PHPP**) 

__Objetivos del proyecto:__ Diseñar e implementar una plataforma hibrida basada en procesamiento GPU's para la ejecución en paralelo de la factorización SVD como sigue:

* Implementar Plataforma Hibrida de procesamiento en Paralelo (**PHPP**)
* Implementar la factorización de matrices SVD en computo en paralelo con CUDA-C

__Calendario:__ 

* [Avance 07-04-2017](avance_07_04_2017).
1. Definición (ARQUITECTURA DE COMPONENTES).
2. Correr prueba en arquitectura propuesta con al menos un  "HELLO WORLD" en CUDA-C.
3. Determinar cluster a seleccionar.

* [Avance 17-04-2017](avance_17_04_2017).
1. Se definio factorización SVD con algoritmo en CUDA-C a usar.
2. Se valido algoritmo TEST de SVD en CUDA-C
3. Se valido algortimo TEST de SVD en Python
4. Se revisarón las referencias para consolidar la teoria. 
5. Se definio SGE (Sun Grind Engine) para la distribución de tareas (chunks)

* [Avance 24-04-2017](avance_24_04_2017).

1. Por definir.

## Referencias del proyecto:

* http://math.nist.gov/~RPozo/

* https://en.wikipedia.org/wiki/JAMA_(numerical_linear_algebra_library)

* SVD en cuda: [S. Lahabar, P. J. Narayanan. Singular Value Decomposition on GPU using CUDA](https://cvit.iiit.ac.in/images/ConferencePapers/2009/Sheetal09Singular.pdf)

* Se menciona el método de [Golub-Reinsch](http://people.duke.edu/~hpgavin/SystemID/References/Golub+Reinsch-NM-1970.pdf) para el cual es útil leer: G. Golub, W. Kahan. Calculating the singular values and pseudo inverse of a matrix y el capítulo 8 del libro: G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.

* Para revisar lo basico de SVD https://en.wikipedia.org/wiki/Singular_value_decomposition 

by __RIL && ADV__
