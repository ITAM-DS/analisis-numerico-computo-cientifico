# Avance_17_04_2017
## Integrantes:

    Ixchel Guadalupe Meza Chávez  
    Amaury Gutierrez Acosta  

## Trabajo:
### Individual

**Ixchel**:  

Lei este [artículo](https://www.dropbox.com/s/auocakuljym0hec/mnih2015.pdf?dl=0) sobre el algoritmo que queremos implementar, revisé tres repositorios de implementaciones utilizando DQN que se pueden encontrar en los siguientes links:
* [DeepLearningVideoGames](https://github.com/asrivat1/DeepLearningVideoGames)  
* [DQN-tensorflow](https://github.com/devsisters/DQN-tensorflow)  
* [simple_dqn](https://github.com/tambetm/simple_dqn/tree/master/src)  

Por último del ejemplo que quise instalar la semana pasada y no pude porque mi tarjeta no cubre con la capability necesaria, tomé el código de [LeNet](https://github.com/tbennun/cudnn-training/blob/master/lenet.cu) y busqué en la documentación de [cuDNN](https://www.dropbox.com/s/z6lolxum907go04/cudnn_library.pdf?dl=0) las funciones y handlers para ver qué hacen y cómo se implementan.

**Amaury**:

Implementé un [contenedor de docker](https://github.com/amaurs/docker-cudnn) para el desarrollo del proyecto. Este incluye las tecnologías de las que hablamos en el primer avance: cuDNN, Arcade Learning Environment. El propósito es tener un ambiente de desarrollo centralizado para evitar problemas de versiones entre los integrantes del equipo. En el link del proyecto de github se encuentran más detalles sobre el uso del contenedor.

Para evaluar la factibilidad del proyecto se intentó armar un prototipo usando [Open Gym AI](https://github.com/openai/gym) y [tensorflow](https://github.com/tensorflow/tensorflow), esto no fue tan fácil como se pensaba en un principio y hay que revisar los algoritmos con mayor profundidad. Una referencia sencilla y bien explicada del proceso se puede encontrar en el capítulo 16 sección 6 del libro [Reinforcement Learning: An Introduction](https://www.dropbox.com/s/w2lyhd3nsyqx7j2/bookdraft2016sep.pdf?dl=0).

### Equipo

Debido a la dificultad que se tiene con la GPU del equipo de uno de los integrantes, se han planteado varias alternativas para solventar dicha situación. 

- Se puede usar una imagen de Amazon para correr los procesos una vez que estén implementados. La ventaja es la facilidad de uso ya que no dependeremos del hardware de nadie. La desventaja es el costo prohibitivo de esto.

- Se puede conseguir un equipo adicional para el desarrollo del proyecto.

- Se puede cambiar el scope del proyecto para simplificar la arquitectura de la red neuronal y dejar de usar el *framework* cuDNN para usar las rutinas de más bajo nivel de CUDA. Esto puede disminuir la complejidad del proyecto. Para la próxima entrega se habrá tomado una decisión al respecto.

 ## Referencias
 
 - [Human-Level Control through Deep Reinforcement Learning](https://www.dropbox.com/s/auocakuljym0hec/mnih2015.pdf?dl=0)

 - [Reinforcement Learning: An Introduction](https://www.dropbox.com/s/w2lyhd3nsyqx7j2/bookdraft2016sep.pdf?dl=0)
