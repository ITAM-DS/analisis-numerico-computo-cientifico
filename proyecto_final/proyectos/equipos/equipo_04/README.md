## Equipo 04
## Integrantes
* Arturo González-172906
* Arturo Torre-90226

#### Referencia al proyecto final: https://www.dropbox.com/s/0izbhyuult1767a/CUDA-MNO.pdf?dl=0

#### Referencia a la presentación final: https://www.dropbox.com/s/k4i8fmypcwa8h70/CUDA-MNO.html?dl=0


## Titulo del proyecto
Reconocimiento de caras utilizando cómputo en paralelo.

## Objetivo
El objetivo de nuestro proyecto es la construcción de un sistema de detección de rostros con la capacidad de obtener la identidad de los rostros dada una base de datos de imágenes.

## Referencias

Para este proyecto utilizaremos los servicios ec2 de la plataforma en la nube de amazon para el cómputo acelerado por GPUs, CUDA y OpenCV por el momento.


Para poder identificar los rostros en las imagenes o videos, se necesitan 4 etapas que son:

    1. Encontrar los rostros en la imagen.
    2. Proyección de los rostros en un mismo plano.
    3. Analizar las características faciales de la imagen.
    3. Comparar estas características con imágenes conocidas.
    4. Hacer una predicción.

Cada etapa se puede llevar a cabo con distintas técnicas y algoritmos, algunas propuestas a continuación.

#### HOG: Histogram of Oriented Gradients: 
Es un descriptor de caracteristicas cuyo propósito es el de detectar objetos. El gradiente se refiere en el cambio de la intensidad en los pixeles de la imagen, en concreto el gradiente más utilizado es de los cambios en la intensidad de la luz. Este algoritmo puede aplicarse en el paso 1 que se refiere a encontrar los rostros en las imágenes.

Referencia: https://en.wikipedia.org/wiki/Histogram_of_oriented_gradients


#### Facial Landmark Detection: 
Se refiere a la alineación de la imagen contra una posición de referencia para que pueda hacerse una comparación entre imágenes. Esto hace mucho sentido dado que en las imágenes de entrenamiento existen imágenes de la misma persona en distintas posturas y distintos ángulos, esto es un tipo de normalización. Después de esta operación se puede proceder a encontrar las características del rostro de cada persona.

Referencia: https://www.learnopencv.com/facial-landmark-detection/


#### Redes neuronales convolucionales: 
Contienen las mismas componentes que las redes neuronales convencionales (neuronas, aprenden por pesos y sesgos). Cada neurona recibe entradas, lleva a cabo un conjunto de operaciones (producto punto).
La diferencia relevante es que las redes convolucionales asumen que las entradas a la red son imágenes, esto permite codificar ciertas propiedades dentro de la red, haciéndola mucho más eficiente para el procesamiento de imágenes.
Algo muy relevante para nuestro proyecto de las redes neuronales como algoritmo de aprendizaje es que son altamente paralelizables, lo que implica que podemos obtener beneficio de su implementación en cómputo acelerado por GPUs.  
En cuanto a la implementación de las redes neuronales, existen ya varias, sin embargo prácticamente todas están hechas en lenguajes de alto nivel (pytorch-python), o no tienen soporte para cómputo acelerado por GPU (tensorflow-python, keras-r,h2o-python), por lo que lograr incorporar una red neuronal a nuestro proyecto construido en C consideramos puede ser el mayor reto técnico.

Referencia: https://en.wikipedia.org/wiki/Convolutional_neural_network

#### Arturo Torre 90226

#### Análisis de componentes principales
Dada una representación vectorial de s dimensiones de cada cara en un conjunto de formación de imágenes, análisis de componentes principales (ACP) tiende a encontrar un subespacio t-dimensional cuyos vectores base corresponden a la dirección de varianza máxima en el espacio de la imagen original. Este nuevo subespacio es normalmente inferior dimensional (t < < s.). Si los elementos de la imagen se consideran como variables aleatorias, los vectores de la base del PCA se definen como los  eigenvectores de la matriz de dispersión,

Referencia: https://pdfs.semanticscholar.org/fdca/5ecdf5fff9b5580a6bf18a813e3982693ea9.pdf


#### Análisis de componentes independientes
Este algoritmo minimiza las dependencias de segundo orden y de orden superior en los datos de entrada e intenta encontrar la base a lo largo del cual los datos son estadísticamente independientes. 

Referencia: http://www.face-rec.org/algorithms/ICA/liu99comparative.pdf


#### Análisis discriminante
Esta herramienta se encarga de  encontrar los vectores en el espacio subyacente que mejor discriminan entre las clases. Para todas las muestras de todas las clases, se definen la matriz de dispersión entre clases SB y la matriz de dispersión dentro de la clase SW. El objetivo es maximizar SB mientras minimizando SW.

