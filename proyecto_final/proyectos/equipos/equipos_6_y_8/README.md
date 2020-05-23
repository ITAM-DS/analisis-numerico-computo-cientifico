# Proyecto Final de la materia de Métodos Numéricos y Optimización de la Maestría en Ciencia de Datos

## [Equipos 6 y 8](equipos/equipos_6_y_8)

**Profesor:** Erick Palacios Moreno

### Integrantes del equipo

| # | Alumno                            | Clave única | usuario de Github                                              |Roles|
|---|-----------------------------------|-------------|----------------------------------------------------------------|---|
| 1 | Angel Rafael Ortega Ramírez       | 123972      | [123972](https://github.com/123972)                            |Project Manager|
| 2 | Elizabeth Rodriguez               | 191430      | [erodriguezul](https://github.com/erodriguezul)                |Revisión de código|
| 3 | Karla Alfaro Pizaña               | 137314      | [alpika19186](https://github.com/alpika19186)                  |Revisión de código |
| 4 | Leonardo Marín                    | 175903      | [leonardomarintellez](https://github.com/leonardomarintellez)  |Programador|
| 5 | Mario Rodríguez                   | 164471      |[shimanteko](https://github.com/shimanteko)   |Programador|
| 6 | Elizabeth Viveros                 | 161224      |[ElyVV](https://github.com/ElyVV)   |Programadora|

Ttulo del proyecto: `Análisis de Componentes Principales y Regresión: PCA-R`

Objetivo del proyecto: implementar un método numérico aplicado a un  
problema real. En este caso el método numérico que se analiza es el de A
nálisis de Componentes Principales (PCA) con el método de SVD y de Jacobi  
one-sided. El problema de aplicación es intentar explicar los puntajes en
 Matemáticas y Lenguaje y Comunicación en la prueba PLANEA ELCE MS 2016  
 usando, principalmente, las respuestas a un cuestionario de contexto que  
 se aplicó a los alumnos.equipo_ejemplo

## Ligas importantes

[Repositorio del equipo:](https://github.com/123972/Final-Project-MNO-2020)

* [Trabajo escrito](https://github.com/123972/Final-Project-MNO-2020/blob/master/results/reporte_final.ipynb)
* [Presentacion](https://github.com/123972/Final-Project-MNO-2020/tree/master/results)
* [Implementacion](https://github.com/123972/Final-Project-MNO-2020/blob/master/results/reporte_final.ipynb)

## Rutas a los avances  

[Avances del proyecto](equipos/equipos_6_y_8):

* [Avance 1](https://github.com/123972/Final-Project-MNO-2020/tree/master/avances/Avance_1)
* [Avance 2](https://github.com/123972/Final-Project-MNO-2020/tree/master/avances/Avance_2)
* [Avance 3](https://github.com/123972/Final-Project-MNO-2020/tree/master/avances/Avance_3)

## Estructura del repositorio

La estructura del repositorio está basado en [este](https://drivendata.github.io/cookiecutter-data-science/) template y
 está organizado de la siguiente forma:

* Carpeta [avances](https://github.com/123972/Final-Project-MNO-2020/tree/master/avances): contiene
 los avances de cada una de las etapas del proyecto.

* Carpeta [data](https://github.com/123972/Final-Project-MNO-2020/tree/master/data): contiene la base de datos a utilizar,
así como información sobre el procedimiento de feature engineering a seguir para unir ambas bases de datos y la limpieza
de las variables.

* Carpeta [docker](https://github.com/123972/Final-Project-MNO-2020/tree/master/docker): Contiene la información  
pertienete para poder correr los scripts y notebooks en un contenedor de docker.

* Carpeta [docs](https://github.com/123972/Final-Project-MNO-2020/tree/master/docs): Contiene el cuestionario utlilizado
durante la encuesta en la que se obtuvieron los datos utilizados en este proyecto, así como las  
[imágenes](https://github.com/123972/Final-Project-MNO-2020/tree/master/docs/images) empleadas en el README.md y las  
[referencias](https://github.com/123972/Final-Project-MNO-2020/tree/master/docs/References) utilizadas durante el  
proyecto.

* Carpeta [environment](https://github.com/123972/Final-Project-MNO-2020/tree/master/environment/mno_env): Contiene el  
ambiente con las instalaciones de python empleadas en este proyecto. Dichas instalaciones también se pueden instalar vía
el archivo de requirements.txt

* Carpeta [notebooks](https://github.com/123972/Final-Project-MNO-2020/tree/master/notebooks): Contiene cinco carpetas  
con los notebooks y scripts de la sección del  
[EDA](https://github.com/123972/Final-Project-MNO-2020/tree/master/notebooks/EDA),  
[Feature Engineering](https://github.com/123972/Final-Project-MNO-2020/tree/master/notebooks/feature_engineering),  
[Feature Selection](https://github.com/123972/Final-Project-MNO-2020/tree/master/notebooks/feature_selection)
 y de los equipos de [Programación](https://github.com/123972/Final-Project-MNO-2020/tree/master/notebooks/Programacion)
  y [Revisión](https://github.com/123972/Final-Project-MNO-2020/tree/master/notebooks/Revision).  

* Carpeta [results](https://github.com/123972/Final-Project-MNO-2020/tree/master/results):Esta carpeta contiene los resultados obtenidos por el proyecto, así como la presentación y el reporte final.

* Carpeta [src](https://github.com/123972/Final-Project-MNO-2020/tree/master/src): Incluye todos los scripts separados en tres secciones: [feature engineering](https://github.com/123972/Final-Project-MNO-2020/tree/master/src/feature_engineering), [feature selection](https://github.com/123972/Final-Project-MNO-2020/tree/master/src/feature_selection), [PCA](https://github.com/123972/Final-Project-MNO-2020/tree/master/src/pca) y [test algorithms](https://github.com/123972/Final-Project-MNO-2020/tree/master/src/test_algorithms)  

* Carpeta [tests](https://github.com/123972/Final-Project-MNO-2020/tree/master/tests):[Incluye algunas pruebas y el perfilamiento](https://github.com/123972/Final-Project-MNO-2020/tree/master/tests)

## Referencias del proyecto

El algoritmo de PCA

Podemos encontrar la documentación de este repositorio en las siguientes ligas:

* Implementación mediante método de la potencia:
  * [The power method for aproximating eigenvalues](https://ergodic.ugr.es/cphys/LECCIONES/FORTRAN/power_method.pdf)
  * [Power Method with Inverse & Rayleigh](https://www.youtube.com/watch?v=LHlg_lfihiA)
  * [Lecture #8: PCA and the Power Iteration Method](http://theory.stanford.edu/~tim/s15/l/l8.pdf)
  * [Principal Components](https://researcher.watson.ibm.com/researcher/files/ie-jakub.marecek/ch08_eigenvalues_handout.pdf)
  
La referencia del método de Halko al que hace alusión el paquete de scikit-learn, lo podemos encontrar en la siguiente liga:

* [Finding Structure with Randomness: Probabilistic Algorithms for Constructing Approximate Matrix Decompositions∗](http://users.cms.caltech.edu/~jtropp/papers/HMT11-Finding-Structure-SIREV.pdf)