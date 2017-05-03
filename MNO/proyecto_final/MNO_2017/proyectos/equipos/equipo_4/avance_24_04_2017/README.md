# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Avances individuales:

**Fernanda**:
Esta semana revisé la [implementación de Sai Krishna.](http://cs.indstate.edu/~syedugani/number.html) que encontró Liz y parecia ser que realizaba los cálculos correctamente, sin embargo, como Javier encontró una inconsistencia en este no se agregará a los métodos que tenemos de corroboración de resultados para poder proveer a nuestros compañeros de varias herramientas que puedan usar si algún día se topan con un problema parecido en la realidad. 

Además de esto revisé junto con Javier el error en este [artículo](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0) al momento de realizar el cálculo de la mutiplicación. En efecto este artículo tiene un error en uno de los sumandos y por lo tanto no obtiene un resultado final preciso. Esta comprobación la realizamos utilizando los programas que utilizaremos para corroborar que son la librería BigInteger de JAVA y *WolframAlpha*

Encontré la forma exacta de la matriz inversa para el caso de 3 y 4 secciones. Continuo trabajando en el caso de 5 secciones que genera una matriz de 9x9 entradas.

**Javier**:

Esta semana Javier continuo trabajando en el código en C considerando las discusiones que hemos tenido como equipo en función del tamaño máximo de las secciones y la utilización de matrices exactas. Para esto trabajó en el código que replica lo hecho en el [archivo de R](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_4/avance_24_04_2017/Codigos/validacion/validacion.R) en C utilizando enteros long y strings. 

Al revisar la [implementación de Sai Krishna.](http://cs.indstate.edu/~syedugani/number.html) encontró inconsistencias y por lo tanto esta ya no se considerará como un método de comprobación de resultados. 

**Lizbeth**:

Esta semana Liz encontró la [implementación de Sai Krishna.](http://cs.indstate.edu/~syedugani/number.html) y nos lo comunicó para que hicieramos de igual manera la validación. De igual manera encontró una [implementación del algoritmo](https://github.com/rvelthuis/BigNumbers) la cual exploraremos durante esta semana. 

Comenzó a trabajar en el en el template e introducción del [trabajo final.](https://www.dropbox.com/s/ghjjntmzbwdct4a/equipo_4_trabajo_final.pdf?dl=0)

---

### Avance de equipo:

Durante esta semana realizamos algunas pruebas extras para comprobar que los errores que encontramos en el [artículo](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0) son en realidad un problema del artículo y no algo que estábamos pasando por alto al momento de realizar los cálculos. Además continuamos comprobando los resultados que obtenemos tanto con la primera versión del código en C como la versión de este código en R. Es necesario recordar que el código en C por el momento solo divide el número en tres secciones y es necesario que exista la posibilidad de dividirlo en 4 o 5 dependiendo de los resultados. 

Además realizamos cambios en la estructura del repositorio para cumplir con las especificaciones.

## Comentarios sobre el avance:

* Modificar este avance de acuerdo a comentarios de [../avance_17_04_2017/](../avance_17_04_2017/)

* Hay búsquedas de referencias sobre teoría de números? cómo andamos en esa teoría? 

* En la referencia http://marco.bodrato.it/papers/Bodrato2007-OptimalToomCookMultiplicationForBinaryFieldAndIntegers.pdf se habla sobre https://gmplib.org/ o http://www.shoup.net/ntl/ o http://pari.math.u-bordeaux.fr/ (están escritas en C, c++) se implementa en R para tener un prototipo? se realizará en C en un futuro? si no está en C, ¿cómo cubren con objetivo del proyecto final? ¿se cubre por que está relacionado el tema con teoría de números, interpolación, polinomios, sistemas de ecuaciones lineales, sistema de punto flotante? ¿entonces tendrán un estudio de esta teoría?

* Para los trabajos individuales de Fernanda y Javier: ¿pueden describir su entendimiento de ese artículo y poner la liga al mismo? los archivos .md nos dan la facilidad de poner ligas, usen esto para no tener que ir a su 1er avance donde están las referencias. ¿Qué inconsistencias? es muy general este comentario que dan.

* Javier, "mejora del código" ¿debido a? ¿en qué sentido mejora?

* Lizbeth, ¿esa implementación es lo que hablaban en su avance 2 sobre tener una comparación? o la comparación será con lo que tienen ustedes escrito en R? 

* Sobre el avance de equipo: ¿Falló esta comparación? (¿con el programa de R me imagino? y ¿Sai qué obtuvo?) ¿Buscamos alternativas por esta disparidad? ¿razón de la disparidad? ¿ahora cuáles alternativas consideran? ¿FFT?

* El algoritmo lo tienen programado en R (correcto?), pero está cubierta la teoría que subyace? ¿uds podrían revisar en qué falló y arreglar la disparidad de la que hablan, sin necesidad de ir a más referencias o alternativas? si es el caso (ambas preguntas) continúen con el objetivo, si su respuesta es negativa, mi sugerencia es modificar proyecto pues sus avances están siendo una primera investigación de este tema y no dará tiempo, en un futuro pueden revisar este tema con detenimiento y hacer pruebas y como mencionan en su programa de trabajo con fecha de 24 de abril: "Generar casos de prueba con los resultaados parciales para validación. Ya que si un caso falla de debe ir hacia atrás en el programa para poder ver en donde esta fallando." ----> lo de ir hacia atrás no creo que se tenga que hacer en un proyecto de escuela por el tiempo acotado que tienen.

* Sugiero elijan un tema de proyecto cuya teoría esté resuelta para el éxito del mismo en tiempo, forma e intersección con el curso.


