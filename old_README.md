# analisis-numerico-computo-cientifico.

Este es el repositorio para la materia de "Métodos Numéricos y Optimización (MNO)" impartida en la maestría de ciencia de datos del ITAM por el **Prof. Erick Palacios Moreno**, github: [palmoreck](https://github.com/palmoreck).

### Dar click en [liga](https://drive.google.com/file/d/19TA_wSrX-uYIotaQ4CINsU7mZyo5h45w/view?usp=sharing) para el temario.

En esencia el curso sigue un desarrollo de acuerdo al siguiente dibujo:

<img src="https://dl.dropboxusercontent.com/s/0hqal8ni3d5rbso/curso_MNO.png?dl=0" heigth="300" width="300">

Los módulos del 1 al 3 constituyen *building blocks* para el módulo 4.


## Ramas del repositorio.

En este repositorio se han creado diferentes ramas que pueden ser accesadas como se aprecia en esta imagen:

<img width="320" alt="imagen" src="https://user-images.githubusercontent.com/3290689/70867013-1e950880-1f36-11ea-8fce-ed37a275d874.png">

Seleccionar por ejemplo la rama **mno-2018-1** (u otra) para información del curso de MNO de 2018.

**Dar click en [liga](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1#m%C3%A9todos-num%C3%A9ricos-y-optimizaci%C3%B3n) para la rama del curso del semestre enero-mayo 2020.**

## Breve explicación del repositorio en la rama master.

En la carpeta [C](C) encuentran:

* [C/Clases](C/Clases) para introducción al lenguaje C de programación.

* Dentro de [C/BLAS](C/BLAS) y [C/LAPACK](C/LAPACK) se tienen funciones para ejecución de algunas rutinas de [BLAS](http://www.netlib.org/blas/), [LAPACK](http://www.netlib.org/lapack/) en un sistema ubuntu.

* Dentro de [C/extensiones_a_C/](C/extensiones_a_C) se encuentran las siguientes extensiones al lenguaje de programación C: [C/extensiones_a_C/MPI](C/extensiones_a_C/MPI) para [MPI](http://mpi-forum.org/), [C/extensiones_a_C/Phtreads](C/extensiones_a_C/Pthreads) para [Pthreads](https://computing.llnl.gov/tutorials/pthreads/), [C/extensiones_a_C/openMP](C/extensiones_a_C/openMP) para [openMP](http://www.openmp.org/) y [C/extensiones_a_C/CUDA](C/extensiones_a_C/CUDA) para [CUDA](https://docs.nvidia.com/cuda/cuda-c-programming-guide/).  

* Dentro de [C/extensiones_a_C/CUDA/PyCUDA](C/extensiones_a_C/CUDA/PyCUDA) hay información y ejemplos de uso de [PyCUDA](https://documen.tician.de/pycuda/). También se recomienda revisar el tema de CUDA en [módulo 2 cómputo en paralelo de este repo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico#ii-c%C3%B3mputo-en-paralelo)

En el [Wiki](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki) encuentran información sobre [Amazon Web Services](https://aws.amazon.com/es/).

**Normalmente los pull requests no se hacen a la rama `master` salvo haya una modificación a realizar en tal rama (modificación para algún código o contenido por ejemplo).**

A continuación se presentan links a las notas y material de cada tema. Adicionalmente se encuentran en el directorio [temas](temas).

## Índice de notas. 


Cada número contiene información del tema respectivo, dar click en el tema de interés. Las notas están escritas en [Jupyter notebooks](https://jupyter.org/). Ver [I python, You R, We Julia](https://blog.jupyter.org/i-python-you-r-we-julia-baf064ca1fb6) para algunas características de tales notebooks.

Adicionalmente, algunos temas tienen un botón de [binder](https://mybinder.org/) ![Binder](https://mybinder.org/badge_logo.svg) para ejecutar de forma interactiva el contenido (**ojo: cada botón tiene ambientes de docker distintos por lo que un mismo botón puede no funcionar para notas de temas distintos, p.ej. el botón de la nota 1.2 no funciona para la 1.4**). 

Tenemos otro botón :) Este es de [google colab](https://colab.research.google.com/github/shranith/Colab-intro/blob/master/Colab_intro.ipynb) ![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg) para ejecución de forma interactiva de los notebooks de jupyter en los que se utilizan GPU's para procesamiento. 

Ver [dockerfiles-for-binder](https://github.com/palmoreck/dockerfiles-for-binder) para documentación de las imágenes de [docker](https://www.docker.com/) usadas y en la liga [jupyterhub/binderhub](https://github.com/jupyterhub/binderhub) encuentran información de binder.

Ver [research.google...faq](https://research.google.com/colaboratory/faq.html) y [colab-github-demo](https://github.com/googlecolab/colabtools/blob/master/notebooks/colab-github-demo.ipynb) para más información de google colab.

Ver [Jupyter kernels](https://github.com/jupyter/jupyter/wiki/Jupyter-kernels) para una tabla de los [kernels](https://jupyter.readthedocs.io/en/latest/install-kernel.html) disponibles en jupyter.


## I [Cómputo científico](temas/I.computo_cientifico/)

1.1 [Analisis numérico y cómputo científico.](temas/I.computo_cientifico/1.1.Analisis_numerico_y_computo_cientifico.ipynb) 

1.2 [Sistema de punto flotante.](temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_c_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb) (nota escrita en jupyterlab + kernel de C)


* [Ejercicios punto flotante](https://www.dropbox.com/s/09o9aasjyzya4ff/Punto_flotante.pdf?dl=0)

1.3 [Condición, estabilidad y normas.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb) (nota escrita en jupyterlab)

* [Ejercicios de normas y condición](https://www.dropbox.com/s/78rryxn3i58bg6c/Normas_condicion.pdf?dl=0)

Métodos de diferenciación e integración numérica:

1.4 [Polinomios de Taylor y diferenciación numérica.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.4.Polinomios_de_Taylor_y_diferenciacion_numerica.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.4.Polinomios_de_Taylor_y_diferenciacion_numerica.ipynb) (nota escrita en jupyterlab + kernel de R)


* [Ejercicios Taylor y diferenciación numérica](https://www.dropbox.com/s/n5srgxh2xdisaec/Taylor_y_dif_numerica.pdf?dl=0)

1.5 [Integración numérica](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.5.Integracion_numerica.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.5.Integracion_numerica.ipynb) (nota escrita en jupyterlab)

* [Ejercicios Integración numérica](https://www.dropbox.com/s/vk28jsrh2gwqzo3/Int_numerica.pdf?dl=0)


1.6 [Perfilamiento de código](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento.ipynb)

* [Python](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.6.Perfilamiento_Python.ipynb) (nota escrita en jupyterlab)

* [R](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento_R.ipynb)

* [C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento_C.ipynb) (pendiente)


1.7 Opciones para resolver bottlenecks:

* [Compilar a C, Python + C: Cython](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.7.Compilar_a_C_Cython.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.7.Compilar_a_C_Cython.ipynb) (nota escrita en jupyterlab)

* [Reescribir funciones a C++: Rcpp](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.7.Reescribir_funciones_a_C%2B%2B_Rcpp.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/I.computo_cientifico/1.7.Reescribir_funciones_a_C%2B%2B_Rcpp.ipynb) (nota escrita en jupyterlab + kernel de R)

* Cómputo en paralelo (módulo II).

* Uso del caché y operaciones BLAS (módulo III).

## II [Cómputo en paralelo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/II.computo_paralelo)

2.1 [Un poco de historia y generalidades](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.1.Un_poco_de_historia_y_generalidades.ipynb).


**La descripción y uso de las siguientes librerías/módulos/paquetes/API's no tiene el propósito de ser extensa ni completa pues en un futuro pueden existir herramientas con mejor desempeño, documentación o comunidad. En las referencias de cada nota aparecen ligas y libros con documentación para extender su aprendizaje.** 

2.2 [Sistemas de memoria compartida](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Sistemas_de_memoria_compartida.ipynb)


* Python

    * [Multiprocessing](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Python_multiprocessing.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/II.computo_paralelo/2.2.Python_multiprocessing.ipynb) (nota escrita en jupyterlab)
    
    * [Dask](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Python_dask.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/II.computo_paralelo/2.2.Python_dask.ipynb) (nota escrita en jupyterlab)



* R

    * [Parallel](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.R_parallel.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/II.computo_paralelo/2.2.R_parallel.ipynb) (nota escrita en jupyterlab + kernel de R)


* C

    * [OpenMP](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.C_OpenMP.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_c_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/II.computo_paralelo/2.2.C_OpenMP.ipynb) (nota escrita en jupyterlab + kernel de C)
    
        * Ver: [ejemplos con openMP](C/extensiones_a_C/openMP/ejemplos/), [parallel_and_critical_directives](C/extensiones_a_C/openMP/ejemplos/1_parallel_and_critical_directives/), [reduction_clause](C/extensiones_a_C/openMP/ejemplos/2_reduction_clause/), [parallel_for_directive](C/extensiones_a_C/openMP/ejemplos/3_parallel_for_directive/)


2.3 [CUDA](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.CUDA.ipynb)


* C

    * [CUDA C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.CUDA_C.ipynb) [![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.CUDA_C.ipynb) (nota escrita en jupyterlab + kernel de C)
    
        * Ver: [instalación de CUDA](C/extensiones_a_C/CUDA/instalacion), [ejemplos en CUDA C](C/extensiones_a_C/CUDA/ejemplos/), [CUBLAS](C/extensiones_a_C/CUDA/CUBLAS/), [CUSOLVER](C/extensiones_a_C/CUDA/CUSOLVER/)

* Python

    * [CuPy](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.Python_CuPy.ipynb) [![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.Python_CuPy.ipynb) (nota escrita en jupyterlab)
    
    * PyCUDA (pendiente)
    
        * Ver: [PyCUDA](Python/PyCUDA/)

* R

    * [gputools](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.R_gputools.ipynb) [![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.R_gputools.ipynb) (nota escrita en jupyterlab + kernel de R)
    * Rth (pendiente) ver [Rth-org/Rth](https://github.com/Rth-org/Rth) y más reciente [matloff/Rth](https://github.com/matloff/Rth)
    * gpuR (pendiente) ver [gpuR](https://github.com/cdeterman/gpuR)


* Herramientas adicionales a revisar:

    * [numba](http://numba.pydata.org/), [numba github](https://github.com/numba/numba), [A ~5 minute guide to Numba](https://numba.pydata.org/numba-doc/dev/user/5minguide.html).



## III [Cómputo matricial](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/III.computo_matricial)


3.1 [Vectorizacion, BLAS y el uso del caché eficientemente](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.1.Vectorizacion_BLAS_y_el_uso_del_cache_eficientemente.ipynb)

3.2 OpenBLAS

* Ejemplos:

    * [Python](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.2.Python_OpenBLAS.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_openblas?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/III.computo_matricial/3.2.Python_OpenBLAS.ipynb) (nota escrita en jupyterlab) <- Si utilizan binder hay que ir al home del user jovyan y ejecutar `bash run_installations.sh`
    
    * [R](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.2.R_OpenBLAS.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel_openblas?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/III.computo_matricial/3.2.R_OpenBLAS.ipynb) (nota escrita en jupyterlab + kernel de R) <- Si utilizan binder hay que ir al home del user jovyan y ejecutar `bash run_installations.sh`
    


3.3 [Solucion de sistemas de ecuaciones lineales y factorizaciones matriciales](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.Solucion_de_SEL_y_FM.ipynb)

* Métodos o algoritmos básicos del álgebra lineal para resolver sistemas de ecuaciones lineales y factorizaciones matriciales:

    * [3.3.a Factorización LU](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.a.Factorizacion_LU.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/III.computo_matricial/3.3.a.Factorizacion_LU.ipynb) (nota escrita en jupyterlab)
    * [3.3.b Factorización de Cholesky](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.b.Factorizacion_de_Cholesky.ipynb) (pendiente)
    * [3.3.c Factorización QR](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.c.Factorizacion_QR.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/III.computo_matricial/3.3.c.Factorizacion_QR.ipynb) (nota escrita en jupyterlab)
    * [3.3.d Descomposición en Valores Singulares: SVD](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.d.SVD.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/III.computo_matricial/3.3.d.SVD.ipynb) (nota escrita en jupyterlab)
    * [3.3.e Jacobi y Gauss Seidel](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.e.Jacobi_Gauss-Seidel.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/III.computo_matricial/3.3.e.Jacobi_Gauss-Seidel.ipynb) (nota escrita en jupyterlab)


* [Ejercicios cómputo matricial](https://www.dropbox.com/s/kns8on2z8f0gva3/Computo-matricial.pdf?dl=0)


## IV [Optimización convexa y machine learning](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/IV.optimizacion_convexa_y_machine_learning)

Los resultados de los problemas de optimización revisados en este módulo pueden obtenerse con las herramientas:

* [cvxpy](https://www.cvxpy.org/) y [cvxpy github](https://github.com/cvxgrp/cvxpy). 

* [cvxr](https://cvxr.rbind.io/) y [cvxr github](https://github.com/cvxgrp/CVXR/).

Estas herramientas obtienen resultados de acuerdo a [Disciplined Convex Programming](https://dcp.stanford.edu/).

4.1 [Optimización numérica y machine learning](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.1.Optimizacion_numerica_y_machine_learning.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.1.Optimizacion_numerica_y_machine_learning.ipynb) (nota escrita en jupyterlab)


4.2 [Algoritmos para Unconstrained Convex Optimization](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Algoritmos_para_UCO.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Algoritmos_para_UCO.ipynb) (nota escrita en jupyterlab)

* [Algoritmos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/IV.optimizacion_convexa_y_machine_learning/algoritmos):

    * [Descenso en gradiente](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Descenso_en_gradiente_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Descenso_en_gradiente_Python.ipynb) (nota escrita en jupyterlab)

        * [Descenso en gradiente, implementación en R](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Descenso_en_gradiente_R.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Descenso_en_gradiente_R.ipynb) (nota escrita en jupyterlab + kernel de R)
    
    * [Descenso por coordenadas](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Descenso_por_coordenadas_R.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Descenso_por_coordenadas_R.ipynb) (nota escrita en jupyterlab + kernel de R)

    * [Método de Newton](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Metodo_de_Newton_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.2.Metodo_de_Newton_Python.ipynb) (nota escrita en jupyterlab)
    
 


4.3 Ejemplos de uso de algoritmos para UCO:

* [Mínimos cuadrados](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Minimos_cuadrados_R.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Minimos_cuadrados_R.ipynb) (nota escrita en jupyterlab + kernel de R)

 

* [Regresión logística](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Regresion_logistica_R.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_r_kernel?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Regresion_logistica_R.ipynb) (nota escrita en jupyterlab + kernel de R)


* [Componentes principales](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Componentes_principales_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Componentes_principales_Python.ipynb) (nota escrita en jupyterlab)




4.4 [Algoritmos para Constrained Equality Convex Optimization](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.4.Algoritmos_para_CECO.ipynb)


* [Algoritmos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/IV.optimizacion_convexa_y_machine_learning/algoritmos):


    * [Metodo de Newton para puntos iniciales factibles](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.4.Metodo_de_Newton_para_puntos_iniciales_factibles_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.4.Metodo_de_Newton_para_puntos_iniciales_factibles_Python.ipynb) (nota escrita en jupyterlab)

    * [Metodo de Newton para puntos iniciales no factibles](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.4.Metodo_de_Newton_para_puntos_iniciales_no_factibles_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.4.Metodo_de_Newton_para_puntos_iniciales_no_factibles_Python.ipynb) (nota escrita en jupyterlab)

**Nota del prof: estoy reescribendo las notas y añadiendo botones para interactividad.**  

4.5 Ejemplos de uso de algoritmos para CECO:

* [Modelo de Markowitz](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1/proyecto_final/proyectos/equipos/equipos_2_y_3)


4.6 [Algoritmos para Constrained Inequality and Equality Convex Optimization](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.6.Algoritmos_para_CIECO.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.6.Algoritmos_para_CIECO.ipynb) (nota escrita en jupyterlab)

* [Algoritmos](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/temas/IV.optimizacion_convexa_y_machine_learning/algoritmos)

    * [Metodo de barrera logarítmica para puntos iniciales factibles](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.6.Metodo_de_BL_para_puntos_iniciales_factibles_Python.ipynb) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_numerical?urlpath=lab/tree/analisis-numerico-computo-cientifico/temas/IV.optimizacion_convexa_y_machine_learning/4.6.Metodo_de_BL_para_puntos_iniciales_factibles_Python.ipynb) (nota escrita en jupyterlab)

    * [Metodo de barrera logarítmica para puntos iniciales no factibles]



4.7 Ejemplos de uso de algoritmos para CIECO:

* [Máquina de soporte vectorial para datos linealmente no separables] Ver: [MSV paralelo](https://www.dropbox.com/s/qf416dacvh0nvq6/MSV_RL_tesis_maestria_Erick.pdf?dl=0) para una explicación de la implementación con cómputo en paralelo.


Ver [RAPIDS](https://rapids.ai/)



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

AWS.5 [AWS y Dask](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/5.AWS-y-Dask)

AWS.adicional1 [AWS: Relational Database System]


---

### Antiguo diseño de README:

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



3.3 [Sistemas de ecuaciones lineales: métodos iterativos.](https://www.dropbox.com/sh/uikk6wfh1aqoc6m/AACddaJWDlHa6hMxgdy5DCVza?dl=0)

3.4 [Tensores. Una introducción.](https://www.dropbox.com/s/udwrro2f11j2a0q/3.4.Tensores.pdf?dl=0)

* [Preguntas 3.4](https://www.dropbox.com/s/6p2xzftozyca3uk/preguntas_tensores.txt?dl=0)

3.5 [Aplicaciones del álgebra lineal numérica.](https://www.dropbox.com/s/dfwk0y04ksgfilv/3.3.Aplicaciones_del_algebra_lineal_numerica.pdf?dl=0)

* [Preguntas 3.5](https://www.dropbox.com/s/h3j2acb39twln7o/preguntas_aplicaciones_algebra_lineal_numerica.txt?dl=0)

3.6.1 [Multiplicación de matrices con cómputo en paralelo.](https://www.dropbox.com/s/bgoua82py00h22o/3.4.1.Multiplicacion_de_matrices_con_computo_en_paralelo.pdf?dl=0)

3.6.2 [SVD con cómputo en paralelo.](https://www.dropbox.com/s/p8p905v34uth28w/3.4.2.SVD_con_computo_en_paralelo.pdf?dl=0)


* [Preguntas 3.1.1](https://www.dropbox.com/s/s72yem79ef10k9h/preguntas_multiplicacion_matrices_y_estructura_de_datos.txt?dl=0)

* [Preguntas 3.1.2](https://www.dropbox.com/s/zbjd153jhhhc8os/preguntas_localidad_y_vectorizacion_analisis_del_error.txt?dl=0)


* [Preguntas 3.2.1](https://www.dropbox.com/s/g3w9sfa09nkn94p/preguntas_eliminacion_Gaussiana_factorizacion_LU.txt?dl=0)

* [Preguntas 3.2.2](https://www.dropbox.com/s/iwpn6a8nr7w6h5d/preguntas_SVD_QR_Cholesky.txt?dl=0)



* [Preguntas 4.1](https://www.dropbox.com/s/kg57u7dulqnuou9/preguntas_intro_optimizacion.txt?dl=0)

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