Referencia: http://www.face-rec.org/algorithms/LDA/discriminant-analysis-for-recognition.pdf


#### Búsqueda evolucionaria
Es un método adaptativo basado en el eigen-espacio que intenta buscar el mejor conjunto de ejes de proyección con el fin de maximizar una función de ajuste, midiendo al mismo tiempo la precisión de clasificación y la capacidad de generalización del sistema. Este algoritmo es útil cuando la dimensión del espacio de la solución del problema es demasiado grande.

Referencia: http://www.face-rec.org/algorithms/EP/liu98face.pdf

#### Elastic Bunch Graph Matching
Como sabemos la forma de la cara humana se parece entre todas las personas (claro, con sus particularidades). Digamos que comparten una topografía similar. En ese sentido, los rostros pueden representarse como gráficas, con nodos colocados en puntos clave (por ejemplo nariz, etc.) y bordes etiquetados con vectores de distancia 2-D. Cada nodo contiene un conjunto de 40 coeficientes de ondas de Gabor complejos en diferentes escalas y orientaciones (fase, amplitud). En base a estos puntos el algoritmo establece el reconocimiento facial.

Referencia: http://www.face-rec.org/algorithms/EBGM/WisFelKrue99-FaceRecognition-JainBook.pdf


#### Trace Transform
Este método es una generalización de la transformación de radón, que se puede utilizar para reconocer objetos bajo transformaciones, por ejemplo, rotación, traducción y escalamiento. Diferentes transformaciones de trazas pueden ser producidas a partir de una imagen utilizando diferentes funciones de traza.

Referencia: http://www.face-rec.org/algorithms/Trace/eecon03.pdf

#### Modelo Activo de Apariencia (AAM)
Es un modelo estadístico integrado que combina un modelo de variación de la forma con un modelo de las variaciones del aspecto en un marco forma-normalizado. Un AAM contiene un modelo estadístico de la forma y del aspecto del gris-nivel del objeto que puede generalizar a casi cualquier ejemplo válido. La coincidencia de una imagen implica encontrar parámetros de modelo que minimicen la diferencia entre la imagen y un ejemplo de modelo sintetizado proyectado en la imagen.

Referencia: http://www.face-rec.org/algorithms/AAM/app_models.pdf

#### Modelo Morfo 3-D
El rostro humano es una superficie en un espacio tridimensional. Por lo tanto el modelo tridimensional debe ser mejor para representar caras, especialmente para manejar variaciones faciales, tales como pose, iluminación etc. Existe un método basado en un modelo tridimensional de cara morphable que codifica la forma y la textura en términos de parámetros de modelo, y algoritmo que recupera estos parámetros de una sola imagen de una cara.

Referencia: http://www.face-rec.org/algorithms/3D_Morph/avbpa2003.pdf

#### Reconocimiento Facial en 3-D
La principal novedad de este enfoque es la capacidad de comparar superficies independientemente de las deformaciones naturales resultantes de las expresiones faciales. Primero, se adquiere la imagen de la serie y la textura de la cara. Después, la imagen de la serie es preprocesada quitando ciertas piezas tales como pelo, que puede complicar el proceso del reconocimiento. Finalmente, se computa una forma canónica de la superficie facial. Tal representación es insensible a orientaciones de la cabeza y expresiones faciales, así simplifican el procedimiento.

Referencia: http://www.face-rec.org/algorithms/3D_Morph/CIS-2003-05.pdf

#### Procedimientos Bayesianos
Una medida de similitud probabilística basada en métodos bayesianos en donde las diferencias de intensidad de la imagen son características de las variaciones típicas en la apariencia de un individuo. Se definen dos clases de variaciones de la imagen facial: variaciones intrapersonales y variaciones extrapersonales. La similitud entre caras se mide usando la regla de Bayes.

Referencia: http://www.face-rec.org/algorithms/Bayes/TR2000-42.pdf

#### Máquinas de Soporte Vectorial
Dado un conjunto de puntos pertenecientes a dos clases, este algoritmo, encuentra el hiperplano que separa la mayor fracción posible de puntos de la misma clase en el mismo lado, al tiempo que maximiza la distancia de cualquiera de las clases al hiperplano. Se usa el algoritmo de componentes principales de entrada para extraer características de las imágenes faciales y luego las funciones de discriminación entre cada par de imágenes son aprendidas por el algoritmo.

Referencia: http://dx.doi.org/10.1109/AFGR.2000.840634

#### Modelos Markovianos
Los modelos Markovianos son un conjunto de modelos estadísticos utilizados para caracterizar las propiedades estadísticas de una señal. El algoritmo consiste en dos procesos interrelacionados: (1) una cadena de Markov subyacente, inobservable con un número finito de estados, una matriz de la probabilidad de la transición del estado y una distribución inicial de la probabilidad del estado y (2) un sistema de las funciones de la densidad de la probabilidad asociadas con cada estado.

