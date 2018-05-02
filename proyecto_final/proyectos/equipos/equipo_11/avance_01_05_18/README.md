# Avance_07_04_2017

## Integrantes:

* Roberto

* Thalía

* Lorena 

## Trabajo:

### Individual

Lorena: 
Implementación en C del algoritmo de Dijkstra de manera secuencial, se armó la primera parte, las estructura de datos para almacenar el Grafo, las distancias entre el nodo origen y los nodos destino, así como la lista de nodos visitados: [codigo](avance_01_05_18/codigo).

Roberto: Leí la referencia [referencia] (https://www.researchgate.net/profile/Kurt_Mehlhorn/publication/47842024_A_Parallelization_of_Dijkstra%27s_Shortest_Path_Algorithm/links/00b4951cbf96929546000000/A-Parallelization-of-Dijkstras-Shortest-Path-Algorithm.pdf): 
A. Crauser, K. Melhorn, U. Meyer, P. Sanders. (1998) A Parallelization of Dijkstra's Shortest Path Algorithm, que discute la manera de dividir el algoritmo en fases, donde las operaciones de cada fase se pueden ejecutar en paralelo. 

Thalía:

Leí la [referencia](https://ieeexplore.ieee.org/document/6240942/ )Nadira Jasika, Naida Alispahic, Arslanagic Elma, Kurtovic Ilvana, et al. (2012)Dijkstra's shortest path algorithm serial and parallel execution performance analysis, donde se discuten implementaciones del algoritmo tanto en serie como en paralelo, y la parte en paralelo implementada en openmp, también menciona el rendimiento de las distintas implementaciones,  y entra en mucho detalle en esta parte experimental, mencionan el tipo de procesadores ocupados y van comparando los tiempos de ejecución y las mejoras en rendimiento de la parte en paralelo y en serie.  

### Equipo

Se reestructuró la sección del trabajo escrito que hablaba sobre paralelización para quitar los temas redundantes con la clase y entrar ya de lleno en la parte de paralelización del algoritmo de Dijkstra. Se discutieron los artículos que leyeron Roberto y Thalía, Se revisó el escrito y se agregó lo que faltaba de teoría, específicamente terminé  secciones de subestructura óptima del camino más corto y relajación. Se discutió como se hará la implementación en C secuencial de acuerdo a los ejemplos encontrados hasta ahora. 





