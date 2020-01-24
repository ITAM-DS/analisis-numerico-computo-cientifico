# Métodos Numéricos y Optimización 2020

[Temario](https://drive.google.com/file/d/19TA_wSrX-uYIotaQ4CINsU7mZyo5h45w/view?usp=sharing)

[El curso, calificación y entregas, correo al cual escribir](el_curso_de_MNO.md)


## Organización del curso:

Las clases son los días miércoles y sábados. 

| Días   | Tema                                                              |
| :--------:|:-----------------------------------------------------------------:|
| 22 de enero| Introducción al curso: Análisis numérico y cómputo científico. Inicio de nota de sistema de punto flotante| 
| sábado 25 de enero| Introducción a AWS, configuración de servicios básicos. Activar créditos de AWS. Uso de git-github y docker|
| 29 de enero|Continuación de nota sistema de punto flotante e inicio de nota de condición de un problema y estabilidad de algoritmos|
| 5 de febrero|Continuación de nota de condición de un problema y estabilidad de algoritmos|
|12 de febrero|Nota de polinomios de Taylor y diferenciación numérica|
|19 de febrero|Nota de integración numérica|
|sábado 22 de febrero|Instalación de herramientas útiles en AWS: docker, Rstudio, jupyterlab. Uso de imágenes de docker creadas para la clase|
|26 de febrero|Nota de perfilamiento y compilación a C: Cython|
|4 de marzo|Discusión de uso de cómputo en paralelo. Historia y generalidades. Procesos e hilos. Arquitecturas de computadora: memoria distribuida y memoria compartida. La CPU y la GPU|
|11 de marzo|Uso de software para cómputo en paralelo: C, Python o R. Ejemplos de diferenciación e integración en paralelo|
|18 de marzo|Uso de software para cómputo matricial: C, Python o R. Niveles de BLAS. Bottlenecks a considerar para cómputo matricial: uso del caché eficientemente|
|25 de marzo|Aplicaciones del álgebra lineal numérica: mínimos cuadrados y su relación con problemas convexos.| 
|sábado 28 de marzo|Uso de instancias de AWS con GPU's. Ejemplos con C, Python o R|
|1 de abril|Uso de métodos numéricos en la solución de ecuaciones no lineales: método de Newton en una y más dimensiones|
|15 de abril|Problemas de optimización convexa. Algoritmos de optimización sin restricciones|
|sábado 18 de abril|Uso de kubernetes en AWS |
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

[Lista alumn@s con calificaciones](https://drive.google.com/file/d/1XPPBFq2X1Rzc5R5tWIvsYpm0_7_CfskF/view?usp=sharing)

[Objetivo, descripción, lista de ejemplos para proyecto final](proyecto_final)

[Indicaciones para proyecto final MNO](proyecto_final/indicaciones)

[Lista de proyectos finales MNO](proyecto_final/proyectos)

[Liga hacia clases de C](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C)

[Liga hacia índice del branch master](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master)

[Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS)




## Clase 1

22 de enero

Vimos generalidades del curso, forma de calificar, dinámica de clase.

Revisamos notas:

* [1.1.Analisis_numerico_y_computo_cientifico.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.1.Analisis_numerico_y_computo_cientifico.ipynb)

* [1.2.Sistema_de_punto_flotante.ipynb](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.2.Sistema_de_punto_flotante.ipynb) hasta números de máquina binarios.

De tareas quedaron:

1) Enviar correo a erick89.itam@gmail.com

2) Crear cuentas (si no tienen) en:

  * AWS y activar créditos de acuerdo a [Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS). Verificar que se pueden lanzar instancias en el servicio de EC2.
  
  * Github
  
  * Dockerhub
  
3) Enviar correo con l@s integrantes de su equipo.
