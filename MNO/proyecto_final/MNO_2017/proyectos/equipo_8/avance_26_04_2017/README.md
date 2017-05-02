Individual: Walter Martínez Santana

En esta ocasión, analicé el algoritmo de factorización de Choleskyen dos propuestas diferentes: una que está en el libro de Douglas Faires y Burden, y el otro en el Fischer. 
La diferencia es que uno propone un algoritmo compacto en la forma de la redacción, pero computacionalmente y al programarlo, más amplio. En este caso es evidente la depedencia
entre variables al momento del cálculo. El otro algoritmo, presenta una mayor uniformidad algorítmica, separando de mejor manera (según mi manera de verlo) las dependencias y
logrando con ello abrir un escenario donde posiblemente se puedan manejar las dependencias de manera que puedan implementarse de manera paralela.
Además, la el segundo algoritmo reutiliza la matriz a la que se está factorizando ganado optimización en la memoria, en los accesos a la misma.
Por esta razón,opté por hacer un análisis más profundo de este algoritmo teniendo en mente romper las dependencias y generar una propuesta de un algoritmo paralelo para
resolverlo. 
En otro orden de ideas, estuve investigando acerca de la arquitectura CUDA con el fin de encontrar opciones para poder manejar ciertas dependencias. Existe algunos "peros", 
por ejemplo, existe una rutina de sincronización que solo se manjea dentro delos threads de un bloque específico y no aplica en toda la malla, lo cual agrega un factor más de complejidad
para implementar un algoritmo de factorización Cholesky en una arquitectura CUDA. Otro factor es que el número de threads de la malla solo puede ser  de manera rectagunlar, mxn.
La próxima fase es analizar una implementación del algoritmo de factorización de Cholesky mediante bloquesesperando encontrarpatrones menos dependientes entre las variables.
