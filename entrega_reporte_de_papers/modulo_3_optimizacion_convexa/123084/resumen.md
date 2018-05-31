


# Optimización Convexa para Datos de Gran Escala




El paper realiza una descripción exhaustiva de los avances y retos en el área matemática de optimización convexa, bajo el contexto de requerimientos de métodos escalables y precisos para un entorno donde la dimensión de los datos presenta y sigue presentando, un reto de considerable dificultad. 

Los métodos tradicionales de optimización para funciones objetivo, ya sean diferenciables o no, consisten de multiplicaciones matriz-matriz, matriz-vector, descomposiciones relativamente simples como Cholevsky, entre otras; que en un contexto de datos de gran escala, incrementan considerablemente el orden de maginitud de (veáse notación Big O) la complejidad computacional, lo cual, valga la redundancia, incrementan el costo de sus implementaciones, limitandolos a hardware muy caro, por lo que resultan, en varios sentidos, prohibitivos.

En este contexto, la necesidad de desarrollar técnicas de optimización escalables se volvió imperativa. Es por ello que ha habido una gran cantidad de inovación en lo que el autor llama los Métodos de primer orden (First Order Methods). En particular, el desarrollo de nuevas teorías al respecto de la minimización de rango y la dispersión estructurada (aclaro, uso dispersión en sustitución del inglés sparse, en un contexto de algebra lineal, el que se refiere a matrices con una gran cantidad de elementos en cero.), ha elevado en gran manera el interés de la teoría de la optimización convexa como vía de resolución de problemas en imagenología medica, geofísica y bioinformática. El éxito de la optimización convexa para desarrollar algoritmos eficientes que computan soluciones óptimas globales, así como la interpretación de propiedades interesantes de la solución a partir de la geometría convexa, son sólo algunos de los aspectos que han contribuido aún más al interés en el área.

El desarrollo de estructuras y arquitecturas de cómputo en paralelo ha contribuido también al interés ya que mediante nuevas infraestructuras de software como spark,hadoop en alto nivel, CUDA en bajo, ha permitido paralelizar algunos de los algoritmos, a pesar de que, como veremos más adelante, la comunicación y la sincronización, durante la ejecución de los mismos, puede presentar varias complicaciones. 

Asimismo, existe un tercer componente que soporta esta nueva perspectiva de la teoría de la optimización convexa, el uso de técnicas aleatorias, las cuales han tenido incidencia directa en la escalabilidad de los nuevos algoritmos. No obstante, también éstas presentan consideraciones que se deben de tener presentes para implementarlas con precisión aceptable. Entre los vértices importantes de esta vertiente están se encuentra el reemplazo de métodos  tradicionales exactos, como el cálculo del gradiente determinístico, con estimadores del mismo. Es importante mencionar que los resultados en términos de complejidad computacional son bastante buenos en términos de ejecución, así como de la calidad de la solución, si bien se llegó a ella de forma estocástica. Otro mencionado por el autor es el de aleatorización de rutinas básicas de algebra lineal.



Posteriormente, el autor hace un desarrollo y análisis del ecosistema de lo que el llama los métodos de primer orden. 

Primero ejemplifica el descenso en gradiente con un algoritmo computacional, cuya tasa de convergencia es buena, dado que se elija un tamaño de paso adecuado. Asimismo realiza una comparación de la resolución del problema de mínimos cuadrados entre el método de regularización de LASSO, que devuelve, con gran escalabilidad, resultados que eliminan ruido (denoising effect), a diferencia de los métodos tradicionales de punto interior que requieren un mucho más espacio debido a la aplicación de multiplicaciones de matrices, o a descomposiciones de Cholesky, por ejemplo. Si bien en el mundo de grandes datos, las soluciones aproximadas son buenas, el método de regularización de LASSO posee estructuras adicionales muestran la convergencia de los métodos de primer orden, haciendolos competitivos en precisión con los métodos de punto interior.

Las gráficas de la figura uno muestran claramente cómo los métodos que explotan la aproximación estocástica escalan bastante bien con respecto a métodos gredientes conjugados, accediendo a tan sólo unas pocas filas de la matriz.

Hablando en particular de métodos de optimización en funciones convexas suaves, hay métodos similares a los de newton que incluso requieren menos iteraciones que los métodos de primer orden. Sin embargo, ocupan mayor computo, no generalizan bien a funciones convexas no suaves ni problemas restringidos.

Sin embargo, apesar de usar mucho más iteraciones, los métodos del primer orden si escalan a funciones convexas no suaves, generalizan y se pueden usar en problemas con restricciones. Ejemplificando de nuevo con el descenso en gradiente, en tiempo de ejecución, dado que usan operaciones menos costosas, aunque más iteraciones, suelen tener mejor desempeño. Asimismo, si se hacen supuestos simples incluso se puede predeterminar incluso el número de iteraciones que llevará en llegar el óptimo y ajustar el tamaño de paso acordemente acorde. 

