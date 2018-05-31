# Avance_17_04_2018

## Integrantes:

* David

* Mirtha

* Luis

## Trabajo:

### Individual

Mirtha:

Dado que hemos definido que nuestro proyecto consistirá en la implementación de Componentes Principales en C, comencé por revisar papers y libros que profundizan en la parte teórica y práctica con algunos ejemplos de implementación del método de PCA y SVD [PCA, Mark Richardson 2009](http://www.dsc.ufcg.edu.br/~hmg/disciplinas/posgraduacao/rn-copin-2014.3/material/SignalProcPCA.pdf), la sección 7.3 del libro [Introduction to Linear Algebra](http://download1.libgen.io/get.php?md5=BD18C7914D573808859A8FB73E710EE7&key=9S0LWRA703FGM3LY) - PCA y SVD), así como las consideraciones que deben tomarse en cuenta.

Esta técnica permite encontrar un numero de factores d<m, donde m es el número inicial de variables aleatorias disponibles, que explican aproximadamente el valor de las m variables, lo anterior, transformando un conjunto de variables posiblemente correlacionadas en un menor número de variables a lo que se llama Componentes Principales y que puede interpretarse como una reducción de la dimensionalidad.

Adicional a repasar el funcionamiento de PCA y dado que destacan la relación estrecha entre PCA y SVD leí sobre este método para recordarlo conceptualmente.

Por último, busqué ejemplos en los que se ha implementado PCA en R y Python y por ahora analicé detalladamente un ejemplo en R dado que es el lenguaje con el que me siento más familiarizada [Practical Guide to Principal Component Analysis](https://www.analyticsvidhya.com/blog/2016/03/practical-guide-principal-component-analysis-python/). Este ejercicio me ayudó a tener una idea mucho más clara de las fases que podemos considerar en la implementación de nuestro proyecto y me dio ideas de cómo atacar el problema.

Luis:

Consulté la parte teórica del método PCA en el libro de [Linear Algebra de Friedberg](http://linux.ajusco.upn.mx/~angolero/tesis-trabajo/Algrebra%20lineal%20-%20Stephen%20Friedberg.pdf) y en la siguiente liga de internet [liga](https://onlinecourses.science.psu.edu/stat505/node/51), esto para hacer un repaso del tema y considerarlo para siguientes etapas del proyecto.

Consulté información relacionada con las “iteraciones de Jacobi”, encontré que este método se ha implementado de forma secuencial (paralelo en MPI) para resolver sistemas lineales [Parallel iterative methods for Linear Systems](http://homepages.math.uic.edu/~jan/mcs572/paritermeths.pdf). Analicé como es que se paraleliza el proceso mediante una “sincronización de mariposa”, como es la comunicación y el cómputo en cada etapa. Consulté la sintaxis de la instrucción [MPI_Allgather](https://www.mpich.org/static/docs/v3.2/www3/MPI_Allgather.html) que recopila datos de las tareas y distribuye datos combinados. Por lo que consideró que este es un buen acercamento a lo que tenemos que implentar para el método PCA. Considero que podemos tomar esta información como punto de partida para desarrollar nuestro proyecto.

Consulté códigos en C que han desarrollado el método de [PCA](http://crsouza.com/2009/10/30/principal-component-analysis-in-c/). Analicé la forma en que se generan las matrices SVD, los valores singulares, eigen valores y a partir de estos la descomposición. Esta información sirve para replicar, analízar y adaptar a los objetivos del proyecto.

David:

Me apoye con Mirtha para revisar la teoría y métodos detrás del PCA, en particular consulte las siguientes referencias: 
 
* 1.[Principal Component Analysis a Tutorial](https://www.researchgate.net/publication/309165405_Principal_component_analysis_-_a_tutorial)
* 2.[PCA wikipedia](https://en.wikipedia.org/wiki/Principal_component_analysis)

En particular encontré que el método paralelizable es el que usa descomposición SVD, pues también se puede llevar a cabo el PCA a través de la matriz de covarianzas, sin embargo el método númerico por SVD es más exacto.

Por lo cuál revisé el algoritmo Jacobi clasico del libro [Matrix Computations, Golub ](http://web.mit.edu/ehliu/Public/sclark/Golub%20G.H.,%20Van%20Loan%20C.F.-%20Matrix%20Computations.pdf). Fue de especial interés el hecho que en el capítulo 8.4.6 encontré la versión en paralelo la cuál se buscará implementar después de tener el método secuencial.

Intentamos un primer acercamiento del algoritmo en R según la referencia de stats de Rbase [prcomp](https://www.rdocumentation.org/packages/stats/versions/3.4.3/source):

prcomp.default <-
    function(x, retx = TRUE, center = TRUE, scale. = FALSE, tol = NULL,
             rank. = NULL, ...)
{
    chkDots(...)
    x <- as.matrix(x)
    x <- scale(x, center = center, scale = scale.)
    cen <- attr(x, "scaled:center")
    sc <- attr(x, "scaled:scale")
    if(any(sc == 0))
        stop("cannot rescale a constant/zero column to unit variance")
    n <- nrow(x)
    p <- ncol(x)
    k <- if(!is.null(rank.)) {
	     stopifnot(length(rank.) == 1, is.finite(rank.), as.integer(rank.) > 0)
	     min(as.integer(rank.), n, p)
	     ## Note that La.svd() *still* needs a (n x p) and a (p x p) auxiliary
	 } else
	     min(n, p)
    s <- svd(x, nu = 0, nv = k)
    j <- seq_len(k)
    s$d <- s$d / sqrt(max(1, n - 1))
    if (!is.null(tol)) {
        ## we get rank at least one even for a 0 matrix.
        rank <- sum(s$d > (s$d[1L]*tol))
        if (rank < k) {
            j <- seq_len(k <- rank)
            s$v <- s$v[,j , drop = FALSE]
        }
    }
    dimnames(s$v) <- list(colnames(x), paste0("PC", j))
    r <- list(sdev = s$d, rotation = s$v,
              center = if(is.null(cen)) FALSE else cen,
              scale = if(is.null(sc)) FALSE else sc)
    if (retx) r$x <- x %*% s$v
    class(r) <- "prcomp"
    r
}

Aunque, cabe mencionar que la implementación anterior se debe descomponer más, es decir no usar funciones pre-existentes en R como SVD para su posterior implementación en C.
  

Equipo

Después de analizar y discutir la información consultada concideramos que como primer acercamiento desarrollaremos un método secuencial en C y posteriormente, considerando el tiempo y dificulad, buscaremos implentarlo en paralelo, por ejemplo, en MPI.