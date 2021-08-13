# Optimización

En este repositorio encuentran el contenido para los cursos de **optimización**\* (*aka* opt) y **optimización avanzada**\* (*aka* opt2) impartida en la maestría de ciencia de datos del ITAM por el prof. Erick Palacios Moreno, github: [palmoreck](https://github.com/palmoreck). 

\*El curso de optimización se imparte en agosto-diciembre y el de optimización avanzada en enero-mayo.

### Se ha creado el siguiente libro\* con el contenido de los temas en [libro de optimización](https://itam-ds.github.io/analisis-numerico-computo-cientifico/) para su consulta. Este libro seguiremos a lo largo de los cursos.

\*El libro fue creado con [jupyter book](https://jupyterbook.org/intro.html).

### En [temario-opt](https://drive.google.com/file/d/1dj7bU5uN_ngEhUxhKL9YzCfPGLVc8Z0j/view?usp=sharing) encuentran el temario de optimización.

### En [pres-opt](https://hackmd.io/@palmoreck/Hkr5rVQ-v) encuentran una presentación de introducción al curso de optimización 2021.

### Dar click en el siguiente botón para unirse\* al chat del curso de optimización 2021 en [gitter](https://gitter.im/): [![Gitter](https://badges.gitter.im/optimizacion-2021/community.svg)](https://gitter.im/optimizacion-2021/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

\***Se puede hacer el registro con su cuenta de [github](https://github.com/)**.

---

## Optimización avanzada

### En [temario-opt-2](https://drive.google.com/file/d/17ydFChBFxxAOzsIPwUu90KR01zRXdCNZ/view?usp=sharing) encuentran el temario de optimización avanzada.

### En [opt](https://analisis-numerico-computo-cientifico.readthedocs.io/) se obtiene documentación de un paquete de *Python* que sirve de apoyo para los ejemplos de las notas.

### En [pres-opt-2](https://hackmd.io/@palmoreck/SklS4hhAD#/) encuentran una presentación de introducción al curso de optimización avanzada 2021.

---

### Imágenes de *Docker* creadas

|Curso| Imagen|
|:---:|:---:|
|Optimización | [palmoreck/jupyterlab_optimizacion:3.1.0](https://github.com/palmoreck/dockerfiles/tree/master/jupyterlab/optimizacion)|
|Optimización avanzada | [palmoreck/jupyterlab_optimizacion_2:3.1.0](https://github.com/palmoreck/dockerfiles/tree/master/jupyterlab/optimizacion_2)

Tales imágenes se descargan con un `docker pull` desde la terminal una vez hayan instalado *docker*\* en sus computadoras. En cada nota del libro se indica el comando `docker run` para correr los contenedores. O bien de acuerdo a la documentación de la imagen, ver por ejemplo [running optimizacion docker image in a docker container](https://github.com/palmoreck/dockerfiles/blob/master/jupyterlab/optimizacion/README.md#running-jupyterlab_optimizacion-docker-image-in-a-docker-container), [running optimizacion_2 docker image in a docker container](https://github.com/palmoreck/dockerfiles/blob/master/jupyterlab/optimizacion_2/README.md#running-jupyterlab_optimizacion_2-docker-image-in-a-docker-container) . 

\*Ver [herramientas/docker/](https://github.com/ITAM-DS/Propedeutico/tree/main/herramientas/docker) para referencias de [docker](https://www.docker.com/).


## Organización de github classroom para optimización 2021

La organización [optimizacion-2021-gh-classroom](https://github.com/optimizacion-2021-gh-classroom) fue creada para alojar sus repositorios de [github classroom](https://classroom.github.com/) en los que entregarán sus prácticas. Ver [github education](https://github.com/education) como una referencia.

## Ramas del repositorio.

En este repositorio se han creado diferentes ramas que pueden ser accesadas como se aprecia en esta imagen:

<img width="320" alt="imagen" src="https://user-images.githubusercontent.com/3290689/89135347-8a8ea600-d4f2-11ea-9699-0395fd784ebd.png">

Seleccionar por ejemplo la rama **mno-2019-1** (u otra) para información del curso de MNO de 2019.

**Dar click en [optimizacion-2021](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/optimizacion-2021) para la rama del curso de optimización 2021.**

La rama [gh-pages](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/gh-pages) contiene los `html`s para visualización del [libro de optimización](https://itam-ds.github.io/analisis-numerico-computo-cientifico/).


## Breve explicación del repositorio en la rama *main* y su *wiki*.

En el [Wiki](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki) encuentran información sobre [Amazon Web Services](https://aws.amazon.com/es/).

En el directorio [libro_optimizacion/temas/](libro_optimizacion/temas/) están las notas escritas. 

## Sobre las notas. 

Las notas de cada tema están escritas en [Jupyter](https://jupyter.org/) *notebooks*. Ver [I python, You R, We Julia](https://blog.jupyter.org/i-python-you-r-we-julia-baf064ca1fb6) para algunas características de tales *notebooks*. Ver [notebook](https://jupyterlab.readthedocs.io/en/stable/user/notebook.html) para funcionalidad de los *notebooks*. Ver [Jupyter kernels](https://github.com/jupyter/jupyter/wiki/Jupyter-kernels) para una tabla de los [jupyter-kernels](https://jupyter.readthedocs.io/en/latest/install.html?highlight=install%20kernel#jupyter-kernels) disponibles en *jupyter* (que hacen posible ejecutar instrucciones en el lenguaje *R*, por ejemplo).

### Interactividad

Para ejecutar las notas de forma interactiva dar click en el botón de [binder](https://mybinder.org/) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_optimizacion_2?urlpath=lab/tree/analisis-numerico-computo-cientifico/) o bien dentro del [libro de optimización](https://itam-ds.github.io/analisis-numerico-computo-cientifico/) colocarse sobre el ícono :rocket: 

![binder_thebe_screenshot_jupyter_book](https://user-images.githubusercontent.com/3290689/89106057-42855b80-d3ec-11ea-8519-97f32b66570d.png)

y elegir una ejecución interactiva de los notebooks vía *binder*\* o [thebe](https://github.com/executablebooks/thebe). La ejecución con `thebe` se puede hacer directamente en la liga del libro o si se descargan los archivos a su máquina local también es posible la ejecución (pero requieren conexión a internet en cualquier opción).

\*En la liga [jupyterhub/binderhub](https://github.com/jupyterhub/binderhub) encuentran más información sobre *binder*.

### Para convertir notas a pdf

Usar botón de [binder](https://mybinder.org/) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/palmoreck/dockerfiles-for-binder/jupyterlab_optimizacion_2?urlpath=lab/tree/analisis-numerico-computo-cientifico/)

Abrir una nueva terminal y ejecutar lo siguiente:

```
bash
cd analisis-numerico-computo-cientifico/libro_optimizacion/temas/
jb build . --builder pdfhtml
```

El pdf estará dentro del directorio `analisis-numerico-computo-cientifico/libro_optimizacion/temas/_build/pdf`. Y se puede descargar:

<img width="350" alt="imagen" src="https://user-images.githubusercontent.com/3290689/89846762-c60b1f00-db47-11ea-8d2e-1d21b92ae8b5.png">


<img width="350" alt="imagen" src="https://user-images.githubusercontent.com/3290689/89846768-c9060f80-db47-11ea-8ab0-131e925732ec.png">

### Nota: durante el segundo semestre del 2021 se estarán haciendo cambios continuamente por lo que tendrán que actualizar su descarga, clon o *fork*.

