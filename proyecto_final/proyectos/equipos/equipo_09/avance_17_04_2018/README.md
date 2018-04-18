# Avance_17_04_2018

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

Con base en el plan de trabajo, se revisó el tema de solución del problema de mínimos cuadrados, particularmente la porción 5.2 que aparece en el libro ["Matrix Methods in Data Mining and Pattern Recognition"](https://drive.google.com/file/d/0BxMtevFKwTW_aDE2Tjg1Zk1FbTQ/view)  

El método de mínimos cuadrados es una técnica de análisis numérico que busca optimizar y encontrar una función continua dentro de una familia de funciones que se aproxime mejor a los datos, se busca obtener el mínimo error cuadrático.
Por el lado de su implementación a partir de la Factorización por QR se parte de que Ax ≠ b para sistemas sobredeterminados (cuando se determinan los parámetros de un modelo mediante un ajuste a datos
experimentales), la solución se obtiene minimizando la magnitud del vector "residual" definido como r = b - Ax
de tal forma que se busca encontrar x minimizando la magnitud del vector residual (min ||Ax- b||2).
En ese sentido, las transformaciones householder nos permiten reducir la matriz con el algoritmo QR pues se resuelve A = Q1R a partir de x = R-1Q1Tb de la forma Rx = Q1Tb 

Miguel: 

Realicé la configuración de los ambientes de trabajo usando contenedores de Docker, para el caso de openMP y otra configuración con CUDA, en la carpeta [Docker](docker) se encuentran los archivos de configuración y la evidencia de la configuración. Adicionalmente revise la implementación del algoritmo 
de transformación de Householder del libro [Open CL in Action](https://livebook.manning.com/#!/book/opencl-in-action/chapter-12/156) capítulo 12, si bien la implementación está hecha en OpenCL se explica de manera clara como se implementa el algoritmo. 



Fernando:

He estado trabajando en sintetizar la información de la base teórica del algoritmo QR y los distintos enfoques para lograrlo. Estos constituirían los primeros apartados del documento final y servirán como referencia para el trabajo de programación.


### Equipo

Durante esta semana estuvimos distribuyendo el trabajo para abordar temas indispensables para la implementación: método de mínimos cuadrados, definición del ambiente de desarrollo generando dockerfiles con openmp y openmp-cuda. 







