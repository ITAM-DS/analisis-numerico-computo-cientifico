### Reporte del artículo "Convex Optimization for Big Data" de Volkan Cevher, Stephen Becker y Mark Schmidt.

El artículo comienza señalando que en la optimización convexa se está reinventando debido al Big Data, donde el tamaño de los datos y los parámetros para problemas de optimización son demasiado grandes como para ser procesados localmente, y donde inclusive el álgebra lineal básica tiene que adoptar una nueva estrategia para realizar las operaciones. En este nuevo paradigma basado en "tamaño", los algoritmos convexos ya no tienen necesidad de buscar soluciones muy precisas, pues los modelos de Big Data son necesariamente simples o inexactos.

En la sección "The basics" describen el fundamento de la "Big Data Optimization" con la siguiente funcion compuesta: F^* = min{F(x) = f(x) + g(x) : x en R^p} donde f y g son funciones convexas.

El artículo esta estructurado sobre los siguientes 3 puntos siguientes:

- Métodos de primer orden.

- Aleatorización.

- Cómputo paralelo y distribuido.

__Métodos de primer orden__

En esta sección el artículo describe el procedimiento cuando la función objetivo es "suave", cuando la función objetivo es "compuesta" y con funciones objetivo proximales.

En el primer caso se asume que la función objetivo sólo consiste en una función convexa y diferenciable f. La técnica de primer orden que se utiliza en este caso es el método del gradiente, que utiliza el gradiente local grad{f(x)} y calcula de manera iterativa: x^{k+1} = x^k - alpha_k grad{f(x^k)}, donde k se refiere a la k-ésima iteración y alpha_k es el paso que definimos y que asegura la convergencia. 

Los autores destacan que para minimización suave se pueden utilizar otros métodos que son más rápidos (i.e. requieren menos iteraciones) como Newton.

Detallan el algoritmo de Nesterov para el calculo de gradiente indicando que es el método que logra la mejor tasa de error en el posible peor escenario y que por ende usualmente a este método se le denota como un método de primer orden óptimo. El algorimo de gradiente acelerado de Nesterov se describe a continuación:

1. x^{k+1} = v^{k} - alpha_k * grad{f(v^k)}
2. v^{k+1} = x^{k+1} + beta_k * (x^{k+1} - x^k)

Cuando la función objetivo es compuesta; es decir, la función objetivo consiste en un función convexa f y una función convexa no suave g, en general la no diferenciabilidad de g reduce la eficiencia de los métodos de primer orden. No obstante, se pueden utilizar métodos de gradiente proximales que utilizan la misma aproximación para f pero incluyen el término g.

El articulo detalla el algoritmo del gradiente proximal acelerado e indica que en casos donde la función g tiene la formulación de LASSO, el operador proximal es eficiente y en otro caso particular donde g es una función indicadora de un conjunto compacto, el problema de optimización compuesto se pude resolver con el método de Frank-Wolfe. El algoritmo de gradiente proximal acelerado se describe a continuación:

1. x^{k+1} = prox_{alpha_k g} * (v^k - alpha_k * grad{f(v^k)})
2. v^{k+1} = x^{k+1} + beta_k * (x^{k+1} - x^k)

En tercera instancia indican que en casos en los que los métodos de primer orden que se han detallado no se puedan aplicar, se utiliza un reformulación del problema compuesto: min_{x,z en R^p}{F(x,z) = h(x) + g(z) : Phi{z}=x} con operadores proximales h y g. A esta reformulación se puede aplicar un algoritmo llamado "alternating direction method model" (ADMM) que utiliza un Lagrangiano aumentado y técnicas de descomposición dual.

Indican que este algorimo es altamente recomendable para optimización distribuida y requiere un parámetro de penalización.

Finalmente, comentan que el algoritmo ADMM tiene dos puntos negativos pues una parte del mismo se tiene que resolver numericamente y la otra es que si se realiza la extensión a tener más dos términos objetivo, la convergencia ya no se está garantizada. Para este último punto relativo a funciones objetivo con más de dos términos, se pueden utilizar técnicas de descomposición dual para tratar los múltiples términos en la función objetivo por serparado y resolverlos de forma simultánea en paralelo.

__Aleatorización__

