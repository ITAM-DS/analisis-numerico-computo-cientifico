# Equipo 5

## Integrantes:

Ixchel Guadalupe Meza Chávez  
Amaury Gutierrez Acosta  

**Título del proyecto**: Policy Gradients utilizando CUDA aplicado al juego Breakout de ATARI

En el aprendizaje por refuerzo clásico se aproxima una función del producto cartesiano del espacio de estados y el espacio de acciones. El primer intento de aproximar dicha función usando una red neuronal se debe a Gerald Tesauro, quien creó un programa capaz de aprender a jugar Backgammon a partir de nulo conocimiento. Jugando contra sí mismo, el programa era capaz de generar estrategias y evaluar su eficacia hasta poder vencer a humanos expertos. Usando una idea similar, el artículo cuyas ideas intentaremos replicar en este proyecto plantea la creación de un agente que pueda aprender a jugar videojuegos a partir de la secuencia de matrices de pixeles que constituyen el juego. Para lograr esto, se propone el uso de una red neuronal con dos capas de convolución y una capa completamente conectada. La entrada de la red sería la matriz de pixeles y la salida es un elemento del espacio de acciones que el agente puede tomar.

Para implementar la arquitectura de la red neuronas usaremos [cuDNN](https://developer.nvidia.com/cudnn), este *framework* proporciona herramientas que comúnmente se usan en las redes neuronales. Adicionalmente se explorarán otras opciones para acelerar el entrenamiento de la red neuronal encontradas en la literatura, sin embargo, la implementación de las mismas está fuera del alcance del proyecto. En cuanto a nuestra implementación nos enfocaremos en el juego conocido como Breakout.

El objetivo del proyecto es implementar y evaluar el uso de las tarjetas gráficas para el computo científico. 

En la carpeta [avance_07_04_2017](avance_07_04_2017) se encuentra el reporte del primer avance para determinar y avanzar nuestro proyecto.

En la carpeta [avance_17_04_2017](avance_17_04_2017) se encuentra el reporte del segundo avance para determinar y avanzar nuestro proyecto.

## Plan de trabajo

### [7 de abril](avance_07_04_2017)

Exploración de factibilidad del proyecto. Revisión de literatura. Prueba de ejemplos de cuDNN. Prueba de hardware disponible.

### [17 de abril](avance_17_04_2017)

Revisión de literatura. Prueba de ejemplos que usan DQN. Revisión de la librería cuDNN 

### 24 de abril.

### 2 de mayo.

### 8 de mayo.

### 15 de mayo.

## Referencias

- [Temporal Difference Learning and TD-Gammon](http://courses.cs.washington.edu/courses/cse590hk/01sp/Readings/tesauro95cacm.pdf)

- [Playing Atari with Deep Reinforcement Learning](https://arxiv.org/pdf/1312.5602.pdf)

- [Massively Parallel Methods for Deep Reinforcement Learning](https://arxiv.org/pdf/1507.04296.pdf)
