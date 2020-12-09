# Optimización

### [Temario](https://drive.google.com/file/d/1dj7bU5uN_ngEhUxhKL9YzCfPGLVc8Z0j/view?usp=sharing)

### El curso, calificación y entregas, correo al cual escribir en el documento [generalidades_curso_de_optimizacion.md](generalidades_curso_de_optimizacion.md)

### Dar click en el siguiente botón para unirse\* al chat del semestre agosto - diciembre 2020 en [gitter](https://gitter.im/): [![Gitter](https://badges.gitter.im/optimizacion-2020-2/community.svg)](https://gitter.im/optimizacion-2020-2/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge) 

\*Se puede hacer el registro con su cuenta de [github](https://github.com/).

## Organización del curso:

Las clases son los días miércoles.

| Semanas   | Tema                                                              |
| :--------:|:-----------------------------------------------------------------:|
| Semana 1 (5 - 7 de agosto)| Introducción a generalidades del curso. Análisis Numérico y Cómputo Científico. Sistema de punto flotante.| 
| Semana 2 (10 - 14 de agosto) | Continuación de sistema de punto flotante. Normas vectoriales y matriciales.|
| Semana 3 (17 - 21 de agosto) | Condición de un problema y estabilidad de un algoritmo.|
| Semana 4 (24 - 28 de agosto) | Revisión de creación de cuentas en AWS, dudas generales y discusión video para configuraciones básicas.|
| Semana 5 (31 de agosto a 4 septiembre) | Continuación de condición de un problema y estabilidad de un algoritmo.|
| Semana 6 (7 - 11 de septiembre) | Definiciones de funciones, derivadas. Métodos de diferenciación numérica.|
| Semana 7 (14 - 18 de septiembre) | Asueto |
| Semana 8 (21 - 25 de septiembre) | Revisión de dudas en AWS, discusión segundo video para configuraciones básicas.|
| Semana 9 (28 de septiembre - 2 de octubre) | Métodos de integración numérica.|
| Semana 10 (5 - 9 de octubre) | Transformaciones en el Álgebra lineal numérica y factorización QR.|
| Semana 11 (12 - 16 de octubre) | Métodos para aproximación de eigenvalores y eigenvectores.|
| Semana 12 (19 -  23 de octubre) | Método de rotaciones de Jacobi para aproximar la descomposición en valores singulares.|
| Semana 13 (26 - 30 de octubre) | Métodos para resolver ecuaciones no lineales.|
| Semana 14 (4 - 6 de noviembre) | Relación entre ecuaciones no lineales y problemas de optimización. Definiciones de conjuntos y funciones convexas. Ejemplos de problemas de optimización convexa.|
| Semana 15 (9 - 13 de noviembre) | Continuación ejemplos de problemas de optimización convexa.|
| Semana 16 (16 - 20 de noviembre) | Métodos para programación lineal: método simplex y por puntos interiores.|
| Semana 17 (23 - 27 de noviembre) | Continuación métodos para programación lineal. Programación entera y optimización de redes.|
| Semana 18 (30 de noviembre - 4 de diciembre) | Continuación programación entera y optimización de redes.|

Total de clases: 18. Total de número de horas: 48 hrs.


[Equipos de optimización]()

### [Lista de estudiantes con calificaciones](https://drive.google.com/file/d/1xbRRkL5096TNRwExwUqmEJb3KjFYwxa5/view?usp=sharing)

[Objetivo, descripción, lista de ejemplos para proyecto final](proyecto_final)

[Indicaciones para proyecto final](proyecto_final/indicaciones)

[Lista de proyectos finales](proyecto_final/proyectos)

[Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS)

[Tutorial para activar créditos de Amazon Web Services actualizado desde año 2020](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.1Activar-creditos-de-AWS-(update))




## Clase 1

5 de agosto

Introducción al curso, para esto se revisó la presentación en [liga](https://hackmd.io/@palmoreck/Hkr5rVQ-v). Revisar las tareas a realizar para primer clase de esta presentación.

Finalizamos la nota [1.1 Análisis numérico y cómputo científico](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.1/Analisis_numerico_y_computo_cientifico.html).

Liga al video de la sesión: [liga microsoft teams](https://web.microsoftstream.com/video/18d6d06f-32e4-4e6a-b56f-847f84de86dc). Tienen que hacer login con su cuenta del itam y luego les pedirá que ingresen nuevamente pero con su cuenta de comunidad itam y luego vuelvan a copiar la liga anterior en la misma pestaña de su browser o en otra.

## Clase 2

12 de agosto

Llegamos hasta reglas de corte y redondeo de la nota: [1.2 Sistema de punto flotante](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.2/Sistema_de_punto_flotante.html)

Liga al video de la sesión: [liga microsoft teams](https://web.microsoftstream.com/video/f8df432e-af2d-4aba-9d9b-68d7f639251d). Tienen que hacer login con su cuenta del itam y luego les pedirá que ingresen nuevamente pero con su cuenta de comunidad itam y luego vuelvan a copiar la liga anterior en la misma pestaña de su browser o en otra.

### De tarea quedó

Realizar la **parte 1** de configuraciones de servicios básicos en AWS que encuentran [aquí](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki#para-videos-de-configuraciones-de-servicios-b%C3%A1sicos-e-instalaci%C3%B3n-de-herramientas-%C3%BAtiles) y podamos discutir en la Semana 4 (24 - 28 de agosto) creación de cuentas en AWS y dudas generales de éstas configuraciones. Para las personas que tienen un sistema operativo Windows y quieran conectarse a las instancias de AWS consultar: [UserGuide/putty](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/putty.html)


## Clase 3

19 de agosto

Finalizamos [1.2 Sistema de punto flotante](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.2/Sistema_de_punto_flotante.html)

Llegamos hasta [resultados-computacionales-que-son-posibles-probar](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.3/Normas_vectoriales_y_matriciales.html#resultados-computacionales-que-son-posibles-probar) de la nota 1.3 Normas vectoriales y matriciales.

Liga al video de la sesión: [liga microsoft teams](https://web.microsoftstream.com/video/6c9df898-1320-4f5e-ac70-a220ad4dc961). Tienen que hacer login con su cuenta del itam y luego les pedirá que ingresen nuevamente pero con su cuenta de comunidad itam y luego vuelvan a copiar la liga anterior en la misma pestaña de su browser o en otra.


## Clase 4

26 de agosto

Finalizamos [1.3 Normas vectoriales y matriciales](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.3/Normas_vectoriales_y_matriciales.html).

En la primera parte llegamos a [algunas-propiedades-del-numero-de-condicion-de-una-matriz](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.4/Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.html#algunas-propiedades-del-numero-de-condicion-de-una-matriz) de la nota 1.4 Condición de un problema y estabilidad de un algoritmo.

En la segunda parte revisamos el contenido del video que quedó de tarea revisar: [configuraciones de servicios básicos e instalación de herramientas útiles](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki#para-videos-de-configuraciones-de-servicios-b%C3%A1sicos-e-instalaci%C3%B3n-de-herramientas-%C3%BAtiles) únicamente la **primera parte**.

Liga al video de la sesión: [liga google drive](https://drive.google.com/file/d/1uxNFLcXRt_OPquHgh7dpV6GTBvnaVnFF/view?usp=sharing) (estará sólo unos días la liga disponible para su descarga). También pueden descargarlo desde Teams pero sólo estará disponible unos días.


## Clase 5

2 de septiembre

Finalizamos [1.4 Condición de un problema y estabilidad de un algoritmo](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.4/Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.html).

Llegamos hasta el [Ejemplo](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.5/Definicion_de_funcion_continuidad_derivada.html#ejrestriccionalinea) de una función restringida a una línea de la nota 1.5 Definición de función, continuidad y derivada.


El video lo pueden descargar desde Teams pero sólo estará disponible unos días.

## Clase 6

9 de septiembre

Finalizamos [1.5 Definición de función, continuidad y derivada](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.5/Definicion_de_funcion_continuidad_derivada.html).

Llegamos hasta [Diferenciación numérica por diferencias finitas](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.6/Polinomios_de_Taylor_y_diferenciacion_numerica.html#diferenciacion-numerica-por-diferencias-finitas)

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 7


23 de septiembre

Finalizamos [Diferenciación numérica por diferencias finitas](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.6/Polinomios_de_Taylor_y_diferenciacion_numerica.html#diferenciacion-numerica-por-diferencias-finitas)

En la segunda parte revisamos el contenido del video que quedó de tarea revisar [configuración de s3, efs, aws y dask](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki#para-videos-de-configuraciones-de-servicios-b%C3%A1sicos-e-instalaci%C3%B3n-de-herramientas-%C3%BAtiles) (se levantó dask-scheduler y dask-workers en una sola máquina).

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 8

30 de septiembre

Llegamos hasta [Aproximación de características de variables aleatorias en integración numérica](https://itam-ds.github.io/analisis-numerico-computo-cientifico/I.computo_cientifico/1.7/Integracion_numerica.html#aproximacion-de-caracteristicas-de-variables-aleatorias). Quedó de tarea revisar esta última sección para finalizar la nota.

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 9

7 de octubre

Llegamos hasta inicio de [transformaciones-de-rotacion](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.1/Operaciones_y_transformaciones_basicas_del_Algebra_Lineal_Numerica.html#transformaciones-de-rotacion)

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 10

14 de octubre

Finalizamos [Operaciones_y_transformaciones_basicas_del_Algebra_Lineal_Numerica.html](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.1/Operaciones_y_transformaciones_basicas_del_Algebra_Lineal_Numerica.html)

Llegamos hasta ejemplo de similitud de [elipse](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.2/Eigenvalores_y_eigenvectores.html#id10)

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 11

21 de octubre

Finalizamos [Eigenvalores_y_eigenvectores](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.2/Eigenvalores_y_eigenvectores.html)

Revisamos rotaciones de Jacobi, método de la potencia e inicio del método de *page rank* en [Algoritmos_y_aplicaciones_de_eigenvalores_eigenvectores_de_una_matriz](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.3/Algoritmos_y_aplicaciones_de_eigenvalores_eigenvectores_de_una_matriz.html)

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 12

28 de octubre

Finalizamos [Algoritmos_y_aplicaciones_de_eigenvalores_eigenvectores_de_una_matriz](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.3/Algoritmos_y_aplicaciones_de_eigenvalores_eigenvectores_de_una_matriz.html) y [Valores_vectores_singulares_y_algoritmos_para_calcular_la_SVD](https://itam-ds.github.io/analisis-numerico-computo-cientifico/II.computo_matricial/2.4/Valores_vectores_singulares_y_algoritmos_para_calcular_la_SVD.html)


El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 13

4 de noviembre

Finalizamos [Definición de problemas de optimización, conjuntos y funciones convexas](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.1/Definicion_de_problema_optimizacion_conjuntos_y_funciones_convexas.html#problemas-de-optimizacion-numerica)


El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 14

11 de noviembre

Llegamos hasta [resolviendo-el-problema-con-cvxpy](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.2/Algoritmos_de_descenso_y_busqueda_de_linea_en_uco.html#resolviendo-el-problema-con-cvxpy) en el ejemplo número 2 de la misma nota.

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 15

18 de noviembre

Finalizamos [Algoritmos_de_descenso_y_busqueda_de_linea_en_uco](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.2/Algoritmos_de_descenso_y_busqueda_de_linea_en_uco.html)

Llegamos hasta [regresión logística](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.3/Ejemplos_problemas_UCO_e_intro_CIEO_y_PI.html#regresion-logistica-clasificacion-en-mathcal-c-0-mathcal-c-1)

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 16

25 de noviembre

Llegamos hasta [ejemplo 3 en nota 3.3 Ejemplos_problemas_UCO_e_intro_CIEO_y_PI](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.3/Ejemplos_problemas_UCO_e_intro_CIEO_y_PI.html#ejemplo-3)

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.


## Clase 17

2 de diciembre

Llegamos a cubrir hasta [problemas-de-programacion-lineal](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.3/Ejemplos_problemas_UCO_e_intro_CIEO_y_PI.html#problemas-de-programacion-lineal). Tal tema junto con puntos interiores se revisó rápidamente.

El video lo pueden descargar desde Teams pero sólo estará disponible unos días.
