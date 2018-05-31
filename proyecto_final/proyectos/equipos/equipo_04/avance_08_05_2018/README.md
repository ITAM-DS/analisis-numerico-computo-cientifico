## Avance 5 Proyecto Final

### Equipo 4

### Integrantes
* Arturo González Bencomo - 172906
* Arturo Torre González - 90226

Respondiendo a los comentarios de la retroalimentación anterior, respecto si se implementará ALEXNET, aún no decidimos si utilizarla o no, pero nos gustaría entrenar una red propia.

### Arturo González Bencomo - Arturo Torre González
En este avance entrenamos una red neuronal convolucional utilizando pytorch para clasificación de imágenes de distintas categorias (avión, carro, etc). 
Esto lo hicimos basandonos en un proyecto desarrollado por pytorch con la finalidad de mostrar las capacidades de deep learning del mismo. 
En este avance nos quedamos en la implementación de la red neuronal utilizando cómputo paralelo únicamente en el CPU, posteriormente lo haremos usando los GPU de nuestra instancia de AWS. En nuestra instancia con GPUs, el procesamiento sera mucho más rápido y las predicciones seran mucho más acertadas. 

La secuencia de pasos que implementamos son: 

1. Descargamos las imágenes a modo de datasets de entrenamiento y test contenidos en repositorios de pytorch.
2. Preprocesmiento y normalización de los datasets mediante transformaciones de torchvision.
3. Definición de una clase del tipo red neuronal convolucional con funcion de activación relu.
4. Entrenamos la red neuronal con 10 epochs.
5. Verificamos las predicciones de las imágenes.

La implementación que realizamos utilizó varias clases de pytorch a continuación se mencionan:

* autograd: Este paquete brinda funcionalidades para obtener diferenciación automática para todos los tensores. Esta funcionalidad es de suma necesidad para la optimización de las redes neuronales en las etapa de backpropagation, ya que cada iteracion puede ser distinta. 

Ejemplo:
$$ x = [x_{1},x_{2},x_{3},x_{4}] $$

$$ x = [1,2,3,4] $$

$$ y = x^2 $$

$$ y = [1,4,9,16] $$

$$ z = sum (y + 3) = sum([4,7,12,19]) $$

$$ z = 42 $$

Entonces: Los gradientes a cada elemento de x serian: 

$$ \frac{\partial z}{\partial  x_{1}} = 2*x $$ Aplicamos para todos los elementos del vector

Incluimos un pequenio código para demostrar esto: 

    import torch
    x = torch.tensor([1,2,3,4], requires_grad=True)
    y = x**2
    print(y)
    z = y+3
    out = z.sum()
    print(z, out)
    out.backward()
    print(x.grad)


* torch.nn: Clase de pytorch que permite implementar redes neuronales genéricas con funciones de activación tanto RELU como sigmoide. Minimiza la distancia euclidiana al cuadrado.
* torchvision: Es un compendio de paquetes que contiene datasets utiles, modelos y transformaciones para procesamiento de imágenes.
* torch.optim: Paquete de algoritmos de optimización incluye los mas comunes (descenso gradietne, gradiente estocástico, etc).
* matplotlib.pyplot: Método de matplotlib para visualización de cualquier tipo de gráficas e imágenes, lo utilizamos para visualizar las imágenes con las que trabajamos.

Todo lo explicado anteriormente esta en el archivo red-neural.py


#### Referencias
https://pytorch.org/tutorials/beginner/blitz/cifar10_tutorial.html
https://pytorch.org/docs/master/