Referencia: http://dx.doi.org/10.1109/ICASSP.1998.678085

#### Boosting
La idea detrás del boosting es emplear secuencialmente a un aprendiz débil en una versión ponderada de una muestra de entrenamiento determinada para generalizar un conjunto de clasificadores de su tipo. Aunque cualquier clasificador individual puede realizar levemente mejor que conjeturar al azar, el conjunto formado puede proporcionar un clasificador muy exacto.

Referencia: http://www.face-rec.org/algorithms/Boosting-Ensemble/decision-theoretic_generalization.pdf

#### Reconocimiento facial basada en video
En los últimos años se han realizado más investigaciones en el área de reconocimiento facial a partir de secuencias de imágenes. Reconocer a los seres humanos de vídeo de vigilancia es difícil debido a la baja calidad de las imágenes y porque las imágenes de la cara son pequeñas. Aún así, se han construido técnicas que permiten “solventar” esos problemas.

Referencia: http://www.face-rec.org/algorithms/Video/NRC-48216.pdf


#### RGBA

Es un modelo de color que permite la representación de cualquier color mediante una mezcla de 3 colores (rojo, azul y verde). Sin embargo, debido que no existe una definición concreta de los colores primarios (rojo, azul y verde) se da el caso de que ante mismos valores para representar un color en particular se tengan representaciones de imágenes diferentes. Posteriormente al modelo RGB se le agregó un cuarto componente o canal, conocido como "alpha" que define la opacidad de un pixel en una imagen. En consecuencia, la combinación de los colores más la opacidad de los mismos permite homogenizar las imágenes producidas por distintos modelos RGB. En nuestro ejemplo la rutina lib.pngtest nos permite descomponer una imagen dada en las 4 columnas que se mencionan en el modelo RGBA.


### Referencias generales

Repositorio de Github especializado en redes neurales para reconocimiento visual:

http://cs231n.github.io/convolutional-networks/ 

Página especializada en explicación de algoritmos para reconocimiento facial


http://www.facerec.org/algorithms/

Página que explica uso de CUDA y OpenCV para reconocimiento facial

https://devtalk.nvidia.com/default/topic/493003/face-detection-using-opencv-and-cuda-how-make-it-real/

Paper en reconocimiento facial

https://www.researchgate.net/publication/238648508_Implementing_face_recognition_using_a_parallel_image_processing_environment_based_on_algorithmic_skeletons 

Página dedicada al deep learning

https://medium.com/@ageitgey/machine-learning-is-fun-part-4-modern-face-recognition-with-deeplearningc3cffc121d78


### Referencias Pytorch

Repositorio de Pytorch

https://github.com/pytorch/pytorch 

Tutorial de pytorch 

https://github.com/yunjey/pytorch-tutorial

Página oficial de Pytorch

http://pytorch.org/about/ 

Segundo tutorial de Pytorch

https://www.analyticsvidhya.com/blog/2018/02/pytorch-tutorial/

Repositorio donde se implementa una red neural con Pytorch

https://github.com/mattmacy/vnet.pytorch

Documentación de Pytorch sobre como manejar tensores

https://pytorch.org/docs/stable/tensors.html 

Manual sobre la librería TorchVision para Pytorch

https://pytorch.org/docs/master/torchvision/


### Otras Referencias

Tutorial de la librería libpng de C

https://gist.github.com/niw/5963798

Una presentación sobre redes neurales que da una explicación introductoria

https://ccc.inaoep.mx/~pgomez/deep/presentations/2016Loncomilla.pdf

Capítulo que explica el uso de redes neurales para clasificación de imágenes

http://neuralnetworksanddeeplearning.com/chap1.html 

Explicación en video sobre redes neurales

https://www.youtube.com/watch?v=aircAruvnKk

Recursos adicionales sobre redes neurales

https://playground.tensorflow.org/#activation=tanh&batchSize=10&dataset=circle&regDataset=regplane&learningRate=0.03&regularizationRate=0&noise=0&networkShape=4,2&seed=0.26220&showTestData=false&discretize=false&percTrainData=50&x=true&y=true&xTimesY=false&xSquared=false&ySquared=false&cosX=false&sinX=false&cosY=false&sinY=false&collectStats=false&problem=classification&initZero=false&hideText=false

Tesis del itam donde se desarrolla un clasificador visual de monedas

https://hammurabi.itam.mx/exlibris/aleph/a23_1/apache_media/ES1E18G9DU8HB4B1T7H3KCFDVCRB7C.pdf

Paper sobre la paralelización de redes neurales convolucionales

https://arxiv.org/abs/1404.5997 

Recursos sobre la clasificación de imágenes en Pytorch

https://medium.com/@14prakash/almost-any-image-classification-problem-using-pytorch-i-am-in-love-with-pytorch-26c7aa979ec4