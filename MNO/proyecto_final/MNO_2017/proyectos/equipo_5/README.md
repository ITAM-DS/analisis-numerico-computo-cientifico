# Equipo 5

## Integrantes:

Ixchel Guadalupe Meza Chavez  
Amaury Gutierrez Acosta  

**Título del proyecto**: Deep reinforcement learning utilizando librerias cuDNN aplicado al juego Pong de ATARI

En el aprendizaje por refuerzo clásico se aproxima una función del producto cartesiano del espacio de estados y el espacio de acciones. El primer intento de aproximar dicha función usando una red neuronal se debe a Gerald Tesauro, quien creó un programa capáz de aprender a jugar Backgammon a partir de nulo conocimiento. Jugando contra si mismo, el programa era capaz de generar estrategias y evaluar su eficacia hasta poder vencer a humanos expertos. Usando una idea similar, el artículo cuyas ideas intentaremos replicar en este proyecto plantea la creación de un agente que pueda aprender a jugar videojuegos a partir de la secuencia de matrices de pixeles que constituyen el juego. Para lograr esto, se propone el uso de una red neuronal con dos capas de convolución y una capa completamente conectada. La entrada de la red sería la matriz de pixeles y la salida es un elemento del espacio de acciones que el agente puede tomar.

Para implementar la arquitectura de la red neuronas usaremos [cuDNN](https://developer.nvidia.com/cudnn), este *framework* proporciona herramientas que comunmente se usan en las redes neuronales. Adicionalmente se explorarán otras opciones para acelerar el entrenamiento de la red neuronal encontradas en la literatura, sin embargo, la implementación de las mismas está fuera del alcance del proyecto. En cuanto a nuestra implementación nos enfocaremos en el juego conocido como Breakout.

El objetivo del proyecto es implementar y evaluar el uso de las tarjetas gráficas para el computo científico. 

## Avances 7 de Abril

### Uso de Tarjeta Gráfica

Se investigo sobre la factibilidad del proyecto. Para esto se evaluó el uso de las herramientas planteadas. Se corrió un ejemplo de uso de la librería cuDNN con resultados exitosos. Dicho [ejemplo](https://github.com/tbennun/cudnn-training), implementa el problema clásico de clasificación, usando el *dataset* de dígitos escritos a mano: [MINST](http://yann.lecun.com/exdb/mnist/). Dicho ejercicio consiste en entrenar a una red neuronal de convolución a reconocer dígitos escritos a mano. Los resultados con la GPU fueron muy alentadores alcanzando una exactitud de 92% en tan solo 3 segundos de entrenamiento. Se evaluaron dos métodos distintos para la prueba de la GPU.

#### Instalación Nativa

Se instaló la paquetería de CUDA y cuDNN en una computadora macbook pro con una tarjeta *GeForce GT 650M*. El código se compiló y ejecutó sin problemas.

#### NVIDIA Docker

Usando un wrapper de docker que permite hacer la conexión automática entre los drivers de la GPU y el contenedor, es posible usar la utilidad de la GPU dentro del ambiente virtual proporcionado. Adicionalmente, existe una imagen de docker que tiene tanto CUDA como cuDNN. Para usar dicha imagen se usa el siguiente comando:

```
sudo nvidia-docker run --name cuda --rm -it  nvidia/cuda:8.0-cudnn5-devel /bin/bash
```

Para el ejemplo que se usó, es necesario usar cuDNN versión 5, actualmente existe ya una versión más moderna que parece no ser compatible. Debido a la escasa documentación del framework, creemos que lo mejor será usar esta versión y basarnos en el ejemplo mencionado.

### Ambiente de Entrenamiento

Usaremos una librería desarrolla *ex profeso* para el entrenamiento de agentes de aprendizaje por refuerzo. Se hicieron pruebas con dos herramientas. La experiencia se describe a continuación.

#### Open Gym AI

[Open Gym AI](https://gym.openai.com/) es un *wrapper* de [Arcade Learning Environment](http://www.arcadelearningenvironment.org/) escrito para el lenguaje de programación python. Las ventajas que ofrece es la posibilidad de programar en un lenguaje de alto nivel. La principal desventaja es que habría que escribir mucho del codigo para realizar las funciones en CUDA o usar librerias existentes como PyCuda.

#### Arcade Learning Environment

El [código](https://github.com/mgbellemare/Arcade-Learning-Environment) de Arcade Learning Environment es abierto, por lo que se probó la compilación del mismo. El proceso fue sencillo y la documentación es mejor que la de Open Gym AI. Adicionalmente no hace falta hacer conexiones entre lenguajes de programación ya que está escrito en C.

Debido a las ventajas que ofrece el uso directo de Arcade Learning Environment se decidió usar esta herramienta para el proyecto. Esto nos evitará problemas de *glue* code.

### Algoritmo

Se evaluaron dos algoritmos que permiten realizar el aprendizaje por refuerzo para nuestro problema de interés. La elección del algoritmo dependerá de la dificultad de la implementación.

#### [Deep Q-Network](https://deepmind.com/research/dqn/)

Este algoritmo usa una red neuronal de convolución para aproximar la función de decisión sobre el espacio de acciones. Fue el algoritmo que hizo famosos estos métodos al lograr entrenar agentes que fueran capaces de ganar cualquier juego de Atari a partir de cero conocimiento.

#### [Policy Gradient](http://karpathy.github.io/2016/05/31/rl/)

Inspirado en métodos más clásicos de optimización como descenso de gradiente, este algoritmo usa una red neuronal de menos capas para realizar el aprendizaje.

Intentaremos implementar el algoritmo con redes de convolución para explorar el método. En caso de que la dificultad sea muy alta optaremos por el segundo método que ofrece una menor complejidad.

## Referencias

- [Temporal Difference Learning and TD-Gammon](http://courses.cs.washington.edu/courses/cse590hk/01sp/Readings/tesauro95cacm.pdf)

- [Playing Atari with Deep Reinforcement Learning](https://arxiv.org/pdf/1312.5602.pdf)

- [Massively Parallel Methods for Deep Reinforcement Learning](https://arxiv.org/pdf/1507.04296.pdf)