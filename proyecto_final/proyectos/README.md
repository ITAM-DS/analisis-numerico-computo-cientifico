# Lista de proyectos:

---

## [Equipo 1](equipos/equipo_1)

Ttulo del proyecto: `Reducing Commercial Aviation Fatalities`

Objetivo del proyecto: Este proyecto aborda el problema descrito en la competencia de Kaggle llamada “Reducing Commercial Aviation Fatalities”. El propósito de esta competencia es identificar si los pilotos de aviones presentan algún estado cognitivo que pueda ser peligroso en diversas simulaciones de vuelo, así como cuáles son sus causas. El objetivo del proyecto, desde la perspectiva del análisis y optimización numérica, es aplicar un regresión logística multinomial en donde se pretende clasificar cada evento observado en las categorías Atención Canalizada (CDA), Atención Desviada (DA), Sorpresa (SS) o Ausencia de ella (A). Los problemas de optimización de esta forma parten de minimizar la devianza generada por el modelo propuesto y por los datos disponibles.


[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 2](equipos/equipo_2)

Ttulo del proyecto: `Comparación de Métodos de reducción de dimensionalidad  CUR Descomposition y SVD aplicados a un problema de sistemas de recomendación.`

Objetivo del proyecto: Implementación y evaluación de los algoritmos  CUR Descomposition  y SVD, utilizando las librerías de BLAS y CUDA GPUs. La evaluación del desempeño de estos algoritmos se realizará en un  problema de sistemas de recomendación (aún no elegimos nuestro data set, lo cual es un punto importante pues podría modificar nuestra selección de la aplicación)  tanto en tiempo de procesamiento como en la precisión de sus resultados (de acuerdo a alguna métrica adecuada al problema de aplicación seleccionado como por ejemplo RECM o MAD).  La premisa es que CUR Descomposition al ser las matrices C y R ralas si la matriz original M es rala, debe ser más rápido que SVD pero desconocemos si esto tiene un trade-off  con la calidad de los resultados obtenidos.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 3](equipos/equipo_3)

Ttulo del proyecto: `Benchmark de Distintos Servicios en la Nube`

Objetivo del proyecto: Comparar los Servicios en la nube más conocidos y definir cuál tiene mejor performance sobre un algoritmo de mínimos cuadrados.

Construiremos un algoritmo básico de Mínimos Cuadrados para solucionar problemas de regresión lineal en los lenguajes de programación Python y R los cuales estará contenidos en una imagen de docker y esta será desplegada en instancias de Amazon Web Services (AWS) y Google Cloud Platform (GCP). Se buscará comparar las ventajas y desventajas, tales como performance y facilidad de usar las herramienta, entendiendo la arquitectura que corre debajo de ellas para finalmente hacer una recomendación de uso.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 4](equipos/equipo_4)

Ttulo del proyecto: `Aplicación del algoritmo de Optimización de Enjambre de Partículas en la inversión de datos geofísicos gravimétricos`

Objetivo del proyecto: Implementar el algoritmo de Optimización de Enjambre de Partículas para la inversión de la anomalía gravimétrica de tres cilindros en subsuelo.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 5](equipos/equipo_5)

Ttulo del proyecto: `Solución al Problema del Agente Viajero mediante el método de Simulated Annealing.`

Objetivo del proyecto: Solución Óptima al Problema del Agente Viajero de planificación de rutas utilizando el método de optimización gradient free de Simulated Annealing. Este método está inspirado en principios de física utilizados para procedimientos como el endurecimiento del acero. Se evaluará hacer una comparación de soluciones con un método especializado de optimización para este problema de ruteo, el algoritmo Dijkstra.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 6](equipos/equipo_6)

Ttulo del proyecto: ``

Objetivo del proyecto: El proyecto tiene como objetivo encontrar la cartera óptima de inversión de una serie de activos financieros. Aplicando la teoría de moderna de optimización de portafolios, en específico el modelo de Markowitz en conjunto con el Capital Asset Pricing Model (CAPM). El modelo de Markowitz busca encontrar la cartera eficientes en términos de rentabilidad y riesgo. El model CAPM permite identificar el portafolio que tenga la mayor rentabilidad por riesgo asumido.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 7](equipos/equipo_7)

