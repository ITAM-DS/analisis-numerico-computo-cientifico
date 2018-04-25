# Proyecto Final: Factorización Cholesky
## Cómputo en paralelo.
## Objetivo: 
### Realizar una implementación de la factorización de cholesky en alguna de las tecnologías de cómputo distribuido o compartido visto en clase.

### Teoría de Cholesky:

Hector:

Se leyó en las notas 3.2.2 [Notas](https://www.dropbox.com/s/s4ch0ww1687pl76/3.2.2.Factorizaciones_matriciales_SVD_Cholesky_QR.pdf?dl=0) de factorizaciones_matriciales... acerca de la factorización de Cholesky, se revisaron diversas matrices positivas definidas que vienen de ejemplo en los apuntes, características que deben cumplir algunas de ellas, propiedades y observaciones. Se revisó el algoritmo para calcular la factorización de Cholesky versión Gaxpy y los comentarios emitidos en la nota acerca de esto, de lo cual resalta lo siguiente:

        +El algoritmo mencionado requiere de n^3/3 flops.
        +Si una matriz A es spd tiene factorización Cholesky. Asimismo, si el algoritmo anterior termina exitosamente (sin raíces cuadradas de números negativos) y con raíces cuadradas positivas entonces A es spd.
        +Entre otros puntos sobresalientes ....
        
Mencionas en las notas que para la factorización Cholesky se revisen los algoritmos del libro Matrix Compuatations [Matrix Computations](https://www.dropbox.com/h) en el capítulo 4 acerca de Golub & Van Loan. 

En estos capítulos se aprecia la descripción de los algoritmos para:

    +Gaxpy Cholesky
    +Outer Product Cholesky
    +Block Dot Product Cholesky
    Notas sobre la estabilidad del Cholesky process
    +Aplicaciones en caso de Matrices Semidefinidas y Symmetric Pivoting.

Uriel detalla un poco más lo anterior en su avance de la semana.


Alejandro:

Para la implementación de un problema que aplique la factorización Cholesky se implementará una o varias iteraciones de un filtro de Kalman sencillo, con parámetros estáticos para hacer dle problema de optimización de logverosimilitud algo relativamente sencillo, aunque nada simple.

Uno de los problemas que vamos a ver en esto será el de la optimización, dado que no conozco en este momento algún algoritmo de optimización, ya sea restringida o libre que pueda ser distribuido oparalelizado, por lo que al ser el filtro de Kalman un proceso iterativo que involucra una optimización, esto representará un problema de join de forks adicional.

Se incluye en implementación un ejemplo simple del filtro de Kalman en C.

La factoriación de Cholesky entra en elmomento de procesar y calcular la matriz inversa de la matriz de varianzas-covarianza para la función de logverosimilitud que va a optimizarse después de la iteración de Kalman con las estimaciones posteriores.

Algo de la literatura recomendada para el filtro de Kalman:
(introduction to random signals and applied kalman filtering pdf)[https://wp.kntu.ac.ir/ghaffari/Advanced%20Control-II-2017/Introduction_to_Random_Signals_and_Applied_Kalman_Filtering-4th_edition.pdf]

la cual ilustra perfectamente el uso del Filtro para procesamiento de señales y da algunas nociones básicas de procesos estocásticos para ser manipulados mediante el filtro.

Uriel:


Un primer acercamiento para resolver la factorización de Cholesky en una implementación con memoria compartida es dividir la matriz en bloques factorizables.

Para este fin se revisaron los temas del libro Matrix Computatons en su edicion 3 y 4. En la edición 3 se desarrollan los temas y algoritmos básicos y se explica el procedimiento de bloques Gaxpy para multiplicación de matrices que indica la forma en que se puede separar el cálculo en paralelo y posteriormente se implementa el algoritmo para Cholesky (6.3.2 A Shared memory Cholesky).

En el algoritmo revisado se puede implementar mediante la actualización o sobre escribir los valores de la matriz diagonal inferior en la matriz A para que los nuevos valores puedan ser usados en la siguiente iteración.

En la cuarta edición se revisaron los algoritmos para una factorización gaxpy se explican en términos de uso de columnas. De los capítulos siguientes se obtiene el esquema general de la factorización de Cholesky por bloques (4.2.9 Block Cholesky):
En una matriz A Rnxn con factorización de Cholesky G ( A = GGt) 
Se puede obtener la factorización tratando cada bloque (simétrico) como un valor dentro de la factorización.
El bloque A11 = G11G11t
El bloque A21 = G21G11t
El bloque A22 = G21G21t + G22G22t
Con estos datos podemos obtener tres pasos:
Paso 1 : Calcular la factorización de Cholesky para el bloque A11 con la finalidad de obtener G11.
Paso 2: Resolver el sistema multiple derecho triangular bajo para G21.
Paso 3: Calcular el factor de Cholesky G22 de A22 - G21G21t = A22 - A21A11^-1 A21t

El algoritmo debe ser recursivo, por lo cual se puede expresar como:

función G = BlockCholesky(A,n,r)
    if n<=r
        Calcular la factorización de Cholesky A=GGt
    else
        Calcular la factorización de Cholesky A(1:r,1:r) = G11G11t
        Resolver G21G11t = A(r+1:n,1:r) para G21    
A’ =A(r+1:n,r+1:n)-G21G21t
G22 = BlockCholesky(A’,n-r,r)
G = matriz [G11 0; G21 G22]
end
end


Mejorando la parte recursiva se desarrolla el algoritmo no recursivo, en el cual se considera el parámetro n = Nr (donde r es el parámetro de bloques) y se considera a N un int positivo.

Para este caso todos los bloques se consideran de tamaño rxr se puede derivar el algoritmo Cholesky de bloques no recursivo (Algorithm 4.2.4). Si i=j entonces G11 es el factor de Cholesky de S, si i>j entonces GijGijt = S.

for j = 1:N
for i=j:N
Calcular S = Aij - sum(GikGjkt, k=1 : j-1)    
if i = j
    Calcular la factorización de Cholesky S = GjjGjjT
else
    Resilver GijGjjt = S para Gij
    end
    Aij = Gij
end
end

Siguiendo en la línea de resolver la factorización utilizando bloques, se revisó el trabajo de João Paulo Tarasconi Ruschel titulado “Parallel Implementations of the Cholesky Decomposition on CPUs and GPUs” donde propone una resolución con base en filas y la explicación deriva en la dependencia de datos para calcular cada elemento de la matriz. 

Se puede aprovechar la independencia de elementos para paralelizar el cálculo de filas para cada columna. Esta es una forma de realizarlo con directivas de openMP que se revisó para este avance.

Como tercer fuente y en continuidad directa con el avance anterior se investigó el documento de J. D. Hogg titulado “A DAG-based parallel Cholesky factorization for multicore systems “ en el cual se revisaron los Directed Acyclic Graphs (DAGS) para crear el algoritmo de factorización de Cholesky.

El primer paso descrito es separar la matriz A en bloques Aij de ancho nb 



Fuentes:

Golub, G., Van Loan, C.. (2013). 4.2 Positive Definite Systems. In Matrix Computations(159-188). USA: The Johns Hopkins University Press.

TARASCONI RUSCHEL, J.,. (2016). Parallel Implementations of the Cholesky Decomposition on CPUs and GPUs. Porto Alegre: UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL INSTITUTO DE INFORMÁTICA CURSO DE CIÊNCIA DA COMPUTAÇÃO.
link: [Parallel Implementations](http://www.lume.ufrgs.br/bitstream/handle/10183/151001/001009773.pdf) 

Hogg, J. D., . (2008). DAG-based parallel Cholesky factorization for multicore systems. UK: Science and Technology Facilities Council.
link: [DAG-BASED](https://www.researchgate.net/publication/30420599_A_DAG-based_parallel_Cholesky_factorization_for_multicore_systems) 




Equipo:

En esta fase el equipo se dedicó a la investigación de algoritmos e implementaciones diversas de la factorización de cholesky en openMP. Teoría del tema desarrollada en las notas vistas en clase y consulta al libro de Matrix Computations ayudaron bastante en este primer punto. 



El trabajo escrito también cooperativo está [aquí](https://docs.google.com/document/d/1_VOtnyJGHTWvyHCHC9L-mSRSNSslY22qrSikXzquL2g/edit?ts=5ad56af8)

En la carpeta [Referencias](https://www.dropbox.com/home/Cholesky-Theory) tenemos los artículos escritos.
