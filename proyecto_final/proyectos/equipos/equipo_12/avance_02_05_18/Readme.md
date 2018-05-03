### Integrantes:

-   Oliab Herrera Coria 107863
-   Carlos Castro Correa 103531
-   Víctor Augusto Samayoa Donado 175750

### Introducción del avance 4

### Método congruencial.

Retomando el algoritmo del método congruencial

donde *m* ∈ ℤ<sup>+</sup> y *a*, *c* ∈ ℤ. Además, recordando la
definición de ciclo:

-   **Ciclo:** es la cantidad de números pseudo-aleatorios generados
    antes de que se repita el primer número de la cadena. Esta es una de
    las propiedades más importantes de los algoritmos pues determinar
    qué tan grande puede ser nuestro conjunto de números.

Notamos que el ciclo depende principalmente del número *m*. Esto debido
principalmente a que se está usando la operación de *modulo* lo cuál
solo nos permite obtener números del 0, 1, …, *m* − 1. Por tal motivo al
hablar de máximizar el cíclo será siempre buscar un cíclo de valor *m*
para un *m* ∈ ℤ<sup>+</sup> fijo.

Sin embargo, los valores *a*, *c* ∈ ℤ también juegan un papel importante
en el cíclo, ya que si, por ejemplo, se usa un valor *a* = 0 entonces
sin importar el valor de la semilla (seed) siempre se tendrá que
*x*<sub>*n* + 1</sub> = *c* *m**o**d* *m*. Además, la semilla también
impacta en la obtención del cíclo.

Por tal motivo, nos dimso a la tarea de investigar y generar diversas
cadenas de números pseudoaleatorios con diferentes parámetros posibles
para entender su impacto en el cíclo.

