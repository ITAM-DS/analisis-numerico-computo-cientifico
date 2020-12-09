# Estimación de probabilidades de incumplimiento

[**Repositorio del proyecto**](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico)


## Introducción

La obtención de probabilidades de incumplimiento es una parte fundamental en la toma de decisiones en las instituciones de crédito. La probabilidad de incumplimiento se define, en general, como la probabilidad de que un acreditado no cumpla con las obligaciones de su crédito durante 90 días o más. En este trabajo se mostrará una forma de calcular dichas probabilidades y se contrastara con la forma de calcular probabilidades de incumplimento para realizar Credit Scoring de créditos hipotecarios.

### 1. Objetivo:

Análisis de las Probabilidades de Incumplimiento de créditos hipotecarios de Estados Unidos para identificar periodos de crisis y propuesta de credit scoring, mediante el uso de las herramientas vistas en el curso de Análisis Numérico y Computo Científico.

### 2. Datos:

Se utilizará la información de 60 trimestres de 5000 créditos hipotecarios de Estados Unidos tomada de protafolios bursatilizado (RMBSs) a partir del año 2000 hasta 2015. El proveedor de la base es el [**International Financial Reasearch**](http://www.internationalfinancialresearch.org/), y se tiene acceso a ella por la adquisición del libro Deep Credit Risk de Daniel Rosch y Harald Scheule, que es la principal fuente de este trabajo.


### 3. Temas
* Optimización de problema convexo
* Análisis de Componentes Principales
* Cálculo de eigenvalores y eigenvectores

### 4. Software
* El lenguaje de programación utilizado en este proyecto es `Python` 
* Se levantó una [instancia **S3**](http://ec2-3-83-103-223.compute-1.amazonaws.com:8888/lab) en AWS, la cual nos apoyó a trabajar de manera "continua" sobre una serie de algoritmos. Para entrar a ella es necesario de una contraseña, se pide pedirla a los respectivos autores de este proyecto.


### 5. Bibliografía:
1. *Rosch Daniel*, Scheule Harald. Deep Credit Risk. 2020. Amazon Fulfillment, Polonia.
1. *Siddiqi, Naeem*. Credit Risk Scorecards, Developing and Implementing Credit Scoring. 2006. Wiley, New Jersey 

## Integrantes y asignación de tareas del equipo

|User | Nombre Completo| Tarea |
|:---:|:---:|:---:|
|@oaperez3|Oscar Perez|Project manager, levantamiento de instancia en AWS, implementación de metodología, responder preguntas
|@Eduardo-Moreno|Eduardo Moreno|Investigación de variables, implementación metodología, responder preguntas
|@yefovar|Yedam Fortiz|Testing, estudio de parte matemática, expositor
|@arenitss|Nayeli Arenas|Redacción, revisón de resultados, expositor


## Estructura del repositorio
Las carpetas incluídas en el repositorio contienen la siguiente información:
* [notebooks](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico/tree/main/notebooks): contiene los análisis implementados en este proyecto de manera separada, son 2 estimación de probabilidades de incumplimiento en el tiempo (`PDS_tiempo.ipynb`) y  estimación de probabilidades de incumplimiento, utilizando la metodología de WOE (Weight of Evidence) y IV (Information Value) (`CREDIT_SCORING-ipynb`).
* [pruebas_aws](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico/tree/main/pruebas_aws): evidencia (capturas de pantalla) del trabajo implementado en la instancia AWS. Se añadió debido a que hubo fallas, las cuales fueron reportadas al equipo de AWS de una de las instancias en las cuales se trabajó.
* [utils](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico/tree/main/utils): contiene todas las funciones implementadas por los integrantes del equipo.
* [test](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico/tree/main/tests): archivos `.py` que implementan las pruebas unitarias a las funciones creadas para la resolución del problema de optimización convexo y de cálculo de eigenvalores y eigenvectores.
* [Reporte](https://github.com/arenitss/Proyecto_Final_Analisis_Numerico_Computo_Cientifico/tree/main/Reporte): reporte escrito del proyecto
