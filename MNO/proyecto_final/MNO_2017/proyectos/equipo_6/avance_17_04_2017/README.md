# Avance_17_04_2017

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez

## Trabajo:

### Individual

Adrián Vázquez (120028):

__Implementación de SVD__

Se revisaron los siguientes [metodos](metodos) implementados en CUDA-C.

__Implementación de arquitectura__

Se usara [sun grid engine](http://star.mit.edu/cluster/docs/0.93.3/guides/sge.html#) para distribución de Chunks [como sigue.](ambiente)

Ricardo Lastra (160167):

__Teoria SVD__

Se revisarón las referencias siguientes:

SVD en cuda: [S. Lahabar, P. J. Narayanan. Singular Value Decomposition on GPU using CUDA](https://cvit.iiit.ac.in/images/ConferencePapers/2009/Sheetal09Singular.pdf)

Se menciona el método de [Golub-Reinsch](http://people.duke.edu/~hpgavin/SystemID/References/Golub+Reinsch-NM-1970.pdf) para el cual es útil leer: G. Golub, W. Kahan. Calculating the singular values and pseudo inverse of a matrix y el capítulo 8 del libro: G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.

y se genero el siguiente [markdown.](code/factorizacion_svd_cuda_teoria.html)

Asi mismo se realizó la comprobación de resultados del algoritmo SVD para una matriz (3x3) con CUDA Toolkit E.1. y usando SciPy y el algoritmo de SVD implementado en Python con la funcion de numpy ["np.linalg.svd"](code/Clase_SVD.ipynb), donde al ejecutar ambos programas y comparar las salidas, obtuvimos los mismos resultados de U, S y V* !!!!

![GitHub Logo](images/cuda_python_resul.png) 

### Equipo
Se define usar la factorizacion SVD para nuestro problema de siniestros, integrando el toolkit de CUDA-C.
Se plasmaron los 2 metodos con CUDA-C para SVD a traves de 2 métodos, librería y manual, los cuales esperamos nos sea retroalimentado cual seria la mejor opción en nuestro caso.
Se revisara aun mas teoria para definir matriz nxp para leer los datos.
Se compararon los resultados de las pruebas demo con CUDA-C y SVD con Python, obteniendo los mismos resultados. Se anexa codigo Python.



## Comentarios sobre avance:

## (Respuestas) Comentarios sobre avance:
