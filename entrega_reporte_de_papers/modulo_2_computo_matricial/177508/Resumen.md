
ITAM 
Resume: Singular Value Decomposition on GPU using CUDA 
Uriel Miranda Miñon 
177508

Los algoritmos de algebra lineal son básicos para una gran cantidad de aplicaciones  y la incorporación de GPUs como motores para el cálculo de las mismas ha permitido una expansión en su desarrollo. En el documento revisado se expone el cálculo de la descomposición en valores singulares de una matriz densa utilizando CUDA.
Con la finalidad de aprovechar el cómputo se implementa SVD utilizando  bidiagonalización y diagonalización.

Para el caso de la bidiagonalización se utiliza una serie de transformaciones de Householder con base en BLAS. La diagonalización se logra aplicando el algoritmo QR implícito. Los resultados muestran que se logra una ventaja respecto al algoritmo implementado en MATLAB y en la implementación de LAPACK enIntel Math Kernel Lybrary.

Es importante mencionar que como soporte de la información uno de los autores, Sheetal Lahabar, ha realizado diversas investigaciones y trabajado en la descomposición de valores singulares utilizando CUDA. Por otro lado, P.J. Narayanan es conocido por sus contribuciones en visión computacional (reconstrucción dinámica de escenas 3D a través de realidad virtual convertida en productos comerciales, Structure-Free-Motion, Pantallas Computacionales), Graficas computacionales (Ray-tracing de superficies implícitas) y computo paralelo en GPU( (Algoritmos gráficos, String Sorting, técnicas de ML, ANN y clustering así como diversas aplicaciones en tareas de visión computacional). Es pionero en el uso de de plataformas innovadoras para aplicaciones de visión computacional como redes neuronales, clustering y deep learning. 

El SVD de una matriz A de mxn es una factorización de la forma:

A=UΣV^T

Donde U es una matriz ortogonal de mxm, V es una matriz ortogonal de nxn y ∑ es una matriz diagonal de mxn con elementos en la diagonal >=0 en orden descendente.

Gracias al incremento en performance de las GPU ha sido posible su uso genérico y programación para realizar tareas intensivas y altamente paralelizables, su gran ancho de banda en memoria permite trabajar con enormes conjuntos de datos.

Como ejemplo para el documento analizado se utilizan las tarjetas NVIDIA GeForce 8800 GTC con un ancho de banda de 86.4 GB/s y un máximo teórico de procesamiento ed 246 GFLOPS así como la NVIDIA GTX 280 con un máximo de 933 GFLOPS de procesamiento. Se compara también con la NVIDIA Tesla S1070 que se compone de cuatro Tesla T10 cada una con 4 GB de memoria con un procesamiento teórico de 1 TFLOP.

Tal como vimos en el curso, las GPU son una gran herramienta para cálculo científico y representan el cambio de paradigma en procesamiento en paralelo.

En el documento revisado se utilizan estas propiedades para desarrollar un algoritmo que aproveche el cálculo y permita obtener el SVD de matrices densas en un fracción del tiempo que las demás implementaciones.

Se han realizado varias aproximaciones en diferentes campos utilizando Level3 CUBLAS e implementaciones propietarias como las incluidas en MATLAB e inclusive en arquitecturas FPGA dedicadas. La aproximación más cercana es la realizada con el método One Sidede Jacobi sobre GPU utilizando CUDA.

Intel ha apostado por implementaciones en CPU de gran precisión y optimizadas para sus procesadores ( MKL) que mejoran el performance de LAPACK.

En términos generales el algoritmo busca obtener cada elemento de SVD de manera óptima. Para ello se utilizó el método Golub-Reinsch dado que se puede mapear correctamente a las arquitecturas de GPU.

	B⟵ Q^T AP (Bidiagonalización de A a B)
	Σ⟵ X^T BY (Diagonalización de B a Σ )
	U⟵ QX
	V^T⟵ 〖(PY)〗^T  (Cómputo de matrices ortogonales U y〖 V〗^T  y SVD de A=UΣV^T   )


La primera parte es la bidiagonalizaciónen la que la matriz A se puede descomponer en A=QBP^T aplicando una serie de transformaciones de Householder donde B es una matriz bidiagonal y Q y P son matrices unitarias Householder.

Se utiliza el vector u^((1)) de longitud m para el vector A(1:m,1) y v^((1)) de longitud n para A(1,2:n), donde al final se obtiene la matriz bidiagonalizada B tal que  B⟵ Q^T AP
Donde:
Q^T=∏_(i=1)^n▒H_i 

P=∏_(i=1)^(n-2)▒G_i 

H_i=I-σ_(1,i) u^((i)) u^(〖(i)〗^T )y G_i=I-σ_(2,i) v^((i)) v^(〖(i)〗^T )

La biodiagonalización Householder se alcanza alternando multiplicaciones matriz-vector con actualizaciones Rank-one que se pueden expresar utilizando BLAS nivel 2.
Dado que es muy costoso computacionalmente, se prefirió utilizar bloques con implementación de LAPACK. Para esto se divide la matriz A en bloques de tamaño L y se actualiza cuando las columnas y filas de L son bidiagonalizadas.

Con estas adecuaciones el algoritmo tiene un total de O(mn2) operaciones para m>=n.

El algoritmo completo es:
 

Su implementación en CUDA es mediante BLAS (CUBLAS) por su eficiencia con los cálculos de bloques propuesta.  Entre las optimizaciones se encuentra completar las matrices a múltiplos de 32 con ceros ya que eso ha demostrado ser más eficiente debido a los problemas de alineamiento de la memoria.

El rendimiento de CUBLAS depende en gran parte de la colocación de los datos y el uso de la librería y para maximizar los resultados, las matrices son inicializadas en la tarjeta para evitar cuellos de botella en la comunicación entre CPU y GPU.

El procedimiento es el siguiente, se realiza la bidiagonalización de A en la GPU solamente los elementos en la  diagonal y diagonal superior se copian a la CPU para proceder con la diagonalización mientras que las matrices Q y PT permanecen en la tarjeta. El espacio requerido para almacenamiento en la tarjeta es  (3(mL+Ln)+m2+n2+mn+2max(m,n))x4 bytes en la GPU.

En el caso del paso dos que consiste en la diagonalización de la matriz se descompone la matriz obtenida en el paso anterior.
Σ= X^T BY
Donde Σ es la matriz diagonal, X y Y son matrices unitarias ortogonales. En el algoritmo se actualizan los elementos de la diagonal y superior de la matriz, y el algoritmo completo es:
 
 

La diagonalización en este punto es clave y por tanto se dedica una sección a revisar la forma de paralelizar utilizando rotaciones de Givens y copiando los elementos de la diagonal y diagonal superior al CPU.

 

En el algoritmo 4 se presentan las dependencias que no permiten realizar el proceso en paralelo debido a que hay una dependencia al resultado anterior, pero se logra calcular el resultado final de cada fila en paralelo.

Las transformaciones de matrices también se realizan en paralelo. El algoritmo presentado divide cada fila de la matriz en bloques para que cada elemento pueda ser procesado por un thread y se puede realizar de manera eficiente en CUDA.

Cada bloque se realiza de 64 o 256 threads, el bloque requerirá de 2x(Tx4) bytes de memoria compartida para los elementos de la matriz. 

El algoritmo es eficiente dado que realiza el mismo número de operaciones en GPU que el secuencial.

Una vez computado todos los elementos el proceso final es multiplicación de matrices para obtener los elementos del SVD, estas son U=QX y V^T=〖(PY)〗^T de la primera fase; se utilizó CUBLAS para las multiplicaciones. Para el caso de las matrices Q,P^T,X^T,Y^T,U y V^T ya están en la tarjeta. Se coian las matrices U yV^T al CPU que son los resultados.

En la parte de los resultados se obtuvo una importante ganancia con respecto al algoritmo de Intel MKL a partir de matrices mayores a 512 y la diferencia entre tarjetas es muy poca para matrices cuadradas, en el caso de matrices rectangulares la diferencia comienza desde n=64 y se pudieron realizar cálculos de matrices mayores a 14k que no es posible realizar en CPU. Aún cuando la GPU está limitada a números de precisión simple (al momento de la publicación del documento) el cálculo de SVD de matrices densas en el orden de 14k pueden ser calculadas en GPU con un error menor a 0.001%.

Referencias:

Sheetal Lahabar, P J Narayanan. (May 2009). Singular Value Decomposition on GPU using CUDA. Centre for Visual Information Technology International Institute of Information Technology: IEEE International Parallel Distributed Processing Symposium.

