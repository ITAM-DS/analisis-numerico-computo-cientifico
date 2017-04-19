# Avance_17_04_2017

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez

## Trabajo:

### Individual

Adrián Vázquez (120028):

__Implementación de SVD__

Se revisaron los siguientes [metodos](Metodos) implementados en CUDA-C.

Ricardo Lastra (160167):

__Teoria SVD__

Se reviso la siguiente referencia:

SVD en cuda: [S. Lahabar, P. J. Narayanan. Singular Value Decomposition on GPU using CUDA](https://cvit.iiit.ac.in/images/ConferencePapers/2009/Sheetal09Singular.pdf)

Donde se tiene lo siguiente: 


Tambien se reviso la 2da referencia citada:

Se menciona el método de [Golub-Reinsch](http://people.duke.edu/~hpgavin/SystemID/References/Golub+Reinsch-NM-1970.pdf) para el cual es útil leer: G. Golub, W. Kahan. Calculating the singular values and pseudo inverse of a matrix y el capítulo 8 del libro: G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.

De la cual se dedujo lo sigueinte:


### Equipo
Se define usar la factorizacion SVD para nuestro problema de siniestros. Usando ya el toolkit de CUDA-C.
Se plasmaron los 2 metodos con CUDA-C para SVD a traves de 2 métodos, librería y manual, los cuales esperamos nos sea retroalimentado cual seria la mejor opcion en nuestro caso.
Se revisara aun mas teoria para definir matriz nxp al leer los datos.
Se compararon los resultados de las pruebas demo con CUDA-C y SVD con Python, obteniendo los mismos resultados. Se anexa codigo Python.



## Comentarios sobre avance:

## (Respuestas) Comentarios sobre avance:
