## Avance 2 Proyecto Final

### Equipo 4

### Integrantes
* Arturo González Bencomo - 172906
* Arturo Torre González - 90226

#### Arturo Torre González

Para este avance investigamos sobre módulos de visión artificial de alto desempeño, también avanzamos en la implementación de algoritmos de multiplicaciones matriciales en paralelo en CUDA.

OpenCV: Significa Open Computer Vision es una biblioteca libre de visión artificial originalmente desarrollada por Intel.

Dado que el objetivo del proyecto es la utilización de los GPUs para el procesamiento de imágenes, investigamos e instalamos el módulo OpenCV GPU.

El módulo de OpenCV GPU está escrito usando el desarrollo de CUDA para permitir usar la GPU para el procesamiento de datos A su vez el módulo GPU está diseñado como una extensión de API de host. Este diseño proporciona al usuario un control explícito sobre cómo se mueven los datos entre la CPU y la memoria de la GPU. Este enfoque es flexible y permite cálculos más eficientes.
Los módulos GPU incluyen la clase cv :: gpu :: GpuMat, que es un contenedor primario para los datos almacenados en la memoria de la GPU. Su interfaz es muy similar con cv :: Mat, su contraparte de CPU. Todas las funciones de GPU reciben GpuMat como argumentos de entrada y salida. Esto permite invocar varios algoritmos de GPU sin descargar datos. La interfaz API del módulo GPU también se mantiene similar con la interfaz de la CPU siempre que sea posible.

Requerimientos para instalar OpenCV

*	GCC 4.4.x: Compilador de codigo c 
*	CMake 2.8.7: Constructor de proyecto 
* Git: Manejador de control de versiones 
* GTK+2.x
* pkg-config
* Python 2.6: Lenguaje de programacion Python2.6
* Numpy 1.5: Módulo de computo numerico
* ffmpeg: Programa que puede grabar, transcodificar y hacer streaming de audio y video.
* CUDA Toolkit minimum version 6.5: Herramientas para cómputo en paralelo sobre GPU.
*	[opcional] libtbb2 libtbb-dev
*	[opcional] libdc1394 2.x
*	[opcional] libjpeg-dev, libpng-dev, libtiff-dev, libjasper-dev, libdc1394-22-dev

Si uno se cuenta con todas las paqueterías aquí enumeradas, puede proceder a la instalación de OpenCV.

1.- Descargar el programa desde el repositorio de github correspondiente.

https://github.com/opencv/opencv

2.- Construir el proyecto con la secuencia de comandos de ./configure, make, make install.


#### Arturo González Bencomo
Avanzamos con realizar algunos ejercicios básicos con cuda con los servicios de aws ec2, concretamente instanciamos una computadora del tipo g2.2xlarge y procedimos a instalar lo necesario en CUDA (Seguimos tutorial en repositorio 'ITAM-DS/analisis-numerico-computo-cientifico'). Concretamente realizamos una operación matricial de forma paralela. En el programa construimos dos matrices de tamaño 16x16, e hicimos la multiplicación correspondiente con CUDA, especificando un grid de 1 bloque con 256 threads que corresponden al total de operaciones producto-punto para obtener la matriz resultante. Para realizar este ejercicio nos basamos en un blog que brinda una guía para hacer multiplicaciones matriciales. 

### Referencias
https://opencv.org/
https://opencv.org/platforms/cuda.html
https://docs.opencv.org/trunk/d7/d9f/tutorial_linux_install.html
http://www.cplusplus.com/reference/vector/vector/
https://codeyarns.com/2011/02/16/cuda-dim3/
https://www.quantstart.com/articles/Matrix-Matrix-Multiplication-on-the-GPU-with-Nvidia-CUDA
