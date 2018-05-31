---
title: "Singular Value Decomposition on GPU using CUDA"
author: "Thalía Guerra"
date: "30 de mayo de 2018"
output: html_document
---

La Descomposición en Valores Singulares (SVD) es una técnica utilizada para la factorización de matrices rectangulares, reales o complejas. Es una técnica robusta a errores numéricos. Se usa para calcular la pseudo-inversa de una matriz y en aplicaciones relacionadas con análisis de componentes, reconocimiento de patrones, procesamiento de imágenes, etc.

La SVD de una matriz $A$ de tamaño $m x n$ es cualquier factorización de la forma:
$$ A = U \Sigma V^T$$

donde: 

$U$ es una matriz ortogonal de $m x m$

$V$ es una matriz ortogonal de $n x n$

$\Sigma$ es una matriz diagonal de $m x n$ con $s_{ij} = 0$ si $i \neq j$ y $s_{ii} \geq 0$ en orden descendiente en la diagonal.

Las mejoras en el desempeño del hardware gráfico y el desarrollo de nuevos lenguajes de programación hacen que GPU sea un buen candidato para realizar tareas intensivas, especialmente si se paraleliza en datos.

A pesar de que se ha usado GPU en la ciencia de la computación, no se había implementado una solución para SVD en GPU, que los autores implementan usando la paquetería CUBLAS (implementación de BLAS en GPU) de NVIDIA y kernels de CUDA. Los autores encuentran que esta implementación es más rápida que la implementación de SVD de Intel MKL y mucho más rápida que la de MATLAB. Esta implementación en GPU también permite calcular la SVD de matrices muy grandes, tarea imposible en CPU dadas las limitaciones de memoria.

Los autores usan el método Golub-Reinsch para la implementación del cálculo de la SVD. Este método es un algoritmo con acercamiento similar al de Jacobi que se usa en LAPACK. El algoritmo se realiza de la siguiente manera:

1.  $B \leftarrow Q^T AP$ 

Bidiagonalización de $A$ a $B$. A es una matriz que se puede descomponer como $A = QBP^T$ donde $B$ es una matriz bidiagonal y $Q$ y $P$ son matrices unitarias. La bidiagonalización es un proceso computacionalmente caro que involucra muchas lecturas y escrituras en memoria y multiplicaciones de matrices y de vectores por matrices. Para hacer la bidiagonalización en GPU se debe de transferir la matriz $A$ de CPU a GPU y las operaciones se realizan en los datos que están en GPU usando CUBLAS. Una vez que se termina la bidiagonalización de $A$ se transfieren los elementos de la diagonal y de la superdiagonal al CPU, mientras que las matrices $Q$ y $P^T$ se mantienen en el GPU.
 
2.  $\Sigma \leftarrow X^T BY$ 

Diagonalizacióń de $B$ a $\Sigma$. La matriz $B$ se puede descomponer como $\Sigma = X^T BY$, y se puede reducir a una matriz diagonal aplicando el algoritmo QR. Una vez que el algoritmo converge a la descomposición anterior, la matriz diagonal ($\Sigma$) contiene los valores singulares de $B$ y $X$ y $Y^T$ tienen los vectores singulares de $B$. Con los elementos de la diagonal y la superdiagonal se calculan los vectores de coeficientes en el CPU. El cálculo de las filas de $Y^T$ y de las columnas de $X$ requiere, respectivamente, información de la fila y de la columna anterior, por lo que no se puede paralelizar. Sin embargo, los autores utilizan GPU para procesar los elementos de cada fila en paralelo. Esto implica una gran mejora para matrices muy grandes y mejoras para matrices medianas. La transformación de las matrices $Y^T$ y $X$ también se hace en paralelo en GPU. Posteriormente se copian los vectores de coeficientes a la memoria haciendo iteraciones utilizando la memoria compartida.

3. $U \leftarrow QX$ y $V^T \leftarrow (PY)^T$

Calcular las smatrices ortogonales $U$ y $V^T$ y la SVD de $A = U \Sigma V^T$ usando rutinas de multiplicación de matrices de CUBLAS.

Posteriormente los autores evaluan el desempeño de su algoritmo, comparándolo con la implementación en CPU en MATLAB y en Intel MKL 10.04 LAPACK, con threading dinámico. El algoritmo de los autores se probó en una máquina con Intel Dual Core 2.66 GHx, un procesador gráfico NVIDIA GeForce 8800 GTX, un procesador NVIDIA GTX 280 y NVIDIA Tesla S1070.

Para la evaluación del desempeño se generaron 10 matrices densas de manera aleatoria para cada uno de los tamaños definidos, se corrió el algoritmo 10 veces para cada una de las matrices y se obtuvo el promedio para cada uno de los tamaños de las matrices.

Se obtuvo un speedup de 3.06 a 8.2 sobre la implementación en Intel MKL y de 3.32 a 59.3 sobre la implementación en MATLAB. Sin embargo, para matrices pequeñas la implementación en CPU es mejor que la implementación en GPU. Para matrices cuadradas grandes, el speedup aumenta mientras aumenta el tamaño de la matriz.

Adicionalmente, esta implementación en GPU permite calcular la SVD para matrices muy grandes (14x14 o 16x16), cuyo cómputo no es posible en CPU por limitaciones de memoria.

Los autores encuentran también que las diferencias entre los resultados de la SVD implementada en CPU y en GPU (generadas porque GPU tiene un soporte de doble precisión muy limitado) son mínimas, siendo la más alta de 0.013%.
  