Asimismo, a partir de estos supuestos se pueden usar técnicas más poderosas como el metodo acelerado de nesterov, que elige el tamaño de paso en función de estos supuestos, así como un parámetro extra llamado de momento, que le permite ser bastante eficiente. 

Posteriormente el autor hace un paréntesis al respecto de la estructura de problemas fuertemente convexos. Afirma que los problemas convexos se pueden convertir en fuertemente convexos, mediante la adición de un término cuadrático de regularización, y ejemplifica el mismo con la regularización de Ridge.

Por último, para terminar la seccionreferente a métodos de primer orden, el autor menciona que también se pueden usar técnicas de este estilo con funciones objetivo no suaves, mediante aproximaciones que el denomina proximal mappings. Brevemente para mencionar algunos, se encuentra el Algoritmo ADMM y el algoritmo Primal-Dual Hybrid Gradient algorithm.


Si bien ya lo mencionamos previamente, el autor pasa ahora ahondar sobre los beneficios de las técnicas de aleatorización para escalar los métodos de optimización convexa de primer orden. Un ejemplo interesante es el algoritmo de google page rank que consiste en encontrar el primer valor singular de una matrix estocástica que explica las relaciones entre las páginas de internet. Si bien se resuelve mediante el método de la potencia, también se puede aproximar muy bien como un problema de mínimos cuadrados con un parámetro de penalización sobre las restricciones. Este ejemplo tiene como fin observar que los métodos de primer orden pueden hacer muy buenas aproximaciones de sus métodos primigenios o tradicionales. 

Siguiendo con el ejemplo de page rank, el autor ejemplifica una optimización a partir de lo que el llama métodos de descenso coordinados. Si bien tradicionalmente implicaría muchas operaciones de matrices, este método elige una coordenada de forma greedy y calcula la derivada direccional para converger en una tasa aproximada. Encontrar la coordenada no es una descisión trivial.Asimismo, no puedes ser óptima con respecto a métodos tradicionales como calcular el gradiente tal cual. Posteriormente propone iterar secuencialmente sobre las coordenadas, sin embargo esto reduce muy cañon la tasa de convergencia. 

Aquí es donde hace la revelación, ya que resulta que una elección aleatoria de la coordenada da mucho mejores resultados que los propuestos arriba.

Por otra parte los métodos de gradiente estocástico cson aun mejor por que actualizan todas las coordenadas simultaneamente a través de gradientes aproximados. Son buenos para minimizar funciones que son susceptibles a descomposicion como errores de mínimos cuadrados o campos aleatorios condicionales. 

Asimismo también se puede usar la aleatoriedad para llevar aproximaciones bastante precisas a operaciones cocstosas de álgebra lineal.Un ejemplo bastante interestan es la descomposición SVD aleatoria, que permite hacer, mediante aproximaciones de menor rango, un resumen bastante preciso de matrices muy grandes. En general, las aproximaciones de menor rango aleatorias constituyen un gran método para llevar a cabo estas operaciones con bajo costo computacional.


Por último el autor finaliza el ensayo haciendo referencia a los principales aspectos que subyacen en la dificultad de paralelizar y distribuir los métodos aleatorios de primer orden. Primero, la comunicación. Este constituye un road block mayor ya que los costos computacionales en un sistema distribuido complejo para integrar los distintos nodos que realizan una paralelización puede ser complejo y susceptible a fallas. Por otra parte, la sincronización presenta otro probleman, ya que, de paralelizar trabajo, algunos nodos terminarían ántes que otros y si operan resultados que dependen de la actualización de una variable global, pueden generarse, en el caso más sencillo, condiciones de carrera que llevan a resultados completamente erróneos, no debido a un error de método sino simplemente a la dificultad de sincronizar el trabajo del algoritmo. Si bien existen diversos frameworks tanto de alto como de bajo nivel, la paralelización de los métodos mencionados anteriormente presentan dificultades importantes como las dos mencionadas previamente. 


La optimización convexa es en mi opinión un área sumamente interesante de las matemáticas/computación que está en medio de un tremendo dinamismo e inovación dados los tremendos avances que ha sido capaz de demostrar en múltiples aplicaciones. El área de investigación es enorme, sobre todo a la hora de implementar procesos estocásticos para generar métodos más eficientes, dado el éxito que ha demostrado la intersección de ambas áreas. Asimismo, la investigación sobre el tercer pilar, el cómputo distribuido también conforma una área importantísima para poder implementar la paralelización de éstas técnicas. 

