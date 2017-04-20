# Equipo 2

Integrantes: 
* Mónica Ballesteros 
* Ariana López 
* Fabiola Cerón

**Título del proyecto:** `Paralelización de mínimos cuadrados con OpenMP` 


**Objetivos del proyecto:** Investigar y evaluar el algoritmo de factorización QR así como su implementación en OpenMP para la solución de mínimos cuadrados.

**Programa de trabajo:**

| No. 	| Fecha      	| Actividad                                                                                                                                                                                  	|
|:-----:	|------------	|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| 1   	| 17/04/2017 	| Entender Reflexiones de Householder, sus características y propiedades.                                                                                                                            	|
| 2   	| 24/04/2017 	| Entender aplicación del método de Reflexiones de Householder para cálculo QR secuencial. *Inicio de programación secuencial de QR*.                                                                  	|
| 3   	| 02/05/2017 	| Entender aplicación de QR a mínimos cuadrados (MC). Código secuencial de QR terminado e inicio de código MC.                                                                                       	|
| 4   	| 08/05/2017 	| Investigación sobre implementación de QR en OpenMP e inicio de programación. Código secuencial de MC terminado. Iniciar programación en paralelo de OpenMP.  Empezar a redactar documento escrito. 	|
| 5   	| 15/05/2017 	| Códigos de implementación de QR en OpenMP y MC terminados. Dependiendo del avance se evaluará la aplicación a un problema de regresión.                                                            	|
| 6   	| 22/05/2017 	| Documento escrito terminado sin capítulo de complejidad y conclusiones.                                                                                                                            	|
| 7   	| 29/05/2017 	| Complejidad de algoritmo QR y conclusiones. Entrega de repo final y presentación.                                                                                                                  	|

**Avances del Proyecto:**

* En la carpeta [avance_07_04_2017](avance_07_04_2017) se encuentra el primer avance del proyecto que incluye la investigación de factorización LU y QR así como su aplicación en la solución de mínimos cuadrados. Erick nos sugirió leer el libro de Matrix Computation de Golub. 

* Determinamos cambiar el alcance del proyecto debido a que Erick nos sugiere enfocarnos en factorización QR, y en particular estudiaremos el método de Reflexiones de Householder. Empezamos a revisar las referencias de acuerdo al plan de trabajo establecido.  En la carpeta [avance_17_04_2017](avance_17_04_2017) se encuentra el reporte de este primer avance sobre la teoría de Reflexiones de Householder.

[Trabajo escrito](https://drive.google.com/drive/folders/0B5IJ1w6MjxegNUM2d29lTWdIREU?usp=sharing)

[Presentacion](https://drive.google.com/drive/folders/0B5IJ1w6MjxegRHgwS090WFNLdWM?usp=sharing)

[Implementacion](https://drive.google.com/drive/folders/0B5IJ1w6MjxegcWhTdXFvZnljeHc?usp=sharing)

## Referencias:

* [Reflexiones Householder, rotaciones Givens, mínimos cuadrados en secciones 5.4 a 5.7 del libro: Carl D. Meyer. Matrix analysis and applied linear Algebra.](https://drive.google.com/file/d/0BxMtevFKwTW_ZmpwcDd1M0RTVzA/view?usp=sharing) 

* Teoría sobre QR: secciones 5.1.1 a 5.1.4, 5.1.6 a 5.1.8, 5.1.9, 5.1.11, 5.2 excepto 5.2.6 a 5.2.10 del libro: [G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing)

* Aplicación de QR para resolver mínimos cuadrados: capítulo 5 del libro: L. Eldén, Matrix Methods in Data Mining and Pattern recognition. SIAM, 2007.

* Factorización QR en paralelo:

	+ M. Costnard, J.M. Muller, Y. Robert. Parallel QR Decomposition of a Rectangular Matrix. 1986

	+ F. T. Luk. A Rotation Method for Computing the QR Factorization 1986.

	+ [A. Buttari, J. Langou, J. Kurzak, J. Dongarra. A Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures. 2009](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf)

	+ [D. P. O'Leary, P. Whitman. Parallel QR factorization by Householder and modified Gram-Schmidt algorithms. 1990](https://www.researchgate.net/publication/222459558_Parallel_QR_factorization_by_Householder_and_modified_Gram-Schmidt_algorithms)


