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

Con el fin de aclarar los avances que se han realizado hasta el momento se modifica el avance del 24 de Abril tanto en el READme del equipo(este documento), como en el READme del [avance_24_04_2017](../avance_24_04_2017/)

* Para este día ya hemos comprendido todos en el equipo los pasos del algoritmo a fondo apoyándonos en este [Artículo](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0) y en esta  [página](https://en.m.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication). Ambas referencias nos parecieron a todos las que explican el algoritmo de la manera más clara y sencilla. Para llegar a esta conclusión Javier y Fernanda leimos además otro [artículo](https://www.dropbox.com/s/catd6x49sdc451n/iterative_Toom_Cook.pdf?dl=0) pero nos parecio que no detallaba claramente el algoritmo. De igual manera todo el equipo revisó esta [página](https://gmplib.org/manual/Toom-3_002dWay-Multiplication.html) y acordamos quedarnos con las primeras dos referencias.       

Posteriormente comenzamos a analizar las complicaciones que podrían surgir al momento de implementar este algoritmo. Una de las primeras que surgio fue que estamos limitados a un cierto número de dígitos al momento de realizar cálculos en las fracciones de los números. Dado que nuestro objetivo es no perder precisión decidimos atacar los tres problemas de manera separada. 

* El primer problema fue como corroborar que los resultados que obtendremos son correctos. Para esto decidimos utilizar la librería BigInteger de JAVA que permite procesar números grandes con métodos ya implementados. La principal razón es que esta librería ya tiene precisión comprobada. Como método alternativo de comprobación se podría utilizar también **WolframAlpha** que cuenta con distintos algoritmos ya programados para realizar multiplicaciones de enteros grandes sin pérdida de precisión. 

* El segundo problema fue limitar el tamaño de los números que recibirá el programa para asegurarnos que no se perderá precisión al momento de pasar partes del número de un tipo string a valores numéricos ya que contamos con un número máximo de dígitos que pueden representarse de manera exacta. Por esto decidimos llegar a dividir los números desde 3 hasta 5 pedazos dependiendo del tamaño del número original para asegurarnos que todos los cálculos intermedios cuenten con precisión completa. Como debemos considerar una matriz cuadrada de tamaño 2k -1, con k igual al número de pedazos en los que se divide el número original, consideramos el tamaño de las entradas de la matriz que son los valores a evaluar en el polinomio. Después de considerar ambos problemas decidimos dividir los números mínimo en 3 partes y máximo en 5 y que cada una de estas porciones tenga una longitud máxima de 6 para de esta manera no perder precisión en ningún punto del programa. 

* El tercer problema es realizar la suma de los números finales para obtener el resultado, es necesario programar nuestra propia implementación de la suma ya que el resultado contiene demasiados dígitos y si se utiliza la función de suma normal perderiamos precisión. Recordemos que no perder precisión es uno de nuestros principales objetivos. 

Ya que habiamos decidido realizamos una pequeña prueba del algoritmo en R por facilidad. Simplemente replicamos algunos de los ejemplos que encontramos en algunos artículos, incluso encontramos que este [artículo](https://www.dropbox.com/s/bwziz0hnv78pgp6/ToomCook.pdf?dl=0) tiene un error en el resultado final de la multiplicación por un sumando incorrecto en una etapa. Corroboramos este resultado utilizando las herramientas que ya habiamos decidido utilizar y en efecto nuestra pequeñp programa prueba funciona correctamente. Esto lo hicimos principalmente para comprobar nuestro entendimiento del algoritmo. El código de este programa prueba puede encontrarse [aquí.](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_4/avance_24_04_2017/Codigos/validacion/validacion.R)

Realizando esta prueba en R nos percatamos que podrían aparecer problemas al momento de invertir la matriz de evaluación del polinomio ya que muchas veces se trata de fracciones y los que buscamos es no perder precisión por esto decidimos buscar las inversas de las matrices de manera exacta(con fracciones) y de esta manera asegurarnos que el tamaño de los números involucrados en las operaciones no afecte la precisión. Se comenzó a hacer esto utilizando **WolframAlpha**  que resuelve los sistemas de manera algebraica, se utilizó este programa y no Maple porque no fue posible acceder desde las computadoras de la institución(problema de licencias). Se sigue trabajando en la última matriz (9x9) que contiene entradas muy grandes que no pueden ser ingresadas en la interfaz web de WolframAlpha.

Comenzamos a construir el programa ya en el lenguaje de la entrega final que será en *C*. Utilzando énteros long y strings para recibir los números como input. Se continúa trabajando en este programa ya que es necesario que identifique el número de secciones que se utilizaran y es necesario además que contemos con las tres matrices con sus inversas exactas. 

Aparte de esto hemos comenzado ya con el documento, realizando un template general de como estará estructurado el trabajo y hemos comenzado con la introducción. Además estamos buscando ejemplos muy claros con los que  nosotros y nuestros compañeros nos podamos topar que muestren problemas al perder precisión al realizar multiplicaciones de números grandes, esto con el fin de mostrar la relevancia de este problema en la vida real.


#### [02 de mayo:](avance_02_05_2017)

#### [08 de mayo:](avance_08_05_2017)

#### [15 de mayo:](avance_15_05_2017)


