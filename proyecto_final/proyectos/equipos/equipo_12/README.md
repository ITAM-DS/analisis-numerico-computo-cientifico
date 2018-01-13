## Equipo 12

Integrantes:

* Vianney Sánchez Gutiérrez

Título del proyecto: `Programación paralela de la descomposición de matrices LU.`

Objetivo del proyecto: `Objetivo del proyecto: El objetivo del proyecto es aplicar programación paralela a través del uso de MPI con la intención de factorizar cualquier matriz cuadrada con el método LU, una matriz L triangular inferior con 1's en la diagonal y una matriz U triangular superior, de tal forma que A pueda ser escrita como A=LU.`

En la carpeta [avance_07_04_2017](avance_07_04_2017) se encuentran las referencias que encontramos y las referencias que 
el profesor Erick colocará, las cuales comenzaremos a revisar con la intención de comenzar con la primera fase del proyecto.

## Referencias:

* [Key concepts for parallel out of core lu factorization](http://www.netlib.org/utk/people/JackDongarra/PAPERS/082_1997_key-concepts-for-parallel-out-of-core-lu-factorization.pdf)

* [Parallel algorithms for LU decomposition on a shared memory multiprocessor](https://www.researchgate.net/publication/220560498_Parallel_algorithms_for_LU_decomposition_on_a_shared_memory_multiprocessor)

* Descripción sobre la factorización LU en paralelo: sección 3.6 de G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013 y también al final de esa sección trae referencias.

* Un paper que habla sobre la factorización en eliminación Gaussiana con pivoteo parcial: [R. P. Brent. Parallel algorithms in Linear Algebra](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.56.3732&rep=rep1&type=pdf) 

* Eliminación Gaussiana en paralelo: sección 4.2 de Demmel, Heath, Van der Vost. Parallel numerical linear algebra.

* Sólo para ayuda y ejemplo de uso de funciones de MPI que no vimos en la clase pero puede servirles de introducción para multiplicación de matriz-vector: sección 3.4.9 de P. Pacheco, An Introduction to Parallel Programming, Morgan Kaufmann, 2011.
