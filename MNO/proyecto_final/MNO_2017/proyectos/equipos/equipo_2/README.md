# Equipo 2

Integrantes: 
* Mónica Ballesteros 
* Ariana López 
* Fabiola Cerón

**Título del proyecto:** `Solución de Mínimos Cuadrados con Factorización QR vía transformaciones Househoulder` 


**Objetivos del proyecto:** Investigar e implementar el algoritmo de factorización QR utilizando reflexiones de Householder así como su aplicación para la solución de mínimos cuadrados.

**Programa de trabajo:**

| No. 	| Fecha      	| Actividad                                                                                                                                                                                  	|
|:-----:	|------------	|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| 1   	| 17/04/2017 	| Entender Reflexiones de Householder, sus características y propiedades.                                                                                                                            	|
| 2   	| 24/04/2017 	| Entender aplicación del método de Reflexiones de Householder para cálculo QR secuencial. *Inicio de programación secuencial de QR*.                                                                  	|
| 3   	| 02/05/2017 	| Entender aplicación de QR a mínimos cuadrados (MC). *Código secuencial de QR terminado e inicio de código MC*.                                                                                       	|
| 4   	| 08/05/2017 	| Investigación sobre implementación de QR en OpenMP e inicio de programación. *Código secuencial de MC terminado*. **Iniciar programación en paralelo de OpenMP**.  Empezar a redactar documento escrito. 	|
| 5   	| 15/05/2017 	| **Ajuste del alcance del proyecto**. Derivado de la revisón de avance con Erick, se determinó modifcar el alcance del proyecto.                                                            	|
| 6   	| 22/05/2017 	| Código QR secuencial terminado e inicio de MC.                                                                                                                            	|
| 7   	| 30/05/2017	| Documento escrito terminado. Entrega de repo final y presentación.                                                                                                                  	|

**Avances del Proyecto:**

* En la carpeta [avance_07_04_2017](avance_07_04_2017) se encuentra el primer avance del proyecto que incluye la investigación de factorización LU y QR así como su aplicación en la solución de mínimos cuadrados. Erick nos sugirió leer el libro de Matrix Computation de Golub. 

* Determinamos cambiar el alcance del proyecto debido a que Erick nos sugiere enfocarnos en factorización QR, y en particular estudiaremos el método de Reflexiones de Householder. Empezamos a revisar las referencias de acuerdo al plan de trabajo establecido.  En la carpeta [avance_17_04_2017](avance_17_04_2017) se encuentra el reporte de este primer avance sobre la teoría de Reflexiones de Householder.

* Una vez entendidas las características y propiedades de las reflexiones de Householder, en esta semana estudiamos su aplicación para el cálculo de QR secuencial.  Además, iniciamos con la programación de las funciones principales que requiere el algoritmo que calcula el vector de Householder.  Lo anterior se encuentra en la carpeta [avance_26_04_2017](avance_26_04_2017).

* En la carpeta [avance_02_05_2017](avance_02_05_2017) se encuentra el código de la implementación del vector de Householder y del algoritmo QR.  El código muestra impresiones de cada cálculo en cada paso para ayudarnos a entender y verificar el cómputo tanto de los factores importantes como mu, sigma y la parte escencial del vector v.  En esa misma carpeta se encuentra también el reporte de avance en la teoría, ahora de mínimos cuadrados.

* Esta semana leímos sobre la implementación de QR en OpenMP.  Investigamos las principales funciones de LAPACK que pueden ser utilizadas.  Repasamos la teoría sobre memoria compartida.  El detalle de todo lo anterior se encuentra en [avance_08_05_2017](avance_08_05_2017).

* En la carpeta [avance_15_05_2017](avance_15_05_2017), se describe la modificación del alcance del proyecto, adicionalmente se reorganizó el calendario de trabajo.

* En la carpeta [avance_22_05_2017](avance_22_05_2017) se reporta el avance de esta semana, donde se concluyó la implementación del algoritmo secuencial de factorización QR usando Reflexiones de Householder, además se inició la programación de mínimos cuadrados, mismos que se encuentran en la siguiente carpeta: [Implementacion](codigo). De forma paralela se está desarrollando el trabajo escrito y se ha definido su estructura general, el cual se puede consultar en la liga correspondiente.

* Se presenta en la carpeta [avance_29_05_2017](avance_29_05_2017) el avance final del proyecto.  En la carpeta [Trabajo escrito](trabajo_escrito) se encuentra el documento final del proyecto y en la carpeta [Implementacion](codigo) los archivos en C de la implementación.  Finalmente se anexa la [Presentacion](https://drive.google.com/file/d/0B5IJ1w6MjxegSlhFc2xPOW9fRE0/view?usp=sharing).

[Trabajo escrito](trabajo_escrito)

[Presentacion](https://drive.google.com/file/d/0B5IJ1w6MjxegSlhFc2xPOW9fRE0/view?usp=sharing)

[Implementacion](codigo)

## Referencias:

* Reflexiones Householder, rotaciones Givens, mínimos cuadrados en secciones 5.4 a 5.7 del libro: [Carl D. Meyer. Matrix analysis and applied linear Algebra.](https://drive.google.com/file/d/0BxMtevFKwTW_ZmpwcDd1M0RTVzA/view?usp=sharing) 

* Teoría sobre QR: secciones 5.1.1 a 5.1.4, 5.1.6 a 5.1.8, 5.1.9, 5.1.11, 5.2 excepto 5.2.6 a 5.2.10 del libro: [G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view?usp=sharing)

* Aplicación de QR para resolver mínimos cuadrados: capítulo 5 del libro: L. Eldén, Matrix Methods in Data Mining and Pattern recognition. SIAM, 2007.

* Factorización QR en paralelo:

	+ M. Costnard, J.M. Muller, Y. Robert. Parallel QR Decomposition of a Rectangular Matrix. 1986

	+ F. T. Luk. A Rotation Method for Computing the QR Factorization 1986.

	+ [A. Buttari, J. Langou, J. Kurzak, J. Dongarra. A Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures. 2009](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf)

	+ [D. P. O'Leary, P. Whitman. Parallel QR factorization by Householder and modified Gram-Schmidt algorithms. 1990](https://www.researchgate.net/publication/222459558_Parallel_QR_factorization_by_Householder_and_modified_Gram-Schmidt_algorithms)

	+[A. Buttari, J. Langeou, J. Kurzak, J. Dongarra. Parallel tiled QR factorization for multicore architectures 2008](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view?usp=sharing)


