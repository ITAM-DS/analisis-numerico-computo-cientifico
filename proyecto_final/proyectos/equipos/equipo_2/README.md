# Proyecto_SVD_OPT
Proyecto final métodos númericos y optimización

## Equipo 2

Integrantes:

* Yusuri Arciga Reyes
* Aide Jazmín González Cruz
* Karina Lizette Gamboa Puente
* Oscar Arturo Bringas López


### **Título del proyecto**: Sistema de recomendación de establecimientos para clientes de BBVA


#### **Objetivo del proyecto**: 

Explotar los conocimientos adquiridos en la materia de Métodos Numéricos I (Optimización), particularmente se busca aplicar el aprendizaje relacionado a SVD en aplicaciones de sistemas de recomendación.

**Contenido:**

- Carpeta [data](https://github.com/AideJGC/Proyecto_SVD_OPT/tree/main/data) Contiene la base de entrenamiento y prueba en formato txt, utiles para R las cuales no tienen encabezados, también puede ser útiles para Python, sin embargo, en el archivo de implementación de la librería en Python estas pueden obtenerse a partir de los archivos originales.

- Carpeta [img](https://github.com/AideJGC/Proyecto_SVD_OPT/tree/main/img) Cuenta con los resultados de las corridas realizadas en Python como en R.

- Carpeta [notebooks](https://github.com/AideJGC/Proyecto_SVD_OPT/tree/main/notebooks) Cuenta con el [EDA - GEDA](https://github.com/AideJGC/Proyecto_SVD_OPT/blob/main/notebooks/EDA_BBVA.ipynb) del `data set`con el que se trabajo, y los archivos donde se implemento la librería `libmf` tanto en [Python](https://github.com/AideJGC/Proyecto_SVD_OPT/blob/main/notebooks/Implementacion_LIBMF_Python.ipynb) como en [R](https://github.com/AideJGC/Proyecto_SVD_OPT/blob/main/notebooks/Implementacion_LIBMF_R.Rmd).

- Carpeta [src](https://github.com/AideJGC/Proyecto_SVD_OPT/tree/main/src) Cuenta con la librería `utils.py` necesaria para el tratamiento de datos en el EDA - GEDA, y la librería `functions.py` en la que se programo el algoritmo QR, pero que no se logró utilizar en este proyecto.



**Recursos externos:**


Trabajo escrito [liga_trabajo_escrito](https://drive.google.com/file/d/18BbDeOR05CJearVb1k0JN5lOGdvswdQm/view?usp=sharing)

Presentación [liga_presentación](https://docs.google.com/presentation/d/19ktgKm-Y7yiB1-d_LxG4JBRG6ZZ0iNlh00RU5qPILpw/edit#slide=id.p1)

Acceso a carpeta de seguimiento del proyecto [Drive](https://drive.google.com/drive/u/2/folders/1615XRAEYcm5-ao3OmS8FfB10SQJom5Ki)

Liga del repositorio [liga_repo](https://github.com/AideJGC/Proyecto_SVD_OPT/)


**Referencias del proyecto:**

***SVD***

* [Introducción a Sistemas de Recomendación](https://blog.bi-geek.com/introduccion-a-sistemas-de-recomendacion/)

* [Sistemas de recomendación | Qué son, tipos y ejemplos. Grapheverywhere](https://www.grapheverywhere.com/sistemas-de-recomendacion-que-son-tipos-y-ejemplos/)

* [¿Qué Es Un Sistema De Recomendación?](https://www.smarthint.co/es/que-es-un-sistema-de-recomendacion-2/)

* [Algoritmo SVD aplicado a los sistemas de recomendación en el comercio](https://revistas.udistrital.edu.co/index.php/tia/article/view/11827)


***Factorización de la matriz no negativa***

* [Non-Negative Matrix Factorization (NMF) for Recommender Systems](https://medium.com/@farnazgh73/non-negative-matrix-factorization-nmf-4798d29e8c62)


***LIBMF***

* [Fast Parallel Stochastic Gradient Method for Matrix Factorization in Shared Memory Systems](https://www.csie.ntu.edu.tw/~cjlin/papers/libmf/libmf_journal.pdf)

* [A Learning-rate Schedule for Stochastic Gradient Methods to Matrix Factorization](https://www.csie.ntu.edu.tw/~cjlin/papers/libmf/mf_adaptive_pakdd.pdf)

* [LIBMF: A Library for Parallel Matrix Factorization in Shared-memory Systems](https://www.csie.ntu.edu.tw/~cjlin/papers/libmf/libmf_open_source.pdf)

* [libmf](https://github.com/cjlin1/libmf)

* [python-libmf](https://github.com/PorkShoulderHolder/python-libmf/tree/master/libmf)

* [recosystem.](https://cran.r-project.org/web/packages/recosystem/recosystem.pdf)




