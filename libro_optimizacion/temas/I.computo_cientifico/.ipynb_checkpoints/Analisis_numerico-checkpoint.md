Nota generada a partir de [liga](https://www.dropbox.com/s/z5ifw3ti66gukdy/1.1.Analisis_numerico_y_computo_cientifico.pdf?dl=0)

# 1.1 Análisis numérico y cómputo científico

## Introducción


El cómputo científico (ver [liga](https://en.wikipedia.org/wiki/Computational_science)) es parte de lo que se conoce como ciencia de la computación, cuya investigación incluye las fases:

1) Desarrollo de un modelo matemático para un fenómeno de interés. 

2) Desarrollo de un algoritmo.

3) Implementación del algoritmo en un software.

4) Simulaciones numéricas del fenómeno con el software.

5) Representación de los resultados calculados (gráficas o herramientas visuales).

6) Interpretación y validación de los resultados.

y se realizan los puntos anteriores en una forma repetida ($1$-$6$) dependiendo de los resultados obtenidos en $6$.

El cómputo científico se encarga de las fases $2$ a $4$: desarrollo, implementación y uso de los algoritmos numéricos y software para aplicaciones. Ejemplos de aplicaciones las encontramos en análisis y ajuste de modelos a datos, optimización y machine learning, entre otras.


## Análisis numérico y cómputo científico.

Nuestro curso involucra temas del análisis numérico el cual se enfoca al diseño y análisis de algoritmos para resolver problemas que surgen en la ciencia de la computación e ingeniería. Por esto, al análisis numérico se le ha llamado también cómputo científico y se distingue de otras áreas de la ciencia de la computación en que trabaja con **cantidades continuas**, cantidades como velocidad y temperatura presentes naturalmente son algunos ejemplos. 

Tales cantidades las encontramos en muchos problemas de matemáticas los cuales no se resuelven en principio con un número finito de pasos, sino que deben resolverse por un proceso iterativo que converja a la solución, teóricamente infinito. Sin embargo, en la práctica, no se realizan procesos infinitos y además no se resuelven problemas de manera exacta; se obtienen respuestas aproximadamente correctas, "suficientemente cercanas o precisas" al resultado deseado. Así, el análisis numérico debe trabajar con recursos finitos y cantidades discretas.

Lo anterior subraya uno de los aspectos más importantes del cómputo científico: encontrar algoritmos iterativos que **converjan** "rápidamente", así como dar una estimación de la **exactitud** de las aproximaciones calculadas. Así, un segundo tema que distingue al análisis numérico de otras áreas de la ciencia de la computación es el relacionado con las **aproximaciones** y sus efectos. Es indispensable que tales aproximaciones sean controladas por algoritmos "buenos", esto es, que sean **eficientes** (hacer más con menos), sean **confiables** y **exactos** ante la serie de aproximaciones realizadas: sean **estables**.

La eficiencia se relaciona directamente con el **costo computacional**, el cual típicamente se mide a partir del número de operaciones que realiza el algoritmo (aunque otra componente común para medir el costo computacional, es la transferencia de datos entre las diferentes jerarquías de memoria en una máquina) y la **estabilidad** se refiere a no amplificar los **errores** generados por las aproximaciones o resultados calculados durante la ejecución del algoritmo. Asimismo, la estabilidad se relaciona con la pregunta: ¿si se perturban los datos de entrada, el algoritmo calcula una solución "cercana" a los datos no perturbados? (esta pregunta tiene que ver con el **análisis de sensibilidad** en un algoritmo ante perturbaciones en los datos de entrada).

## Fuentes de error

Algunas fuentes de error que nos encontramos al resolver un problema surgen por:

* Uso de modelos (simplificación u omisión).

* Mediciones con instrumentos.

* Cálculos previos.

Las fuentes anteriores típicamente están fuera de nuestro control. En el cómputo científico se estudian dos fuentes que influyen directamente en el algoritmo utilizado para resolver un problema y sí podemos controlarlas:

* Truncamiento: relacionado con el uso de procesos o cantidades finitas.

