# Métodos Numéricos y Optimización 2020

[Temario](https://drive.google.com/file/d/19TA_wSrX-uYIotaQ4CINsU7mZyo5h45w/view?usp=sharing)

[El curso, calificación y entregas, correo al cual escribir](el_curso_de_MNO.md)

### Dar click en el siguiente botón para unirse al chat del semestre enero-mayo 2020 en [gitter](https://gitter.im/): [![Gitter](https://badges.gitter.im/mno-2020-1/community.svg)](https://gitter.im/mno-2020-1/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge) Se puede hacer el registro con su cuenta de [github](https://github.com/).

## Organización del curso:

Las clases son los días miércoles y sábados. 

| Días   | Tema                                                              |
| :--------:|:-----------------------------------------------------------------:|
| 22 de enero| Introducción al curso: Análisis numérico y cómputo científico. Inicio de nota de sistema de punto flotante| 
| sábado 25 de enero| Introducción a AWS, configuración de servicios básicos. Activar créditos de AWS. Uso de git-github y docker. Uso de imágenes de docker creadas para las notas de clase|
| 29 de enero|Continuación de nota sistema de punto flotante e inicio de nota de condición de un problema y estabilidad de algoritmos|
| 5 de febrero|Continuación de nota de condición de un problema y estabilidad de algoritmos|
|12 de febrero|Nota de polinomios de Taylor y diferenciación numérica|
|19 de febrero|Nota de integración numérica y nota de perfilamiento|
|sábado 22 de febrero|Creación de roles y uso de S3 en AWS. Uso imágenes de docker creadas para las notas de clase. Levantamiento de clúster de máquinas con dask|
|26 de febrero|Compilación a C: Cython y Rcpp|
|4 de marzo|Discusión de uso de cómputo en paralelo. Historia y generalidades. Procesos e hilos. Arquitecturas de computadora: memoria distribuida y memoria compartida. La CPU y la GPU|
|11 de marzo|Uso de software para cómputo en paralelo: C, Python o R. Ejemplos de diferenciación e integración en paralelo|
|18 de marzo|No hubo clase por COVID-19|
|25 de marzo|CUDA, CUDA-C, CuPy y gputools. Uso de software para cómputo matricial: C, Python o R. Niveles de BLAS. Bottlenecks a considerar para cómputo matricial: uso del caché eficientemente| 
|sábado 28 de marzo|Uso de instancias en google colab y en AWS con GPU's. CUDA-C, CuPy y gputools|
|1 de abril|Métodos para resolver sistemas de ecuaciones lineales y factorizaciones matriciales. Aplicaciones del álgebra lineal numérica: componentes principales, mínimos cuadrados y su relación con problemas convexos.|
|15 de abril| Uso de métodos numéricos en la solución de ecuaciones no lineales: método de Newton en una y más dimensiones. Problemas de optimización convexa. Algoritmos de optimización sin restricciones|
|sábado 18 de abril|Uso de kubernetes en AWS/ Ejercicio de uso de CuPY y gputools en google colab y/o AWS |
|22 de abril|Implementación de algoritmos de optimización sin restricciones|
|sábado 25 de abril|**1er grupo de equipos para entrega de avances de proyecto**|
|29 de abril|Optimización, dualidad y condiciones de Karush-Kuhn-Tucker. Algoritmos de optimización con restricciones de igualdad|
|6 de mayo|Implementación de algoritmos de optimización con restricciones de igualdad|
|sábado 9 de mayo|**2o grupo de equipos para entrega de avances de proyecto**|
|13 de mayo|Algoritmo de barrera logarítmica. Implementación de barrera logarítmica|
|sábado 16 de mayo|**3er grupo de equipos para entrega de avances de proyecto**|
|20 de mayo|Máquina de soporte vectorial con algoritmo de barrera logarítmica. Implementación distribuida|

Total de clases: 24. Total de número de horas: 72 hrs.





[Equipos de MNO](https://drive.google.com/file/d/1_kez3wqmc7jYZgLeNrP9wYouWImWaI4M/view?usp=sharing)

[Lista de estudiantes con calificaciones](https://drive.google.com/file/d/1XPPBFq2X1Rzc5R5tWIvsYpm0_7_CfskF/view?usp=sharing)

[Objetivo, descripción, lista de ejemplos para proyecto final](proyecto_final)

[Indicaciones para proyecto final MNO](proyecto_final/indicaciones)

[Lista de proyectos finales MNO](proyecto_final/proyectos)

[Liga hacia clases de C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C)

[Liga hacia índice del branch master](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master)

[Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS)

[Tutorial para activar créditos de Amazon Web Services actualizado desde año 2020](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.1Activar-creditos-de-AWS-(update))




## Clase 1

22 de enero

Vimos generalidades del curso, forma de calificar, dinámica de clase.

Revisamos notas:

* [1.1.Analisis_numerico_y_computo_cientifico.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.1.Analisis_numerico_y_computo_cientifico.ipynb)

* [1.2.Sistema_de_punto_flotante.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb) hasta números de máquina binarios.

**De tareas quedaron:**

1) Enviar correo a erick89.itam@gmail.com

2) Crear cuentas (si no tienen) en:

  * AWS y activar créditos de acuerdo a [Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS). Verificar que se pueden lanzar instancias en el servicio de EC2.
  
  * Github
  
  * Dockerhub
  
3) Enviar correo con l@s integrantes de su equipo.


## Clase 2

sábado 25 de enero

