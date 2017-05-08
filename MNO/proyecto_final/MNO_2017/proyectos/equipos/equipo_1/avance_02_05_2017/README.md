![logo](images/logoitam.gif)

# Maestría en Ciencia de Datos

## Proyecto Final

### Avance_02_05_2017

### Integrantes:

** Gabriela Flores**

** Paulina Salgado**

** Guillermina Montanari**

### Trabajo:
### Equipo

Comenzamos a trabajar en el documento de presentacion del proyecto final:

Cambios generales respecto del alcance anterior:

1. Vamos a partir de un diccionario de datos, es decir, **no** incluiremos en este trabajo actividades de:

 - Scrappeo de datos
 - Limpieza y preparacion del set de datos para Mineria de Texto
 
2. Basamos nuestro trabajo en un codigo de Python existente: (Mijangos)
 
     - Se parte de sentencias provenientes de un texto ya limpio
     
     - Graficamos los datos iniciales (se usan solo dos dimensiones)
     
     - Se entrena la Red Neuronal con un set de datos de Entrenamiento, que se calculan de a pares (75% del set original)
     
     - Se hace la prueba con el set de datos de Prueba
     
     - Se grafican los datos finales (se usan solo dos dimensiones)
     
3. Las redes neuronales aplicadas a Word2Vec, son redes neuronal con la particularidad que en el paso de la capa de entrada a la de las neuronas ocultas solo implica obtener de la matriz inicial de pesos de columna que es la de la palabra objetivo. No hay una funcion de activacion en esta capa.

4. La parte de paralelizacion de este algoritmo, ocurre en dos niveles:

  - TAREAS: Al calcular el **softmax** y el **update**:

      **softmax:** calcula esa probabilidad a traves de probabilidad total
  
      **update:** es el programa pricipal, el cual primero llama a la funcion **softmax**, y con esa probabilidad hace primero el update en la **Matriz de Salida** de los pesos - WO - y finalmente retropropaga esos cambios en la **Matriz de Entrada** - WI.

  - DATOS: se asignan grupos de palabras en el calculo de los pesos de salida y en el Back propagation. Esto es a que la convergencia al hacerlo en forma secuencial o paralela con los datos no se ve afectada.
  
**Referencias**

**Parallelizing Word2Vec in Shared and Distributed  Memory**
                https://drive.google.com/open?id=0B9UK_UtOYJ8IUUxQcHpBME1YQWc
  
**Parallel Training of a Back-Propagation Neural Network using CUDA**
                https://drive.google.com/open?id=0B9UK_UtOYJ8ITFE2Uy1JQlRhSjg
  
**NNTrainingAlgorithmsParallelArchitectures4FinanceApplications** 
                https://drive.google.com/open?id=0B9UK_UtOYJ8IV3B4cE1WbnBXeXc
  
**Word2Vec Tutorial - The Skip-Gram Model**
                http://mccormickml.com/2016/04/19/word2vec-tutorial-the-skip-gram-model/
   
**Word2Vec Tutorial - Negative Sampling**
                http://mccormickml.com/2017/01/11/word2vec-tutorial-part-2-negative-sampling/
   
   