Ttulo del proyecto: `Estudio del problema de optimización en redes: minimización de costos de flujo en una red aplicado a la industria eléctrica`

Objetivo del proyecto: Estudiar el problema de minimización de costos de flujo en una red, analizando el marco conceptual en el cual está definido. Asimismo, describir algunos de los algoritmos teóricos desarrollados para resolver este problema, y sus implementaciones en el lenguaje de programación de Python, además de explorar distintas paqueterías disponibles en el mercado, con el fin de analizar su funcionalidad, eficiencia, así como sus ventajas y desventajas. Todo lo anterior aplicándolo a algún problema práctico de la vida real, como lo es el de la red de la industria eléctrica nacional.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 8](equipos/equipo_8)

Ttulo del proyecto: `Método de Crank-Nicolson para valuación de opciones`

Objetivo del proyecto: Usaremos el método de Black-Scholes para hacer el planteamiento de las ecuaciones de derivadas parciales en el cálculo de valuación de opciones. Como estas ecuaciones no siempre tienen solución exacta, se utilizará el método de Crank-Nicolson y el método de Líneas para aproximar su valor. Una vez planteado el sistema de ecuaciones, buscaremos resolverlo con factorización LU con pivoteo parcial y el algoritmo de Thomas para encontrar la combinación de métodos más adecuada.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 9](equipos/equipo_9)

Ttulo del proyecto: `Implementación del Método de Longstaff & Schwartz para valuación de opciones americanas`

Objetivo del proyecto:     

0. Describir algunas generalidades de opciones put y call, los tipos de contratos que hay de este tipo de instrumentos. El framework general de Black & Scholes y la fórmula cerrada para opciones Europeas.

1. Dado un histórico de los precios de una acción, se estiman los parámetros de drift y difusión para implementar el esquema se simulación Monte-Carlo.

2. Se hacen 100,000 (esto puede cambiar o se puede modular) simulaciones, i.e. se obtienen 100,000 trayectorias del proceso de precios de activo subyacente al derivado.

3. Para cada fecha, sobre todas las simulaciones, se estima el valor de continuación vía regresión polinomial, basándose en polinomio de Laguerre, Hermite, Legendre, Chebyshev o Jacobi. Es decir, se resuelven 100,000 -1 problemas de optimización para estimar los valores de continuación, i.e. se resuelven 100,000-1 problemas con ayuda de descomposiciones SVD. En cada regresión se van eliminando las trayectorias en las que no es óptimo continuar con el contrato, es decir, las matrices de diseño van disminuyendo de dimensión.

4. Una vez que se estiman los valores de continuación, se construye una estrategia de ejercicio y se procede a valuar la opción al promediar el valor presente de los payoffs que determinó la estrategia de ejercicio.

5. Se puede paralelizar algunas etapas tanto de la simulación de trayectorias, resolución del problema de optimización y construcción de la estrategia de ejercicio.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 10](equipos/equipo_10)

Ttulo del proyecto: `Uso del modelo de Black-Scholes para estimación de valor en opciones`

Objetivo del proyecto: El método de descomposición de Adomian, permite encontrar una solución “semi” analítica para una ecuación diferencial (ordinaria o parcial). La idea básica es descomponer la ecuación en parte lineal y no lineal, dentro de la misma detectar los distintos operadores involucrados e invertir el de mayor orden; descomponer la parte no lineal en polinomios (mejor conocidos los polinomios de Adomian)

Se busca aplicar este método a un modelo de Black-Scholes, creando una especie de “intefaz” o proceso automático que mediante API’s genere los datos necesarios para predecir los valores de las opciones en el futuro.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 11](equipos/equipo_11)

Ttulo del proyecto: `Componentes principales para la compresión y representación de audio`

