# analisis-numerico-computo-cientifico.

Este es el repositorio para la materia de "Métodos Numéricos y Optimización (MNO)"  (aka optimización) impartida en la maestría de ciencia de datos del ITAM por el **Prof. Erick Palacios Moreno**, github: [palmoreck](https://github.com/palmoreck).

### Dar click en [liga](https://drive.google.com/file/d/1dj7bU5uN_ngEhUxhKL9YzCfPGLVc8Z0j/view?usp=sharing) para el temario.

### Libro con el contenido de los temas en [libro de optimización](https://itam-ds.github.io/analisis-numerico-computo-cientifico/)

En esencia el curso sigue un desarrollo de acuerdo al siguiente dibujo:

<img src="https://dl.dropboxusercontent.com/s/0hqal8ni3d5rbso/curso_MNO.png?dl=0" heigth="300" width="300">

Los módulos del 1 al 3 constituyen *building blocks* para el módulo 4.


### Dar click en el siguiente botón para unirse\* al chat del curso de optimización del segundo semestre 2020 en [gitter](https://gitter.im/): [![Gitter](https://badges.gitter.im/optimizacion-2020-2/community.svg)](https://gitter.im/optimizacion-2020-2/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

\***Se puede hacer el registro con su cuenta de [github](https://github.com/)**.

### En el curso de optimización utilizaremos la imagen de [docker](https://www.docker.com/) `palmoreck/jupyterlab_optimizacion:2.1.4` cuya documentación la encuentran en [aquí](https://github.com/palmoreck/dockerfiles/tree/master/jupyterlab/optimizacion)\*. 

\* Tal imagen de docker se descarga con un `docker pull palmoreck/` desde la terminal una vez hayan instalado docker en sus computadoras. Ver [herramientas/docker/](https://github.com/ITAM-DS/Propedeutico/tree/master/herramientas/docker) para referencias de docker.


## Ramas del repositorio.

En este repositorio se han creado diferentes ramas que pueden ser accesadas como se aprecia en esta imagen:

<img width="320" alt="imagen" src="https://user-images.githubusercontent.com/3290689/70867013-1e950880-1f36-11ea-8fce-ed37a275d874.png">

Seleccionar por ejemplo la rama **mno-2018-1** (u otra) para información del curso de MNO de 2018.

**Dar click en [liga]() para la rama del curso del semestre agosto-diciembre 2020.**

## Breve explicación del repositorio en la rama master.

En la carpeta [C](C) encuentran:

* [C/Clases](C/Clases) para introducción al lenguaje C de programación.

* Dentro de [C/BLAS](C/BLAS) y [C/LAPACK](C/LAPACK) se tienen funciones para ejecución de algunas rutinas de [BLAS](http://www.netlib.org/blas/), [LAPACK](http://www.netlib.org/lapack/) en un sistema ubuntu.

* Dentro de [C/extensiones_a_C/](C/extensiones_a_C) se encuentran las siguientes extensiones al lenguaje de programación C: [C/extensiones_a_C/MPI](C/extensiones_a_C/MPI) para [MPI](http://mpi-forum.org/), [C/extensiones_a_C/Phtreads](C/extensiones_a_C/Pthreads) para [Pthreads](https://computing.llnl.gov/tutorials/pthreads/), [C/extensiones_a_C/openMP](C/extensiones_a_C/openMP) para [openMP](http://www.openmp.org/) y [C/extensiones_a_C/CUDA](C/extensiones_a_C/CUDA) para [CUDA](https://docs.nvidia.com/cuda/cuda-c-programming-guide/).  

* Dentro de [C/extensiones_a_C/CUDA/PyCUDA](C/extensiones_a_C/CUDA/PyCUDA) hay información y ejemplos de uso de [PyCUDA](https://documen.tician.de/pycuda/). También se recomienda revisar el tema de CUDA en [módulo 2 cómputo en paralelo de este repo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico#ii-c%C3%B3mputo-en-paralelo)

En el [Wiki](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki) encuentran información sobre [Amazon Web Services](https://aws.amazon.com/es/).

**Normalmente los pull requests no se hacen a la rama `master` salvo haya una modificación a realizar en tal rama (modificación para algún código o contenido por ejemplo).**

Las notas y material de cada tema se encuentran en el directorio [libro_optimizacion/temas/](libro_optimizacion/temas/).

## Sobre las notas. 

Las notas de cada tema están escritas en [Jupyter notebooks](https://jupyter.org/). Ver [I python, You R, We Julia](https://blog.jupyter.org/i-python-you-r-we-julia-baf064ca1fb6) para algunas características de tales notebooks. Ver [notebook](https://jupyterlab.readthedocs.io/en/stable/user/notebook.html) para funcionalidad de los notebooks. Ver [Jupyter kernels](https://github.com/jupyter/jupyter/wiki/Jupyter-kernels) para una tabla de los [kernels](https://jupyter.readthedocs.io/en/latest/install-kernel.html) disponibles en jupyter (que hacen posible ejecutar instrucciones en el lenguaje R, por ejemplo, en tales notebooks).

Adicionalmente, algunos temas tienen un botón de [binder](https://mybinder.org/) ![Binder](https://mybinder.org/badge_logo.svg) para ejecutar de forma interactiva el contenido (**ojo: cada botón tiene ambientes de docker distintos por lo que un mismo botón puede no funcionar para notas de temas distintos, p.ej. el botón de la nota 1.2 no funciona para la 1.4**). 

Tenemos otro botón :) Este es de [google colab](https://colab.research.google.com/github/shranith/Colab-intro/blob/master/Colab_intro.ipynb) ![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg) para ejecución de forma interactiva de los notebooks de jupyter en los que se utilizan GPU's para procesamiento. 

Ver [dockerfiles-for-binder](https://github.com/palmoreck/dockerfiles-for-binder) para documentación de las imágenes de [docker](https://www.docker.com/) usadas y en la liga [jupyterhub/binderhub](https://github.com/jupyterhub/binderhub) encuentran información de binder.

Ver [research.google...faq](https://research.google.com/colaboratory/faq.html) y [colab-github-demo](https://github.com/googlecolab/colabtools/blob/master/notebooks/colab-github-demo.ipynb) para más información de google colab.


## Organización de github classroom

La organización [optimizacion-2020-2-gh-classroom](https://github.com/optimizacion-2020-2-gh-classroom) fue creada para alojar repositorios de [github classroom](https://classroom.github.com/) (ver [github education](https://github.com/education)). Esta organización será nuestro *playground* para el curso de optimización :)

