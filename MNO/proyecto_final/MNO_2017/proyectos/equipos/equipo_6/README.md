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
5. Se definio SGE (Sun Grid Engine) para la distribución de tareas (chunks)

* [Avance 24-04-2017](avance_24_04_2017).

1. Se realizo analisis para GRID con SGE.
2. Se revisaron los metodos de calculo de SVD thin y se revisaron sus 3 fases.
3. Se documento la Fase 1
4. Se valido algoritmo TEST de SVD en Rstudio

* [Avance 02-05-2017](avance_02_05_2017).

1. Se definio MPI para distribución de archivos.
2. Se documento la Fase 2
3. Se realizaron operaciones de multiplicación de diferentes matrices en `Rstudio`

* [Avance 08-05-2017](avance_08_05_2017).

1. Se configuro cluster de AWS y Star Cluster.
2. Se documento la Fase 3
3. Se sigue leyendo el libro `Matrix Computations` de H. Golub y F. Van Loan desde el capitulo 8.

* [Avance 15-05-2017](avance_15_05_2017).

1. Se configuro para correr local  `A = U * Σ * V T` con la funcion __cusolverDnDgesvd__. 
2. Se documento el algoritmo de la funcion `cusolverDnDgesvd` en un RMD.

* [Avance 22-05-2017](avance_22_05_2017).

1. Finalmente se corrio una prueba final con una Matriz real MxN usando __cusolverDnDgesvd__.
2. Se implemento en `Python` el metodo SVD para descomposicion y aproximacion de una imagen, a traves de obtener los valores singulares de la imagen en su forma de matriz, y con los valores de `U` , `Sigma` , `Vt` validamos los resultados con el __cusolverDnDgesvd__.
 
* [Avance 29-05-2017].

1. Se concluye proyecto en tiempo y forma. Se incluyen las carpetas y link a presentacion final. Muchas Gracias!
* [Codigo](code).
* [Trabajo Final](trabajo_escrito).
* [Link a Presentacion](https://drive.google.com/drive/folders/0B5eQQH_TPIY-YjVmSE5NS3BSYzQ).

## Referencias del proyecto:

* http://math.nist.gov/~RPozo/

* https://en.wikipedia.org/wiki/JAMA_(numerical_linear_algebra_library)

* SVD en cuda: [S. Lahabar, P. J. Narayanan. Singular Value Decomposition on GPU using CUDA](https://cvit.iiit.ac.in/images/ConferencePapers/2009/Sheetal09Singular.pdf)

* Se menciona el método de [Golub-Reinsch](http://people.duke.edu/~hpgavin/SystemID/References/Golub+Reinsch-NM-1970.pdf) para el cual es útil leer: G. Golub, W. Kahan. Calculating the singular values and pseudo inverse of a matrix y el capítulo 8 del libro: G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.

* Para revisar lo basico de SVD https://en.wikipedia.org/wiki/Singular_value_decomposition

* Para repaso de algebra, muy bueno!!!, libro de  Algebra Lineal de Mina S. de Carakushansky y guilherme de La Penha Editorial Ma Graw Hill
* Para revisar teoria de LAPACK y gestion de matrices en memoria. ftp://ece.buap.mx/pub/profesor/academ48/Libros/TesisDavid.pdf

by __RIL && ADV__
