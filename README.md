# analisis-numerico-computo-cientifico

En la carpeta [C](C) encuentran:

* Clases para introducción al lenguaje C de programación.

* Dentro de [C/BLAS](C/BLAS) y [C/LAPACK](C/LAPACK) se tienen funciones para ejecución de algunas rutinas de [BLAS](http://www.netlib.org/blas/), [LAPACK](http://www.netlib.org/lapack/) en un sistema ubuntu.

* Dentro de [C/extensiones_a_C/](C/extensiones_a_C) se encuentran las siguientes extensiones al lenguaje de programación C: [MPI](http://mpi-forum.org/), [Pthreads](https://computing.llnl.gov/tutorials/pthreads/), [openMP](http://www.openmp.org/), [CUDA](https://docs.nvidia.com/cuda/cuda-c-programming-guide/). 

Para información sobre el curso de Métodos Numéricos y Optimización impartido en ITAM, ir a la rama correspondiente de este repositorio y seleccionar la fecha de interés.

Índice de notas. Cada número contiene información del tema respectivo.

## I [Cómputo científico](https://www.dropbox.com/sh/2o888m9v7i3ngsf/AACRxfa8bIl-LMBl7Jtb-y72a?dl=0):

1.1 [Analisis numérico y cómputo científico.](https://www.dropbox.com/s/z5ifw3ti66gukdy/1.1.Analisis_numerico_y_computo_cientifico.pdf?dl=0)

* [Preguntas 1.1](https://www.dropbox.com/s/geg0wji899tuf89/preguntas_analisis_numerico_computo_cientifico.txt?dl=0)

1.2 [Sistema de punto flotante.](https://www.dropbox.com/s/9fsupm3bhwmv7cb/1.2.Sistema_de_punto_flotante.pdf?dl=0)

* [Preguntas 1.2](https://www.dropbox.com/s/rfqs34rpav2hjs3/preguntas_sistema_de_punto_flotante.txt?dl=0)

1.3 [Condición, estabilidad y normas.](https://www.dropbox.com/s/5bc6tn39o0qqg35/1.3.Condicion_estabilidad_y_normas.pdf?dl=0)

* [Preguntas 1.3](https://www.dropbox.com/s/zbf78u0uxr31ei0/preguntas_condicion_estabilidad_normas.txt?dl=0)

## II [Cómputo en paralelo](https://www.dropbox.com/sh/vrdgj7bugi1flyp/AAAMP6R2n5GZY71KXkWT4ZEja?dl=0):

2.1 [Un poco de historia y generalidades](https://www.dropbox.com/s/z465znq3wwao9ad/2.1.Un_poco_de_historia_y_generalidades.pdf?dl=0).

* [Preguntas 2.1](https://www.dropbox.com/s/lm0z67b7q5a7qqi/preguntas_generalidades_computo_paralelo.txt?dl=0)

2.2 Sistemas de memoria distribuida: [MPI](C/extensiones_a_C/MPI).

* [Preguntas 2.2](https://www.dropbox.com/s/l5x3tjaocj949e8/preguntas_mpi.txt?dl=0)

* [Levantar un cluster de forma pseudo distribuida con openmpi y docker](C/extensiones_a_C/MPI/openMPI/)

[Ejemplos con openmpi](C/extensiones_a_C/MPI/openMPI/ejemplos/):

* [send_receive_broadcast_reduce](C/extensiones_a_C/MPI/openMPI/ejemplos/1_send_receive_broadcast_reduce)

* [io_scatter_gather](C/extensiones_a_C/MPI/openMPI/ejemplos/2_io_scatter_gather)

* [openMPI y BLAS](C/extensiones_a_C/MPI/openMPI/ejemplos/3_openMPI_y_BLAS/)

2.3 Sistemas de memoria compartida: [Pthreads](C/extensiones_a_C/Pthreads)

* [Preguntas 2.3](https://www.dropbox.com/s/kfazlrd7crdlch4/preguntas_pthreads.txt?dl=0)

[Ejemplos con Pthreads](C/extensiones_a_C/Pthreads/ejemplos/)

2.4 Sistemas de memoria compartida: [openMP](C/extensiones_a_C/openMP)

* [Preguntas 2.4](https://www.dropbox.com/s/oytugjz8s3znvrl/preguntas_openmp.txt?dl=0)

[Ejemplos con openMP](C/extensiones_a_C/openMP/ejemplos/)

* [parallel_and_critical_directives](C/extensiones_a_C/openMP/ejemplos/1_parallel_and_critical_directives/)

* [reduction_clause](C/extensiones_a_C/openMP/ejemplos/2_reduction_clause/)

* [parallel_for_directive](C/extensiones_a_C/openMP/ejemplos/3_parallel_for_directive/)

2.5 Compute Unified Device Architecture ([CUDA](C/extensiones_a_C/CUDA/)).

* [Preguntas 2.5](https://www.dropbox.com/s/gu9knsc4qgyu95b/preguntas_cuda.txt?dl=0)

* [Instalación](C/extensiones_a_C/CUDA/instalacion)

* [Ejemplos](C/extensiones_a_C/CUDA/ejemplos/)

## III [Cómputo matricial](https://www.dropbox.com/sh/azwz5p69bnbamtw/AAB5t2SafFK_1XvthNT9Tflda?dl=0)

3.1.1 [Multiplicación de matrices y estructura de datos.](https://www.dropbox.com/s/fyqwiqasqaa3wlt/3.1.1.Multiplicacion_de_matrices_y_estructura_de_datos.pdf?dl=0)

3.1.2 [Localidad y vectorización. Análisis del error en cómputos matriciales básicos.](https://www.dropbox.com/s/l4hq45rj860ql9f/3.1.2.Localidad_y_vectorizacion.Analisis_del_error_en_computos_matriciales_basicos.pdf?dl=0)

3.2.1 [Sistemas de ecuaciones lineales: eliminación Gaussiana y factorización LU.](https://www.dropbox.com/s/jwu8lu4r14pb7ut/3.2.1.Sistemas_de_ecuaciones_lineales_eliminacion_Gaussiana_y_factorizacion_LU.pdf?dl=0)

3.2.2 [Factorizaciones matriciales: SVD, Cholesky, QR. (Vista rápida).](https://www.dropbox.com/s/s4ch0ww1687pl76/3.2.2.Factorizaciones_matriciales_SVD_Cholesky_QR.pdf?dl=0)

3.3 [Sistemas de ecuaciones lineales: métodos iterativos.]

3.4 [Tensores. Una introducción.](https://www.dropbox.com/s/udwrro2f11j2a0q/3.4.Tensores.pdf?dl=0)

3.5 [Aplicaciones del álgebra lineal numérica.](https://www.dropbox.com/s/dfwk0y04ksgfilv/3.3.Aplicaciones_del_algebra_lineal_numerica.pdf?dl=0)

3.6.1 [Multiplicación de matrices con cómputo en paralelo.](https://www.dropbox.com/s/bgoua82py00h22o/3.4.1.Multiplicacion_de_matrices_con_computo_en_paralelo.pdf?dl=0)

3.6.2 [SVD con cómputo en paralelo.](https://www.dropbox.com/s/p8p905v34uth28w/3.4.2.SVD_con_computo_en_paralelo.pdf?dl=0)

## IV [Optimización convexa](https://www.dropbox.com/sh/en1tmz93b1lfvnq/AADZIcACu2T3k7sqHp-dS06Ma?dl=0)

4.1 [Introducción.](https://www.dropbox.com/s/qb3swgkpaps7yba/4.1.Introduccion_optimizacion_convexa.pdf?dl=0)

4.2 [Problemas de optimización convexa.](https://www.dropbox.com/s/6isby5h1e5f2yzs/4.2.Problemas_de_optimizacion_convexa.pdf?dl=0)

* [Ejemplo de optimización, aprendizaje automático y cómputo en paralelo.](https://www.dropbox.com/s/qf416dacvh0nvq6/MSV_RL_tesis_maestria_Erick.pdf?dl=0)

4.3 [Teoría de convexidad.](https://www.dropbox.com/s/5g7uwg6274k2yyf/4.3.Teoria_de_convexidad.pdf?dl=0)

4.4 [Dualidad.]

4.5 [Algoritmos.]


## V Cómputo en la nube

\*[Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Activar-creditos-de-AWS)

5.1 [Amazon Web Services y OpenMPI.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) 


## [C](C/)

[clase1](C/clases/clase1.md)

[clase2](C/clases/clase2.md)

[clase3](C/clases/clase3.md)

[clase4](C/clases/clase4.md)

[clase5](C/clases/clase5.md)

[clase6](C/clases/clase6.md)

## [BLAS](C/BLAS)

[Ejemplos](C/BLAS/ejemplos/):

* [level1](C/BLAS/ejemplos/level1/)

* [level2](C/BLAS/ejemplos/level2/)

* [level3](C/BLAS/ejemplos/level3/)

## [LAPACK](C/LAPACK)

[Ejemplos](C/LAPACK/ejemplos/):

* [solve_linear_equations](C/LAPACK/ejemplos/solve_linear_equations/)
