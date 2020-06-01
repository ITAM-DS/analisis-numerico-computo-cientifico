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
* [Presentacion](https://github.com/123972/PCA-nutricion/blob/master/results/PCA_presentacion.pdf)
* [Implementacion](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/mno-2020-1/proyecto_final/proyectos/equipos/equipos_6_y_8/codigo)


**Repositorio anterior**
[Repositorio del equipo:](https://github.com/123972/Final-Project-MNO-2020)

* [Trabajo escrito](https://github.com/123972/Final-Project-MNO-2020/blob/master/results/reporte_final.ipynb)
* [Presentacion](https://github.com/123972/Final-Project-MNO-2020/blob/master/results/PCA_presentacion.pptx)
* [Implementacion](https://github.com/123972/Final-Project-MNO-2020/tree/master/src)

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

La estructura del repositorio está basado en [este](https://drivendata.github.io/cookiecutter-data-science/) template y
 está organizado de la siguiente forma:

- Carpeta [avances](https://github.com/123972/PCA-nutricion/tree/master/avances): contiene
 los avances de cada una de las etapas del proyecto.

- Carpeta [data](https://github.com/123972/PCA-nutricion/tree/master/data): contiene la base de datos a utilizar.

- Carpeta [docker](https://github.com/123972/PCA-nutricion/tree/master/docker): Contiene la información 
pertienete para poder correr los scripts y notebooks en un contenedor de docker.

- Carpeta [docs](https://github.com/123972/PCA-nutricion/tree/master/docs): Contiene la carpeta 
[img](https://github.com/123972/PCA-nutricion/tree/master/docs/img) que incluye las imagenes empleadas en el reporte final.

- Carpeta [environment](https://github.com/123972/PCA-nutricion/tree/master/environment): Contiene el 
ambiente con las instalaciones de python empleadas en este proyecto. Dichas instalaciones también se pueden instalar vía
el archivo de requirements.txt

- Carpeta [notebooks](https://github.com/123972/PCA-nutricion/tree/master/notebooks): Contiene tres carpetas 
con los notebooks de las siguentes secciones: 
[EDA](https://github.com/123972/PCA-nutricion/tree/master/notebooks/EDA), 
[Programación](https://github.com/123972/PCA-nutricion/tree/master/notebooks/Programacion)
  y [Revisión](https://github.com/123972/PCA-nutricion/tree/master/notebooks/Revision).   

- Carpeta [results](https://github.com/123972/PCA-nutricion/tree/master/results):Esta carpeta contiene los resultados obtenidos por el proyecto, así como la [presentación](https://github.com/123972/PCA-nutricion/blob/master/results/PCA_presentacion.pdf) y el [reporte final](https://github.com/123972/PCA-nutricion/blob/master/results/reporte_final.ipynb).

- Carpeta [references](https://github.com/123972/PCA-nutricion/tree/master/references): Incluye todas las referencias consultadas durante el proyecto.

- Carpeta [src](https://github.com/123972/PCA-nutricion/tree/master/src): Incluye todos los scripts separados en dos secciones:[pca](https://github.com/123972/PCA-nutricion/tree/master/src/pca) y [test algorithms](https://github.com/123972/PCA-nutricion/tree/master/src/test_algorithms) 


## Referencias del proyecto

- Codesansar. (s.f). [Power Method Algorithm for Finding Dominant Eigen Value and Eigen Vector](https://www.codesansar.com/numerical-methods/power-method-algorithm-for-finding-dominant-eigen-value-and-eigen-vector.htm)
- Dan, D. J. (2014). [Power-Method-PCA](https://github.com/dianejdan/Power-Method-PCA/blob/master/power-pca.py)
- Data.world. (2017). [USDA National Nutrient DB](https://data.world/craigkelly/usda-national-nutrient-db)
- Equipo SVD. (2020). [Examen de cómputo matricial equipo SVD](https://github.com/mno-2020-gh-classroom/ex-modulo-3-comp-matricial-svd-czammar)
- Equipo QR. (2020). [Examen de cómputo matricial equipo QR](https://github.com/mno-2020-gh-classroom/ex-modulo-3-comp-matricial-qr-dapivei)
- Fox, J., Chalmers, P., Monette, G., & Sanchez, G. (2020). [PowerMethod: Power Method for Eigenvectors in matlib: Matrix Functions for Teaching and Learning Linear Algebra and Multivariate Statistics](https://rdrr.io/cran/matlib/man/powerMethod.html)
- Palacios M. Erick. (2020). Notas de MNO 2020. [SVD](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.3.d.SVD.ipynb)
- Palacios M. Erick. (2020). Notas de MNO 2020. [Componentes principales](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/IV.optimizacion_convexa_y_machine_learning/4.3.Componentes_principales_Python.ipynb)
- Palacios M. Erick. (2020). Notas de MNO 2020. [Cómputo en paralelo - Dask](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Python_dask.ipynb)
- Ramos, Irene. (2020). ["Tipología_manejo_agrícola"](https://github.com/iramosp/tesis-paisajes/blob/master/Tipologia_manejo_agricola.ipynb)
- Rencher, Alvin C & William F. Christensen. (2012). Methods of Multivariate Analysis. Department of Statistics, Brigham Young University, Provo, UT.- Third Edition. Ch 12.
- Sharma Subhash. (1996). Applied Multivariate Techniques. University of South Carolina. Ch4.
- U.S. Department of Agriculture, Agricultural Research Service. 2014. USDA National Nutrient Database for Standard Reference, Release 27. Methods and Application of Food Composition Laboratory Home Page, http://www.ars.usda.gov/nea/bhnrc/mafcl
- Wikipedia. [QR algorithm](https://en.wikipedia.org/w/index.php?title=QR_algorithm&oldid=956468981)
- González, Felipe (2018). Notas de aprendizaje de máquina. [Métodos basados en árboles](https://felipegonzalez.github.io/aprendizaje-maquina-mcd-2018/metodos-basados-en-arboles.html#arboles-para-regresion-y-clasificacion.)
- Wikipedia [Power iteration](https://en.wikipedia.org/w/index.php?title=Power_iteration&oldid=957783806) (last visited May 29, 2020)
- Mackey, Lester. (2008). Deflation Methods for Sparse PCA. Advances in Neural Information Processing Systems 21 - Proceedings of the 2008 Conference. 21. 1017-1024.