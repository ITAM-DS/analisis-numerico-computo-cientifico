# Avance_17_04_2017

## Trabajo:

### Indivudual

#### Ollin:
Comencé con el desarrollo de un script en C que lea los archivos de grafos y genere la estructura con nodos y aristas.


#### Isabel y Raul:  
Levantamos una máquina en AWS (p2 con ubuntu), para lo que fue necesario mandar un correo a aws pidiendo permiso para levantar este tipo de máquina.   
A ésta máquina, la que le instalamos CUDA con ayuda de [esta referencia](http://docs.aws.amazon.com/AWSEC2/latest/UserGuide/accelerated-computing-instances.html#install-nvidia-driver) y de [esta otra](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#abstract) y algunas otras ya que no se encontró un tutorial que resolviera todos los problemas que surgen al instalar CUDA en una máquina AMI p2 de amazon. 
Se probó que funcionara CUDA en esta máquina corriendo [un hello world](hello_world.cu) y  [este otro ejemplo](producto.cu)
También leímos [esta referencia](LNCS-ICA3PP2016.pdf) que nos pareció interesante ya que habla de un algoritmo para problemas de combinatoria permutativa basados en estructura de datos IVM (Integer-Vector-Matrix). Aunque nuestro problema es distinto, nos pareció interesante la forma en que los autores abordaron el problema.  

### Equipo
Comentamos las necesidades técnicas para llevar aa cabo una implementaión en CUDA como lo es el levantamiento de una máquina en AWS con esa capacidad, debido a las limitaciones de hardware por lo que se decidió montar dicha instancia. Otra necesidad fue justo hacer un modelo de grafo para poder llevar a cabo la implementación, por lo que decidimos empezar con esto de inmediato.

Analizamos y discutimos los artículos revisados la semana anterior para tener un mejor entendimiento de las propiedades y usos de la matriz de Hashimoto non-backtracking. Observamos que los artículos centran la aplicación de la matriz en variantes de detección de clusters, detección de comunidades y como medida de concentración de un grafo. Este conjunto de aplicaciones cuentan de gran relevancia para entender la estructura del grafo y la representación de la red usando la codificación de la matriz de Hashimoto non-backtracking permite realizar dichos análisis de una manera más eficientes.

El (artículo-1)[https://arxiv.org/pdf/1306.5550.pdf] y el (artículo-2)[https://arxiv.org/pdf/1308.6494.pdf], muestra que los algoritmos espectrales son bastante competitivos para detectar comunidades en grafos, sin embargo fallan al encontrarse con redes ralas. El uso de la matriz de Hashimoto junto con los algoritmos espectrales resuelve este problema, y le ganan por mucho a los algoritmos de agrupación estándar.
El (artículo-3)[https://arxiv.org/pdf/1506.08326.pdf] y (artículo-4)[https://arxiv.org/pdf/0712.0192v1.pdf] muestra otra variante de aplicación de la matriz de Hashimoto, donde se observa la dinámica de propagación o alcance de un individuo hacia toda la red. Dadas las propiedades de la matriz, esta representa una mejora para los algoritmos que analizan este comportamiento.

Basándonos en las referencias anteriores podemos entender el comportamiento de la matriz de Hashimoto, sus aplicaciones y la estructura que debemos de mantener al construirla ocupando las técnicas de programación en paralelo.
