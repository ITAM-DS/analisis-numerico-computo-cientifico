## Reporte del módulo de optimización convexa

El artículo en general toca el tema de "Avances en optimización convexa de algoritmos para Big Data", la idea es de los mismos es reducir las problemáticas computacionales, de almacenamiento y de comunicación.

#### Sección de Convex optimization in the wake of Big Data

Hasta hace algún tiempo, la importancia que tenía el tema de optimización convexa recaía en distintas aplicaciones, sin embargo dos de las más obvias eran; tener algoritmos eficientes que fueran capaces de calcular soluciones optimas globales y la habilidad de usar geometría convexa para revisar propiedades de la solución. Hoy en día, los problemas de poder manejar datasets cada vez más grandes y resolver problemas de dimensiones inimaginables hace algún tiempo, le han dado un nuevo boost a la optimización convexa.

Notamos que para la parte de las bases de optimización convexa, los autores dan una descripción general de:

- **Métodos de primer orden**: Obtienen soluciones de precisión media-baja, estos métodos logran convergencia casi independiente al número de dimensiones con las  que se este trabajando, e normalmente se programan bajo una metodología que los hace excelentes candidatos para implementaciones distribuidas o en paralelo.

- **Randomization**: Estos algoritmos vuelven *escalables* métodos de primer orden, ya que podemos controlar su comportamiento esperado. Mediante la aleatorización muchas veces podemos utilizar una muestra aleatoria para obtener el comportamiento global, con esto obtenemos resultados en tiempos muchos más cortos.

- **Implementaciones en paralelo o distribuidas**: Estas implementaciones sacan jugo a las nuevas capacidades tecnológicas mediante una optimización de muchos de los métodos de primer orden.

En cuanto a los métodos de primer orden, se presenta la ecuación tradicional y el punto relevante desde mi opinión es que se pueden obtener soluciones con operaciones sencillas como multiplicación de matriz-vector. Además tenemos una variante como LASSO para agregar un término de regularización y mejorar el performance del algoritmo. Se da el ejemplo de como el gradiente estocástico se escala de manera más eficiente que un gradiente conjugado, ya que sólo requerimos acceder a una fracción de los datos.

#### Sección de First-Order Methods for Smooth and Non-Smooth Convex Optimization

En esta sección los autores abordan principalmente el *framework* de gradiente proximal y cómo es que problemas *non-smooth* pueden ser resueltos casi tan eficientemente como sus contrapartes *smooth*.

El artículo da una breve introducción de funciones objetivo *smooth* las cuales se pueden resolver con métodos de pocas iteraciones pero de mayor complejidad computacional que otros del estilo de decenso gradiente el cual aún con más iteraciones para llegar a una precisión determinada, tiene un costo bajo por iteraciones y es fácilmente generalizable a distintas aplicaciones. En muchos casos ese costo mínimo por iteración convierte a estas metodologías en las más rápidas.

Interesantemente se puede calcular el número de iteraciones que se requerirán para una precisión objetivo, y con una modificación propuesta por Nesterov se obtiene un método de primer orden óptimo (método de gradiente acelerado). La discusión de los autores comienza a ser más bien de condiciones en donde al aplicar algunas reglas creativas para escoger los parámetros de regularización y momentum se han obtenido muy bueno resultados en la práctica.

Posteriormente se trata con funciones objetivo *F* compuestas por una función convexa y diferenciable <a href="https://www.codecogs.com/eqnedit.php?latex=f" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f" title="f" /></a> y una función *non-smooth* convexa <a href="https://www.codecogs.com/eqnedit.php?latex=g" target="_blank"><img src="https://latex.codecogs.com/gif.latex?g" title="g" /></a>. Los métodos de gradiente proximal toman ventaja de la estructura compuesta anterior, para lograr tasas de convergencia similares a las de problemas *smooth*. Finalmente se habla de que los métodos anteriores que explotan de manera óptima las propiedas de concordancia de <a href="https://www.codecogs.com/eqnedit.php?latex=f" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f" title="f" /></a> tienen operadores de proximidad manejables, lo cual se explota en las siguientes secciones.

A continuación los autores hablan de funciones ojetivo proximales, realmente se hace una reformulación que parece inofensiva, pero que da pie para una mejora en capacidades de cómputo y modelaje. Primero que nada, esta reformulación puede recibir problemas con funciones objetivo *non-smooth* y *non-Lipschitz*, las cuales son muy comunes; segundo, podemos hacer uso del algoritmo ADMM (Alternating direction method of multipliers), el cual es muy poderoso ya que utiliza técnicas como la del Lagrangiano aumentado y descomposición dual. Además ADMM es fácilmente paralelizable, por último los autores tocan un par de problemas con el algoritmo que tienen que ver con resolver una ecuación que se requiere, pero hay paquetes que lo hacen y la otra es que cuando la función objetivo tiene más de dos términos, se pierden las garantías de convergencia.

#### Sección de Big Data scaling via randomization

En esta parte, el artículo habla de que, aún cuando los métodos de primer orden pueden resolver problemas de gran escala, en la práctica, el número total de procesos que se tienen que dar debido a las iteraciones de dichos métodos puede volverse imposible de realizar cuando las dimensiones del problema en cuestión crecen. Afortunadamente, los métodos de primer orden son lo suficientemente robustos como para ser aproximados via sus primitivas de optimización. Los autores entonces tratan en esta parte nuevas aproximaciones mediante aleatorización que permiten llevar los métodos de primer orden a escalas nunca antes vistas. Un ejemplo de estos problemas podría ser el PageRank de Google.

