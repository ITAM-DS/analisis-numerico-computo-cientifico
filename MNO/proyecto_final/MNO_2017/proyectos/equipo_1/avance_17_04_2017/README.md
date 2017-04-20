# Avance_17_04_2017

## Integrantes:

**Gabriela Flores**
**Paulina Salgado**
**Guillermina Montanari**

## Trabajo:
### Individual

**Paulina**: Referencias de Word Embeddings, Word2Vec y Redes Neuronales.
              
               Word embedding es un conjunto de modelos que se usan en técnicas de aprendizaje en procesamiento del lenguaje natural,   donde las palabras son mapeadas de un texto (corpus) a vectores con entradas reales. La idea es tomar un corpus (texto) de entrada y producir un espacio vectorial de salida de cientos de dimensiones, ya que cada palabra única de corpus tiene un vector asignado. Los vectores son posicionados en el espacio de tal manera que aquellos que comparten espacios comunes están cercanos.
              
              Para ello se utilizan redes neuronales, (aprendizaje no supervisado) con una capa oculta. Las neuronas en la capa oculta son todas lineales. La capa de entrada está configurada para tener tantas neuronas como hay palabras en el vocabulario para el entrenamiento. El tamaño de la capa oculta se ajusta a la dimensionalidad de los vectores de palabras resultantes. El tamaño de la capa de salida es el mismo de la capa de entrada.
              
              A continuación se encuentran <a href="https://drive.google.com/drive/u/1/folders/0ByF7NuX9EW1Ib0NEenJpdF82dnM"> las referencias </a> en donde se explica con mayor detalle el funcionamiento de word embeding y los algoritmos utilizados en su implementación: 
              
              -Continuos Bag of words (CBOW), From Data to Decisions, Integrated Knowledge Solutions.
              
              -Distrbuted Representations for Natural Language Processing, Tomas Mikalov-Facebook ML Prague 2016. 
              
              -Exploiting Similarities among Languages for Machine Translation, Tomas Mikolov, Quoc V. Le, Ilya Sutskever, 2013.
              
              

**Gabriela**: 
1. Revisión de la implementación del algoritmo en python para identificar que partes de código se pueden paralelizar y/o optimizar.
  - Se localizaron artículos acerca de la paralelización de redes neuronales con back-propagation en CUDA, ya que Word2Vec las utiliza, a continuación se listan los artículos:
    + [Shunlu Zhang, Pavan Gunupudi, Qi-Jun Zhang, "Parallel back-propagation neural network training technique using CUDA on multiple GPUs", Numerical Electromagnetic and Multiphysics Modeling and Optimization (NEMO) 2015 IEEE MTT-S International Conference on, pp. 1-3, 2015.](https://drive.google.com/a/ci.itam.mx/file/d/0B9UK_UtOYJ8IRldNWjBEMk1yV3M/view?usp=sharing)

2. Investigación de las opciones para ejecutar código de Cuda C y Python.
2. Another item
  * Unordered sub-list. 


**Guillermina**: plataforma CUDA

  - Instalacion del driver y toolkit de CUDA: 
      -- http://docs.nvidia.com/cuda/cuda-installation-guide-linux/#axzz4eMvndrn1
      
 - Prueba de un programa CUDA en entorno UBUNTU:
 
      -- Hardware para el proyecto:https://drive.google.com/open?id=0ByF7NuX9EW1IZU1XaWdodVJSXzQ
      
      -- Tarjeta grafica: https://drive.google.com/open?id=0ByF7NuX9EW1IZnRudEJoWlNWVUk
          
      -- Codigos compilados y ejecutados como primera prueba de la instalacion de CUDA:  https://drive.google.com/open?id=0ByF7NuX9EW1IS1M3aWJBMnhGRGs
          
     -- La compilacion de los programas en CUDA se realiza con: nvcc <archivo.cu> -o <archivo.out>
     
     -- La ejecucion se hace con: ./<archivo.out> 

  - Versiones instaladas:
  
    -- gcc: https://drive.google.com/open?id=0ByF7NuX9EW1ISVhPd0JhMmVsWEE
    
    -- nvcc: https://drive.google.com/open?id=0ByF7NuX9EW1IYTJETHFQSWpRRlU
    
    
    
### Equipo

## Redefinición del alcance del proyecto.

Redefinimos el objetivo del proyecto: Paralelizar word2vect con el modelo continuos bag of words (CBOW), mediante Cuda C.

