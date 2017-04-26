## Equipo 11


---

**Integrantes:**
  
  - Mariana Godina
  - Sonia Mendizábal

---

**Título del proyecto:** `PCA aplicado al consumo de Proteínas en las Dietas de 25 Países`

**Objetivo del proyecto:** El objetivo del proyecto es 
detectar patrones de consumo de proteínas en las dietas
de 25 países implementando componentes principales y 
descomposición de valores singulares (SVD) en 
el lenguaje de programación C usando metodologías
computacionales de optimización.

**Referencias:**

* [B. B. Zhou, R. P. Brent. On Parallel Implementation of the One-sided Jacobi Algorithm for Singular Value Descompositions](https://pdfs.semanticscholar.org/cf5e/afcd87a9fcf1c77cfb431f0b8a8518f11445.pdf)

* [R. P. Brent, F. Luk. The solution of singular-value and symmetric eigenvalue problems on multiprocessor arrays.](https://maths-people.anu.edu.au/~brent/pd/rpb084i.pdf)

* Capítulo 8, Jacobi Methods, del libro: G. H. Golub, C. F. Van Loan, Matrix Computations. John Hopkins University Press, 2013.

* Sobre rotaciones Givens: capítulo 5 del libro Carl D. Meyer. Matrix analysis and applied linear Algebra. En este libro también encuentran teoría sobre eigenvalores-vectores, diagonalización y descomposición en valores singulares.

* G. H. Dunteman. Principal Component Analysis.

* Referencia para los cyclic distribution (round robin), capítulo 8 de [P.Pacheco. Parallel Programming with MPI](http://www.cs.usfca.edu/~peter/ppmpi/).

Referencias para one-sided block jacobi svd (si desean leerlas está muy bien, sólo comento que al tiempo que las revisé todavía estaban afinando los approaches que seguían)

* [G. Oksa, M. Vajtersic. Parallel One-Sided Block Jacobi SVD Algorithm: I. Analysis and Design](https://www.cosy.sbg.ac.at/research/tr/2007-02_Oksa_Vajtersic.pdf) (le seguí la pista por 4 reportes más, ustedes pueden buscarlos si les interesa)

* Uno del 2012: [M. Becka, G. Oksa, M. Vajtersic. Parallel One-Sided Block-Jacobi SVD Algorithm](http://www.iam.fmph.uniba.sk/algoritmy2012/zbornik/14Oksa.pdf)

* Uno del 2016 (quizás sea bueno leer primero esta referencia para saber en qué fase del desarrollo se encuentra este algoritmo) [S. Kudo, Y. Yamamoto, M. Becka, M. Vajtersic. Performance analysis and optimization of the parallel one-sided block Jacobi SVD algorithm with dynamic ordering and variable blocking](http://onlinelibrary.wiley.com/doi/10.1002/cpe.4059/full)


---