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

Ttulo del proyecto: `Análisis de Componentes Principales para Clasificación de Grupos de Comida con Base en su Información Nutrimental`

Objetivo del proyecto: El objetivo de este proyecto es implementar un método numérico aplicado a un problema real. En este caso el método numérico que se analiza es el de Análisis de Componentes Principales (PCA) con el método de SVD, algoritmo QR y método de la potencia. El problema de aplicación es un análisis no supervisado de clasificación para agrupar distintos alimentos con base en su información nutrimental habiendo eliminado, primeramente, la multicolinealidad existente en la base.

## Ligas importantes

**Sobre el repositorio actual:**
[Repositorio del equipo:](https://github.com/123972/PCA-nutricion)

* [Trabajo escrito](https://github.com/123972/PCA-nutricion/blob/master/results/reporte_final.ipynb)
* [Presentacion](https://github.com/123972/PCA-nutricion/blob/master/results/PCA_presentacion.pptx)
* [Implementacion](https://github.com/123972/PCA-nutricion/blob/master/results/reporte_final.ipynb)

**Repositorio anterior**
[Repositorio del equipo:](https://github.com/123972/Final-Project-MNO-2020)

* [Trabajo escrito](https://github.com/123972/Final-Project-MNO-2020/blob/master/results/reporte_final.ipynb)
* [Presentacion](https://github.com/123972/Final-Project-MNO-2020/tree/master/results)
* [Implementacion](https://github.com/123972/Final-Project-MNO-2020/blob/master/results/reporte_final.ipynb)

## Rutas a los avances  

[Avances del proyecto](equipos/equipos_6_y_8):

* [Avance 1](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1/proyecto_final/proyectos/equipos/equipos_6_y_8/avance1)
* [Avance 2](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1/proyecto_final/proyectos/equipos/equipos_6_y_8/avance2)
* [Avance 3](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1/proyecto_final/proyectos/equipos/equipos_6_y_8/avance3)
* [Avance 4](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1/proyecto_final/proyectos/equipos/equipos_6_y_8/avance4)

## Fechas

| # | Milestone/avance                                           | Fecha       | Entregable                                                 |
|---|------------------------------------------------------------|-------------|------------------------------------------------------------|
| 1 | Avance 1:Selección de BD, lenguaje, tema, roles            | 25/Abril    | README.md en Avance_1                                      |
| 2 | Avance 2: EDA & Feature Engineering y código simple        | 16/Mayo     | Notebooks de EDA & FE                                      |
| 3 | Avance 3: Revisión y reporte final                         | 21/Mayo     | Notebooks del funcionamiento, notebook del Reporte final   |
| 4 | Presentación del proyecto                                  | Examen Final| Notebook Reporte Final y explicación                       |

## Estructura del repositorio

## Estructura del nuevo repositorio

La estructura del repositorio está basado en [este](https://drivendata.github.io/cookiecutter-data-science/) template y
 está organizado de la siguiente forma:

* Carpeta [avances](https://github.com/123972/PCA-nutricion/tree/master/avances): contiene
 los avances de cada una de las etapas del proyecto.

* Carpeta [data](https://github.com/123972/PCA-nutricion/tree/master/data): contiene la base de datos a utilizar,
así como información sobre el procedimiento de feature engineering a seguir para unir ambas bases de datos y la limpieza
de las variables.

* Carpeta [docker](https://github.com/123972/PCA-nutricion/tree/master/docker): Contiene la información  
pertienete para poder correr los scripts y notebooks en un contenedor de docker.

* Carpeta [docs](https://github.com/123972/PCA-nutricion/tree/master/docs): Contiene el cuestionario utlilizado
durante la encuesta en la que se obtuvieron los datos utilizados en este proyecto, así como las  
[imágenes](https://github.com/123972/PCA-nutricion/tree/master/docs/images) empleadas en el README.md y las  
[referencias](https://github.com/123972/PCA-nutricion/tree/master/docs/References) utilizadas durante el  
proyecto.

* Carpeta [environment](https://github.com/123972/PCA-nutricion/tree/master/environment): Contiene el  
ambiente con las instalaciones de python empleadas en este proyecto. Dichas instalaciones también se pueden instalar vía
el archivo de requirements.txt

* Carpeta [notebooks](https://github.com/123972/PCA-nutricion/tree/master/notebooks): Contiene cinco carpetas  
con los notebooks y scripts de la sección del  
[EDA](https://github.com/123972/PCA-nutricion/tree/master/notebooks/EDA),  
[Programación](https://github.com/123972/PCA-nutricion/tree/master/notebooks/Programacion)
  y [Revisión](https://github.com/123972/PCA-nutricion/tree/master/notebooks/Revision).  

* Carpeta [results](https://github.com/123972/PCA-nutricion/tree/master/results):Esta carpeta contiene los resultados obtenidos por el proyecto, así como la presentación y el reporte final.

* Carpeta [src](https://github.com/123972/PCA-nutricion/tree/master/src): Incluye todos los scripts separados en dos secciones:[PCA](https://github.com/123972/PCA-nutricion/tree/master/src/pca) y [test algorithms](https://github.com/123972/PCA-nutricion/tree/master/src/test_algorithms)

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

* Palacios M. Erick, Notas de MNO 2020, [SVD](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.d.SVD.ipynb)
* Palacios M. Erick, Notas de MNO 2020, [Componentes principales](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Componentes_principales_Python.ipynb)
* Rencher, Alvin C & William F. Christensen. (2012). Methods of Multivariate Analysis. Department of Statistics, Brigham Young University, Provo, UT.- Third Edition. Ch 12.
* Sharma Subhash. (1996). Applied Multivariate Techniques. University of South Carolina. Ch4.
* Equipo SVD, [Examen de cómputo matricial equipo SVD](https://github.com/mno-2020-gh-classroom/ex-modulo-3-comp-matricial-svd-czammar).  
