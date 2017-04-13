# Avance_07_04_2017

## Integrantes: 
* Mónica Ballesteros 
* Ariana López 
* Fabiola Cerón


## Trabajo:

## Individual: 

Mónica Ballesteros. 

[Investigación](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipo_2/avance_07_04_2017/LU.docx) sobre la factorización LU, ejemplo práctico, mostrando la descomposición del primer paso (LU), utilizando las referencias descritas en el documento, así como revisión de un algoritmo secuencial. El documento se contempla como avance del primer borrador del trabajo escrito a entregar. Se continuará trabajando en la revisión de las versiones de descomposición LU y su implementación en paralelo,me encuentro revisando [tesis de factorizaciones LU en openmp](https://www.upv.es/titulaciones/MUCPD/).

Ariana López. 

[Investigación](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipo_2/avance_07_04_2017/QR.gdoc) sobre la factorización de matrices QR, principalmente enfocado a los algoritmos de Gram-Schmidt y Householder, mostrando el soporte teórico, un ejemplo numérico y un resumen de su complejidad en flops por cada uno. Se añaden las 3 referencias principales utilizadas, así como revisión de los algoritmos secuenciales. El documento se contempla como avance del primer borrador del trabajo escrito a entregar. Se continuará trabajando en la revisión de las versiones de descomposición QR y su implementación en OpenMP.

Fabiola Cerón. 

[Investigación](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipo_2/avance_07_04_2017/LU_QR_MC.docx) sobre la solución de mínimos cuadrados usando LU y QR; además se comparo la complejidad algorítmica de ambas soluciones. Me encuentro trabajando en la implementación de los mínimos cuadrados para finalmente aplicar el problema en regresión múltiple.


# Equipo:

Esta primera entrega contempla la investigación y entendimiento de los algoritmos LU y QR, así como su aplicación en la solución de mínimos cuadrados. Se realiza un comparativo de ambos algoritmos y buscaremos determinar la implementación que resulte mas conveniente. Hemos revisado los algoritmos y estamos en proceso de determinar si usaremos LU o QR para después lo realizaremos en Openmp.

## Comentarios sobre avance:

* Algunas ligas no funcionan por ejemplo al darle click a la palabra "avance_07_04_2017" en el README.md del nivel proyectos/Equipo_2 no te lleva a ninguna página. 

* En este repo no se suben archivos `*.docx` o `.pdf`. Pueden borrar de esta carpeta "avance_07_04_2017" estos archivos por favor? No requiero que me den archivos de investigación. En el párrafo (o párrafos) que resume lo que cada persona hizo se puede apreciar la investigación hecha.

* Enfóquense a la factorización QR, LU puede ser una alternativa pero tradicionalmente resolvemos el problema de mínimos cuadrados con QR. Sólo faltaba resolver lo de las referencias para QR, las cuales las coloco en su README.md del nivel proyectos/Equipo_2.

* Como se trabajará QR entonces usamos Householder o rotaciones Givens, Gram-Schmidt no lo investigamos. Hay que resolver lo de Householder o rotaciones Givens. Está muy bien que se investigue el algoritmo de forma secuencial.

* En un primer paso se estudia las reflexiones por Householder y rotaciones Givens, en un segundo paso las características y propiedades de estas transformaciones. En un tercer paso se estudia su aplicación para el cálculo de QR de forma secuencial. En un cuarto paso su aplicación al problema de mínimos cuadrados. En un quinto paso la implementación en paralelo en un sistema de memoria compartida. No inviertan lectura en complejidad de algoritmo QR, eso viene en un sexto paso o séptimo paso.

* Hay gran cantidad de referencias en el google drive. Es poco factible que todas sean revisadas. Les sugiero que se acoten a algunas de ellas. Si me dan un link en el que están todas las referencias me pierdo en cuál están leyendo y cuál no. Es mejor si puntualizan con bullets aquellas que están trabajando y leyendo. Referencias están en el README.md del nivel proyectos/Equipo_2.


