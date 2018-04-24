Proyecto final: Análisis numérico
---------------------------------

### Integrantes:

-   Oliab Herrera Coria 107863
-   Carlos Castro Correa 103531
-   Víctor Augusto Samayoa Donado 175750

### Introducción del avance 3

Durante esta semana hemos continuado con la investigación de diversos
algoritmos congruenciales para la generación de cadenas de número
pseudo-aleatorios; en esta etapa, podemos destacar la importancia de
algunas caracterísitcas importantes al simularlos:

-   Longitud de la cadena: se refiere a la cantidad de números
    aleatorios que puede generar nuestra cadena antes de perder sus
    propiedades de aleatoriedad y ciclo.
-   Aleatoriedad: es importante que los números generados se comporten,
    en la medida de lo posible, como realizaciones aleatorias, por
    ejemplo, como las cadenas obtenidas a partir de los *generadores de
    números aleatorios naturales*.
-   Pruebas: son una serie de pruebas estadísticas que nos permiten
    determinar, bajo cierto nivel de confianza, si una cadena de números
    es *aleatoria* o lo rechazamos.
-   Ciclo: es la cantidad de números pseudo-aleatorios generados antes
    de que se repita el primer número de la cadena. Esta es una de las
    propiedades más importantes de los algoritmos pues determinar qué
    tan grande puede ser nuestro conjunto de números.

En las siguientes secciones vamos a utilizar los términos mencionados
anteriormente para facilitar las explicación y el avance de la semana.

### Método congruencial.

El método congruencial consiste en una de las opciones disponibles para
la generación de números aleatorios, se trata de uno de los algoritmos
más sencillos, fáciles de comprender e implementar. Una de las ventajas
de este método es que una vez que sus parámetros son definidos, el ciclo
de la cadena es fijo y siempre es el mismo, esto representa una
característica deseable a la hora de reproducir experimentos o
investigación.

Esta técnica consiste en un algoritmo que produce una secuencia de
número pseudo-aletorios generados a partir de una ecuación lineal. El
algoritmo está definido por la siguiente relación de recurrencia,
restricciones y variables:

*X*<sub>*n* + 1</sub> = (*a**X*<sub>*n*</sub> + *c*) mod *m*

*m*, 0 &lt;*m*.  
*a*, 0 &lt;*a* &lt; *m*.  
*c*, 0 ≤*c* &lt; *m*.  
*X*<sub>0</sub>, 0 ≤*X*<sub>0</sub> &lt; *m*.

Para este trabajo, programamos una primer rutina del método congruencial
en C (adjuntamos la rutina en nuestro reposotorio como
**metodo\_congruencial.C**); para una prueba inicial, utilizaremos los
siguientes parámetros: *m = 67*, *a = 3*, *c = 4* y *X\_0 = 2* y las
siguientes observaciones:

El **ciclo** de nuestra primer cadena de números aleatorios es igual a
**22**, a partir del siguiente número, la cadena regresa al valor con el
que iniciamos:

-   Observamos que después de 22 números generados el ciclo se repite.
-   La siguiente cadena contiene poco más de 50 números por lo que vemos
    que el ciclo se repite dos veces.

![Imagen1](https://drive.google.com/uc?id=1AkgF9fjCJFVf-uZCmXuoqX3lF_ES6IzG)

Ahora, vamos a generar una segunda cadena con los siguientes parámetros:
*m = 1034*, *a = 5*, *c = 45* y *X\_0 = 7*.

-   Observamos que después de 230 números generados la cadena se repite.
-   La siguiente cadena contiene poco más de 500 números por lo que
    vemos que el ciclo se repite dos veces.

![Imagen2](https://drive.google.com/uc?id=1JdnFRMn7BXY-FO8GX0GBBANL3jbMGGJ1)

Finalmente, probamos una tercer cadena con parámetros definidos por el
estándar **Turbo Pascal** para generar números aletorios, en esta caso,
los parámetros son *m = 4,294,967,296*, *a = 1,664,525*, *c =
1,013,904,223* y *X\_0 = 234*.

![Imagen3](https://drive.google.com/uc?id=1mCWOomSDmGPum6b3xk53cIyyZgCImNR-)

En esta última cadena generamos 15,000 números aletorios y nunca
encontramos un número repetidos por lo que la longitud del ciclo es de,
al menos, 15,000. A diferencia de las dos primeras cadenas observamos
que todos los parámetros son mucho más grandes, en particular recordemos
que los parámetros *a*, *c* y *X\_0* son menores que *m* por lo que
aumentan su magnitud permite más "libertad" al algoritmo para generar
más números antes de repetirse.

Podemos pensar a las variables del algoritmo como parámetros de entrada
de una función que nos devuelve una cadena de números. En particular,
nos interesa maximizar la longitud de dicha cadena a partir de la
correcta definición de los parámetros *m*, *a*, *c* y *X\_0*.

Lo anterior nos lleva a realizar los siguientes pasos:

-   Estudiar las propiedades del método congruencial
-   Plantear el problema de periodo máximo en términos de los
    coeficientes m, a y c
-   Convertir el problema anterior en un problema de optimización
    (alcanzar un periodo máximo)
-   Encontrar valores de m, a y c que nos permitan alcanzar el periodo
    máximo.
-   Evaluar el uso de métodos congruenciales de la forma

### Avance individual

**Oliab**: Para este avance investigué sobre la paralelización de
algorítmos de generación de números aleatorios. Encontré y empecé a
revisar el paquete
[Random123](https://www.deshawresearch.com/resources_random123.html) que
tiene implentada la paralelización de varios algoritmos en C. Para
entender más sobre la implementación consulté el siguiente
[paper](https://www.nag.co.uk/IndustryArticles/gpu_gems_article.pdf)
sobre paralelización en GPU.

Este avance nos sirve para poder comparar la calidad de números
generados por nosotros con los generados por un algoritmo en paralelo,
esto en caso de que de tiempo.

**Carlos**: Para este avance estuve haciendo la implementación de método
congruencial en C para entender su funcionamiento y para usar esto como
base para empezar a trabajar en la optimización de parámetros de este
parámetros. Se hicieron varias pruebas que pueden ser revisadas en el
siguiente link las cuales fueron usadas después para la elaboración de
este reporte.

El código generado se puede revisar en la carpeta de código de esta
entrega.

**Victor**: Durante este periodo revisé bibliografía para medir la
calidad de los número aleatorios que generemos.

Para esto, se hizo un algoritmo que calcula la frecuencia (y la
probabilidad) de cada una de las subsecuencia de longitud dada para la
secuencia principal indicada en el programa. Aún falta modificarlo para
que la secuencia principal la lea de un archivo. El código se puede ver
en la carpeta de código del trabajo.

Se llegó a la conclusion de usar la batería de pruebas del NIST se pueda
descargar de este
[link](https://csrc.nist.gov/projects/random-bit-generation/documentation-and-software),
y el artículo que explica su funcionamiento es el \[2\]. En particular,
el capítulo 5 da las instrucciones sobre cómo instalar el programa. En
estos momentos ya contamos con el programa compilado y listo para
ejecutar las pruebas de las secuencias que generemos con los algoritmos.
Los detalles teóricos están en la siguiente
[liga](https://docs.google.com/document/d/1m4rcsfr39bRoOpqFL8m2_KiRlr2V5CiEmb05Ot9pEYA/edit?usp=sharing)

Para la siguiente entrega las tareas que tenemos son: - Oliab: Generar
secuencias con la librería que encontró - Carlos y Victor: Plantear el
problema de optimización para la longitud de la secuencia