[Agenda](https://drive.google.com/file/d/1bDLx7IvpnN6syhkmiv_n9hj0jAx00M1K/view?usp=sharing)

Videos divididos por hora:

1) [Primera hora](https://www.youtube.com/watch?v=ZWrQ2vhlfvs&t=128s) 

[Notas primera hora](https://drive.google.com/file/d/1hEPPZmoCcbsaUVZhcM_9Bwn4kENrWUxn/view?usp=sharing)

2) [Segunda hora](https://www.youtube.com/watch?v=UXP0bp4ocLE)

[Notas segunda hora](https://drive.google.com/file/d/1ELy-Jsk47X5hIYplhFrbPjQC6PV7FvlW/view?usp=sharing)

3) [Tercera hora](https://www.youtube.com/watch?v=imL_GgZoREs)

[Notas tercera hora](https://drive.google.com/file/d/1xbzCrPZRoXgmsH4d5-NeRGnotLQSEhX2/view?usp=sharing)

**De tarea crear user con el servicio de IAM para hacer login no con `root`, dar un alias a su cuenta para hacer login, no con los números de la cuenta y activar créditos con [Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS)**


## Clase 3

29 de enero

Finalizamos nota: [1.2.Sistema_de_punto_flotante.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb)

Iniciamos nota: [1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb)

Dejé primera tarea para obtener el \% de participación por equipo usando github classroom (ver [github education](https://education.github.com/)). Se entrega en una semana

## Clase 4

5 de febrero

Finalizamos la nota [1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb)

Iniciamos la nota [1.4.Polinomios_de_Taylor_y_diferenciacion_numerica](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.4.Polinomios_de_Taylor_y_diferenciacion_numerica.ipynb)


Dejé segunda tarea para obtener el \% de participación por equipo usando github classroom. Se entrega en una semana


## Clase 5

12 de febrero


Finalizamos la nota [1.4.Polinomios_de_Taylor_y_diferenciacion_numerica](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.4.Polinomios_de_Taylor_y_diferenciacion_numerica.ipynb)


Finalizamos regla compuesta del Trapecio de la nota [1.5.Integracion_numerica.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.5.Integracion_numerica.ipynb)

Dejé tercera tarea para obtener el \% de participación por equipo usando github classroom. Se entrega en dos semanas.


## Clase 6

19 de febrero

Finalizamos la nota [1.5.Integracion_numerica.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.5.Integracion_numerica.ipynb)

Finalizamos [1.6.Perfilamiento.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento.ipynb), [1.6.Perfilamiento_Python.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.6.Perfilamiento_Python.ipynb).

Llegamos a la introducción de [1.7.Compilar_a_C_Cython.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.7.Compilar_a_C_Cython.ipynb).

## Clase 7

sábado 22 de febrero

Videos divididos por hora:

1) [Primera hora](https://youtu.be/1mEzfMYC9uo) 

[Notas primera hora](https://drive.google.com/file/d/1BhkLNUh0KXgVlYNC49XfExArFoEQ75hl/view?usp=sharing)

2) [Segunda hora](https://youtu.be/VdLcaz1rIos)

[Notas segunda hora](https://drive.google.com/file/d/1Kn875y9lKDZUIqvLxmfJzbGCDBm34kiv/view?usp=sharing)

3) [Tercera hora](https://youtu.be/KGusfdWzP5Q)

[Notas tercera hora](https://drive.google.com/file/d/1TVCbwdnt6LW4yBCV708L4CPzZ3gTxrpi/view?usp=sharing)

**De tarea hay que instalar jupyterlab y el ejemplo al final de [5.AWS y Dask](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/5.AWS-y-Dask) en un clúster de máquinas en AWS. Sólo hay que modificar la configuración para master**


## Clase 8

26 de febrero

Finalizamos [1.7.Compilar_a_C_Cython.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.7.Compilar_a_C_Cython.ipynb) y [1.7.Reescribir_funciones_a_C++_Rcpp.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.7.Reescribir_funciones_a_C%2B%2B_Rcpp.ipynb)

Llegamos hasta Unidades de memoria en [2.1.Un_poco_de_historia_y_generalidades.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.1.Un_poco_de_historia_y_generalidades.ipynb)

## Clase 9

4 de marzo

Finalizamos:

[2.1.Un_poco_de_historia_y_generalidades.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.1.Un_poco_de_historia_y_generalidades.ipynb)

[2.2.Python_multiprocessing.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Python_multiprocessing.ipynb)

## Clase 10

11 de marzo

Repasamos:

[2.2.Python_multiprocessing.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Python_multiprocessing.ipynb)

Finalizamos:

[2.2.Python_dask.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.Python_dask.ipynb)

[2.2.R_parallel.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.R_parallel.ipynb)

[2.2.C_OpenMP.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.2.C_OpenMP.ipynb)

Iniciamos:

[2.3.CUDA.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.CUDA.ipynb)

## Clase 11

18 de marzo

No hubo clase por COVID-19

## Clase 12

25 de marzo

Finalizamos [2.3.CUDA.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.CUDA.ipynb)

Finalizamos [3.1.Vectorizacion_BLAS_y_el_uso_del_cache_eficientemente.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/III.computo_matricial/3.1.Vectorizacion_BLAS_y_el_uso_del_cache_eficientemente.ipynb)

## Clase 13

28 de marzo

Finalizamos:

[2.3.CUDA_C.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.CUDA_C.ipynb)

[2.3.Python_CuPy.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.Python_CuPy.ipynb)

[2.3.R_gputools.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/II.computo_paralelo/2.3.R_gputools.ipynb)




