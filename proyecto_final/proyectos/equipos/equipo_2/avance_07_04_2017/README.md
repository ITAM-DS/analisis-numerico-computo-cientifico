# Avance_07_04_2017

## Integrantes: 
* Mónica Ballesteros 
* Ariana López 
* Fabiola Cerón


## Trabajo:

## Individual: 

**Mónica Ballesteros.**

Investigación sobre la factorización LU, ejemplo práctico, mostrando la descomposición del primer paso (LU), utilizando las referencias descritas en el documento, así como revisión de un algoritmo secuencial. El documento se contempla como avance del primer borrador del trabajo escrito a entregar. Se continuará trabajando en la revisión del algortimo QR.


**Ariana López.**

Investigación sobre la factorización de matrices QR, principalmente enfocado a los algoritmos de Gram-Schmidt y Householder, mostrando el soporte teórico, un ejemplo numérico y un resumen de su complejidad en flops por cada uno. Se añaden las 3 referencias principales utilizadas, así como revisión de los algoritmos secuenciales. El documento se contempla como avance del primer borrador del trabajo escrito a entregar. Se continuará trabajando en la revisión de las versiones de descomposición QR y su implementación en OpenMP.


**Fabiola Cerón.**

Investigación sobre la solución de mínimos cuadrados usando LU y QR; además se comparó la complejidad algorítmica de ambas soluciones. Me encuentro trabajando en la implementación de los mínimos cuadrados.


## Equipo:

Como producto de esta investigación se generó un [documento de apoyo](https://drive.google.com/file/d/0B5IJ1w6MjxegRWE1dm10T2FuMzA/view?usp=sharing) que comprende los conceptos básicos y el entendimiento de los algoritmos LU y QR, así como su aplicación en la solución de mínimos cuadrados. Se realiza un comparativo de ambos algoritmos y buscaremos determinar la implementación que resulte mas conveniente. Hemos revisado los algoritmos y estamos en proceso de determinar si usaremos LU o QR para después lo realizaremos en Openmp.

## Comentarios sobre avance:

* Algunas ligas no funcionan por ejemplo al darle click a la palabra "avance_07_04_2017" en el README.md del nivel proyectos/Equipo_2 no te lleva a ninguna página. Esto me ayuda a revisar de manera sencilla su trabajo.

* En este repo no se suben archivos `*.docx` o `.pdf`. Pueden borrar de esta carpeta "avance_07_04_2017" estos archivos? No requiero que me den archivos de investigación. En el párrafo (o párrafos) que resume lo que cada persona hizo se puede apreciar la investigación hecha. Si estos documentos sirven de borrador, mejor en el README.md del nivel MNO/proyecto_final/MNO_2017/proyectos/ coloquen una liga a su trabajo escrito (sólo una, no tres por cada persona del equipo) vean el equipo ejemplo de este README.md.


* Enfóquense a la factorización QR, LU puede ser una alternativa pero tradicionalmente resolvemos el problema de mínimos cuadrados con QR. Sólo faltaba resolver lo de las referencias para QR, las cuales las coloco en su README.md del nivel proyectos/Equipo_2.

* Como se trabajará QR entonces usamos Householder o rotaciones Givens, Gram-Schmidt no lo investigamos, sólo lo estudiamos rápidamente y por comprensión. Hay que resolver lo de Householder o rotaciones Givens. Está muy bien que se investigue el algoritmo de forma secuencial. Entonces comparamos cuál usar: facilidad, entendimiento, documentación...

* En un primer paso se estudia las reflexiones por Householder y rotaciones Givens, en un segundo paso las características y propiedades de estas transformaciones. En un tercer paso se estudia su aplicación para el cálculo de QR de forma secuencial. En un cuarto paso su aplicación al problema de mínimos cuadrados. En un quinto paso la implementación en paralelo en un sistema de memoria compartida. No inviertan lectura en complejidad de algoritmo QR, eso viene en un sexto paso o séptimo paso. Así podremos determinar qué paso tenemos que revisar. Les sugiero hagan un plan de trabajo y usen una programación de calendario.

* Hay gran cantidad de referencias en el google drive. Es poco factible que todas sean revisadas. Les sugiero que se acoten a algunas de ellas. Si me dan un link en el que están todas las referencias me pierdo en cuál están leyendo y cuál no. Es mejor si puntualizan con bullets y mencionan las secciones o capítulos de aquellas que están trabajando y leyendo. Referencias están en el README.md del nivel proyectos/Equipo_2. Internet seguramente será una ayuda pero es un mar de información.

* Deben mejorar la investigación hecha por cada persona y entre ustedes. Es crucial que en estos dos o tres primeros avances se tenga un entendimiento de la teoría subyacente en QR. Mi sugerencia es que revisen las referencias que les coloco en el README.md del nivel proyectos/Equipo_2 y entre ustedes discutan la teoría. Por ejemplo, determinen leer una sola referencia hasta un punto y reúnanse a discutir, si dividen el trabajo en el sentido de que alguien revisa la teoría de QR y alguien revisa la teoría de minimos cuadrados, me parece que será difícil y lenta la revisión de teoría. Dudas respecto a la teoría las podemos aclarar en clase o correo o personal.


