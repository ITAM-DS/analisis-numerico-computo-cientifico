## Avance 3 Proyecto Final

### 24/04/2018

### Equipo 4

### Integrantes
* Arturo González Bencomo - 172906
* Arturo Torre González - 90226

#### Arturo González Bencomo

Para la implementación del proyecto de reconocimiento facial, se requiere usar la técnica de redes neurales. En ese sentido, existe un paquete de Python llamado Pytorch. Pytorch incluye dos importantes características:

1.- Computación con tensores, parecido al paquete numpy, con una fuerte aceleración en GPU.
2.- Redes neurales profundas basado en un sistema autodiff

La librería de Pytorch contiene los siguientes componentes:

torch: Una librería tipo Numpy para cómputo de tensores con GPU.

torch.autograd: librería que soporta todas las operaciones diferenciables con tensores en Torch

torch.nn: una librería de redes neurales.

torch.optim: paquete de optimización que cuenta con métodos de optimización como SGD, RMSProp, LBFGS, Adam etc.

torch.multiprocessing: multiprocesador de python, pero con memoria compartida a través del procesamiento de Tensores torch.

torch.utils: Data loader y otras funciones útiles.

torch.legacy: guarda código de legado para cuando se requiere reconstruir hacia atrás las cosas.

Como se mencionó que Pytorch está montado sobre Python y cuenta con las siguientes habilidades:
1.- Un reemplazo de numpy para poder usar el poder cómputo de la GPU. 
2.- Una plataforma de deep-learning con mucha flexibilidad y velocidad.

Como se vio en clase el poder de cómputo de GPU se ha incrementado considerablemente en los últimos años. Es por eso que este proyecto se basa en el poder de cómputo de la GPU a través del cómputo en paralelo de CUDA.

#### Arturo Torre González

Avanzamos en la programación en varios aspectos. 

1. A nuestra máquina virtual ubuntu con cuda en aws, le descargamos la librería libpng que brinda funcionalidades para realizar operaciones con imagenes del tipo png que son imagenes de alta resolución. Ejecutamos el siguiente comando en la terminal de linux: 

        sudo apt-get install libpng12-dev

2. Una vez que se instaló la librería, procedimos a probar las funcionalidades de la misma con un ejemplo encontrado en internet en el sitio: https://gist.github.com/niw/5963798, este código lo incluimos en el commit (archivo 'libpng_test.c') 

3. Posteriormente descompusimos la imagen en una matriz de colores RGBA 

Un poco de teoria sobre RGBA: 

Es un modelo de color que permite la representación de cualquier color mediante una mezcla de 3 colores (rojo, azul y verde). Sin embargo, debido que no existe una definición concreta de los colores primarios (rojo, azul y verde) se da el caso de que ante mismos valores para representar un color en particular se tengan representaciones de imágenes diferentes. Posteriormente al modelo RGB se le agregó un cuarto componente o canal, conocido como "alpha" que define la opacidad de un pixel en una imagen. En consecuencia, la combinación de los colores más la opacidad de los mismos permite homogenizar las imágenes producidas por distintos modelos RGB. En nuestro ejemplo la rutina lib.pngtest nos permite descomponer una imagen dada en las 4 columnas que se mencionan en el modelo RGBA.


4. Posteriormente convertimos en escala de grises la matriz original debido a que es el formato mas conveniente para nuestro objetivo, existen varias tecnicas para esto pero la que usamos fue la siguiente:
    
    intensidad de pixel = 0.2989xrojo + 0.5870xverde + 0.1140xazul
    
Para reconstruir la imagen a partir de la matriz de escala de grises guardada en csv, utilizamos el código en python:

        from PIL import Image, ImageDraw
        from numpy import genfromtxt

        g = open('archivo.csv','r')
        temp = genfromtxt(g, delimiter = ',')
        im = Image.fromarray(temp).convert('RGB')
        im.show()

Todo lo anterior, lo realizamos con código secuencial en C, pero posteriormente lo intentamos en CUDA pero aun no terminamos el programa, sin embargo enviamos los avances (archivos kernel.h, kernel.cu, grayscale.cu)


### Referencias
http://pytorch.org/about/
https://www.analyticsvidhya.com/blog/2018/02/pytorch-tutorial/
