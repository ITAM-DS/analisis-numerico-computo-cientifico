---
title: Reporte: Convex Optimization for Big Data.
author: Alejandro Daniel Pérez Palacios, 167256
date: 31/Mayo/2018
---

# Reporte: Convex Optimization for Big Data.

El objetivo del artículo es repasar los avances recientes en el campo de optimización convexa para big data, lo cual busca reducir los cuellos de botella computacionales de almacenamiento y comunicación. Los algoritmos están basados en principios simples y alcanzan una aceleración asombrosa incluso para problemas clásicos.

## Optimización convexa en el despertar del Big Data.

Aunque la optimización convexa data desde hace tiempo para el procesamiento de señales, su importancia en las formulaciones y optimización ha incrementado debido al surgimiento de nueva teoria de minimización de rangos o matrices ralas, además de los exitosos modelos estadísticos como máquina de soporte vectorial.

Hay múltiples razones por el aumento de interés en el campo, siend las dos más obvias la existencia de algortimos eficientes para calcular las soluciones óptimas y la abilidad de utilzar geometría convexa para probar propiedades útiles de la solución. 

Sin embargo, la popularidad por la optimización convexa pone a prueba a los diversos algoritmos para encontrar las soluciones óptimas que se basen en datos de gran tamaño provenientes de diversas fuentes como internet, texto u otros problemas que causan que el crecimiento sea de terabytes a exabytes cuando antes era de megabytes a gigabytes. Incluso con los avances en cuanto a paralelismo y cómputo distribuido la utilidad de los algoritmos clásicos no pasa más alla de la teoría para un conjunto de datos de tal tamaño.

Es por esto que la optimización convexa se tuvo que adaptar a este tipo de datos en los que una simple rutina de algebra lineal representa un problema. El contraste más claro con respecto a la optimización clásica es que no es necesario buscar una precisión cien por ciento certera ya que los problemas con este tipo de datos son simple e incluso inexactos.

## Idea general.

Una idea básica para entender los algoritmos de optimización para big data se basa en 3 pilares:

  + **Métodos de Primer orden**: Estos métodos obtienen una precisión baja/mediana de la solución númerica de su función objetivo, éstos métodos presentan una casi independencia a la dimensión del problema en cuanto a su convergencia y típicamente dependen de primitivas computacionales que son ideales para el cómputo distrbuido y paralelización.
  + **Aleatorización**: Las técnicas de aleatorización sobresalen en el ámbito de aproximación con respecto a otras técnicas ya que funcionan como un motor para los métodos de primer orden y además podemos controlar su comportamiento esperado.
  + **Cómputo distribuido y en paralelo**: Los métodos de primer orden son lo suficientemente flexibles para su implementación en paralelo o de manera distribuida.
  
Los 3 pilares se complementan de tal manera que ofrecen beneficios de escalabilidad para la optimización en big data. Por ejemplo los métodos de primer orden aleatorizados presentan una aceleración en convergencia con respecto a su contraparte determinística; en particular, un ejemplo que relaciono con esto de la maestría es el descenso gradiente estocástico para redes neuronales, ya que se desea minimizar una función pero por la cantidad de datos se van tomando muestras con las que se calcula el gradiente y se va convergiendo a la misma solución que el gradiente determinista pero de manera más rápida (para muchos datos).

Uno de los problemas habituales dentro de la optimización es el de regresión lineal, en el que deseamos hallar los coeficientes que mejor ajusten a nuestros datos, este ajuste se traduce en la minimimización del error cuadrático medio y recibe el nombre de mínimos cuadrados. Este problema es ampliamente usado en varios campos de la ciencia y en problemas prácticos y una de las maneras más claras de encontrar la solución es mediante descenso gradiente.

Se muestra en el artículo que el algortimo de descenso gradiente estocástico presenta una convergencia rápida con menos cantidad de datos que su contraparte determinística.

En el artículo se comenta que utilizando un marco completo de gradiente proximal se pueden resolver problemas no suaves casi tan fácilmente como problemas suaves, cosa que a mediados de los 2000 no se entendía del todo.

### Objetivo suave.

Para este caso tomamos una función a optimizar _f_ convexa y diferenciable. La técnica elemental para encontrar el óptimo es descenso gradiente, en la que se toma el gradiente local <a href="http://www.codecogs.com/eqnedit.php?latex=\triangledown&space;f(x)" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\triangledown&space;f(x)" title="\triangledown f(x)" /></a> y se realiza la siguiente actualización:

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;x^{k&plus;1}&space;&=&space;x^k-\alpha_k\triangledown&space;f(x^k)&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;x^{k&plus;1}&space;&=&space;x^k-\alpha_k\triangledown&space;f(x^k)&space;\end{align*}" title="\begin{align*} x^{k+1} &= x^k-\alpha_k\triangledown f(x^k) \end{align*}" /></a>

