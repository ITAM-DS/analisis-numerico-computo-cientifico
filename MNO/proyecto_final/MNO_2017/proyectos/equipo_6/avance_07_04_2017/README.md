# Avance_07_04_2017

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez

## Trabajo:

### Individual

Adrián Vázquez (120028):

__Arquitectura del Proyecto:__ La arquitectura de referencia para el Proyecto PHPP esta representada en el siguiente diagrama:

![GitHub Logo](images/ArquitecturaReferencia-v1.0.png) 


__Implementación__


Se ejecutaron las siguientes [funciones](code) en CUDA-C para realizar una prueba de ejecucón de programa en CUDA-C con Docker.

Se elaboró y documento un [DOCKER_FILE y un DOCKER_COMPOSE](docker-cuda.md) para ejecución de programa [como sigue.](ambiente)

Se documentara mas MPI para distribución de archivos posteriormente como Erick nos comento.

Ricardo Lastra (160167):

Investigar el coste operativo de la implementación de los siguientes tipos de cluster:  (PONER DOCUMENTACION DE AWS Y VIABILIDAD DE USO)

	-CLUSTER TIPO A. DIRECTO EN PC CON TAREJETA NVIDIA
	-CLUSTER TIPO B. USANDO DOCKER COMPOSE PARA NODOS
	-CLUSTER TIPO C. USANDO MAQUINAS AWS (Contribución al material de MNO para el uso de AWS)


__Selección de Herramientas__


A partir del planteamiento anterior se investigo lo siguiente:

-Se usara el cluster tipo B. Se escribieron y se corrieron pruebas con [demo](code) de `suma.cu` y `matrix.cu` lo cual encontramos mas viable su uso por lo siguiente: 
	Sin costo en $
	Con docker se puede documentar muy bien todo el programa y su arquitectura
	Es fácil de compilar

-Se evaluo usar maquinas de AWS con AMI de CUDA 7.5 y se desarrollo lo siguiente:

Ya con una cuenta en Amazon Web Services se desarrollo el prender una maquina de la siguiente forma:

1-Se levanto una maquina EC2 siguiendo las instrucciones de la siguiente referencia:

[referencia](http://docs.aws.amazon.com/AWSEC2/latest/UserGuide/launching-instance.html)

2-Se integro AMI para usar CUDA 7.5 montada en una EC2 usando la siguiente referencia:

[referencia](https://aws.amazon.com/marketplace/pp/B01DCKFASQ)

3-Se levanto la EC2 t2.small de Bitfusion Boost Ubuntu 14 Cuda 7.5, en la siguiente IMAGEN se ve como esta en estatus "running"

![GitHub Logo](images/EC2_AMI_CUDA7.5.PNG) 

4-Para configurar el ambiente Amazon-Docker se siguió la siguiente referencia:

[referencia](https://docs.docker.com/machine/drivers/aws/#options)



### Equipo

Se determino usar docker-cuda-c para proyecto dado que existen ventajas como costos reducidos, documentacion a través de una herramienta conocida como lo es Docker, asi como la facilidad para compilar con nvcc matrix.cu -o matrix.out 
Se descarto el uso de AMAZON y sus AMIS con CUDA ya que el costo en DLLS es elevado para pruebas ya que cobran para 2 cores un aproximado mensual de $40 USD. 
Tambien encontramos que para el uso de AMAZON-Docker necesitabamos mas tiempo en la configuración final para ejecutar toda la plataforma, tiempo que decidimos usarlo en el algoritmo elegido.


## Comentarios sobre avance:

* Se realizó un buen avance en cuestión de implementación, ahora hay que hacer un buen avance en la teoría. 

* Muy bien con lo de nvidia-docker. Como entiendo se instalan los drivers de nvidia en tu máquina y luego se construye la imagen con el dockerfile que pusieron y se corre el run de la imagen para tener instalado el toolkit en tu contenedor y cuando entras al contenedor puedes ejecutar programas `*.cu` y usará la gpu de tu máquina, correcto?

* Este tiene un free trial de 5 días:

https://aws.amazon.com/marketplace/pp/B01DCKFASQ

les funciona? o quizás primero de forma local y luego una prueba ahí.

* En el trabajo individual de Ricardo se menciona en el punto 2 una referencia que te lleva al log-in de una cuenta de aws. Revisen esta referencia que ponen para que no te pida que loggees a una cuenta.

* Si la factorización a utilizar es SVD entonces hay que revisar teoría de la misma y sus implementaciones. Coloco referencias en el README.md del nivel proyectos/equipo_6

* Me gustaría ver cómo están los chunks de su dataset, es decir, en una carpeta tenemos `chunk1.txt`, `chunk2.txt`, etc? o es una matriz que tiene una columna que te indica el chunk? o cómo están divididos? Si tenemos archivos de chunks como el caso `chunk1.txt`, `chunk2.txt`, etc podríamos saltarnos lo de mpi y utilizar un sistema de colas como [sun grid engine](http://star.mit.edu/cluster/docs/0.93.3/guides/sge.html#)

## (Respuestas) Comentarios sobre avance:

* Es correcto el proceso de nvidia-docker como se menciona. Se usara la GPU de la maquina.

* Ya se probo el free trial, y aun así genera algunos costos por temas de levantar la EC2, se opta por la GPU local en la laptop de Adrian

* Se revisaron referencias, mismas que se hacen referencia en el avance de la siguiente semana [Avance 17-04-2017](avance_17_04_2017).

* Si se tendran los datos por `chunk1.txt`, `chunk2.txt`, etc, y en el avance de la siguiente semana [Avance 17-04-2017](avance_17_04_2017). se pondra lo que se reviso del sistema de colas [sun grid engine](http://star.mit.edu/cluster/docs/0.93.3/guides/sge.html#)

* Gracias por la atencion y observaciones.

