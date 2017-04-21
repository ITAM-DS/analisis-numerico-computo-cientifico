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

 ## Comentarios sobre el avance:

 * Ambos trabajos individuales están muy bien y creo que la parte que está resuelta es la aplicación: DL para el juego de breakout pues la documentación para ejecución de los frameworks o librerías o funciones existe y en general está bien y ambos han tenido pasos exitosos (ya sea construyendo el ambiente vía docker o la ejecución de ejemplos). Sin embargo, como podemos observar en estas referencias de este nuevo avance que uds proporcionan hay que cubrir una literatura vasta y amplia para que exista un entendimiento del DQN de forma completa y que un primer acercamiento consistiría en los siguientes temas:

-) Reinforcement learning.

-) Redes neuronales.

-) Convolutional neural nets.

-) Deep learning.

-) DQN.

Pero intermedio de estos temas tenemos otros que están relacionados con optimización. Esto es lo que a mi parecer podemos revisar en este tiempo que de igual forma constituye un muy buen inicio para desmenuzar a la aplicación que realizarán. 

Sugiero continúen con la aplicación pero cubran la siguiente literatura sobre optimización:

* Paper que da un panorama actual (2016) sobre los métodos de optimización para large scale machine learning: [L. Bottou, F. E. Curtis, J. Nocedal. Optimization Methods for Large-Scale Machine Learning](http://leon.bottou.org/publications/pdf/tr-optml-2016.pdf), en particular es muy importante la revisión del SG y SGD.

* Paper del tipo "optimization vs learning": [L. Bottou, O. Bousquet. The Tradeoffs of Large Scale Learning](http://leon.bottou.org/publications/pdf/nips-2007.pdf)

* Sobre tricks en backprop: [Y. LeCunn, L. Bottou, G. B. Orr, K. R. Müller. Efficient BackProp](http://yann.lecun.com/exdb/publis/pdf/lecun-98b.pdf)

Pueden revisar estas referencias para el tercer avance y enfocarse en particular hacia SG.






