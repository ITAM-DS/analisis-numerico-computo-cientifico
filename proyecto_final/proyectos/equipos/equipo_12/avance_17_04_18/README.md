
El primer reporte con imagenes se puede ver en :https://docs.google.com/document/d/1-bw1rVVeuS97q3tsk7enykFDidSMQHoIhXpq0bdsyZM/edit?usp=sharing


Reporte_1

Integrantes:

Oliab Herrera Coria 107863  
Carlos Castro Correa 103531  
Víctor Augusto Samayoa Donado 175750  

Equipo:

Para este primer reporte, reunimos una serie de referencias y artículos científicos y de divulgación sobre la definición de números aleatorios, su generación y pruebas de aleatoriedad. También incluímos una serie de referencias sobre distintas fuentes de números aleatorios naturales que serán utilizados para comprobar la eficiencia de nuestro trabajo.

Dada la cantidad de referencia y el alcance de nuestro proyecto, decidimos repartir su revisión entre los miembros del equipo con la finalidad de definir el algoritmo que vamos a seleccionar, dejando el avance en código e implementación para la siguiente entrega.


Individual: 

Oliab:

En la primera etapa me tocó revisar los artículos

Random number in scientific computing an introduction

Mis conclusiones sobre estos artículos y su relación con nuestro proyecto son las siguientes:

En la revisión de artículos para generar un algoritmo de números aleatorios, identifiqué la necesidad de que el algoritmo use una “semilla” (seed) de tal forma que nos permita tener un control sobre la reproducibilidad. Es decir, cada vez que el algoritmo genere una cadena de número usando la misma semilla, se debe obtener la misma cadena. 

Por tal motivo es necesario generar un algoritmo que genere una semilla cada vez que se ejecute el algoritmo, salvo que al ejecutar el algoritmo nosotros indiquemos una semilla específica. Para esto, generé una primera versión de un programa que solicita el tiempo del CPU en segundos, de tal forma que si no se incluye una semilla está función se encargará de generar una.

Un primer algoritmo que encontré es el que usa una combinación lineal de factores y calcula su módulo un entero primo p

$$x0=seed$$    
$$$xi= (a1xi-1 + a2xi-2 +... + anxi-n ) mod p$$

Sin embargo, este algoritmo depende en gran medida de los valores ai, n y el número primo p. Y que el máximo periodo antes de comenzar a identificar patrones es de pn-1, y eso considerando que se escogieron los valores correctos para garantizar este máximo periodo. Cabe destacar que este algoritmo, en un primer análisis, no es posible paralelizar ya que depende de valores calculados previamente. Pero encontré que puede servir como una nueva función “seed” que genere un “bloque de semillas” para algoritmos más complicados.

La próxima semana terminaré de analizar otros algoritmos encontrados para plantear mis propuestas al equipo sobre los algoritmos a implementar.

Los avances se pueden ver [aquí](https://github.com/oliab/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_12/avance_17_04_18/codigo)


Carlos:

Leí las siguientes referencias:

Random number generators a survival guide for large scale simulations

Mis conclusiones sobre estos artículos y su relación con nuestro proyecto son las siguientes:

El artículo se centra en cómo paralelizar algunos algoritmos que generen pseudo números aleatorios. Aunque establece que este proceso por lo general es complicado debido a que en un proceso paralelo la calidad de los números aleatorios generados es aún más importante ya que se llegan a usar hasta 105veces más número aleatorios que en un proceso secuencial. Sin embargo, los buenos algoritmos de números aleatorios son difíciles de paralelizar o, en caso de serlo, pierden eficiencia o calidad en sus resultados.

Un algoritmo sencillo de implementar el el de recurrencia lineal módulo un número primo, sin embargo, este algoritmo tiene un periodo que depende del número primo, y los coeficientes que se usan dentro del algoritmo, ver la siguiente figura.

El algoritmo previo, puede ser usado como una entrada a algoritmos que trabajen el paralelo, para esto es necesario incluir un proceso que se llama “Block Splitting” u otro de nombre “Leapfrogging”.

Block Splitting consiste en generar una secuencia de números aleatorios y particionarla en bloques adyacentes tantos como procesos paralelos se vayan a ejecutar. Leapfrogging consiste en ir dando “saltos” en la secuencia, estos saltos deben ser del tamaño igual al número de proceso a ejecutar. El diagrama siguiente diagrama ilustra ambos procesos.



Para implementar esto en un proceso paralelo, es necesario generalizar la recurrencia  lineal para operar con matrices, sin embargo esto conlleva optimizar el producto de matrices para tener un algoritmo eficiente. Considero que esto último va a ser lo que defina si el algoritmo a realizar va a ser paralelizable o nos limitaremos a algoritmos secuenciales, sin embargo necesito discutirlo con mis compañeros de equipo.


Víctor:

Mi trabajo consistió en la revisión de los siguientes artículos:

Borel Normality and Algorithmic Randomness
Random numbers certified by Bell’s theorem
A statistical test suite for random and pseudorandom number generators for cryptographic applications

Mis conclusiones sobre estos artículos y su relación con nuestro proyecto son las siguientes:

El concepto de aleatoriedad es fundamental en diversas aplicaciones como lo pueden ser la en cuestiones de seguridad como la criptografía, actividades lúdicas como los juegos de azar e incluso aplicaciones científicas para generar simulaciones de algún fenómeno.

De los artículos revisado, identifiqué que no existe una definición matemática sobre lo que se entiende por un número aleatorio. Lo que sí existen son diferentes pruebas para determinar el grado de aleatoriedad de una secuencia de bits. Lo cual conlleva a dos conceptos, los “verdaderos números aleatorios” (TRNGs) y los “pseudo números aleatorios” (PRNGs).

Los TRNGs son generados por diversos grupos de investigación que usan fenómenos físicos para generar una cadena de bits lo suficientemente larga para de ahí construir los números aleatorios. Mientras que los PRNGs pueden ser generados mediante algoritmos en una computadora.

De esta revisión, se concluye que en nuestro proyecto se van a crear PRNGs, ya que los TRNGs provienen de fenómenos naturales. Así que nuestro objetivo será generar una cadena de bits aleatorios lo más larga posible que cumpla las pruebas de aleatoriedad.

Queda pendiente terminar de revisar los artículos incluidos en la liga correspondiente, seleccionar las pruebas que se usarán en este trabajo y decidir el algoritmo a implementar para la generación de PRNGs. También es necesario identificar una página de internet del algún grupo de investigación que proporcione cadenas de números aleatorios para usarlos como referencia respecto a los valores obtenidos en las pruebas de aleatoriedad.