donde _k_ es la _k_-ésima iteración y <a href="http://www.codecogs.com/eqnedit.php?latex=\alpha_k" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\alpha_k" title="\alpha_k" /></a> es el tamaño de paso para asegurar la convergencia.

Aún cuando puede haber algoritmos que tomen menos iteraciones que el descenso gradiente, su facilidad de computo comparado con otros algoritmos nos ayuda a disminuir el tiempo de convergencia. Además si realizamos algunos supuestos sobre _f_ podemos saber cuantas iteraciones necesitará el algoritmo para llegar a una solución acertada bajo un nivel de confianza <a href="http://www.codecogs.com/eqnedit.php?latex=\epsilon" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\epsilon" title="\epsilon" /></a>. La suposición es que la función es Lipschitz continua, es decir:

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;\forall&space;x,y\in\mathbb{R}^p,||\triangledown&space;f(x)-\triangledown&space;f(y)||_2\leq&space;L||x-y||_2&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;\forall&space;x,y\in\mathbb{R}^p,||\triangledown&space;f(x)-\triangledown&space;f(y)||_2\leq&space;L||x-y||_2&space;\end{align*}" title="\begin{align*} \forall x,y\in\mathbb{R}^p,||\triangledown f(x)-\triangledown f(y)||_2\leq L||x-y||_2 \end{align*}" /></a>

Para una constante _L_. Si _f_ tiene segunda derivada podemos deducir que el método del gradiente tomara <a href="http://www.codecogs.com/eqnedit.php?latex=O(1/\epsilon)" target="_blank"><img src="http://latex.codecogs.com/gif.latex?O(1/\epsilon)" title="O(1/\epsilon)" /></a> iteraciones para una solución acertada a un nivel de precisión <a href="http://www.codecogs.com/eqnedit.php?latex=\epsilon" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\epsilon" title="\epsilon" /></a>. 

Aunque se puede definir una cota superior para el número de iteraciones la precisión del algoritmos aún puede mejorarse, es lo que se menciona en el artículo mediante el método de gradiente de Nesterov al agregar un parámetro extra para el momento.

  1) <a href="http://www.codecogs.com/eqnedit.php?latex=x^{k&plus;1}=v^k-\alpha_k\triangledown&space;f(v^k)" target="_blank"><img src="http://latex.codecogs.com/gif.latex?x^{k&plus;1}=v^k-\alpha_k\triangledown&space;f(v^k)" title="x^{k+1}=v^k-\alpha_k\triangledown f(v^k)" /></a>
  2) <a href="http://www.codecogs.com/eqnedit.php?latex=v^{k&plus;1}=x^{k&plus;1}&plus;\beta_k(x^{k&plus;1}-x^k)" target="_blank"><img src="http://latex.codecogs.com/gif.latex?v^{k&plus;1}=x^{k&plus;1}&plus;\beta_k(x^{k&plus;1}-x^k)" title="v^{k+1}=x^{k+1}+\beta_k(x^{k+1}-x^k)" /></a>

Este ayuda a que la k-ésima iteración se "mueva" en la mejor dirección posible y se mantenga en esa dirección.

Entre las características que puede presentar una función que sean de utilidad para la optimización debemos poner especial atención a la convexidad fuerte. Diremos que una función _f_ es fuertemente convexa si <a href="http://www.codecogs.com/eqnedit.php?latex=x&space;\mapsto&space;f(x)&space;-\mu/2||x||_2^2" target="_blank"><img src="http://latex.codecogs.com/gif.latex?x&space;\mapsto&space;f(x)&space;-\mu/2||x||_2^2" title="x \mapsto f(x) -\mu/2||x||_2^2" /></a> es convexa para algún valor <a href="http://www.codecogs.com/eqnedit.php?latex=\mu>0" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\mu>0" title="\mu>0" /></a>. Cualquier problema convexo puede transformarse en un problema fuertemente convexo al añadir el término de regularización.