La siguiente gráica se genero para un valor de *m* = 3 y todas las
posibles combinaciones de *a*, *c*, *s**e**e**d* ∈ ℤ, tales que
*a*, *b*, *s**e**e**d* &lt; 3.
![](https://drive.google.com/uc?id=1UyYi8c4Ew8cAQQmx4hKmJao59ym6VDw0)

En este caso, notamos que cualquier combinación de *a* = 1 y
*c* ∈ {1, 2} nos generará un cíclo máximo (en este caso
*c**i**c**l**o* = 3, ya que *m* = 3) sin importar el valor de la
semilla. Mientras, que para cualquier otra combinación el cíclo depende
de la semilla.

La siguiente gráica se genero para un valor de *m* = 4 y todas las
posibles combinaciones de *a*, *c*, *s**e**e**d* ∈ ℤ, tales que
*a*, *b*, *s**e**e**d* &lt; 4.
![](https://drive.google.com/uc?id=1dGNE2AlSZTZD7yyJftJCxthrcxJk3kvI)

En este caso, notamos que cualquier combinación de *a* = 1 y
*c* ∈ {1, 3} nos generará un cíclo máximo (en este caso
*c**i**c**l**o* = 4, ya que *m* = 4) sin importar el valor de la
semilla. Mientras, que para cualquier otra combinación el cíclo depende
de la semilla.

La siguiente gráica se genero para un valor de *m* = 5 y todas las
posibles combinaciones de *a*, *c*, *s**e**e**d* ∈ ℤ, tales que
*a*, *b*, *s**e**e**d* &lt; 5.
![](https://drive.google.com/uc?id=1-xRy23IZ2yLz57XaADir7bek-0ykwrYC)

En este caso, notamos que cualquier combinación de *a* = 1 y
*c* ∈ {1, 2, 3, 4} nos generará un cíclo máximo (en este caso
*c**i**c**l**o* = 5, ya que *m* = 5) sin importar el valor de la
semilla. Mientras, que para cualquier otra combinación el cíclo depende
de la semilla.

La siguiente gráica se genero para un valor de *m* = 6 y todas las
posibles combinaciones de *a*, *c*, *s**e**e**d* ∈ ℤ, tales que
*a*, *b*, *s**e**e**d* &lt; 6.
![](https://drive.google.com/uc?id=11IBQllRbX5EJ-LcqKDteBOKDPui4Tgk_)

En este caso, notamos que cualquier combinación de *a* = 1 y
*c* ∈ {1, 5} nos generará un cíclo máximo (en este caso
*c**i**c**l**o* = 6, ya que *m* = 6) sin importar el valor de la
semilla. Mientras, que para cualquier otra combinación el cíclo depende
de la semilla.

La siguiente gráica se genero para un valor de *m* = 7 y todas las
posibles combinaciones de *a*, *c*, *s**e**e**d* ∈ ℤ, tales que
*a*, *b*, *s**e**e**d* &lt; 7.
![](https://drive.google.com/uc?id=1PxlU93pLCHSK8UTxa6fgMHIcxC3J-84W)

En este caso, notamos que cualquier combinación de *a* = 1 y
*c* ∈ {1, 2, 3, 4, 5, 6} nos generará un cíclo máximo (en este caso
*c**i**c**l**o* = 7, ya que *m* = 7) sin importar el valor de la
semilla. Mientras, que para cualquier otra combinación el cíclo depende
de la semilla.

Lo anterior nos muestra que, si se elijen correctamente los valores de
*a* y de *c*, no es necesarios preocuparnos por la semilla que
inicializará la cadena de números pseudoaleatorios ya que siempre se
tendrá un cíclo máximo.

También llegamos a la conclusión de que es necesario encontrar una
caracterización de la forma *c**i**c**l**o*(*m*, *a*, *c*) tal que para
los valore *a*<sub>0</sub> y *c*<sub>0</sub> se tenga que
*c**i**c**l**o*(*m*, *a*<sub>0</sub>, *c*<sub>0</sub>)=*m*, dada una
*m* ∈ ℤ<sup>+</sup> fija.

El objetivo inicial erá usar teoría de optimización convexa para
encontrar los valores *a*<sub>0</sub> y *c*<sub>0</sub> que nos
permitieran maximizar el cíclo. Sin embargo, nos encontramos con las
siguientes limitaciones:

1.  La función *c**i**c**l**o*(*m*, *a*, *c*) cumple que
    esto significa que no tenemos las propiedades de un espacio
    vectorial real (continuo) y por lo tanto no podemos usar los
    conceptos de límite y derivada.

2.  A pesar de que pudieramos extender la función a un espacio vectorial
    real (continuo) para aplicar lso conceptos de teoría de optimización
    convexa, no tenemos una representación funcional de la función
    *c**i**c**l**o*. Esto es, no conocemos (ni encontramos en la
    revisión de la literatura) la forma en que se combinan los valores
    de *m*, *a* y *c* para obtener el valor del cíclo.

Lo anterior nos lleva a replantear la forma de resolver este problema y
llegamos a la siguiente conclusión:

1.  A pesar de no conocer la forma funcional del cíclo, si es posible
    máximizarlo ya que la función siempre estará acotada por el valor
    del módulo *m*.

2.  Es posible apoyarnos en la teoría de números para caracterizar el
    cíclo y encontrar las relaciones que deben de cumplir *m*, *a* y *c*
    de tal forma que siempre aseguremos el cíclo máximo.

En este sentido encontramos el siguiente teorema:

Si *c* &gt; 0, entonces para cualquier valor inicial
*s**e**e**d* ∈ {0, 1, ....,*m* − 1} la congruencia líneal genera una
secuencia con cíclo máximo (cíclo de valor *m*) si y sólo si se
satisfacen las siguientes condiciones:

-   Los parámetros *c* y $m $ son primos relativos. Esto es
    *M*.*C*.*D*(*m*, *c*)=1
-   Para cada número primo *p* que divide a *m*, entonces *a* − 1 es un
    múltiplo de *p*
-   Si *m* es un múltiplo de 4 entonces *a* − 1 también es un múltiplo
    de 4

Consideremos las siguientes secuencias de números aleatorios:

La siguiente gráica se genero para un valor de *m* = 2048 y algunas de
las posibles combinaciones de *a*, *c*, *s**e**e**d* ∈ ℤ, tales que
*a*, *b*, *s**e**e**d* &lt; 2048.

![](https://drive.google.com/open?id=1QV5b7_gpXY3yzZnpJCMOeUF-OW6zTl0d)

En este caso, notamos que cualquier combinación de
*a* ∈ {65, 1229, 1365} y *c* = 1 nos generará un cíclo máximo (en este
caso *c**i**c**l**o* = 2048, ya que *m* = 2048) sin importar el valor de
la semilla. Mientras, que para cualquier otra combinación el cíclo
depende de la semilla.

Otro punto a considerar es que no solamente se necesita un cíclo máximo,
también se necesitan analizar las condiciones de aleatoriedad .

Observemos los siguientes diagramas de dispersión para las combinaciones
que generan un cíclo máximo.

![](https://drive.google.com/open?id=1NbTV8htYlTSuisaxy5qjw4U7yZX_vplV)

En la gráfica anerior es posible ver que los valores se distribuyen
uniformemente sobre todo el cuadrado de 2048 × 2048, lo cuál nos hace
pensar que tiene buenas propiedades de aleatoriedad. Quedaría pendiente
evaluar esta secuencia con la batería de pruebas de NIST.

![](https://drive.google.com/uc?id=1ST4768m1saBH1B5u5X0icNubaGKt86n3)
![](https://drive.google.com/uc?id=1UGhlgGEb0QQi1-JDnfjRFvfF-iRvCUln)

En estas dos últimas gráficas, observamos que el cíclo máximo no lo es
todo. Es decir, en este caso estámos obteniendo un cíclo de 2048 valores
distintos, pero estos no se distribuyen de forma uniforme sobre el
cuadrado de 2048 × 2048.

Lo anterior nos lleva a concluir que ahora que tenemos identificado como
máximizar el cíclo, debemso identificar parámetros *m*, *a* y *c* que
además de máximizar el cíclo también nos permitan mantener buenas
propiedades de aleatoriedad.

### Avance individual

**Oliab**: Para este avance implementé el algorítmo Mersenne Twister en
C en su forma normal, esto para entenderlo y poder hacer las
adecuaciones necesarias para poder correrlo de manera en paralelo
(acabamos de actualizar las referencias como se solicitó).

Esto se hace para comprar el algoritmo con parámetros optimizados en
contra de un algoritmo "normal" y uno que corre en "paralelo". Se harán
las pruebas NIST entre los números generados por los algoritmos para
poder compararlos.

El código se podrá encontrar en la carpeta de código de este avance y
las salidas de algunas corridas que se hicieron se pueden encontrar
[aquí](https://drive.google.com/open?id=1p_2JUSuFZh_no7nRPUgLlBNilYSdj6SL)

**Carlos**: Para este avance estuve generando diversas cadenas de
números pseudoaleatorios a partir del algoritmo creado la semana pasada.
Estas cadenas se fueron construyendo de la siguiente manera:

-   Se fijaba un valor del módulo *m*.
-   Se elegian valores de *a*, *c* y *s**e**e**d* de tal forma que todos
    elllos cumplieran las restricciones de ser
    *a*, *c*, *s**e**e**d* &lt; *m*.
-   Se iteraba el paso anterior hasta cubrir todas las posibles
    combinaciones.
-   Se exportaban los datos a un archivo para poder usarlos en el
    análisis.

También estuve revisando la parte de la teoría sobre la forma de
máximizar los cíclos y preservar las propiedades de aleatriedad en una
longitud máxima.

Para el próximo avance generare diversas secuencias de cíclo máximo para
explorar su aleatoriedad.

**Victor**: Durante esta semana usé las cadenas de números aleatorios
que generaba Carlos para cargar la información en R y análizar el
comportamiento de los cíclos a partir de las diferentes combinaciones de
los parámetros *m*, *a*, *c* y *s**e**e**d*.

Revise la teoría de congruencia para identificar teoremas que nos
puedieran ayudar a construir cíclos máximos, encontrando así el teorema
citado en este documento.

Este avance nos permite cumplir la caracterización de cíclos máximos. Y
para el próximo avance se usaran las baterias de prueba del NIST para
caracterizar la aleatriedad de las secuencias que generen Carlos y
Oliab.
