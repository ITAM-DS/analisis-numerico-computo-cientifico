![logo](images/logoitam.gif)
# Maestría en Ciencia de Datos
## Proyecto Final
# Avance_24_04_2017

## Integrantes:

** Gabriela Flores**

** Paulina Salgado**

** Guillermina Montanari**

## Trabajo:
### Equipo

Esta semana no tuvimos avances individuales para reportar, ya que estamos revisando el material base de:

* [1] Shunlu Zhang, Pavan Gunupudi, Qi-Jun Zhang, ["Parallel back-propagation neural network training technique using CUDA on multiple GPUs"](https://drive.google.com/a/ci.itam.mx/file/d/0B9UK_UtOYJ8IRldNWjBEMk1yV3M/view?usp=sharing), Numerical Electromagnetic and Multiphysics Modeling and Optimization (NEMO) 2015 IEEE MTT-S International Conference on, pp. 1-3, 2015.

* [2] Xavier Sierra-Canto, Francisco Madera-Ramirez, Victor Uc-Cetina, ["Parallel Training of a Back-Propagation Neural Network using CUDA"](https://drive.google.com/open?id=0B9UK_UtOYJ8ITFE2Uy1JQlRhSjg).

El articulo resume el algoritmo secuencial de Redes Neuronales como sigue: 

![logo](images/Algsec.gif)

Propone dividir el problema en dos tipos de operaciones paralelizables:

1.  **Vector * Matriz**
      a. usando CUBLAS (BLAS en CUDA):
         i. cublasSgemm (cublas API): producto de matrices
         ii. cublasSdot: producto punto

Los pasos del algorito secuencial 1., 3. y 6. pertenecen a este grupo.

2. **Operaciones Aritmeticas**
      b. uso de kernels: funcion de propagacion o activacion de la Red Neuronal. Se propone paralelizar la funcion sigmoidal evaluada para cada entrada de los vectores resultantes de cada etapa.
      
Los pasos del algorito secuecial 2., 4., 5., 6., 7. y 8. pertenecen a este grupo.

Lo cual se puede escribir de la siguiente forma:

![logo](images/Parallel.png)


La funcion sigmoidal esta definida de la siguiente manera:

![logo](images/sigmoid.png)


**Referencias**
**Nvidia documentation cuBLAS** http://docs.nvidia.com/cuda/cublas/#axzz4fP0VhGgv