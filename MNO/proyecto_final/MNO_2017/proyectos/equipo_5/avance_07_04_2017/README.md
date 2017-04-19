# Avance_07_04_2017
## Integrantes:

    Ixchel Guadalupe Meza Chávez  
    Amaury Gutierrez Acosta  

## Trabajo:
### Individual

**Ixchel**:  

Antes de habernos decidido por nuestro proyecto, investigué otra opción. El proyecto era implementar el [algoritmo de Buneman](http://robotics.stanford.edu/~scohen/cr.pdf) paralelizando [block cycle reduction](http://www.prace-ri.eu/IMG/pdf/multicoreparallelizationblockcyclicreduction.pdf) para resolver la [ecuación de Poisson](https://en.wikipedia.org/wiki/Poisson%27s_equation), que mediante métodos como el [método de las diferencias finitas](https://en.wikipedia.org/wiki/Finite_difference_method) reduce la ecuación a una ecuación matricial del tipo ```Ax = b``` donde A es una matriz tribanda de bloques. Sin embargo, nos decidimos por el proyecto que vamos a hacer porque consideramos que tiene  más que ver con nuestra maestría.

Instalé CUDA en mi laptop que tiene una GPU GeForce 610M ya que según las especificaciones es CUDA-enabled y también instalé cuDNN para probar el ejemplo [mnistCUDNN](https://github.com/tbennun/cudnn-training) que Amaury también probó y los ejemplos muestra que vienen con cuDNN v5, sin embargo después de varios intentos e investigar por qué no corría, resultó que mi tarjeta tiene capability=2.1 y para utilizar cuDNN se requiere una capability>=3.0.

Intenté crear una instancia en aws, sin embargo mi cuenta tiene un límite de uso que no me permite crear instancias GPU. Intentaré la siguiente semana resolver este punto.

**Amaury**:

#### Uso de Tarjeta Gráfica

Investigué sobre la factibilidad del proyecto que vamos a realizar. Corrí un ejemplo de uso de la librería cuDNN con resultados exitosos. Dicho [ejemplo](https://github.com/tbennun/cudnn-training), implementa el problema clásico de clasificación, usando el *dataset* de dígitos escritos a mano: [MINST](http://yann.lecun.com/exdb/mnist/). Dicho ejercicio consiste en entrenar a una red neuronal de convolución a reconocer dígitos escritos a mano. Los resultados con la GPU fueron muy alentadores alcanzando una exactitud de 92% en tan solo 3 segundos de entrenamiento. Se evaluaron dos métodos distintos para la prueba de la GPU.

##### Instalación Nativa

Instalé la paquetería de CUDA y cuDNN en una computadora macbook pro con una tarjeta *GeForce GT 650M*. El código se compiló y ejecutó sin problemas.

##### NVIDIA Docker

Usando un wrapper de docker que permite hacer la conexión automática entre los drivers de la GPU y el contenedor, es posible usar la utilidad de la GPU dentro del ambiente virtual proporcionado. Adicionalmente, existe una imagen de docker que tiene tanto CUDA como cuDNN. Para usar dicha imagen se usa el siguiente comando:

```
sudo nvidia-docker run --name cuda --rm -it  nvidia/cuda:8.0-cudnn5-devel /bin/bash
```

Para el ejemplo que se usó, es necesario usar cuDNN versión 5, actualmente existe ya una versión más moderna que parece no ser compatible. Debido a la escasa documentación del framework, creemos que lo mejor será usar esta versión y basarnos en el ejemplo mencionado.

#### Algoritmo

Evalué dos algoritmos que permiten realizar el aprendizaje por refuerzo para nuestro problema de interés. La elección del algoritmo dependerá de la dificultad de la implementación.

##### [Deep Q-Network](https://deepmind.com/research/dqn/)

Este algoritmo usa una red neuronal de convolución para aproximar la función de decisión sobre el espacio de acciones. Fue el algoritmo que hizo famosos estos métodos al lograr entrenar agentes que fueran capaces de ganar cualquier juego de Atari a partir de cero conocimiento.

##### [Policy Gradient](http://karpathy.github.io/2016/05/31/rl/)

Inspirado en métodos más clásicos de optimización como descenso de gradiente, este algoritmo usa una red neuronal de menos capas para realizar el aprendizaje.

### Equipo

### Ambiente de Entrenamiento

Usaremos una librería desarrolla *ex profeso* para el entrenamiento de agentes de aprendizaje por refuerzo. Se hicieron pruebas con dos herramientas. La experiencia se describe a continuación.

#### Open Gym AI

[Open Gym AI](https://gym.openai.com/) es un *wrapper* de [Arcade Learning Environment](http://www.arcadelearningenvironment.org/) escrito para el lenguaje de programación python. Las ventajas que ofrece es la posibilidad de programar en un lenguaje de alto nivel. La principal desventaja es que habría que escribir mucho del codigo para realizar las funciones en CUDA o usar librerias existentes como PyCuda.

#### Arcade Learning Environment

El [código](https://github.com/mgbellemare/Arcade-Learning-Environment) de Arcade Learning Environment es abierto, por lo que se probó la compilación del mismo. El proceso fue sencillo y la documentación es mejor que la de Open Gym AI. Adicionalmente no hace falta hacer conexiones entre lenguajes de programación ya que está escrito en C.

Debido a las ventajas que ofrece el uso directo de Arcade Learning Environment se decidió usar esta herramienta para el proyecto. Esto nos evitará problemas de *glue* code.

#### Algoritmo

Intentaremos implementar el algoritmo con redes de convolución para explorar el método. En caso de que la dificultad sea muy alta optaremos por el segundo método que ofrece una menor complejidad.

 ## Referencias
 
 - [Temporal Difference Learning and TD-Gammon](http://courses.cs.washington.edu/courses/cse590hk/01sp/Readings/tesauro95cacm.pdf)
 
 - [Playing Atari with Deep Reinforcement Learning](https://arxiv.org/pdf/1312.5602.pdf)
 
- [Massively Parallel Methods for Deep Reinforcement Learning](https://arxiv.org/pdf/1507.04296.pdf)


## Comentario sobre el avance:

* Muy interesante tema e importante. Buenas referencias.

* Ixchel, vi rápidamente tu propuesta, creo sí tiene que ver con la maestría, pero lo deciden ustedes.

* Buen avance de Amaury. Leyendo las dos propuestas de algoritmos me parece que el DQN llevará más tiempo del planeado en parte por entendimiento del material y lectura de documentación. Mi sugerencia es continuar con el objetivo pero revisar el Policy Gradient y acotarse a revisar el método de descenso en gradiente y descenso en gradiente estocástico el cual les ayudará a ir cubriendo el material necesario para el DQN en un futuro.