Objetivo del proyecto: El uso de componentes principales para la compresión de audio no suele ser utilizado frecuentemente dado que requiere la implementación del algoritmo y requiere mucho espacio.  Lo anterior implica que el uso de PCA requiere sacrificar la calidad de la reconstrucción del audio para poder ser utilizado.  En segundo lugar, está el problema de la transmisión de audio.  PCA se basa en dos componentes: el flujo de datos y una matriz utilizada para reconstruir la señal original. Si bien es fácil transmitir los datos, no puede transmitir esa matriz. E incluso si divide el flujo en pequeños bloques para darle una pequeña matriz, debe garantizar que la matriz llegue; Si no tiene esa matriz, el flujo de datos no tendrá ningún sentido.

El problema de PCA para la representación de audio puede abordarse desde dos ejes: 1.- la representación del audio en el tiempo, y 2) la representación del audio en términos de frecuencia.

Considerando que este problema implica utilizar la transformada de Fourier, la cuál se torna en un problema de integración, nuestro proyecto busca optimizar el algoritmo PCA para la compresión y transmisión de audio siguiendo los ejes mencionados para realizar una comparación de tiempo, costo computacional y calidad de los resultados.


[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 12](equipos/equipo_12)

Ttulo del proyecto: `Trade War y la Relevancia de los Estados Unidos analizados a través del Precio de Opciones Financieras empleando Algoritmos de Optimización`

Objetivo del proyecto: El proyecto trata de examinar algunos modelos clave para determinar los precios de opciones financieras de tipo europeo y modelos de optimización que son empleados en estos para poder estimar los parámetros necesarios en cada modelo y lograr un óptimo funcionamiento.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 13](equipos/equipo_13)

Ttulo del proyecto: `Sistema de recomendación de Netflix.`

Objetivo del proyecto: Implementación del método de mínimos cuadrados alternados con regularización para un sistema de recomendación de Netflix.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 14](equipos/equipo_14)

Ttulo del proyecto: `Solución del Modelo de Markowitz utilizando programación cuadrática`

Objetivo del proyecto: El proyecto consiste en la implementación de la solución de selección de portafolios utilizando el modelo de Markowitz. 
El modelo de Markowitz toma la media como recompensa y la varianza como riesgo. Se utilizan datos de acciones históricas para calcular la media y la varianza, y el objetivo es maximizar rentabilidad minimizando varianza y maximizando la recompensa.  Se asume que las acciones son variables aleatorias. El problema se formula de la siguiente manera:
Dado un conjunto de activos financieros, encontrar el peso óptimo de cada activo, tal que la cartera general ofrece el menor riesgo para un rendimiento global dado.
Esto conduce a un problema de programación cuadrática (optimización) y lo resolveremos con métodos numéricos aprendidos en clase como la utilización de rutinas de BLAS y Python.

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 15](equipos/equipo_15)

Ttulo del proyecto: `Optimización de recursos, una aplicación informática.`

Objetivo del proyecto: Descripción: Se desea encontrar la forma óptima de asignar recursos en la computadora para realizar una cierta cantidad de tareas en el mínimo tiempo posible. Tenemos un sistema donde la tarea llega para ser ejecutada en el intervalo de tiempo t, esto lo denotaremos como aj. Denotaremos como cj el tiempo de finalización de la tarea. El tiempo utilizado para ejecutar el flujo de la tarea j es la diferencia entre el tiempo de finalización y el tiempo de llegada, es decir, cj-aj . Buscamos minimizar: sum (cj-aj) for j=1 to N

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]



---

## [Equipo ejemplo](equipos/equipo_ejemplo)

Ttulo del proyecto: `Ejemplo`

Objetivo del proyecto: objetivo

[Avances del proyecto](equipos/equipo_ejemplo):

* [avance_1](equipos/equipo_ejemplo/avance_1)

* [avance_2](equipos/equipo_ejemplo/avance_2)

[Trabajo escrito](liga hacia trabajo escrito)

[Presentacion](liga hacia presentacion)

[Implementacion](liga hacia implementacion)