Cada una de las propiedades añadidas al método de descenso gradiente que se derivó de los supuestos ayuda a una convergencia más rápida y certera, cómo se muestra en el artículo podemos actualizar el tamaño de paso en cada iteración o definir el mejor tamaño de paso y mostrar que la convergencia es mejor, siempre y cuando la función _f_ cumpla los supuestos(Lipschitz continua, con segunda derivada o con gradiente Lipschitz.

### Composición de objetivos.

Para este caso consideramos un problema de optimización formado por _f_ suave y _g_ no suave convexa. En general un problema de este estilo hace que la eficiencia de los métodos de primer orden se vea reducida. Es por esto que se utilizan los métodos de gradiente-proximal ya que aprovecha la estructura mixta de este tipo de funciones, además podemos notar a este método como una extensión natural al descenso gradiente cuando lo vemos como un problema de optimización:

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;x^{k&plus;1}&space;&=&space;\underset{y\in\mathbb{R}^p}{argmin}\left&space;\{&space;f(x^k)&plus;\triangledown&space;f(x^k)^T(y-x^k)&plus;\frac{1}{2\alpha_k}||y-x^k||^2\right&space;\}&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;x^{k&plus;1}&space;&=&space;\underset{y\in\mathbb{R}^p}{argmin}\left&space;\{&space;f(x^k)&plus;\triangledown&space;f(x^k)^T(y-x^k)&plus;\frac{1}{2\alpha_k}||y-x^k||^2\right&space;\}&space;\end{align*}" title="\begin{align*} x^{k+1} &= \underset{y\in\mathbb{R}^p}{argmin}\left \{ f(x^k)+\triangledown f(x^k)^T(y-x^k)+\frac{1}{2\alpha_k}||y-x^k||^2\right \} \end{align*}" /></a>

El gradiente-proximal utiliza la misa aproximación de _f_ pero agrega el término _g_ no suave de manera explícita:

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;x^{k&plus;1}&space;&=&space;\underset{y\in\mathbb{R}^p}{argmin}\left&space;\{&space;f(x^k)&plus;\triangledown&space;f(x^k)^T(y-x^k)&plus;\frac{1}{2\alpha_k}||y-x^k||^2&space;&plus;&space;g(y)\right&space;\}&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;x^{k&plus;1}&space;&=&space;\underset{y\in\mathbb{R}^p}{argmin}\left&space;\{&space;f(x^k)&plus;\triangledown&space;f(x^k)^T(y-x^k)&plus;\frac{1}{2\alpha_k}||y-x^k||^2&space;&plus;&space;g(y)\right&space;\}&space;\end{align*}" title="\begin{align*} x^{k+1} &= \underset{y\in\mathbb{R}^p}{argmin}\left \{ f(x^k)+\triangledown f(x^k)^T(y-x^k)+\frac{1}{2\alpha_k}||y-x^k||^2 + g(y)\right \} \end{align*}" /></a>

Para este caso el problema de optimización es la regla de actualización del método gradiente-proximal:

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;x^{k&plus;1}&space;&=&space;prox_{\alpha&space;kg}(x^k-\alpha_k\triangledown&space;f(x^k))&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;x^{k&plus;1}&space;&=&space;prox_{\alpha&space;kg}(x^k-\alpha_k\triangledown&space;f(x^k))&space;\end{align*}" title="\begin{align*} x^{k+1} &= prox_{\alpha kg}(x^k-\alpha_k\triangledown f(x^k)) \end{align*}" /></a>

donde,

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;prox_g(y)&space;&\overset{def}{=}&space;\underset{x}{argmin}\left&space;\{&space;g(x)&plus;\frac{1}{2}||x-y||_2^2&space;\right&space;\}&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;prox_g(y)&space;&\overset{def}{=}&space;\underset{x}{argmin}\left&space;\{&space;g(x)&plus;\frac{1}{2}||x-y||_2^2&space;\right&space;\}&space;\end{align*}" title="\begin{align*} prox_g(y) &\overset{def}{=} \underset{x}{argmin}\left \{ g(x)+\frac{1}{2}||x-y||_2^2 \right \} \end{align*}" /></a>

Para este método también es posible implementar un coeficiente <a href="http://www.codecogs.com/eqnedit.php?latex=\beta_k" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\beta_k" title="\beta_k" /></a> que se refiera al momento.

Además si definimos como restricción que _g(x)_ esté en un conjunto _C_ compacto, podemos resolver el problema de optimización con el método Frank-Wolfe sin el término cuadrático y lograr una tasa de convergencia de <a href="http://www.codecogs.com/eqnedit.php?latex=O(1/\epsilon)" target="_blank"><img src="http://latex.codecogs.com/gif.latex?O(1/\epsilon)" title="O(1/\epsilon)" /></a>.

### Objetivos proximales.

Para muchas aplicaciones no es posible utilizar los métodos vistos previamente de manera directa. Es por esto que definimos nuestro problema de la siguiente forma:

<a href="http://www.codecogs.com/eqnedit.php?latex=\begin{align*}&space;\underset{x,z\in\mathbb{R}^p}{min}\left&space;\{&space;F(x,z):=h(x)&plus;g(z):\Phi&space;z=x&space;\right&space;\}&space;\end{align*}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{align*}&space;\underset{x,z\in\mathbb{R}^p}{min}\left&space;\{&space;F(x,z):=h(x)&plus;g(z):\Phi&space;z=x&space;\right&space;\}&space;\end{align*}" title="\begin{align*} \underset{x,z\in\mathbb{R}^p}{min}\left \{ F(x,z):=h(x)+g(z):\Phi z=x \right \} \end{align*}" /></a>

Esta forma de ver el problema nos ayuda en el modelado y en los cálculos, primero se puede utilizar para múltiples problemas no suaves y segundo es posible resolverse mediante el algoritmo ADMM (_Alternating Direction Method of Multipliers_) el cual se apalanca de técnicas lagrangiana aumentada y de descomposición dual.

## Escalando para big data vía aleatorización.

Aunque los métodos de primer orden son fácilmente aplicables para cualquier tipo de datos, no necesariamente son los mejores para una gran cantidad de datos y las iteraciones pueden no converger. Es por esto que han surgido diversos algortimos de aleatorización de métodos de primer orden que incrementan el alcance de estos a escalas grandes.

A continuación se resumen algunos de los métodos y su aleatorización:

  + __Métodos de descenso coordinado__: Estos métodos se basan en realizar la actualización del descenso gradiente pero sólo al actualizar modificar una de las entradas del vector por iteración, de tal manera que es escoge la i-ésima entrada, se obtiene el i-ésimo gradiente y con este se actualiza el vector completo x. La desventaja principal de este método es encontrar el mejor índice por el cual realizar el descenso lo cual se convierte en una tarea costosa computacionalmente. Una forma de reducir este trabajo computacional es aleatorizando la selección del índice que actualiza el descenso. Este tipo de métodos se utilizan para problemas de la forma _F(Ax)_ con _A_ una matriz.
  + __Métodos de gradiente estocástico__: A diferencia de descenso coordinado que sólo actualiza una entrada a la vez, el gradiente estocástico actualiza todas las entradas pero utilizando una aproximación del gradiente. Este método es mejor utilizarlo en funciones como <a href="http://www.codecogs.com/eqnedit.php?latex=\underset{x\in\mathbb{R}^p}{min}\left&space;\{&space;F(x):=\frac{1}{n}\sum_{j=1}^n&space;F_j(x)\right&space;\}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\underset{x\in\mathbb{R}^p}{min}\left&space;\{&space;F(x):=\frac{1}{n}\sum_{j=1}^n&space;F_j(x)\right&space;\}" title="\underset{x\in\mathbb{R}^p}{min}\left \{ F(x):=\frac{1}{n}\sum_{j=1}^n F_j(x)\right \}" /></a> donde <a href="http://www.codecogs.com/eqnedit.php?latex=F_j" target="_blank"><img src="http://latex.codecogs.com/gif.latex?F_j" title="F_j" /></a> mide el desajuste por cada punto de los datos. La función objetivo la podemos ver como la estimación de la esperanza de la esperanza de F_a.
  
  + __Álgebra lineal aleatorizada__: Para problemas de big data el algebra lineal se presenta como un cuello de botella computacional debido a su dependencia con la dimensión de los datos. Sin embargo cuando los objetos matriciales a trabajar tienen representaciones de rangos bajos es cuando cuando la eficiencia  de los métodos mejora. La idea detrás del algebra lineal aleatorizada es generar aproximaciones de rango chico de las matrices ó aproximarlos. En el artículo se describen tres impactos de aleatorizar esto: El primero es acelerar los cálculos de los operadores de proximidad de funciones que dependena de valores espectrales de la matriz. Segundo se obtienen estimados insesgados del gradiente para matrices cuando la aleatorización fue escogida apropiadamente. Finalmente, este enfoque se puede utilizar para crear funciones objetivo y obtener soluciones por métodos exactos de los datos aleatorizados.
  
## El papel del cómputo en paralelo y distribuido.

Dado que en los últimos años la capacidad de almacenamiento ha aumentado exponencialmente. Es por esto que para poder procesar tal cantidad de datos, a un costo computacional razonable, es necesario que se derive de manera incremental la atención al cómputo distribuido y cómputo en paralelo.

Aunque los métodos de primer orden parecen ajustarse a buenos performance hay dos factores que nos detienen al usar sistemas distribuidos y heterogeneos:

  1. Comunicación: Mala comunicación entre las computadores y entre la memoria local reduce la eficiencia numérica de los métodos de primer orden. Por lo que para evitar esto se puede reducir la comunicación en el algortimo ó generar una copia del vector x(k) en cad máquina y que se llegue a un consenso final entre todas.
  2. Sincronización: Dado que el algoritmo de descenso depende del valor de x(k) para la siguiente iteración es necesario que el algoritmo esté sincronizando correctamente a las máquinas y esto puede causar atrasos. Es por esto que se propone utilizar algoritmos asíncronos.
  
Algo muy importante a considerar es que la comunicación y sincorinzación del hardware en el que estemos trabajando definirá el tipo de algoritmo que usemos por lo que se espera que haya algoritmos nuevos que se adapten a las nuevas plataformas computacionales.

