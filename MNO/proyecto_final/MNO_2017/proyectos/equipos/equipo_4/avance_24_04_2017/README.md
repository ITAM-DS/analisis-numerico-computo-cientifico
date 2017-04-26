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

* En la referencia http://marco.bodrato.it/papers/Bodrato2007-OptimalToomCookMultiplicationForBinaryFieldAndIntegers.pdf se habla sobre https://gmplib.org/ o http://www.shoup.net/ntl/ o http://pari.math.u-bordeaux.fr/ (están escritas en C, c++)


