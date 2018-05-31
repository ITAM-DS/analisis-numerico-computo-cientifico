### Reporte del artículo "Singular Value Descomposition on GPU using CUDA" de Sheetal Lahabar y P.J. Narayanan.

La lectura comienza dando una breve introducción sobre la utilidad de la descomposición en valores singulares (SVD), resalta que la SVD se utiliza para factorizar matrices triangulares, para encontrar la pseudoinversa de una matriz, para resolver sistemas de ecuaciones lineales y para resolver el problema de mínimos cuadrados. Asimismo, se utiliza en aplicaciones relacionadas con componentes principales, procesamiento de señales, reconocimiento de patrones y procesamiento de imágenes, entre muchas otras aplicaciones.

La SVD de una matriz A de m x n es una factorización de la forma A = U*S*V^t donde U es una matriz ortogonal de m x m, V es una matriz ortogonal de n x n y S es una matriz diagonal de m x n, donde s_{ij}=0 si i!=j y s_{ij}>=0 en orden descendente a lo largo de la diagonal.

Posteriormente comenta un poco sobre el desarrollo de la programción en paralelo con las GPU's, los lenguajes que se han desarrollado para este nuevo paradigma de programación como CUDA en el caso de Nvidia y CTM en el caso de ATI/AMD y destaca que los GPU's proveen un enorme ancho de banda y poder computacional. 

En la segunda sección, detalla numerosas referencias a trabajos relacionados y sus alcances, destacando que se han desarrollado varios algoritmos en las GPU's para cálculos matemáticos, operaciones vectoriales y matriciales. 

Menciona que han habido varios intentos por paralelizar el algorito SVD y a grosso modo señala que el resultado en algunos casos es bueno para matrices grandes pero no eficiente para matrices pequeñas, o en su defecto, el "performance" de algunos algoritmos está limitado por la memoria comparida, por lo que sólo funcionan bien para matrices pequeñas.

En la tercera sección detalla el algoritmo SVD segmentándolo en 2 pasos:

- Bidiagonalización.

- Diagonalización.

En la bidiagonalización, la matriz A se descompone en A = Q*B*P^t aplicando una serie de transformaciones de householder, donde B es la matriz bidiagonal; Q y P son matrices unitarias de housholder.

La bidiagonalización de householder se logra alternando multiplicaciones matriz-vector con actualizaciones de rango uno, tal como lo indica Golub y Kahan en su articulo " Calculating the Singular Values and Pseudo-Inverse of a Matrix", donde las actualizaciones se pueden expresar utilizando operaciones de BLAS nivel 2 y una vez que se elimina la columna-renglon, la matriz asociada se actualiza.

Es importante destacar que el autor indica que este método es computacionalmente caro pues involucar varias lecturas y escrituras en la memoria por el proceso de actualización, por lo que añade que se puede utilizar un approach por bloques utilizando LAPACK, donde se calculan nuevos renglones y columnas del bloque justo antes del proceso de eliminar dentro del bloque (i.e. la matriz A se divide en bloques de tamaño L y la actualización ocurre hasta que L columnas y renglones son bidiagonalizados y se realizan cálculos extras para las columnas y renglones actualizados en el mismo bloque). El valor de L se escoge dependiendo del "performance" de las rutinas de BLAS y como se puede apreciar éste algoritmo requiere espacio de almacenamiento adicional.

El autor incorpora el pseudocódigo del algoritmo de bidiagonalización utilizando el esquema por bloques.

Señala que cada paso del algoritmo se puede ejecutar usando funciones de CUDA BLAS (CUBLAS), indicando que CUBLAS tiene un alto desempeño en las operaciones matriz-vector y matriz-matriz. Asimismo, el esquema por bloques para la bidiagonalización se pude calcular de forma eficiente debido al gran desempeño que tiene en el producto matiz-vector y matriz-matriz, aun cuando una de las dimensiones es pequeña.

Detalla que hay evidencia que sugiere que CUBLAS tiene un mucho mejor desempeño cuando trabaja con matrices que tienen dimensiones que son múltiplos de 32 por temas de alineamiento de memoria, por lo que se incorporaran ceros en los vectores y matrices de tal forma que su dimensión sea mútliplo de 32.

Un punto que destaca y que me parece fundamental es que las transferencias de CPU a GPU deben de ser mínimas. Todas las operaciones que se requieren para la bidiagonalización se hacen en los datos locales en la GPU usando CUBLAS; es decir, que la bidiagonalización se hace en sitio y una vez que A ya ha sido bidiagonalizada en la GPU, sólo la diagonal y la superdiagonal se copian a la CPU para la diagonalización que se detalla a continuación.

