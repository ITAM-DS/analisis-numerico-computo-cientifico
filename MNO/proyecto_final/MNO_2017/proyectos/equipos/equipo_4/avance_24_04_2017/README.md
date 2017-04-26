# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Avances individuales:

#### Fernanda:

* Revisión del artículo de Sai Krishna.
* Revisión de las operaciones del artículo en la cual se encontraron ciertas inconsistencias.
* Trabajo con casos de prueba.


#### Javier:

* Mejora de código.
* Revisión de las inconsistencias encontradas en el artículo de Sai Krishna.
* Trabajo con casos de prueba

#### Lizbeth:

* Búsqueda de una implementación del algoritmo.
* Se encontró la [implementación de Sai Krishna.](http://cs.indstate.edu/~syedugani/number.html)
* Se comenzó a trabajar en el template e introducción del [trabajo final.](https://www.dropbox.com/s/ghjjntmzbwdct4a/equipo_4_trabajo_final.pdf?dl=0)

---

### Avance de equipo:

* Realización de algunas pruebas para comprobar las inconsistencias: al ingresar varios valores la implementación se llegó a los mismos resultados, sin embargo con los datos proporcionados en el paper en la implementación se sigue teniendo disparidad en los resultados.
* El resultado encontrado por el equipo con base en las cifras propuestas por Sai Krisna es: 746080071169232484.
* Debido a esto se decidió comenzar a buscar enfoques alternativos a Toom-Cook.
* Se realizaron los cambios al repositorio de acuerdo a las especificaciones del profesor. Se queda en espera de Vo.Bo.

## Comentarios sobre el avance:

* Modificar este avance de acuerdo a comentarios de [../avance_17_04_2017/](../avance_17_04_2017/)

* Hay búsquedas de referencias sobre teoría de números? cómo andamos en esa teoría? 

* En la referencia http://marco.bodrato.it/papers/Bodrato2007-OptimalToomCookMultiplicationForBinaryFieldAndIntegers.pdf se habla sobre https://gmplib.org/ o http://www.shoup.net/ntl/ o http://pari.math.u-bordeaux.fr/ (están escritas en C, c++) se implementa en R para tener un prototipo? se realizará en C en un futuro? si no está en C, ¿cómo cubren con objetivo del proyecto final? ¿se cubre por que está relacionado el tema con teoría de números, interpolación, polinomios, sistemas de ecuaciones lineales, sistema de punto flotante? ¿entonces tendrán un estudio de esta teoría?

* Para los trabajos individuales de Fernanda y Javier, pueden describir su entendimiento de ese artículo y poner la liga al mismo? los archivos .md nos dan la facilidad de poner ligas, usen esto para no tener que ir a su 1er avance donde están las referencias. ¿Qué inconsistencias? es muy general este comentario que dan.

* Javier, "mejora del código" ¿debido a? ¿en qué sentido mejora?

* Lizbeth, ¿esa implementación es lo que hablaban en su avance 2 sobre tener una comparación? o la comparación será con lo que tienen ustedes escrito en R? 

* Sobre el avance de equipo: ¿Falló esta comparación? (¿con el programa de R me imagino? y ¿Sai qué obtuvo? ¿Buscamos alternativas por esta disparidad? ¿razón de la disparidad? ¿ahora cuáles alternativas consideran? ¿FFT?

* El algoritmo lo tienen programado en R (correcto?), pero está cubierta la teoría que subyace? ¿uds podrían revisar en qué falló y arreglar la disparidad de la que hablan, sin necesidad de ir a más referencias o alternativas? si es el caso (ambas preguntas) continúen con el objetivo, si su respuesta es negativa, mi sugerencia es modificar proyecto pues sus avances están siendo una primera investigación de este tema y no dará tiempo, en un futuro pueden revisar este tema con detenimiento y hacer pruebas y como mencionan en su programa de trabajo con fecha de 24 de abril: "Generar casos de prueba con los resultaados parciales para validación. Ya que si un caso falla de debe ir hacia atrás en el programa para poder ver en donde esta fallando." ----> lo de ir hacia atrás no creo que se tenga que hacer en un proyecto de escuela por el tiempo acotado que tienen.

* Sugiero elijan un tema de proyecto cuya teoría esté resuelta para el éxito del mismo en tiempo, forma e intersección con el curso.


