# Equipo 4: Avances de trabajo final.

---

## Integrantes:
* Fernanda Téllez Girón
* Guillermo Javier Quiroz Martínez
* Lizbeth Contreras Figueroa

---

### Titulo del proyecto:

Implementación de multiplicación de números grandes sin perdida de precisión.

### Objetivo:

Implementar el algoritmo de Toom-Cook para realizar multiplicaciones de grandes números sin perder precisión en los cálculos.

---

### Programación de avances:

#### [07 de abril:](avance_07_04_2017)

* Discusión interna sobre alcance del proyecto.
* Presentar al profesor las ideas principales y secundarias para recibir retroalimentación.
* Búsqueda de referencias que nos puedan orientar para el desarrollo del proyecto.


#### [17 de abril:](avance_17_04_2017)

* Dar formato al `Readme` para una mejor navegación.
* Puntualizar brevemente la aportación de las referencias puntualizadas en el avance del 07 de abril.
* Describir el avance en el código.
* Externar los problemas con los que se ha enfrentado el equipo.

#### [24 de abril:](avance_24_04_2017)

Con el fin de aclarar los avances que se han realizado hasta el momento se modifica el avance del 24 de Abril tanto en el READme del equipo(este documento), como en el READme del [avance_24_04_2017](https://github.com/fernandatellezg/analisis-numerico-computo-cientifico/tree/master/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_4/avance_24_04_2017)

* Para este día ya hemos comprendido todos en el equipo los pasos del algoritmo a fondo apoyándonos en este [Artículo](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0) y en esta  [página](https://en.m.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication). Ambas referencias nos parecieron a todos las que explican el algoritmo de la manera más clara y sencilla. Para llegar a esta conclusión Javier y Fernanda leimos además otro [artículo](https://www.dropbox.com/s/catd6x49sdc451n/iterative_Toom_Cook.pdf?dl=0) pero nos parecio que no detallaba claramente el algoritmo. De igual manera todo el equipo revisó esta [página](https://gmplib.org/manual/Toom-3_002dWay-Multiplication.html) y acordamos quedarnos con las primeras dos referencias.       

Posteriormente comenzamos a analizar las complicaciones que podrían surgir al momento de implementar este algoritmo. Una de las primeras que surgio fue que estamos limitados a un cierto número de dígitos al momento de realizar cálculos en las fracciones de los números. Dado que nuestro objetivo es no perder precisión decidimos atacar los tres problemas de manera separada. 

* El primer problema fue como corroborar que los resultados que obtendremos son correctos. Para esto decidimos utilizar la librería BigInteger de JAVA que permite procesar números grandes con métodos ya implementados. La principal razón es que esta librería ya tiene precisión comprobada. Como método alternativo de comprobación se podría utilizar también **WolframAlpha** que cuenta con distintos algoritmos ya programados para realizar multiplicaciones de enteros grandes sin pérdida de precisión. 

* El segundo problema fue limitar el tamaño de los números que recibirá el programa para asegurarnos que no se perderá precisión al momento de pasar partes del número de un tipo string a valores numéricos ya que contamos con un número máximo de dígitos que pueden representarse de manera exacta. Por esto decidimos llegar a dividir los números desde 3 hasta 5 pedazos dependiendo del tamaño del número original para asegurarnos que todos los cálculos intermedios cuenten con precisión completa. Como debemos considerar una matriz cuadrada de tamaño 2k -1, con k igual al número de pedazos en los que se divide el número original, consideramos el tamaño de las entradas de la matriz que son los valores a evaluar en el polinomio. Después de considerar ambos problemas decidimos dividir los números mínimo en 3 partes y máximo en 5 y que cada una de estas porciones tenga una longitud máxima de 6 para de esta manera no perder precisión en ningún punto del programa. 

* El tercer problema es realizar la suma de los números finales para obtener el resultado, es necesario programar nuestra propia implementación de la suma ya que el resultado contiene demasiados dígitos y si se utiliza la función de suma normal perderiamos precisión. Recordemos que no perder precisión es uno de nuestros principales objetivos. 

Ya que habiamos decidido realizamos una pequeña prueba del algoritmo en R por facilidad. Simplemente replicamos algunos de los ejemplos que encontramos en algunos artículos, incluso encontramos que este [artículo](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0) tiene un error en el resultado final de la multiplicación por un sumando incorrecto en una etapa. Corroboramos este resultado utilizando las herramientas que ya habiamos decidido utilizar y en efecto nuestra pequeñp programa prueba funciona correctamente. Esto lo hicimos principalmente para comprobar nuestro entendimiento del algoritmo. El código de este programa prueba puede encontrarse [aquí.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_4/avance_24_04_2017/Codigos/validacion/validacion.R)

Realizando esta prueba en R nos percatamos que podrían aparecer problemas al momento de invertir la matriz de evaluación del polinomio ya que muchas veces se trata de fracciones y los que buscamos es no perder precisión por esto decidimos buscar las inversas de las matrices de manera exacta(con fracciones) y de esta manera asegurarnos que el tamaño de los números involucrados en las operaciones no afecte la precisión. Se comenzó a hacer esto utilizando **WolframAlpha**  que resuelve los sistemas de manera algebraica, se utilizó este programa y no Maple porque no fue posible acceder desde las computadoras de la institución(problema de licencias). Se sigue trabajando en la última matriz (9x9) que contiene entradas muy grandes que no pueden ser ingresadas en la interfaz web de WolframAlpha.

Comenzamos a construir el programa ya en el lenguaje de la entrega final que será en *C*. Utilzando énteros long y strings para recibir los números como input. Se continúa trabajando en este programa ya que es necesario que identifique el número de secciones que se utilizaran y es necesario además que contemos con las tres matrices con sus inversas exactas. 

Aparte de esto hemos comenzado ya con el documento, realizando un template general de como estará estructurado el trabajo y hemos comenzado con la introducción. Además estamos buscando ejemplos muy claros con los que  nosotros y nuestros compañeros nos podamos topar que muestren problemas al perder precisión al realizar multiplicaciones de números grandes, esto con el fin de mostrar la relevancia de este problema en la vida real.


#### [02 de mayo:](avance_01_05_2017)

Durante esta semana continuamos leyendo referencias que nos ayudaron a aclarar algunas dudas que surgieron, estas referencias se detallan en el [avance_01_05_2017](./avance_01_05_2017). Tenemos la primera versión del código que se entregará aunque por el momento solo realice el cálculo dividiendo los números en tres subsecciones. Realizamos algunas validaciones de la primera versión del código aunque solo incluya la implementación para dividir el número en 3 subsecciones. Este código puede encontrarse [aquí](./avance_01_05_2017/codigo)

Discutimos acerca de los pasos a seguir para no perder precisión como consecuencia de resolver el sistema de ecuaciones con la matriz mal condicionada del último caso. Queda por decidir si se reducirá el scope del proyecto (a solo dividir en 3 o 4 secciones los números) o si se atacará este problema con otros métodos numéricos (como descomposición en valores singulares) esto se decidirá de acuerdo con los tiempos y que tanto nos ayuden estas aproximaciones a cumplir con los objetivos del proyecto. 

#### [08 de mayo:](avance_08_05_2017)
Continuamos con la investigación de los métodos que podriamos utilizar para evitar perder precisión y de acuerdo con las sugerencias del profesor revisamos algunas referencias [1](http://web.mit.edu/be.400/www/SVD/Singular_Value_Decomposition.htm) y [2](https://www.mpp.mpg.de/~schieck/svd.pdf) de SVD y otra [referencia](https://www.dropbox.com/s/8flmijftnfk6her/chap8.pdf?dl=0) para decidir si utilizamos la matriz por interpolación de Newton o Lagrange para resolver nuestro problema. 

Además continuamos avanzando con el documento final que se entregará, mismo que puede encontrarse [aquí](https://www.dropbox.com/scl/fi/prtfa2a24snrx9i6o4ewa/Trabajo%20final.docx?dl=0&oref=e&r=AAaa0MNkh97EqTnpysa1RsjQ-IKn_ny1yYna2TCGTshPicMl8iMKjiXizJz2NW8df1mY3r6GbssV8FYTuLZvP_oU0UH15dR-33rM216-Tg077bybqUyy2LvkWJCJ_0LbHDjBbo9CbQoGoxuvQmtmAP1j1c-VKnu2GcCzWOUb2OJYcQ&sm=1). 

Por último continuamos generalizando el código para que las funciones se puedan utilizar para todos los casos del algoritmo y además se comenzó la implementación de la multiplicación de matrices que se utilizara para demostrar el uso de el algoritmo. 

#### [15 de mayo:](avance_15_05_2017)

Continuamos con la investigación de los métodos que podriamos usar para evitar perder precisión por tener que resolver un  sistema lineal con una matriz mal condicionada. Nuestro principal problema es que después de resolver el sistema de ecuaciones lineales se utilizan esos resultados para realizar una suma desplazada en la que cada número se suma en una posición diferente para representar cientos, miles, millones, etc. Esto nos provoca problemas extras ya que si los métodos de aproximación nos hacen perder solo algunos dígitos de precisión al hace la suma este error se recorrería a posiciones más elevadas del número por lo que decidimos junto con el profesor limitar los casos que impllementaremos a dividir los números en 3 y 4 secciones y eliminar el caso de realizar 5 secciones. 

#### [22 de mayo:](avance_22_05_2017)

Ya que decidimos acotar nuestro enfoque a Toom-3 para evitar posibles problemas ocasionados por la matriz mal condicionada que se genera al evaluar en el polinomio terminamos el código para esta implementación. Este código puede encontrarse [aquí](./avance_22_05_2017/codigoC). Además realizamos una implementación en R de la multiplicación de matrices de números grandes. Esta implementación puede encontrarse [aquí](./avance_22_05_2017/codigoR). Es necesario para que esta implementación funciona generar un código que sume los números grandes sin perder precisión, es decir que los sume por secciones y regularize los resultados. 
Por último se continuo trabajando en la versión final del trabajo escrito. 

#### [29 de mayo:](avance_29_05_2017)

Durante esta semana se programó la multiplicación de matrices en *pthreads* utilizando la función de multiplicación de números grandes y una función de suma de números grandes que fue necesario programar desde cero (esta función realiza la suma por medio de secciones del número y regulariza el resultado.) La versión final del código puede entcontrarse [aquí](./avance_29_05_2017/codigoC). Además llegamos a la versión final del trabajo escrito, mismo que puede encontrarse en esta [liga](https://www.dropbox.com/s/w0chrjwje9jij7q/Trabajo%20final%20V2.docx?dl=0)

---

### Reporte final:

[Trabajo escrito](trabajo_escrito)

[Implementación](codigo)

[Presentación](https://www.dropbox.com/s/ryj5rq1jlmqmz6v/presentacion_final_toom_cook.pdf?dl=0)

---

### Referencias:

[---. Singular Value Decomposition (SVD) tutorial.](http://web.mit.edu/be.400/www/SVD/Singular_Value_Decomposition.htm)

[---. Toom 3-Way Multiplication.](https://gmplib.org/manual/Toom-3_002dWay-Multiplication.html)

[---. Toom–Cook multiplication.](https://en.m.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication)

[Bodrato, M., & Zanoni, A. (2006). What About Toom-Cook Matrices Optimality.](http://www.bodrato.it/papers/WhatAboutToomCookMatricesOptimality.pdf)

[Parhi, K. Fast Convolution.](https://www.dropbox.com/s/8flmijftnfk6her/chap8.pdf?dl=0)

[Schieck, J. Solving of linear Equations using SVD.](https://www.mpp.mpg.de/%7Eschieck/svd.pdf)

[Yedugani, S. Toom Cook.](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0)

[Zanoni, A. Iterative Toom-Cook Methods For Very Unbalanced Long Integers Multiplication.](https://www.dropbox.com/s/catd6x49sdc451n/iterative_Toom_Cook.pdf?dl=0)
