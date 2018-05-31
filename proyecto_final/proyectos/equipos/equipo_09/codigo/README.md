Equipo 9 
=================================================

Integrantes
---------------------------------------------------
+ Karen Peña (175952)
+ Miguel Catañeda (175840)
+ Fernando Briseño (171349)


**Título del proyecto:** Mínimos Cuadrados usando la Factorización QR y CUDA

**Objetivo del proyecto:** Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo



Instrucciones para compilar el proyecto. 

Para facilitar el proceso de compilación, ejecución y pruebas y no alterar el ambiente actual de trabajo definimos una imagen de Docker con los paquetes necesarios para el proyecto de CUDA. 


Para el caso de CUDA se utiliza una computadora con tarjeta NVIDIA GeForce 940MX con 2 Mb de memoria y 384 cores CUDA. 

Para configurar el contenedor es necesario realizar la instalación del driver de CUDA en nuestro caso usamos la versión 
384.111 del driver, adicionalmente se configura nvidia docker utilizando las indicaciones de la URL [Docker NVIDIA](https://github.com/NVIDIA/nvidia-docker). 

```
ARG cuda_version=9.0
ARG cudnn_version=7
FROM nvidia/cuda:${cuda_version}-cudnn${cudnn_version}-devel

LABEL maintainer="Equipo 9 MNO 2018 - CUDA"

RUN apt-get update -y && apt-get install -y build-essential \
	    nano \
        vim \
	    man \
        libblas-dev \
        liblapack-dev \
        sudo \
        bzip2 \
        git \
        libgl1-mesa-glx \
        libhdf5-dev \
        openmpi-bin \
        wget \
	openssh-server 

RUN mkdir -p /var/run/sshd
RUN groupadd mno_user
RUN useradd mno_user -g mno_user -m -s /bin/bash  
RUN echo "mno_user ALL=(ALL:ALL) NOPASSWD:ALL" | (EDITOR="tee -a" visudo)
RUN echo "mno_user:mno" | chpasswd
```
[Dockerfile](CUDA/Dockerfile)

Para el proyecto configuramos el contenedor con la versión de CUDA 9 y la versión 7 de Cudnn, estos valores se pueden ajustar desde los parámetros ARG en caso de ser requeridos, adicionalmente este contenedor tambien se puede utilizar para OpenMP.

Para construir se debe ejecutar

```
docker build -t mno_cuda_gcc . 
```

[Script](CUDA/construye.sh)

Para probar la instalación:

```
nvidia-docker run --runtime=nvidia --rm mno_cuda_gcc nvidia-smi
```
Con el resultado: 

```
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 384.111                Driver Version: 384.111                   |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|===============================+======================+======================|
|   0  GeForce 940MX       Off  | 00000000:01:00.0 Off |                  N/A |
| N/A   39C    P8    N/A /  N/A |    159MiB /  2002MiB |     11%      Default |
+-------------------------------+----------------------+----------------------+
                                                                               
+-----------------------------------------------------------------------------+
| Processes:                                                       GPU Memory |
|  GPU       PID   Type   Process name                             Usage      |
|=============================================================================|
+-----------------------------------------------------------------------------+
```

Verificamos la versión del compilador: 

```
nvidia-docker run --runtime=nvidia --rm mno_cuda_gcc nvcc --version
```

Con el resultado: 

```
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2017 NVIDIA Corporation
Built on Fri_Sep__1_21:08:03_CDT_2017
Cuda compilation tools, release 9.0, V9.0.176
```

Probando el queryDevice tenemos el resultado con las caracteristicas de la tarjeta: 

```
 CUDA Device Query (Runtime API) version (CUDART static linking)

Detected 1 CUDA Capable device(s)

Device 0: "GeForce 940MX"
  CUDA Driver Version / Runtime Version          9.0 / 9.0
  CUDA Capability Major/Minor version number:    5.0
  Total amount of global memory:                 2003 MBytes (2100232192 bytes)
  ( 3) Multiprocessors, (128) CUDA Cores/MP:     384 CUDA Cores
  GPU Max Clock rate:                            1189 MHz (1.19 GHz)
  Memory Clock rate:                             2000 Mhz
  Memory Bus Width:                              64-bit
  L2 Cache Size:                                 1048576 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(65536), 2D=(65536, 65536), 3D=(4096, 4096, 4096)
  Maximum Layered 1D Texture Size, (num) layers  1D=(16384), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(16384, 16384), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  2048
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 1 copy engine(s)
  Run time limit on kernels:                     Yes
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Disabled
  Device supports Unified Addressing (UVA):      Yes
  Device PCI Domain ID / Bus ID / location ID:   0 / 1 / 0
  Compute Mode:
     < Default (multiple host threads can use ::cudaSetDevice() with device simultaneously) >

deviceQuery, CUDA Driver = CUDART, CUDA Driver Version = 9.0, CUDA Runtime Version = 9.0, NumDevs = 1, Device0 = GeForce 940MX
Result = PASS
```

Probamos compilar un programa 

Iniciamos el contenedor en la ruta *codigo* que es donde se encuntran los programas. 

```
nvidia-docker run -dit -v $PWD:/programas  --name=mno_cuda_gpu  mno_cuda_gcc
```

Para compilar hay que conectarse al contenedor: 

```
nvidia-docker exec -it mno_cuda_gpu /bin/bash
```

Para compilar y ejecutar el programa, ejecuté dentro de la carpeta programas, haciendo que lea las matrices desde los archivos A.txt y B.txt

```
make compila
```

[Makefile](Makefile)

[MCQR.cu](MCQR.cu)

[A.txt](A.txt)

[B.txt](B.txt)



```
./MCQR.out 10
```

Con el siguiente resultado: 

```
root@f66d6cd75b2e:/programas# ./MCQR.out 10 
matriz[0][0]=1.00000	matriz[0][1]=5.00000	matriz[0][2]=7.00000	matriz[0][3]=7.00000	matriz[0][4]=8.00000	matriz[0][5]=6.00000	matriz[0][6]=5.00000	matriz[0][7]=1.00000	matriz[0][8]=8.00000	matriz[0][9]=4.00000
matriz[1][0]=1.00000	matriz[1][1]=4.00000	matriz[1][2]=2.00000	matriz[1][3]=1.00000	matriz[1][4]=5.00000	matriz[1][5]=6.00000	matriz[1][6]=8.00000	matriz[1][7]=1.00000	matriz[1][8]=2.00000	matriz[1][9]=10.00000
matriz[2][0]=1.00000	matriz[2][1]=2.00000	matriz[2][2]=9.00000	matriz[2][3]=6.00000	matriz[2][4]=3.00000	matriz[2][5]=8.00000	matriz[2][6]=7.00000	matriz[2][7]=7.00000	matriz[2][8]=7.00000	matriz[2][9]=1.00000
matriz[3][0]=1.00000	matriz[3][1]=4.00000	matriz[3][2]=3.00000	matriz[3][3]=1.00000	matriz[3][4]=1.00000	matriz[3][5]=9.00000	matriz[3][6]=5.00000	matriz[3][7]=9.00000	matriz[3][8]=8.00000	matriz[3][9]=5.00000
matriz[4][0]=1.00000	matriz[4][1]=3.00000	matriz[4][2]=9.00000	matriz[4][3]=1.00000	matriz[4][4]=1.00000	matriz[4][5]=5.00000	matriz[4][6]=7.00000	matriz[4][7]=7.00000	matriz[4][8]=4.00000	matriz[4][9]=4.00000
matriz[5][0]=1.00000	matriz[5][1]=9.00000	matriz[5][2]=2.00000	matriz[5][3]=1.00000	matriz[5][4]=5.00000	matriz[5][5]=8.00000	matriz[5][6]=1.00000	matriz[5][7]=8.00000	matriz[5][8]=4.00000	matriz[5][9]=3.00000
matriz[6][0]=1.00000	matriz[6][1]=5.00000	matriz[6][2]=8.00000	matriz[6][3]=8.00000	matriz[6][4]=1.00000	matriz[6][5]=2.00000	matriz[6][6]=8.00000	matriz[6][7]=4.00000	matriz[6][8]=9.00000	matriz[6][9]=3.00000
matriz[7][0]=1.00000	matriz[7][1]=1.00000	matriz[7][2]=10.00000	matriz[7][3]=0.00000	matriz[7][4]=4.00000	matriz[7][5]=0.00000	matriz[7][6]=7.00000	matriz[7][7]=2.00000	matriz[7][8]=7.00000	matriz[7][9]=9.00000
matriz[8][0]=1.00000	matriz[8][1]=6.00000	matriz[8][2]=1.00000	matriz[8][3]=8.00000	matriz[8][4]=8.00000	matriz[8][5]=10.00000	matriz[8][6]=4.00000	matriz[8][7]=8.00000	matriz[8][8]=10.00000	matriz[8][9]=9.00000
matriz[9][0]=1.00000	matriz[9][1]=7.00000	matriz[9][2]=5.00000	matriz[9][3]=8.00000	matriz[9][4]=7.00000	matriz[9][5]=2.00000	matriz[9][6]=10.00000	matriz[9][7]=6.00000	matriz[9][8]=2.00000	matriz[9][9]=7.00000

matriz[0][0]=8.00000
matriz[1][0]=3.00000
matriz[2][0]=0.00000
matriz[3][0]=5.00000
matriz[4][0]=2.00000
matriz[5][0]=4.00000
matriz[6][0]=1.00000
matriz[7][0]=9.00000
matriz[8][0]=1.00000
matriz[9][0]=2.00000

=======================
Solución X
matriz[0][0]=-44.60949
matriz[1][0]=2.77735
matriz[2][0]=0.71198
matriz[3][0]=-3.27124
matriz[4][0]=2.28649
matriz[5][0]=0.51952
matriz[6][0]=3.52443
matriz[7][0]=-0.19927
matriz[8][0]=2.70624
matriz[9][0]=-0.96109
=======================

```

Es importante que si se compila el programa sin el contenedor se debe utilizar la versión 9 de CUDA. 






