## Equipo 9

Integrantes:

* Jorge III Altamirano Astorga - CU: 175904

* Eduardo Selim Martinez Mayorga - CU: 175921

* Ariel Ernesto Vallarino Maritorena - CU: 175875

Título del proyecto: `Implementación del Método de Longstaff & Schwartz para valuación de opciones americanas`

Objetivos del proyecto: 

* Describir algunas generalidades de opciones put y call, los tipos de contratos que hay de este tipo de instrumentos. El framework general de Black & Scholes y la fórmula cerrada para opciones Europeas.

* Dado un histórico de los precios de una acción, se estiman los parámetros de drift y difusión para implementar el esquema se simulación Monte-Carlo.

* Se hacen 100,000 (esto puede cambiar o se puede modular) simulaciones, i.e. se obtienen 100,000 trayectorias del proceso de precios de activo subyacente al derivado.

* Para cada fecha, sobre todas las simulaciones, se estima el valor de continuación vía regresión polinomial, basándose en polinomio de Laguerre, Hermite, Legendre, Chebyshev o Jacobi. Es decir, se resuelven 100,000 -1 problemas de optimización para estimar los valores de continuación, i.e. se resuelven 100,000-1 problemas con ayuda de descomposiciones SVD. En cada regresión se van eliminando las trayectorias en las que no es óptimo continuar con el contrato, es decir, las matrices de diseño van disminuyendo de dimensión.

* Una vez que se estiman los valores de continuación, se construye una estrategia de ejercicio y se procede a valuar la opción al promediar el valor presente de los payoffs que determinó la estrategia de ejercicio.

* Se puede paralelizar algunas etapas tanto de la simulación de trayectorias, resolución del problema de optimización y construcción de la estrategia de ejercicio.

### Entregables

* Trabajo escrito (fuera del repo): [liga_trabajo_escrito](https://www.dropbox.com/s/8q1sqav4omftimo/proyecto-final.pdf?dl=0)

* Presentación (fuera del repo): [liga_presentación](https://www.dropbox.com/s/lqb1b5ryh5q33gp/presentacion.pdf?dl=0)

* Implementación (en el repo): [liga_a_código](src) 

### Avances

* En la carpeta [avance_1](avance_1) se encuentra el reporte del primer avance en nuestro proyecto. 

* En la carpeta [avance_2](avance_2) se encuentra el reporte del primer avance en nuestro proyecto. 

* En la carpeta [avance_3](avance_3) se encuentra el reporte del primer avance en nuestro proyecto. 

* En la carpeta [avance_4](avance_4) se encuentra el reporte del primer avance en nuestro proyecto. 

### Referencias 


Los siguientes se encuentran [aquí](https://www.dropbox.com/sh/vsak8w3gols8mjo/AABaZTxvpzWnIwSlOZvfYUcAa?dl=0)

* Longstaff, F. & Schwartz, E. (2001). _Valuing American Options by Simulation: A Simple Least-Squares Approach_. The Review of Financial Studies Spring 2001 Vol. IS. No. I, pp. 113-147 The Society for Financial Studies

* Choudhury A., King A., Kumar S., & Sabharwal, Y. (2008). _Optimizations in Financial Engineering: The Least-Squares Monte Carlo method of Longstaff and Schwartz_