En problemas de gran escala para métodos de primer orden se utilizan aproximaciones aleatorias.

En esta sección el artículo describe los métodos de descenso por coordenada o entrada, metodos de gradiente estocástico y aleatoriedad en algebra lineal.

En relación al primer método, los autores indican que calcular el gradiente total requiere operaciones matriz-vector en cada iteración, lo cual resulta caro; una operación más "barata" es escoger una coordenada o entrada i de x y sólo modificar la correspondiente variable x_i para mejorar la función objetivo. La forma general del descenco por coordenada se describe a continuación:

1. Escoger un índice i_k en {1,2,...,p} 
2. x^{k+1} = x^k - alpha * grad{F(x^k)}_{ik} * e_{ik}

La clave en este algoritmo es la selección de la coordenada i en cada iteración, para los cual, lo autores sugieren que se lleve a cabo una elección aleatoria de la coordenada.

El segundo método que describen es descenso estocástico, que a diferencia del método descrito con antelación, actualiza todas las coordenadas o entradas de forma simultánea pero usando una aproximación del gradiente. En este caso el algoritmo es como sigue:

1. Escoger un índice j_k en {1,2,...,n} de manera uniforme aleatoria.
2. x^{k+1} = x^k - alpha_k * grad{F(x^k)}_{jk}

En este caso la clave es la elección de los puntos j en cada iteración y de igual manera los autores señalan que se obtienen mejores tasas de convergencia si se selecciona j de manera uniforme aleatoria.

Para el tercer método los autores indican que la idea es aproximar M a traves de Q * (Q^t * M) con Q en R^{p x r} o construir una representación de bajo rango por columna o por renglón para acelerar los cálculos. El algoritmo en este caso es como sigue:

Requerimos una matriz M de dimensión R^{p x p} y un entero r,

1. Escogemos Omega en R^{p x r} iid N(0,1)
2. W = M * Omega
3. Q * R = W
4. U = M^t * Q
5. Regresamos M^{hat}_(r) = Q * U^t


__Cómputo paralelo y distribuido__

Los autores resaltan que debido a los nuevos requerimientos de póder de computo y almacenamiento a un consumo de energía razonable, se debe de incrementar el uso de cómputo distribuido y paralelo.

Mencionan que hay dos dificultades al utilizar hardware distribuido en métodos de primer orden. En primer lugar la comunicación, pues una deficiente comunicación entre computadoras y entre la memoria local pueden reducir la eficiencia numérica al utilizar métodos de primer orden. Para contrarrestar este efecto se utilizan dos estrategias: diseñar algoritmos que minimicen la comunicación y eliminar el vector maestro x^k y en su lugar trabajar con una copia local en cada máquina de tal forma que lleguen a una X^* consensuada al converger.

La segunda dificultad radica en la sincronización, pues para realizar los cálculos de manera exacta de forma distribuida, los métodos de primer orden tienen que coordinar las actividades de diferentes computadoras cuyas primitivas numéricas dependen del mismo vector x^k en cada iteración. Para contrarrestar este problema, se desarrollan algoritmos asíncronos que permiten actualizaciones usandos versiones anteriores del parámetro.

En sistemas grandes, comunicar el gradiente o sus elementos a una locación en el sistema central puede crear un cuello de botella en las comunicaciones. En estos casos, el descenso por coordenada o entrada puede presentar una alternativa para reducir las comunicaciones, aplicando varias actualizaciones de descenso por coordenada al mismo tiempo en paralelo, pues la ventaja radica en que cada procesador sólo tiene que comunicar una actualización de coordenada o entrada.

Cuando la función objetivo se puede descomponer, en realidad se puede aplicar la versión paralela del algoritmo secuencial.

Los autores señalan que los algorimos de primer orden con aleatoriedad resultan efectivos inclusive en ambientes descentralizados y asíncronos con posibilidad de comunicar las fallas.

Finalmente, el artículo concluye indicando que como las restricciones de sincronización y de comunicación del hardware actual son las que dictan la elección del algoritmo a utilizar, se espera que se desarrollen nuevas herramientas para adaptar los algoritmos de convexidad a plataformas computacionales heterogéneas. Asimismo, los autores predicen que se incrementará el uso de modelos compuestos.

















