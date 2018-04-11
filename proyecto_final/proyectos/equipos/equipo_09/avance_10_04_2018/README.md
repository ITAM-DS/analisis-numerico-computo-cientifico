# Avance_10_04_2018

Equipo 9 
=================================================
**Título del proyecto:** Factorización QR

**Objetivo del proyecto:** Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo


Integrantes
---------------------------------------------------
+ Karen Peña (175952)
+ Miguel Catañeda (175840)
+ Fernando Briseño (171349)


## Trabajo:

### Individual

Karen: 


Miguel: 

Revise las referencias bibliográficas, en específico las notas de las clase del tema 
[3.2.2 Factorizaciones matriciales](https://www.dropbox.com/s/s4ch0ww1687pl76/3.2.2.Factorizaciones_matriciales_SVD_Cholesky_QR.pdf?dl=0)
sobre todo la parte de los conceptos geométricos, los proyectores ortogonales elementales, los reflectores elementales
también llamados transformaciones de Householder donde lo más importante que identifiqué fue que para la multiplicación Rx se debe evitar formar la matriz R y tener un costo de *O(m<sup>2</sup>)*, rotaciones las cuales también son llamadas rotaciones Givens. De la referencia de *Carl D. Meyer. Matrix analysis and applied linear Algebra* la factorización *QR* puede ser usada para resolver el problema de mínimos cuadrados ya que es numéricamente estable. 

Por otra lado también revise las implementaciones actuales para la factorización QR:


La biblioteca **LAPACK** cuenta cuenta con subrutinas para calcular la factorización QR,como son: 


| Factorización sin pivote | Factorización con Pivote | Generación de matriz Q | Multiplicación de matriz Q
|:--------:|:-------:|:--------:|:-------:|
| geqrf , geqrfp | geqpf, geqp3 | orgqr , ungqr | ormqr ,unmqr


Para el caso de **CUDA** también existe la implementación para la factorización QR en la biblioteca  *cuSolver*
[Nvidia CuSolver](http://docs.nvidia.com/cuda/cusolver/)

Existe una biblioteca llamada **MAGMA** (Matrix Algebra for GPU and Multicore Architectures) la cual esta enfocada al uso de GPU's y arquitecturas *Multicore*
[MAGMA](http://icl.cs.utk.edu/magma/) la cual tiene routinas para la factorización [QR](http://icl.cs.utk.edu/projectsfiles/magma/doxygen/group__group__qr__batched.html)



Fernando:

### Equipo

Definimos el plan de trabajo con la primera versión de las actividades a realizar, esta lista se puede actualizar conforme avancemos en el desarrollo del proyecto, también hicimos una revisión de las referencias. 







