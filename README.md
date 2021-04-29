# Optimización avanzada

### [Temario](https://drive.google.com/file/d/17ydFChBFxxAOzsIPwUu90KR01zRXdCNZ/view?usp=sharing)

### El curso, calificación y entregas, correo al cual escribir en el documento [generalidades_curso_de_optimizacion_avanzada.md](generalidades_curso_de_optimizacion_avanzada.md)

### Dar click en el siguiente botón para unirse\* al chat del semestre enero mayo 2021 en [gitter](https://gitter.im/): [![Gitter](https://badges.gitter.im/optimizacion-2-2021-1/community.svg)](https://gitter.im/optimizacion-2-2021-1/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

\*Se puede hacer el registro con su cuenta de [github](https://github.com/).

## Organización del curso:

Las clases son los días miércoles.

| Semanas   | Tema                                                              |
| :--------:|:-----------------------------------------------------------------:|
| Semana 1 (11 - 15 de enero) | Introducción a generalidades del curso. Repaso.|
| Semana 2 (18 - 22 de enero) | Continuación repaso. Ecuaciones no lineales.|
| Semana 3 (25 - 29 de enero) | Ecuaciones no lineales. Inicio definiciones generales en redes. |
| Semana 4 (1 - 5 de febrero) | Definiciones generales en redes. Inicio programación lineal. |
| Semana 5 (8 - 12 de febrero) |  Programación lineal.|
| Semana 6 (15 - 19 de febrero) | Método símplex|
| Semana 7 (22 - 26 de febrero)| Método símplex. Método símplex en redes.|
| Semana 8 (1 - 5 de marzo) | Métodos para resolver problemas sin restricciones: métodos de descenso por gradiente, Newton, por coordenadas, descenso más pronunciado.|
| Semana 9 (8 - 12 de marzo)  | Método por puntos interiores para programas lineales.|
| Semana 10 (15 - 19 de marzo)| Método de Newton para resolver problemas con restricciones de igualdad.|
| Semana 11 (22 - 26 de marzo) | Continuación método de Newton para resolver problemas con restricciones de igualdad.|
| Semana 12 (29 de marzo - 2 de abril) | Semana santa. |
| Semana 13 (5 - 9 de abril) | Métodos para resolver problemas con restricciones de igualdad y desigualdad. Barrera logarítmica. Discusión configuración minikube, kale y kubeflow |
| Semana 14 (12 - 16 de abril) | Métodos para resolver problemas con restricciones de igualdad y desigualdad. Barrera logarítmica.|
| Semana 15 (19 - 23 de abril) | Perfilamiento de código y compilación a C: Cython y Rcpp |
| Semana 16 (26 - 30 de abril) | Cómputo en paralelo. Historia y generalidades. Procesos e hilos. Arquitecturas de computadora: memoria distribuida y memoria compartida. La CPU y la GPU |
| Semana 17 (3 - 7 de mayo) | Uso de software para cómputo en paralelo: C, Python, R.|
| Semana 18 (10 - 14 de mayo) | Uso de software para cómputo en la GPU. BLAS y uso del caché eficientemente.|



Total de clases: 17. Total de número de horas: 45 hrs.


[Equipos de optimización avanzada]()

### [Lista de estudiantes con calificaciones](https://drive.google.com/file/d/1pUuzpDY6yTZo4aY1PSmTRYcQDP1YBZ8Q/view?usp=sharing)

[Objetivo, descripción, lista de ejemplos para proyecto final](proyecto_final)

[Indicaciones para proyecto final](proyecto_final/indicaciones)

[Lista de proyectos finales](proyecto_final/proyectos)

[Tutorial para activar créditos de Amazon Web Services](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.Activar-creditos-de-AWS)

[Tutorial para activar créditos de Amazon Web Services actualizado desde año 2020](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/0.1Activar-creditos-de-AWS-(update))


## Clase 1

13 de enero

Introducción al curso, formas de calificar, dinámica.
Repaso hasta la nota [3.1 Definicion_de_problema_optimizacion_conjuntos_y_funciones_convexas](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.1/Definicion_de_problema_optimizacion_conjuntos_y_funciones_convexas.html#)

## Clase 2

20 de enero

Finalizamos repaso hasta la nota [3.3 Ejemplos_problemas_UCO_e_intro_CIEO_y_PI](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.3/Ejemplos_problemas_UCO_e_intro_CIEO_y_PI.html)

Iniciamos la nota [3.4 Ecuaciones no lineales](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.4/Ecuaciones_no_lineales.html) hasta Sistemas de ecuaciones lineales square, underdetermined, overdetermined.

## Clase 3

28 de enero

Llegamos hasta sistemas de ecuaciones no lineales en [3.4 Ecuaciones no lineales](https://itam-ds.github.io/analisis-numerico-computo-cientifico/III.optimizacion_convexa/3.4/Ecuaciones_no_lineales.html#sistema-de-ecuaciones-no-linales)


## Clase 4

3 de febrero

Llegamos hasta [4.1 Red acíclica, árbol y bosque](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.1/Definiciones_generales_de_flujo_en_redes.html#red-aciclica-arbol-y-bosque)


## Clase 5

10 de febrero

Llegamos hasta [4.2 Tipo de soluciones en un PL](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.2/Programacion_lineal_y_metodo_simplex.html#tipo-de-soluciones-en-un-pl)

## Clase 6

17 de febrero

Llegamos hasta [4.2 Prueba del cociente mínimo: forma general y con notación matricial y vectorial](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.2/Programacion_lineal_y_metodo_simplex.html#prueba-del-cociente-minimo-forma-general-y-con-notacion-matricial-y-vectorial)


## Clase 7

24 de febrero

Terminamos nota [4.2 Programación lineal (PL) y método símplex](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.2/Programacion_lineal_y_metodo_simplex.html)


## Clase 8

3 de marzo

Terminamos nota [4.3 Ejemplo del método símplex de redes](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.3/Ejemplo_metodo_simplex_de_redes.html)

Llegamos hasta [Interpretación del problema dual](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.4/Dualidad_lema_de_Farkas_condiciones_KKT_de_optimalidad.html#interpretacion-del-problema-dual)

## Clase 9

10 de marzo

Terminamos nota [4.4 Dualidad, lema de Farkas y condiciones de Karush-Kuhn-Tucker (KKT) de optimalidad](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.4/Dualidad_lema_de_Farkas_condiciones_KKT_de_optimalidad.html)

## Clase 10

17 de marzo

Llegamos a [Tercera idea: reducir la duality gap y centrar nota 4.5](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.5/Metodo_primal_dual_de_BL.html#tercera-idea-reducir-la-duality-gap-y-centrar-uso-de-la-funcion-de-barrera-logaritmica-fbl)

Revisamos [Kale](https://github.com/kubeflow-kale/kale) e hicimos ejemplos en AWS Educate con [deployments](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/deployments/minikube/hostpath_pv) y [src](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/src)

## Clase 11

24 de marzo

Terminamos [4.5 Método primal-dual de barrera logarítmica (BL)](https://itam-ds.github.io/analisis-numerico-computo-cientifico/IV.optimizacion_en_redes_y_prog_lineal/4.5/Metodo_primal_dual_de_BL.html)

Inicio de [5.1 Introducción optimización de código](https://itam-ds.github.io/analisis-numerico-computo-cientifico/V.optimizacion_de_codigo/5.1/introduccion_optimizacion_de_codigo.html)


## Clase 12

9 de abril

Llegamos hasta [5.1 Software para cómputo en paralelo](https://itam-ds.github.io/analisis-numerico-computo-cientifico/V.optimizacion_de_codigo/5.1/introduccion_optimizacion_de_codigo.html#software)

## Clase 13

14 de abril

Llegamos hasta [Blocking algorithms para multiplicación de matrices](https://itam-ds.github.io/analisis-numerico-computo-cientifico/V.optimizacion_de_codigo/5.2/Herramientas_de_lenguajes_y_del_SO_para_perfilamiento_e_implementaciones_de_BLAS.html#blocking-algorithms-para-multiplicacion-de-matrices)

## Clase 14

21 de abril

Finalizamos [Herramientas de lenguajes de programación y del sistema operativo para perfilamiento e implementaciones de BLAS](https://itam-ds.github.io/analisis-numerico-computo-cientifico/V.optimizacion_de_codigo/5.3/Compilacion_a_C.html#ejemplo-via-linea-de-comando)


## Clase 15

28 de abril

Finalizamos [Compilación a C](https://itam-ds.github.io/analisis-numerico-computo-cientifico/V.optimizacion_de_codigo/5.3/Compilacion_a_C.html)