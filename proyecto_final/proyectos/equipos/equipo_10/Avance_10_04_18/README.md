## Avance_10_04_2017



### Integrantes:


* Rodrigo Cedeño (176576)
* Abraham Nieto (51556)
* Roberto Acevedo (89750)


#### Individual

**Abraham:** 

`Se reviso el paper` [referencia](https://pdfs.semanticscholar.org/62c1/1a6f10ed2dd1c954297733e92641e7cd6fb9.pdf) `donde habla de hacer la descomposición SVD en GPUs a tráves de CUDA, en orden de importancia el punto número 3 habla del desarrollo del algoritmo SVD usando el método de  Golub-Reinsch que consiste en 2 pasos: 1.-reducir la matriz original a una matriz bidiagonal y 2.- diagonalizar la matriz encontrada en el paso 1. siguiendo estos pasos podemos construir las matrices U,V,S que cumplan` [$A=U*S*V^T$]
`En el punto 3.1.2 se explica la bidiagonalización en el GPU, donde se meciona que cada paso del algoritmo de bidiagonalización se puede realizar con funciones de CUDA BLAS(CUBLAS) se recomienda ajustar las dimensiones de las matrices a múltiplos de 32. en el punto 3.2.2 se presenta una explicación de la forma de hacer la paralelización  del paso 2 del algoritmo de Golub-Reinsch (diagonalización), al final la idea es implementar SVD en GPU's para aprovechar el paralelismo, pero lo relevante es que para el paso de diagonalización se divide el computo entre GPU y CPU para mejorar el desempeño de este.`    


**Rodrigo:**

`Investigué sobre la implementación de SVD en sistemas de recomendación. Encontré que esta aplicación aunque puede ser lenta en cuanto a tiempo de procesamiento (en comparación con otros métodos basados en memoria), es un método que funciona muy bien, ya que las recomendaciones que hace son muy buenas.`

`Una de las grandes ventajas de la utlización de SVD para sistemas de recomendación es que ayudan a solucionar el problema de los sistemas de recomendación tradicionales donde hay una escasez de datos en matrices dispersas (provocado por la falta de calificaciones en este tipo de sistemas). El SVD ayuda en gran medida a reducir la dimensionalidad del espacio generando recomendaciones con ese espacio reducido, lo cual es súmamente útil para este tipo de sistemas, ya que normalmente se trabaja con bases de datos muy grandes.`

`Lo que se busca hacer básicamente con SVD aplicado a los sistemas de recomendación es utilizar la matriz de votos (la cual contiene las calificaciones de los distintos usuarios) y de ahí extraer los factores que hagan característico a cada usuario y los ítems que son calificados. Como se recomienda en el artículo` ["SVD APLICADO A SISTEMAS DE RECOMENDACIÓN BASADOS EN FILTRADO COLABORATIVO"](http://informatico.ricardomoya.es/docs/ProyectoFinDeMaster_V1.pdf) `de Ricardo Moya García, esto es posible si descomponemos la matriz "S" en dos matrices iguales y multiplicamos cada una de ellas a U y V, obtendremos dos matrices con los factores característicos de los usuarios e items con lo que se obtienen factores latentes que caracterizan a cada usuario e item.`

`El resultado final de la obtención de estos factores es poder encontrar una relación entre item y usuario y poder calcular las distancias que existe entre cada uno para así aplicar alguna métrica de similutd para el filtrado colaborativo. Esto nos ayudará en gran medida a entender correctamente el proceso que se debe realizar para poder aplicar la descomposición SVD a sistemas de recomendación y con esto construir el algoritmo necesario para la paralelización del proceso.`

Fuentes:
<https://medium.com/@m_n_malaeb/singular-value-decomposition-svd-in-recommender-systems-for-non-math-statistics-programming-4a622de653e9>
<http://nicolas-hug.com/blog/matrix_facto_3>
<https://hackernoon.com/introduction-to-recommender-system-part-1-collaborative-filtering-singular-value-decomposition-44c9659c5e75>

<https://www.inf.utfsm.cl/~mmendoza/memorias/Nicolas_Torres.pdf>
<http://informatico.ricardomoya.es/docs/ProyectoFinDeMaster_V1.pdf>
`



**Roberto:**

`Se revisó la referencia sugerida por Abraham y se comprendió el algoritmo **_Golub-Reinsch_**. Partes importantes del algoritmo son los pasos de *bidiagonalización* y *diagonalización* que se sugieren implementar en la *GPU* y *CPU* respectivamente. El artículo hace referencia a que se utilizaron funciones de CUDA BLAS (CUBLAS) en la codificación del algoritmo, por lo que se profundizó en la búsqueda de las funciones y se encontró la librería **_cuSOLVER_** en la siguiente` [referencia](http://docs.nvidia.com/cuda/cusolver/index.html)
`A grandes rasgos la librería cuSOLVER es un paquete de tres librerías que realizan operaciones complejas de algebra lineal. Las librerias son las siguientes:`
`A. cuSolverDN: Dense LAPACK. Entre algunas de sus funciones provee rutinas para bidiagonalización de matrices e incluso para SVD.` 
`B. cuSolverSP: Sparse LAPACK. Entre algunas de sus funciones provee rutinas para factorización QR y solución de eigenvalores.`
`C. cuSolverRF: Refactorization. Entre algunas de sus funciones provee rutinas para factorización y refactorización LU.`
``Nota: se esta revisando la documentación y código de las librerías para evaluar el uso y forma de implementación, evaluar el resultado de las transformaciones para determinar en que parte del modelo se encaja SVD ``

`Adicionalmente se buscaron otras opciones de implementación de SVD utilizando MPI. Se encontraron algunas referencias que indican que dicha implementación puede ser exitosa y eficiente. Las referencias son las siguientes:`
[Parallel Algorithms for the Singular Value Decomposition](https://www.irisa.fr/sage/bernard/publis/SVD-Chapter06.pdf)
[Parallel SVD computation](https://dml.cz/bitstream/handle/10338.dmlcz/702748/PANM_15-2010-1_18.pdf)


#### Equipo

`De acuerdo con lo que se revisó hemos encontrado que existen múltiples formas de abordar el desarrollo del algoritmo en paralelo:` 
`1.-utilizar el método de Golub-Reinsch y ver su viabilidad de desarrollo en CUDA ya sea que existan librerías que lo utilicen o que debamos desarrollarlo desde cero, pero todo esto de forma paralela. Incluso evaluar en CUDA otro métodos como el de Jacobi que viene en las notas del repo y queda pendiente revisarlas completas para el siguiente avance.`
`2.-Del mismo modo que en el punto 1 se pueden hacer las exploraciones pero en mpi o en openmp.`
`Finalmente, cualquiera que sea el lenguaje de implementación, la descomposición SVD será utlizada para alimentar el proceso de filtros colaborativos y posteriormente las recomendaciones.`



