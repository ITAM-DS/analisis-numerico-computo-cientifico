## Equipo 10

Integrantes:

* Maximiliano Alvarez
* Daniel Camarena

Titulo del proyecto: Ambiente distribuido de MPI en AWS para multiplicacion de Matrices

Objetivo del proyecto: Desarrollar un ambiente distribuido de MPI en amazon para realizar multiplicaion de matrices

Calendario

Semana 1
* Investigar el uso de Docker, Swarm, y Compose en AWS
* Investigar implementaciones de multiplicacion de matrices en MPI

Semana 2
* Diseñar arquitectura de MPI utilizando Docker, Swarm y Compose en AWS
* Pseudo codigo de multiplicación de matrices en MPI, protocolo de comunicacion entre nodos

Semana 3
* Implementacion de arquitectura distribuida de MPI utilizando Docker, Swarm y Compose en AWS
* Implementacion de codigo de multiplicacion cd matrices en MPI

## Referencias del proyecto:

* Una descripción de una implementación sencilla de la multiplicación de matrices en paralelo utilizando una arquitectura de anillo lo pueden encontrar en la sección 2 de este [paper](https://www.researchgate.net/publication/2685119_An_Analysis_Of_Parallel_Implementations_Of_The_Block-Jacobi_Algorithm_For_Computing_The_Svd)

* Una descripción la multiplicación de matrices en paralelo en un sistema de memoria distribuida lo encuentran en sección 1.6.7 del libro: G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013. Trae análisis de transferencia de datos; un buen análisis que añadir a su reporte :)

* Descripción sobre la factorización LU en paralelo: sección 3.6 de G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013 y también al final de esa sección trae referencias.

* Un paper que habla sobre la factorización en eliminación Gaussiana con pivoteo parcial: [R. P. Brent. Parallel algorithms in Linear Algebra](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.56.3732&rep=rep1&type=pdf) 

* Multiplicación de matrices en paralelo y eliminación Gaussiana en paralelo: secciones 3.2, 3.3, 4.2 de Demmel, Heath, Van der Vost. Parallel numerical linear algebra.

* Sólo para ayuda y ejemplo de uso de funciones de MPI que no vimos en la clase pero puede servirles de introducción para multiplicación de matriz-vector: sección 3.4.9 de P. Pacheco, An Introduction to Parallel Programming, Morgan Kaufmann, 2011.




