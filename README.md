# analisis-numerico-computo-cientifico.

Este es el repositorio para la materia de "Métodos Numéricos y Optimización (MNO)" impartida en la maestría de ciencia de datos del ITAM por el **Prof. Erick Palacios Moreno.**

### Liga al temario [aquí](https://drive.google.com/file/d/19TA_wSrX-uYIotaQ4CINsU7mZyo5h45w/view?usp=sharing).

## Ramas del repositorio.

En este repositorio se han creado diferentes ramas que pueden ser accesadas como se aprecia en esta imagen:

<img width="320" alt="imagen" src="https://user-images.githubusercontent.com/3290689/70867013-1e950880-1f36-11ea-8fce-ed37a275d874.png">

Seleccionar por ejemplo la rama **mno-2018-1** (u otra) para información del curso de MNO de 2018.

**Aquí la [liga](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1#m%C3%A9todos-num%C3%A9ricos-y-optimizaci%C3%B3n) para la rama del curso del semestre enero-mayo 2020.**

## Breve explicación del repositorio en la rama master.

En la carpeta [C](C) encuentran:

* Clases para introducción al lenguaje C de programación.

* Dentro de [C/BLAS](C/BLAS) y [C/LAPACK](C/LAPACK) se tienen funciones para ejecución de algunas rutinas de [BLAS](http://www.netlib.org/blas/), [LAPACK](http://www.netlib.org/lapack/) en un sistema ubuntu.

* Dentro de [C/extensiones_a_C/](C/extensiones_a_C) se encuentran las siguientes extensiones al lenguaje de programación C: [MPI](http://mpi-forum.org/), [Pthreads](https://computing.llnl.gov/tutorials/pthreads/), [openMP](http://www.openmp.org/), [CUDA](https://docs.nvidia.com/cuda/cuda-c-programming-guide/).  

* Los directorios de [Python](Python) y [algoritmos](algoritmos) serán incorporados a las notas. Este trabajo será realizado durante el semestre enero-mayo 2020.

* A continuación se presentan links a las notas y material de cada tema. Adicionalmente se encuentran en el directorio [temas](temas).

## Índice de notas. 

**Nota del prof: estoy reescribendo las notas y añadiendo botones para interactividad.**

Cada número contiene información del tema respectivo, dar click en el tema de interés. 

Adicionalmente, cada tema tiene un botón de [binder](https://mybinder.org/) ![Binder](https://mybinder.org/badge_logo.svg) para ejecutar de forma interactiva el contenido (**ojo: cada botón tiene ambientes de docker distintos por lo que un mismo botón puede no funcionar para notas de capítulos distintos, p.ej. el botón de la nota 1.2 no funciona para la 1.4**). 

Ver [dockerfiles-for-binder](https://github.com/palmoreck/dockerfiles-for-binder) para documentación de las imágenes de [docker](https://www.docker.com/) usadas y en la liga [jupyterhub/binderhub](https://github.com/jupyterhub/binderhub) encuentran información de binder.


## I [Cómputo científico](temas/I.computo_cientifico/):

1.1 [Analisis numérico y cómputo científico.](temas/I.computo_cientifico/1.1.Analisis_numerico_y_computo_cientifico.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.1.Analisis_numerico_y_computo_cientifico.ipynb)


1.2 [Sistema de punto flotante.](temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_c_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb)


* [Ejercicios punto flotante](https://www.dropbox.com/s/09o9aasjyzya4ff/Punto_flotante.pdf?dl=0)

1.3 [Condición, estabilidad y normas.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb)

* [Ejercicios de normas y condición](https://www.dropbox.com/s/78rryxn3i58bg6c/Normas_condicion.pdf?dl=0)

Métodos de diferenciación e integración numérica:

1.4 [Polinomios de Taylor y diferenciacion_numerica.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.4.Polinomios_de_Taylor_y_diferenciacion_numerica.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.4.Polinomios_de_Taylor_y_diferenciacion_numerica.ipynb)


* [Ejercicios Taylor y diferenciación numérica](https://www.dropbox.com/s/n5srgxh2xdisaec/Taylor_y_dif_numerica.pdf?dl=0)

1.5 [Integración numérica](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.5.Integracion_numerica.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.5.Integracion_numerica.ipynb)

* [Ejercicios Integración numérica](https://www.dropbox.com/s/vk28jsrh2gwqzo3/Int_numerica.pdf?dl=0)


1.6 [Perfilamiento de código](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento.ipynb)

* [Python](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.6.Perfilamiento_Python.ipynb)

* [R]

* [C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento_C.ipynb)

1.7 [Opciones para resolver bottlenecks:]

* [Compilar a C, Python + C: Cython]

* [Reescribir funciones a C++: Rcpp]

* Cómputo en paralelo (capítulo II).

* Uso del caché y operaciones BLAS (capítulo III).

## II [Cómputo en paralelo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/II.computo_paralelo):

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

* [CUBLAS](C/extensiones_a_C/CUDA/CUBLAS/)

* [CUSOLVER](C/extensiones_a_C/CUDA/CUSOLVER/)

* [PyCUDA](Python/PyCUDA/)


## III [Cómputo matricial](https://www.dropbox.com/sh/azwz5p69bnbamtw/AAB5t2SafFK_1XvthNT9Tflda?dl=0)

3.1.1 [Multiplicación de matrices y estructura de datos.](https://www.dropbox.com/s/fyqwiqasqaa3wlt/3.1.1.Multiplicacion_de_matrices_y_estructura_de_datos.pdf?dl=0)

* [Preguntas 3.1.1](https://www.dropbox.com/s/s72yem79ef10k9h/preguntas_multiplicacion_matrices_y_estructura_de_datos.txt?dl=0)

3.1.2 [Localidad y vectorización. Análisis del error en cómputos matriciales básicos.](https://www.dropbox.com/s/l4hq45rj860ql9f/3.1.2.Localidad_y_vectorizacion.Analisis_del_error_en_computos_matriciales_basicos.pdf?dl=0)

* [Preguntas 3.1.2](https://www.dropbox.com/s/zbjd153jhhhc8os/preguntas_localidad_y_vectorizacion_analisis_del_error.txt?dl=0)

3.2.1 [Sistemas de ecuaciones lineales: eliminación Gaussiana y factorización LU.](https://www.dropbox.com/s/jwu8lu4r14pb7ut/3.2.1.Sistemas_de_ecuaciones_lineales_eliminacion_Gaussiana_y_factorizacion_LU.pdf?dl=0)

* [Preguntas 3.2.1](https://www.dropbox.com/s/g3w9sfa09nkn94p/preguntas_eliminacion_Gaussiana_factorizacion_LU.txt?dl=0)

3.2.2 [Factorizaciones matriciales: SVD, Cholesky, QR. (Vista rápida).](https://www.dropbox.com/s/s4ch0ww1687pl76/3.2.2.Factorizaciones_matriciales_SVD_Cholesky_QR.pdf?dl=0)

* [Preguntas 3.2.2](https://www.dropbox.com/s/iwpn6a8nr7w6h5d/preguntas_SVD_QR_Cholesky.txt?dl=0)

3.3 [Sistemas de ecuaciones lineales: métodos iterativos.](https://www.dropbox.com/sh/uikk6wfh1aqoc6m/AACddaJWDlHa6hMxgdy5DCVza?dl=0)

3.4 [Tensores. Una introducción.](https://www.dropbox.com/s/udwrro2f11j2a0q/3.4.Tensores.pdf?dl=0)

* [Preguntas 3.4](https://www.dropbox.com/s/6p2xzftozyca3uk/preguntas_tensores.txt?dl=0)

3.5 [Aplicaciones del álgebra lineal numérica.](https://www.dropbox.com/s/dfwk0y04ksgfilv/3.3.Aplicaciones_del_algebra_lineal_numerica.pdf?dl=0)

* [Preguntas 3.5](https://www.dropbox.com/s/h3j2acb39twln7o/preguntas_aplicaciones_algebra_lineal_numerica.txt?dl=0)

3.6.1 [Multiplicación de matrices con cómputo en paralelo.](https://www.dropbox.com/s/bgoua82py00h22o/3.4.1.Multiplicacion_de_matrices_con_computo_en_paralelo.pdf?dl=0)

3.6.2 [SVD con cómputo en paralelo.](https://www.dropbox.com/s/p8p905v34uth28w/3.4.2.SVD_con_computo_en_paralelo.pdf?dl=0)

## IV [Optimización convexa](https://www.dropbox.com/sh/en1tmz93b1lfvnq/AADZIcACu2T3k7sqHp-dS06Ma?dl=0)

4.1 [Introducción.](https://www.dropbox.com/s/qb3swgkpaps7yba/4.1.Introduccion_optimizacion_convexa.pdf?dl=0)

* [Preguntas 4.1](https://www.dropbox.com/s/kg57u7dulqnuou9/preguntas_intro_optimizacion.txt?dl=0)

4.2 [Problemas de optimización convexa.](https://www.dropbox.com/s/6isby5h1e5f2yzs/4.2.Problemas_de_optimizacion_convexa.pdf?dl=0)

* [Preguntas 4.2](https://www.dropbox.com/s/vroclj9r3peg0dh/preguntas_problemas_optimizacion.txt?dl=0)

4.3.1 [Teoría de convexidad: conjuntos convexos.](https://www.dropbox.com/s/ko86cce1olbtsbk/4.3.1.Teoria_de_convexidad_Conjuntos_convexos.pdf?dl=0)

* [Preguntas 4.3.1](https://www.dropbox.com/s/h1fwqnah55f1qu7/preguntas_conjuntos_convexos.pdf?dl=0)

4.3.2 [Teoría de convexidad: funciones convexas.](https://www.dropbox.com/s/mmd1uzvwhdwsyiu/4.3.2.Teoria_de_convexidad_Funciones_convexas.pdf?dl=0)

* [Preguntas 4.3.2](https://www.dropbox.com/s/bdhmmito6aa4zpc/preguntas_funciones_convexas.pdf?dl=0)

4.4 [Dualidad.](https://drive.google.com/file/d/1zCIHNAxe5Shc36Qo0XjehHgwrafKSJ_t/view?usp=sharing)

* [Preguntas 4.4](https://www.dropbox.com/s/w64oxxcdoc3lucn/preguntas_dualidad.pdf?dl=0)

4.5.1 [Problemas de optimización convexa: definiciones](https://drive.google.com/file/d/1xtkxPCx05Xg4Dj7JZoQ-LusBDrtYUqOF/view?usp=sharing)

[Ejemplo de métodos de bisección, punto fijo y Newton para resolver ecuaciones no lineales](https://www.dropbox.com/s/6zree47e1u3p5wx/Ecuaciones_no_lineales.pdf?dl=0)

4.5.2 [Algoritmos de optimización sin restricciones](https://drive.google.com/file/d/16-_PvWNaO0Zc9x04-SRsxCRdn5fxebf2/view?usp=sharing)

4.5.3 [Algoritmos de optimización con restricciones de igualdad](https://drive.google.com/file/d/12L7rOCgW7NEKl_xJbIGZz05XXVrOaPBz/view?usp=sharing)

4.5.4 [Algoritmos de optimización con restricciones de igualdad y desigualdad](https://drive.google.com/file/d/1RMwUXEN_SOHKue-J9Cx3Ldvj9bejLjiM/view?usp=sharing)

* [Ejemplo de optimización, aprendizaje automático y cómputo en paralelo.](https://www.dropbox.com/s/qf416dacvh0nvq6/MSV_RL_tesis_maestria_Erick.pdf?dl=0)

## Implementaciones de algoritmos para ecuaciones no lineales y optimización convexa

[Ecuaciones no lineales](algoritmos/ecuaciones_no_lineales/)

[Algoritmos para optimización sin restricciones](algoritmos/optimizacion_convexa_sin_restricciones)

[Algoritmos para optimización con restricciones de igualdad: ecuaciones lineales](algoritmos/optimizacion_convexa_con_restricciones_de_igualdad_ecuaciones_lineales)

[Algoritmos para optimización con restricciones de igualdad: ecuaciones lineales y desigualdad](algoritmos/optimizacion_convexa_con_restricciones_de_igualdad_ecuaciones_lineales_y_desigualdad/)




## V Cómputo en la nube

Ejemplos de Uso:

1. [Antares3](https://conabio.github.io/antares3/)

2. [Pangeo](http://matthewrocklin.com/blog/work/2018/01/22/pangeo-2)



### Amazon Web Services (AWS).

AWS.0 [Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS)

AWS.1.1 [Configuración de servicios básicos de AWS](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/1.1.Configuracion-de-servicios-basicos-para-uso-de-AWS) 

AWS.1.2 [Instalación de herramientas útiles en AWS](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/1.2.Instalaci%C3%B3n-de-herramientas-%C3%BAtiles-en-AWS)

AWS.2 [AWS y OpenMPI](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/2.AWS-y-OpenMPI)

AWS.3 [AWS y Sun Grid Engine](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/3.AWS-y-Sun-Grid-Engine)

AWS.4 [AWS y Kubernetes](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/4.AWS-y-Kubernetes)



AWS.adicional1 [AWS: Relational Database System]



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