Posteriormente, se abordan los métodos de decenso en coordenadas. Estos métodos en lugar de calcular el gradiente completo, sólo toman una coordenada y con ella sólo modifican su entrada correspondiente, para mejorar la función objetivo, el punto clave en esta metodología es la elección de las coordenadas. Increíblemente, al aleatorizar la elección de la coordenada tenemos excelentes resultados ya que se llegan a los resultados esperados con una variación relativamente controlada.

A continuación se habla de los métodos de decenso gradiente estocástico. A diferencia de los métodos anteriores, sí se calcula el gradiente completo, sin embargo, no se usa el cálculo exacto, sino que más bien se estima. Bajo esta aproximación, históricamente se han tenido problemas para usar los parámetros correctos, sin embargo, últimamente el uso de pasos grandes para regularizar y el uso de promedios de las iteraciones anteriores hace que el algoritmo se estabilize rápidamente.

En la siguiente parte el artículo toca el tema de algebra lineal aleatorizada. La idea de los métodos que utilizan la aproximación de esta sección es aproximar <a href="https://www.codecogs.com/eqnedit.php?latex=M\approx&space;Q(Q^{T}M)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?M\approx&space;Q(Q^{T}M)" title="M\approx Q(Q^{T}M)" /></a> con <a href="https://www.codecogs.com/eqnedit.php?latex=Q\epsilon&space;\mathbb{R}^{p\times&space;x}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Q\epsilon&space;\mathbb{R}^{p\times&space;x}" title="Q\epsilon \mathbb{R}^{p\times x}" /></a>, o bien construir una representación *low-rank* con base en un subconjunto de columnas o renglones para acelerar el cómputo. Al realizar lo anterior de manera aleatoria, podemos controlar el nivel de error.

También, se describen tres partes importantes del algebra lineal aleatorizado. Primero, se acelera el cómputo de operadores de funciones que dependen de los valores espectrales de la matriz. Segundo, la idea también funciona en la obtención de estimamdores insesgados por gradiente para matrices, lo cual significa que se puede extender a todos los algoritmos de decenso gradiente estocástico. Finalmente, la aleatorización, permite esbozar funciones objetivo, es decir, aproximarlas de otra manera para tener iteraciones mucho más simples que puedan posteriormente ser realizadas con métodos de primer orden, sin perder precisión.

#### Sección de Role of parallel and distributed computation

Debido a las mejoras que se han tenido desde hace algunos años en el poder de cómputo y las capacidades de memoria, hoy en día, podemos manejar cantidades de datos masivas, sin embargo, la potencia que requieren dichos equipos no se ha ido eficientando a la misma velocidad, es por ello que al sacar jugo a las nuevas capacidades, y correr de manera más veloz nuestros algoritmos podemos eficientar consumos de energía y mantenerlos en niveles razonables.

Posteriormente, se platica acerca de dos temas que representan problemas de los métodos de primer orden. Primero, existen problemas de comunicación entre las computadoras y la memoria interna. Segundo, hay problemas de sincronización, ya que para paralelizar los métodos de primer orden se necesita una orquestación de los procesos. Se discuten soluciones a estos problemas en la descripción de los mismos.

A continuación se habla de métodos de primer orden ya que estos pueden ser fácilmente paralelizados, se explica un ejemplo de esto. Existen muchas tecnologías que son capaces de coordinar los procesos de algunos de los algoritmos sencillos, ejemplos de las misma son MapReduce, Hadoop, Spark, Mahout, MADlib ó SystemML. Los autores abordan como siguiente parte, métodos de primer orden que pueden ser implementados en paralelo, pero con el plus de cuidar que no haya un alta comunicación entre el procesador y la memoria interna para mejorar el performance. Finalmente, se unen las aproximaciones anteriores en algoritmos que pueden ser implementados de manera aíncrona y con el menor volumen de comunicación entre el procesador y la memoria interna; estas implementaciones son una explicación de cómo se pueden ir resolviendo los problemas que se presentaron al inicio de esta sección.

#### Sección de Outlook for convex optimization

Los problemas de Big Data muestran que debemos de revisar la manera en que diseñamos algoritmos de optimización convexa, ya que para adaptarlos a las tecnologías y condiciones actuales hay que tomar algunas decisiones poco convencionales con el objetivo de resolver un problema. El artículo muestra que existen pérdidas fundamentales ya sea en tiempos por ganar precisión o viceversa, pero esto representa un área de oportunidad.

Dadas las características del hardware que se use siempre habrá que adaptar ciertos procesos, cuidando las limitantes que existen en cuestión de comunicación y sincronización, pero el uso de muchas de las técnicas y mejoras que se discuten en el artículo muestra que sí existen opciones para obtener los resultados esperados. Además, los autores preveen un uso mayor de modelos compuestos, lo cual supondrá un nuevo reto para obtener la misma información que hasta el momento se ha logrado, pero a una mayor velocidad.

#### Referencia

https://arxiv.org/pdf/1411.0972.pdf
