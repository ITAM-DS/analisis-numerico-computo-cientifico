Proyecto final: Análisis numérico
---------------------------------

### Integrantes:

-   Oliab Herrera Coria 107863
-   Carlos Castro Correa 103531
-   Víctor Augusto Samayoa Donado 175750

### Introducción del avance 4

Durante esta semana hemos profundizado en aspectos esenciales del
nuestro algoritmo congruencial para números aleatorios. Como mencionamos
en el reporte anterior, nuestra investigación se ha centrado en varios
frentes:

-   Longitud de la cadena de números aleatorios.
-   Pruebas de aleatoriedad.
-   Generación de números en paralelo.

A continuación, mencionaremos los avances puntuales y pruebas realizadas
en cada uno de estos aspectos, de igual forma, incluimos los códigos y
gráficas que fueron utilizadas en nuestro trabajo semanal.

### Longitud de la cadena de números aleatorios.

#### Avance Carlos

Antes de presentar los aspectos relevantes, recomerdemos que el
algoritmo de generación de números aleatorios está definido por la
siguiente relación de recurrencia, restricciones y variables:

*X*<sub>*n* + 1</sub> = (*a**X*<sub>*n*</sub> + *c*) mod *m*

*m*,0 &lt;*m*.  
*a*,0 &lt;*a* &lt; *m*.  
*c*,0 ≤*c* &lt; *m*.  
*X*<sub>0</sub>,0 ≤*X*<sub>0</sub> &lt; *m*.

En el reporte anterior, observamos que la elección de los parámetros es
fundamental para determinar la eficiencia de nuestro generador. Por
construcción, la cadena obtenida a partir de este algoritmo tiene una
longitud máxima igual a *m*, pero podría no ser alcanzada si los
parámetros *a*, *c* y *m* no cumplen con ciertas propiedades.

Uno de los enfoques que inicialmente pensamos, consistía en encontrar
los mejores parámetros si planteamos un problema de optimización, es
decir, maximizar la longitud de la cadena de números aleatorios en
función de los parámetros. Intentamos diversas ideas y opciones, sin
embargo, nos encontramos con un impedimento claro: nuesta función no es
convexa ya que el dominio es discreto (números enteros que hacen que el
dominio no sea convexo), por lo tanto, descartamos la idea de
considerarlo como un problema de optimización.

Nuestra investigación de la semana continuó buscando otro enfoque y
encontramos que la solución del problema estaba más relacionada con otra
rama de las matemáticas: **teoría de números**, como preámbulo,
encontramos que para obtener una cadena con longitud máxima, los
parámetros no solo deberían cumplir ciertas con ciertas propiedades sino
que tendrían que tener cierta relación entre sí.

Para este nuevo enfoque nos basamos en una referencia de *Computer
Programming* consultamos el libro *The Art of Computer Programming, Vol.
II, de Knuth* y encontramos la demostración de un teorema que nos
permite seleccionar adecuadamente los parámetros de forma adecuada. A
continuación, enunciamos el teorema, *dejando para el siguiente reporte
un análisis más profundo de sus aspectos e implicaciones*:

**La secuencia lineal congruencial definida por *m*,*a*,*c* y
*X*<sub>0</sub> tiene periodo *m* sí y solo si:**

-   *c* es primo relativo de *m*;
-   *b* = *a* − 1 es un múltiplo de *p*, para cada número primo *p* que
    divide a m.

*Además c es distinto de cero.*

La primera demoestración de este teorema fue realizada por *M.
Greenberger* para el caso particular de *m* = 2<sup>*e*</sup> y el caso
general, fue demostrado por *Hull y Dobell*, sin embargo, como
mencionamos anteriormente, los detalles más técnicos sobre esta
demostración y su relación con la teoría de números serán retomados en
el siguiente reporte.

Notemos que la elección de estos parámetros es fundamental para lograr,
además de la máxima longitud, las propiedades de aletoridad dentro de la
cadena de números. Observemos que obtener una cadena de longitud máxima
es relativamente simple, si ***a* = 1** y ***c* = 1** el periodo siempre
va a ser igual a **1**.

Por ejemplo, si ***a* = 1**, ***c* = 1** y ***m* = 22**, obtenemos la
cadena:

**15, 16, 17, 18, 19, 20, 21, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14**,

sin embargo, aunque la cadena tiene la máxima longitud posible, los
números no son aleatorios por lo que la cadena es inútil para fines de
simulación.

### Pruebas de aleatoriedad.

#### Avance Victor

Se unificaron los programas que generan la "semilla" y los números
pseudoaleatorios con el método congruencial en un solo programa en C
para que al ejecutar el programa se tenga como salida un número
"pseudoaleatorio".

Para aplicar las pruebas de aleatoriedad del NIST, es necesario que el
número esté en representación binaria. Entonces se creó una función que
recibe un número entero y lo transforma a base 2 para después imprimirlo
en la salida estándar. Este programa se juntó con los dos anteriores
para generar un programa en C que regresará número aleatorios pero
convertidos en binarios (ver script DecimalToBinary.C). Una vez
funcionando el programa se ejecutó 100,000 veces para generar una cadena
de números aleatorios lo suficientemente larga para las pruebas, esto se
hizo con un loop en shell (ver rand.sh). Lo anterior se repitió para los
parámetros encontrados en el avance previo; m = 2048, c = 1 y a = 65,
1229, 1365.Los números generados pueden verse
[aquí.](https://drive.google.com/open?id=1nVI6XT4NMOQAzmtz8QnFogb1a0MfRHSq)

Los resultados de las pruebas se ven en los archivos
[finalAnalysisiReport](https://drive.google.com/open?id=17OI55U7bqcRxCqyJjQgVzoUzSvfXxKt7)
y
[freq](https://drive.google.com/open?id=1s9MvT_l9cFVe8oieFW1cTYpbG2nirlxp),
los cuales tienen como sufijo los valores de m, a y c.

Concluimos que nuestro algoritmo a pesar de obtener ciclos máximos no
está teniendo propiedad "buenas" de aleatoriedad. Por lo tanto, debemos
trabajar en optimizar el algoritmo desde el punto de vista que genere
cadenas pseudoaleatorias que pasen las pruebas del NIST.

### Generación de números en paralelo.

#### Avance Oliab

Al principio de este trabajo, la generación de números en paralelo
estaba considerada solamente como un punto de comparación con nuestro
generados de números aleatorios. Queriamos comparar los resultados de
las pruebas NIST.

En la entrega anterior se logró correr una versión de este algoritmo.
Para esta se modificó este para obtener números enteros y poder comparar
estos con los generados por el método congruencial que se especifíca
arriba y actualmente nos encontramos trabajando en la implementación del
código en paralelo de este ya que en la práctica nos interesa la
velocidad en problemas de grandes numeros, pues paralelizar es una gran
herramienta.A

El código modificado para enteros que se usaran en las pruebas se puede
ver en la carpeta de código al igual que el código base que usaremos
como referencia para la paralelización es este. Los números generados
para pruebas se pueden ver
[aquí.](https://drive.google.com/open?id=1nVI6XT4NMOQAzmtz8QnFogb1a0MfRHSq)
