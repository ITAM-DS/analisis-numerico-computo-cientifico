# Lista de proyectos:

---

## [Equipo 1](equipos/equipo_1)

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

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

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 4](equipos/equipo_4)

Ttulo del proyecto: `Aplicación del algoritmo de Optimización de Enjambre de Partículas en la inversión de datos geofísicos gravimétricos`

Objetivo del proyecto: Verificar la implementación correcta del método para el problema anomalía gravimétrica de tres cilindros en subsuelo (qué sobresale del campo gravitatorio).

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 5](equipos/equipo_5)

Ttulo del proyecto: `Recocido simulado y Descenso en gradiente en paralelo para el problema de localizar óptimos globales.`

Objetivo del proyecto: Comparación de métodos que utilizan derivadas (p.ej. descenso en gradiente) vs los que no utilizan derivadas (gradient free) para funciones objetivo shekel, H1, Himmelblau que son utilizadas en física (endurecimiento de acero por ejemplo) hill climbing paralelo vs recocido

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

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 9](equipos/equipo_9)

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 10](equipos/equipo_10)

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]


---

## [Equipo 11](equipos/equipo_11)

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 12](equipos/equipo_12)

Ttulo del proyecto: ``

Objetivo del proyecto: objetivo

[Avances del proyecto]

[Trabajo escrito]

[Presentacion]

[Implementacion]

---

## [Equipo 13](equipos/equipo_13)

Ttulo del proyecto: ``

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
