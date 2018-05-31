Equipo 9 
=================================================

Integrantes
---------------------------------------------------
+ Karen Peña (175952)
+ Miguel Catañeda (175840)
+ Fernando Briseño (171349)


**Título del proyecto:** Mínimos Cuadrados usando la Factorización QR y CUDA

**Objetivo del proyecto:** Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo


Trabajo escrito (fuera del repo): [liga_trabajo_escrito](https://www.dropbox.com/s/ctu5y11cf50xtg1/Factorizaci%C3%B3n%20QR_300518.pdf?dl=0)

Presentación (fuera del repo): [liga_presentación](https://www.dropbox.com/s/dj4x3mw7ycxt6w0/Factorizaci%C3%B3n_qr.pptx?dl=0)

Implementación (en el repo): [código](codigo/README.md)



Plan de trabajo 
--------------------------------------------------

1. Investigar aplicaciones vía Householder y rotaciones Givens.
2. Comprender características y propiedades de las transformaciones. 
3. Estudiar su aplicación para el cálculo de QR de forma secuencial. 
4. Estudiar la aplicación al problema de mínimos cuadrados. 
5. Abordar la implementación en paralelo en un sistema de memoria compartida.

Calendario de entregas 
--------------------------------------------------

| Fecha    | Descripción de actividades   |
|:--------:|:---------------------------- |
|10/04/18  | Integrar bibliografía y plan de trabajo|
|17/04/18  | Investigar en qué consiste el método de mínimos cuadrados. Investigar aplicaciones vía Householder y rotaciones Givens. Definición del ambiente de desarrollo generando dockerfiles uno para openmp y otro openmp-cuda|
|24/04/08  | Comprender características y propiedades de las transformaciones así como el método . Iniciar programación secuencial de QR en alguno de los ambientes.|
|02/05/18  | Concluir programación secuencial de QR en el ambiente. |
|08/05/18  | Conclusiones y comienzo de redación de trabajo escrito.|
|15/05/18  | Trabajo escrito terminado. Elaborar presentación. |
|22/05/18  | Integrar entregables (documento escrito, presentación, código)

Entrega de Avances
--------------------------------------------------
En la carpeta [avance_10_04_2018](avance_10_04_2018) se encuentra el reporte del primer avance del proyecto.

En la carpeta [avance_17_04_2018](avance_17_04_2018) se encuentra el reporte del segundo avande del proyecto. Cabe mencionar que se realizó un ajuste en la aplicación (como se comentó en clase). Nos enfocaremos en resolver el problema de mínimos cuadrados a partir del ambiente de desarrollo generando dockerfiles uno para openmp y openmp-cuda (aún estamos por definir cuál emplearemos).

Actualizamos nuestro calendario para tal efecto.

En la carpeta [avance_24_04_2018](avance_24_04_2018) se encuentra el reporte del tercer avance del proyecto.

En la carpeta [avance_02_05_2018](avance_02_05_2018) se encuentra el reporte del cuarto avance del proyecto.

En la carpeta [avance_08_05_2018](avance_08_05_2018) se encuentra el reporte del quinto avance del proyecto.

Subimos trabajo final, presentación e implementación.




Referencias
--------------------------------------------------

[T. Heat, Michael (2013). Parallel Numerical Algorithms. Chapter 11 – QR Factorization.](https://courses.engr.illinois.edu/cs554/fa2013/notes/11_qr.pdf)

[Carl D. Meyer. Matrix analysis and applied linear Algebra.](https://drive.google.com/file/d/0BxMtevFKwTW_ZmpwcDd1M0RTVzA/view)

[Palacios, Erick (2018). Notas del curso: Métodos numéricos y optimización: Factorizaciones matriciales SVD, Cholesky, QR](https://www.dropbox.com/s/s4ch0ww1687pl76/3.2.2.Factorizaciones_matriciales_SVD_Cholesky_QR.pdf?dl=0)
[G. H. Golub, C. F. Van Loan (2013). Matrix Computations. John Hopkins University Press.](https://drive.google.com/file/d/0B5IJ1w6MjxegWGg4V1pDbFhaSzQ/view)

[A. Buttari, J. Langou, J. Kurzak, J. Dongarra. A (2009). Class of Parallel Tiled Linear Algebra Algorithms for Multicore Architectures.](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf)

[A. Buttari, J. Langeou, J. Kurzak, J. Dongarra (2008). Parallel tiled QR factorization for multicore architectures.](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view)

[Demmel, et al., Communication-avoiding parallel and sequential QR factorizations](http://bebop.cs.berkeley.edu/pubs/mhoemmen2008-tsqr-tech-report.pdf)

[Eisenlohr, et al. (2008), QR Factorization in OpenMP and Cilk Plus: Development Experience and Performance Analysis ](https://www.tacc.utexas.edu/documents/13601/f4a6eba3-95ff-46b4-b180-7cbb90eda407)

[Kurzak, J. y Dongarra, J. (2008), QR Factorization for the CELL Processor](https://www.researchgate.net/publication/237322338_QR_factorization_for_the_CELL_processor)

[Palacios, M. (2001), Sistemas de ecuaciones lineales: métodos directos.](http://pcmap.unizar.es/~mpala/C_N_lecci/CN_1II2_SELdir.pdf)

[Michailidis, P. y Margaritis, K. (2015), Scientific computations on multi-core systems using different programming frameworks](http://users.uom.gr/~pmichailidis/jpapers/jpaper015.pdf)

[Granat, et al. (2009), A Novel Parallel QR Algorith for Hybrid Distributed Memory HPC Systems](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.297.638&rep=rep1&type=pdf)

[Honecker, A. y Schüle, J. (2007) OpenMP Implementation of the Householder Reduction for Large Complex Hermitian Eigenvalue Problems](https://pdfs.semanticscholar.org/aea4/3bd940575642beb7a73deffad0079b315290.pdf)

[Bova, S., (2001) et al. Parallel Programming with Message Passing and Directives](https://engineering.purdue.edu/paramnt/publications/MpiOmp01.pdf)