La matriz bidiagonal se puede reducir a una matriz diagonal aplicando iterativamente el algoritmo QR. La matriz B que se obtiene en el primer paso se descompone como sigue: S = X^t*B*Y donde S es una matriz diagonal, X y Y son matrices unitarias ortogonales.

El autor detalla el pseudocódigo para el proceso de diagonalización, en el cual en cada iteración se actualizan los elementos de la diagonal y de la superdiagonal de tal manera que los elementos de la superdiagonal son menores que su valor anterior. El algoritmo converge a las d_i's que son los valores singulares y X y Y^t contiene los vectores singulares de B.

El proceso de diagonalización se puede implementar en la GPU, copiando la diagonal y la superdiagonal a la CPU, aplicando las rotaciones de Givens a B y calculando los coeficientes de los vectores.

El autor indica que en el algoritmo hay cálculos que dependen del renglón anterior, lo que dificulta la paralelización; no obstante, los resultados para todos los elementos del renglón puenden calcularse en paralelo, utilizando procesadores de threads de la GPU para procesar los elmentos de cada renglon en paralelo. La transformación de las matrices Y^t y X se realiza en paralelo en el GPU. Un swap kernel se llama para ordenar los vectores y las matrices Y^t y X se inicializan a la identidad en el device.

El algoritmo de diagonalización propuesto divide un renglón de la matriz en bloques y cada thread opera en un elmento del renglón. El artículo señala que esta división de renglón en bloques y en ciclo se puede hacer eficientemente con la arquitectura de CUDA pues cada thread hace operaciones independientes. Los datos requeridos por el bloque son almacenados en la memoria compartida y las operaciones ejecutadas en el multiprocesador de la siguiente forma: en cada iteración del ciclo se modifican dos renglones de la matriz y como el segundo renglón es nuevamente modificado en la siguiente iteración, sólo el primer renglón actualizado es copiado de regreso al device mientras el segundo renglón actualizado se queda en la memoria compartida para la siguiente iteración. La memoria compartida es reusada para copiar el tercer renglón para la siguiente iteración y la iteración continúa. El procedimiento de transformación de los renglones hacia adelante es muy parecido al procedimiento hacia atrás. 

Por otro lado, como la transformación de columnas es similar a la de los renglones, se usa el kernel de la transformación por renglón sobre los renglones de X^t en lugar de las columnas de X.

Cuando converge el algoritmo, las d_i's contienen los valores singulares. Y^t y X estan en el device y se utilizan para el cálculo de las matrices ortogonales U y V, realizando dos multiplicaciones matriz-matriz al final para calcular las matrices ortogonales U = Q*X y V^t = (P*Y)^t utilizando las rutinas de CUBLAS. Las matrices Q, P^t, X^t, U y V^y están en el device, por lo que las matrices ortogonales U y V^t entonces pueden ser copiadas al CPU. 

En la parte de resultados en el artículo se analiza el desempeño del algoritmo con la implementación de SVD en Matlab y Intel MKL 10.0.4 LAPACK. Asimismo, se probó el algoritmo en una Intel Dual Core 2.66GHz PC y el los siguientes GPUS: NVIDIA GeForce 8800 GTX, NVIDIA GTX 280 y NVIDIA Tesla S1070.

Para lo anterior, se generaron 10 matrices densas aleatorias en precisión simple considerando varios tamaños de matriz, desde 64 X 64 hasta 8K X 2K.

Como resultados principales menciona que para matrices pequeñas, el CPU tuvo mejor desempeño que la GPU. Asimismo, señala que probaron con varios tamaños de bloque dependiendo del tamaño de la matriz y que el desempeño en matrices cuadradas aumentó utilizando el paradigma de más bloques para matrices más grandes.

Compararon su algoritmo de diagonalización con el algoritmo de diagonalización de Intel MKL y concluyen que éste ultimo arroja mejores resultados para matrices pequeñas pero el desempeño de la GPU mejora con el tamaño de la matriz. En este punto, la diagonalización es la que contribuye en mayor medida a esta mejora en el desempeño, pues la bidiagonalización toma más tiempo en el CPU que la diagonalización; sin embargo, en la GPU la diagonalización es más rápida.

Finalmente, el articulo concluye indicando que usando su implementación híbrida para la diagonalización (i.e. partir los calculos entre el CPU y la GPU) pueden calcular la SVD de matrices muy grandes hasta el orden de 14K, lo cual resulta imposible en CPU debido a limitantes en la memoria.

Asimsimo, señalan que a pesar que las GPU's estan limitadas a números en precisión simple, el error debido a la menor precisión fue menor del 0.001% en las matrices con las que probaron y hay que tener en mente que ésta limitante está cambiando con las nuevas generaciones de GPU's.
















