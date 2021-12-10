## Equipo 6

Integrantes:

* Nyrma Paulina Hernandez Trejo

* Mario Arturo Heredia Trejo

* Juan Carlos Ramirez Cabrera

Título del proyecto: **Indice de incidencia delictiva con PCA**

Objetivo del proyecto: **Crear una medición que permita cuantificar y monitorear la situación delictiva del país a nivel estatal a lo largo del tiempo**

[Repo en el que se trabaja](https://github.com/mhnk77/Optim_proyecto_final)

Trabajo escrito (fuera del repo): [Link al trabajo escrito](https://github.com/mhnk77/Optim_proyecto_final/blob/main/reporte/MNO_Reporte_Final_vfinal.pdf)


En el [notebook](https://github.com/mhnk77/Optim_proyecto_final/blob/main/notebooks/calculo_indice_PCA.ipynb) se encuentra código utilizado para la primer implementación del PCA utilizando funciones de Numpy

Aquí entonctramos la [presentación](https://github.com/mhnk77/Optim_proyecto_final/blob/main/resultados/presentacion.pdf)

Aquí está el [visualizador](https://datastudio.google.com/reporting/e4ffda99-e143-4e69-9454-391ea1796dc6)




### Avances

En la carpeta [avance1](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/optimizacion-2021/proyecto_final/proyectos/equipos/equipo_6/avance_1) se encuentra el reporte del primer avance en nuestro proyecto. 

Carpeta de [avance2](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/optimizacion-2021/proyecto_final/proyectos/equipos/equipo_6/avance_2)

Y [avance3 y ultimo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/optimizacion-2021/proyecto_final/proyectos/equipos/equipo_6/avance_3)

Referencias del proyecto:

* [Stanford Lecture Notes about PCA using QR factorization](https://web.stanford.edu/class/cme335/lecture6.pdf)
* [PCA and SVD explained with numpy](https://towardsdatascience.com/pca-and-svd-explained-with-numpy-5d13b0d2a4d8)


### Descripción general del proyecto

El día 17 de noviembre tuvimos una reunión virtual con Erick en la que se propuso y acordó trabajar en el siguiente proyecto:

Una construcción de un "índice de incidencia delictiva" similar a lo que CONAPO hace con el índice de marginación.

Para llevar a cabo dicho proyecto, se utilizarán datos públicos del Secretariado Ejecutivo del Sistema Nacional de Seguridad Pública.

Dichos datos contienen incidencias de distintos delitos, desde enero 2015 hasta octubre 2021 a nivel mensual y por estado. La meta final será realizar calcular un índice que nos permita ver qué estados tienen una mayor incidencia delictiva.

La metodología a emplear será la siguiente:

Se utilizarán un PCA  (análisis de componentes principales) para descomponer en dimensiones los datos con los que se trabaja. 
Dicho PCA será ejecutado de dos maneras:
 - Primero con funciones ya elaboradas de algún paquete de Python
 - Posteriormente con funciones de elaboración propia del equipo.
 
Además de la construcción y cálculo del índice, se hará una comparación de los resultados de ámbos métodos, buscando explicar las diferencias que se encuentren entre uno y otro.
