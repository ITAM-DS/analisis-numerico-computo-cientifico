# Equipo 2

Integrantes: 
* Mónica Ballesteros 
* Ariana López 
* Fabiola Cerón

**Título del proyecto:** `Paralelización de mínimos cuadrados con OpenMP` 


**Objetivos del proyecto:** Investigar y evaluar el algoritmo de factorización QR así como su implementación en OpenMP para la solución de mínimos cuadrados.

**Programa de trabajo:**
<table>
<colgroup>
<col width="5%" />
<col width="11%" />
<col width="83%" />
</colgroup>
<thead>
<tr class="header">
<th align="center">No.</th>
<th align="center">Fecha</th>
<th align="left">Actividad</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="center">1</td>
<td align="center">17-04-17</td>
<td align="left">Entender Reflexiones de Householder y Rotaciones Givens.</td>
</tr>
<tr class="even">
<td align="center">2</td>
<td align="center">24-04-17</td>
<td align="left">Entender las características y propiedades RH y RG.</td>
</tr>
<tr class="odd">
<td align="center">3</td>
<td align="center">02-05-17</td>
<td align="left">Entender aplicación de transformaciones para cálculo de QR secuencial. Inicio de programación de QR.</td>
</tr>
<tr class="even">
<td align="center">4</td>
<td align="center">08-05-17</td>
<td align="left">Entender aplicación de QR a mínimos cuadrados. Código QR terminado e inicio de código MC.</td>
</tr>
<tr class="odd">
<td align="center">5</td>
<td align="center">15-05-17</td>
<td align="left">Investigación sobre implementación de QR en OpenMP e inicio de programación. Empezar a redactar documento escrito.</td>
</tr>
<tr class="even">
<td align="center">6</td>
<td align="center">22-05-17</td>
<td align="left">Códigos de implementación de QR en OpenMP y MC terminados. Documento escrito terminado sin capítulo de complejidad y conclusiones.</td>
</tr>
<tr class="odd">
<td align="center">7</td>
<td align="center">29-05-17</td>
<td align="left">Complejidad de algoritmo QR y conclusiones.</td>
</tr>
<tr class="even">
<td align="center">8</td>
<td align="center">Por determinar</td>
<td align="left">Entrega de repo final y presentación.</td>
</tr>
</tbody>
</table>

En la carpeta [avance_07_04_2017](avance_07_04_2017) se encuentra el primer avance del proyecto que incluye la investigación de factorización LU y QR así como su aplicación en la solución de mínimos cuadrados. Erick nos sugirió leer el libro de Matrix Computation de Golub. 

Determinamos cambiar el alcance del proyecto debido a que Erick nos sugiere enfocarnos en factorización QR.  Empezamos a revisar as referencias de acuerdo al plan de trabajo establecido.  En la carpeta [avance_17_04_2017](avance_17_04_2017) se encuentra el reporte de este primer avance sobre la teoría de Reflexiones de Householder y Rotaciones Givens.

[Trabajo escrito](https://drive.google.com/drive/folders/0B5IJ1w6MjxegNUM2d29lTWdIREU?usp=sharing)

[Presentacion](https://drive.google.com/drive/folders/0B5IJ1w6MjxegRHgwS090WFNLdWM?usp=sharing)

[Implementacion](https://drive.google.com/drive/folders/0B5IJ1w6MjxegcWhTdXFvZnljeHc?usp=sharing)

## Referencias:

* [Reflexiones Householder, rotaciones Givens, mínimos cuadrados en secciones 5.4 a 5.7 del libro: Carl D. Meyer. Matrix analysis and applied linear Algebra.](https://drive.google.com/file/d/0BxMtevFKwTW_ZmpwcDd1M0RTVzA/view?usp=sharing) 

* Teoría sobre QR: secciones 5.1.1 a 5.1.4, 5.1.6 a 5.1.8, 5.1.9, 5.1.11, 5.2 excepto 5.2.6 a 5.2.10 del libro: [G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.]

* Aplicación de QR para resolver mínimos cuadrados: capítulo 5 del libro: L. Eldén, Matrix Methods in Data Mining and Pattern recognition. SIAM, 2007.

* Factorización QR en paralelo:

	+ M. Costnard, J.M. Muller, Y. Robert. Parallel QR Decomposition of a Rectangular Matrix. 1986

	+ F. T. Luk. A Rotation Method for Computing the QR Factorization 1986.

	+ [A. Buttari, J. Langou, J. Kurzak, J. Dongarra. A Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures. 2009](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf)

	+ [D. P. O'Leary, P. Whitman. Parallel QR factorization by Householder and modified Gram-Schmidt algorithms. 1990](https://www.researchgate.net/publication/222459558_Parallel_QR_factorization_by_Householder_and_modified_Gram-Schmidt_algorithms)


