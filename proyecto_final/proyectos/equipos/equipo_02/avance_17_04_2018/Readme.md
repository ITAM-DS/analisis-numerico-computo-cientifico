# Proyecto Final: Factorización Cholesky
## Cómputo en paralelo.
## Objetivo: 
### Realizar una implementación de la factorización de cholesky en alguna de las tecnologías de cómputo distribuido o compartido visto en clase.

### Teoría de Cholesky:

Hector:

Leí un paper sobre la factorización de cholesky para recordar el concepto de factorización de matrices, de esta manera pude darme cuenta que solo es válido para matrices positivas definidas [enlace:](https://www.dropbox.com/home/Cholesky-Theory?preview=CholeskyDecomposition.pdf).
En mi caso recordar un tema como Cholesky me llevó a leer el capítulo 7 referente a Matrices simétricas y formas cuadráticas del libro “Algebra Lineal y sus aplicaciones” de David C. Lay, como forma de repaso para los temas que se han de desarrollar. Como última consulta de este avance , leí en este [paper](https://www.dropbox.com/home/Cholesky-Theory?preview=LU%2C++QR+and+Cholesky+Factorizations+using+vector+capabilities+of+GPU%27s.pdf) acerca de diversas implementaciones de algunos de los temas vistos en clase en CUDA. Entre los miembros del equipo aún nos encontramos definiendo si se implementará cholesky en openMP o CUDA.


Alejandro:

El problema de paralelización de un algoritmo de fatorización Cholesky, puede abordarse desde el uso de un DAG (Directed Acyclic Graph), esto utilizando un scheduling de tipo “last minute” utilizando OpenMP.
J.D Hogg hace esta implementación mediante sub-bloques de la matriz objetivo mediante un paradigma, FACTOR, SOLVE, UPDATE, lo cual es áltamente paralelizable.

Otro paradigma para poder paralelizar el problema en threads será propuesto por Dong, Haidar, et al. Al proponer 3 algoritmos Fast Batched, se analizan 3 tipos de algoritmos:
 - non-blocked
 - blocked
 - recursive blocked

Esto implementándose enteramente en GPU´s, con un enfoque parecido al anterior, haciendo uso de left-sided factorization y right side optimization para completar un algoritmo que sea paralelizable.
Parece razonable investigar la librería MAGMA de factorización, al parecer de las más convenientes en este punto.

Por lo accesible de la tecnología podría ser que lo mejor para este proyecto sea un paradigma de n-threads enfocado a OpenMP ya que con ayuda de Docker la configuración de esta librería podría ser no muy complicada, para así poder poner foco en el desarrollo del script funcional para lograr la factorización.
Podría ser posible que un desarrollo enfocado en CUDA pueda ser de utilidad para ser “tropicalizado” a OpenMP.
Un proceso paralelizable de interés es PDSYRK, la cual realiza actualizaciones de rango n (sub-bloques de la matriz objetivo).

La librería LAPACK actualmente cuenta con la rutina dpotf2.

Choi, Dongarra, Ostrouchov, et al. lograron paralelizar de forma relativamente sencilla las rutinas de factorización de LAPACK mediante rutinas de ScaLAPACK con módulos multinivel, una implementación de la versión de la factorización de Cholesky de este paradigma podría ser suficiente para este proyecto, el punto sensible será el tener una teoría robusta para poder llevarlo a cabo.

En los papers revisados, las matrices que se factorizan son del orden de (16 x 16) ó (32 x 32)

Bibliografía Revisada:

 - Design and Implementation of the ScaLAPACK LU, QR and Cholesky Factorization Routines, Choi, Dongarra, Ostrouchov, et al.
 - A DAG - based parallel Cholesky factorization for multicore systems, J.D.Hogg
  A Fast Batched Cholesky Factorization on a GPU, Dong, Haidar, Tomov, et al.
 - LU, QR and Cholesky Factorizations using vector Capabilities of GPU´s, Vasily Volkov, James Demmel


Uriel:

Uno de los principales objetivos de la clase es poder resolver problemas de optimización, algunos de los cuales requieren la solución a sistemas de ecuaciones lineales o que en su composición utilizan la factorización de matrices como paso para la solución.

Los sistemas de ecuaciones lineales se representan en forma matricial con la finalidad de obtener soluciones analíticas y generalizadas para conjuntos de datos y características que describen un problema.

Dentro de los métodos para resolver sistemas de ecuaciones lineales encontramos que la mayoría requieren de mucho tiempo y gran poder de cómputo debido a la complejidad del algoritmo y a las operaciones con grandes matrices y alto costo; entre los métodos que mencionamos se encuentran los directivos (Método de sustitución, Método de Igualación, Método de Reducción, Método de Gauss, Regla de Cramer).

Una alternativa es utilizar aproximaciones con métodos iterativos que permitan avanzar progresivamente hacia la convergencia en el resultado esperado.

Utilizando matrices el problema de un sistema de ecuaciones lineales se reduce a encontrar la x tal que Ax=b,  donde A es una matriz conocida y b es un vector conocido. 
Cuanto tenemos una matriz cuadrada A es definida positiva si y solo si : xt Ax > 0 para todo x en Rn.

Si A es definida positiva se puede encontrar una matriz L tal que A= LLt  y la solución al sistema de ecuaciones mediante sustitución back-forward sobre la matríz L.

La factorización de Cholesky es un caso de la factorización LU en el cual L = Ut.

La factorización de Cholesky contempla que la matriz A sea simétrica definida positiva y tendrá factorización si existe una matriz L triangular inferior con elementos positivos en la diagonal tal que A= LLt . Si A es definida positiva (todos los elementos de la diagonal son positivos) entonces la factorización existe y es única.

Aplicaciones:

Entre las principales aplicaciones con enfoque a optimizar los recursos para cómputo se encuentran:

Mínimos cuadrados 
Simulación Montecarlo
Generación de Vectores aleatorios
Filtro de Kalman
Kernel de cálculo de factorizaciones sobre matrices dispersas
Precondicionamiento de métodos iterativos.

Fuentes:

 - Glyn A Holton. (2009). Value-At-Risk: Theory and Practice. United States: Loose leaf - sheets & binder. 

 - HIGHAM J., NICHOLAS. (2002). 10. Cholesky Factorization. Accuracy and Stability of Numerical Algorithms(195-212). Manchester, England: SIAM.

 - Press, W. , Teukolsky, S., Vetterling, W., Flannery, B.. (1997). 2.9 Cholesky Decomposition. En Numerical Recipes in Fortran 77: The Art of Scientific Computing(89-91). Cambridge, UK: Press Syndicate of the University of Cambridge.







Equipo:

En esta fase el equipo se dedicó a la comprensión o recordatorio de Cholesky, se investigaron diversas implementaciones en las tecnologías vistas en clase y a partir de esto decidiremos que modelo de trabajo seguir (CUDA y openMP parecen ser los candidatos)

A continuación se detalla un pequeño script implementado como ejemplo recopilado de la siguiente [página](https://rosettacode.org/wiki/Cholesky_decomposition#C)  Aquí va el script de C que se probó.

En la carpeta de [implementación](https://github.com/alexnivi/analisis-numerico-computo-cientifico/tree/mno-2018-1/proyecto_final/proyectos/equipos/equipo_02/avance_17_04_2018) pondremos los códigos que se vayan desarrollando.

La presentación podemos ver y modificar [aquí](https://docs.google.com/presentation/d/1JHr-1JZNZ7q5VW2oH8azUbistSz1XeGuaDefHo8OLoU/edit?ts=5ad56ae6#slide=id.p)

El trabajo escrito también cooperativo está [aquí](https://docs.google.com/document/d/1_VOtnyJGHTWvyHCHC9L-mSRSNSslY22qrSikXzquL2g/edit?ts=5ad56af8)

En la carpeta [Referencias](https://www.dropbox.com/home/Cholesky-Theory) tenemos los artículos escritos.