* Redondeo: relacionado con la representación de los números y la aritmética realizada en una máquina.


Estas fuentes de error influyen en la exactitud de un cálculo y las perturbaciones que resulten de estas fuentes, serán amplificadas (o no) por la **naturaleza del problema** y el **tipo de algoritmo utilizado**. Al estudio de la exactitud y estabilidad de un algoritmo por fuentes de error se le llama **análisis del error**.

## Análisis del error

En general un problema puede verse como evaluar una función $f: \mathbb{R} \rightarrow \mathbb{R}$. Por ejemplo, sea $x$ el dato de entrada, considérese el problema de evaluar $f(x)$, el dato de salida.

Al trabajar con la máquina, nos encontramos que la representación de un número real en general no es exacta, por ello tenemos una aproximación $\hat{x}$ a la cantidad $x$ (error por redondeo) y nuestra forma de calcular $f$ es por medio de un algoritmo $\hat{f}$, entonces, el error al evaluar $f$ es:

$$\text{Error total} = \hat{f}(\hat{x}) - f(x) = \underbrace{\hat{f}(\hat{x})-f(\hat{x})}_\text{Error Computacional} + \underbrace{f(\hat{x})-f(x)}_\text{Error en datos}.$$

El primer término es generado por el algoritmo utilizado: $\hat{f}$ (cálculos y aproximaciones realizadas por el algoritmo utilizando $\hat{x}$) y el segundo es debido a mediciones o redondeos realizados por la máquina o personas o instrumentos, observa que este término no se ve influenciado por el algoritmo utilizado y es un error que no controlamos.

El error computacional tiene dos componentes: uno por **truncamiento** y otro por **redondeo**: 

* El truncamiento es la diferencia entre el resultado veradero y el resultado que se obtiene con un algoritmo usando aritmética exacta. Por ejemplo, reemplazar una serie infinita (resultado verdadero) con una serie truncada (algoritmo: truncar serie infinita) y evaluar la serie truncada con **aritmética exacta** (por ejemplo usar $\frac{1}{3}$ en los cálculos en lugar de $0.333$). 

* El error por redondeo es la diferencia entre el resultado obtenido por un algoritmo utilizando aritmética exacta y el resultado producido por el mismo algoritmo usando **aritmética de máquina**.

**Obs:** obsérvese que en la descomposición del error total de arriba se utiliza en el error computacional $\hat{x}$. En la nota [1.3.Condición_estabilidad_y_normas](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/blob/master/temas/I.computo_cientifico/1.3.Condicion_de_un_problema_y_estabilidad_de_un_algoritmo.ipynb) se define la estabilidad de un algoritmo utilizando $x$ en lugar de $\hat{x}$ pues se desea medir la cercanía entre $x$ y $\hat{x}$ determinada por el sistema de punto flotante (errores por redondeo).

**Comentario:** aunque los errores por truncamiento y por redondeo son componentes del error total, típicamente un tipo de error domina sobre otro. Hacer la distinción entre ellos, nos ayuda a entender el comportamiento de los algoritmos y los factores que influyen en su **exactitud**.

## Nota sobre exactitud y precisión.

Los errores en los cálculos y las medidas se pueden caracterizar respecto a su exactitud y precisión. La exactitud se refiere a que tan cercano está el valor calculado o medido del valor verdadero. La precisión se refiere a qué tan cercanos se encuentran unos de otros diversos valores calculados o medidos. Obsérvese el siguiente diagrama:

<img src="https://www.dl.dropboxusercontent.com/s/azkoe49xfg3a90d/1.1.exactitud_precision.png?dl=0" heigth="500" width="500">

**Preguntas de comprehensión**

1)¿Cuáles son las características del análisis numérico y cómputo científico?

2)¿Qué propiedades debe tener un buen algoritmo?

3)¿Cuáles fuentes de error principalmente son estudiadas por el análisis numérico y cómputo científico al resolver un problema?

4)Menciona las diferencias entre los términos exactitud y precisión.


**Referencias:**

1. M. T. Heath, Scientific Computing. An Introductory Survey, McGraw-Hill, 2002.
