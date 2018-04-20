**Abraham:** 

`Se reviso` [referencia](https://pdfs.semanticscholar.org/cf5e/afcd87a9fcf1c77cfb431f0b8a8518f11445.pdf) `sugerida por Erick donde se habla del método de Jacobi one sided para el cálculo de SVD el paper se basa en las explicaciones de como las rotaciones en las columnas de las matrices son el principal punto para desarrollar el algoritmo de jacobi en paralelo y contrastando con el avance anterior parece que este método es más adecuado para la parelización de SVD que la bidiagonalización, incluso de acuerdo con las referencias que mostró Roberto en el avance anterior podemos ver que este método de Jacobi es una de las formas en que la función cuSolver calcula el SVD, entonces es importante revisar de que manera trabaja esta función "SVD with singular vectors (via Jacobi method)" para así tener una posible asociación a lo que muestra este paper, es decir, si esta función trabaja con las metodologías de ordenamiento de rotaciones u ordenamiento de indices como el parallel ring.`  


**Rodrigo**

`Siguiendo el consejo del profesor Erick, se leyó el artículo llamado` [The Solution of Singular-Value and summetric EigenValue Problems on Multiprocessor Arrays](https://maths-people.anu.edu.au/~brent/pd/rpb084i.pdf)`. En este articulo se presentan los "Jacobi-like algorithms" para el cómputo de SVD de una matriz m x n (m ≥ n) y descomposición de eigenvalores de una matríz simétrica n x n.`

`Este artículo es muy interesante ya que presenta distintas maneras de constuir arrelgos de procesadores para poder realizar operaciones requeridas para procesar y hacer el cómputo de SVD. Un ejemplo de esto es el llamado "one-dimensional systolic array for SVD computation", donde se utilizan n/2 procesadores con memorias suficientemente grandes para poder almacenar una columna de A y de esta manera poder realizar métodos de Hestenes y terminar con la descomposición SVD.`

`Aunque estos métodos pueden ser un tanto complejos, creo que nos puede ayudar mucho para poder realizar la paralelización de nuestro algoritmo de recomendación de SVD ya que se presentan ventajas con respecto a sistemas seriales. Una vez que nos encontremos construyendo nuestro algoritmo, sería importante volver a revisar esta referencia y poder seleccionar el modelo que mejor se adapte a nuestro sistema, porque podría haber cambios al estructurar el proyecto final.`

**Roberto**

`Se revisaron las referencias del equipo 6 como se sugirió y se encontró que en` [referencia]( https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf) `existen ejemplos de código para descomposición en valores singulares usando librerías de cuSOLVER, sin embargo, dicho código no está basado en el algoritmo **_Golub-Reinsch_**.`

`También se encontró que existe una colección de rutinas de algebra lineal para matrices densas y/o ralas. Dicha colección de rutinas se conoce como MAGMA, que proviene de las abreviaciones en inglés de ”Matrix Algebra for GPU and Multicore Architectures”. Algunas de las posibilidades de solución de MAGMA incluyen:`

`a)      Factorización LU, QR y Cholesky`
`b)      Solución de Eigenvalores y problemas de valores singulares`

`De igual manera, la referencia muestra ejemplos de código para implementar SVD utilizando MAGMA.`


**Equipo**
`Se pueden utilizar las soluciones que propone` [referencia]( https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf) `como una forma de evaluar el desempeño de la implementación SVD que logremos obtener versus los códigos que sugiere el artículo, o en su defecto nos pueden servir de guía para la implementación.`
`Incluso podemos analizar las distintas maneras que CuSolver tiene para realizar el SVD, por tanto trataremos de implementar SVD usando CuSolver y detallando el método que este utiliza para la descomposición SVD por tanto uno de los siguientes pasos serían tener un ambiente de Cuda. `
  
