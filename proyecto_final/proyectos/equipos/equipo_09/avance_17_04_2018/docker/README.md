# Avance_17_04_2018

Equipo 9 
=================================================
**Título del proyecto:** Factorización QR

**Objetivo del proyecto:** Implementar el algoritmo QR para el lenguaje de programación C bajo un enforque de programación en paralelo


Integrantes
---------------------------------------------------
+ Karen Peña (175952)
+ Miguel Catañeda (175840)
+ Fernando Briseño (171349)


## Configuración de ambiente OpenMP

Para el caso de **OpenMP** hice la configuración con la versión 

`
FROM ubuntu:16.04

LABEL maintainer="Equipo 9 MNO 2018"

RUN apt-get update -y && apt-get install -y build-essential \
	nano \
    vim \
	man \
    libblas-dev \
    liblapack-dev \
    sudo \
	openssh-server 

RUN mkdir -p /var/run/sshd
RUN groupadd mno_user
RUN useradd mno_user -g mno_user -m -s /bin/bash  
RUN echo "mno_user ALL=(ALL:ALL) NOPASSWD:ALL" | (EDITOR="tee -a" visudo)
RUN echo "mno_user:mno" | chpasswd
`
[Dockerfile](OpenMP/Dockerfile)

Para construir la imagen se debe ejecutar dentro de la carpeta OpenMP

`
docker build -t mno_gcc . 
`

[Script](OpenMP/construye.sh)

Probar la configuración: 

Para iniciar el contenedor se debe ejecutar:

`
docker run -dit -v $PWD:/programas --name=mno_2018 mno_gcc  
`

Para compilar un programa [trapecio.c](OpenMP/trapecio.c)

`
docker exec -it mno_2018 gcc -Wall -fopenmp /programas/trapecio.c -o /programas/trapecio.out -lm
`

Se ejecuta el programa: 

`
docker exec -it mno_2018 /programas/trapecio.out 20
`

El resultado es: 

`
Integral de -1.000000 a 3.000000 = 1.971765762916818e+01
Error relativo de la solución: 7.462953360883524e-09
`

## Configuración de ambiente CUDA

Para el caso de CUDA se utiliza una computadora con tarjeta NVIDIA GeForce 940MX con 2 Mb de memoria y 384 cores CUDA. 

Para configurar el contenedor es necesario realizar la instalación del driver de CUDA en nuestro caso usamos la versión 
384.111 del driver, adicionalmente se configura nvidia docker utilizando la url [Docker NVIDIA](https://github.com/NVIDIA/nvidia-docker). 

`
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
`
[Dockerfile](CUDA/Dockerfile)

Para el proyecto configuramos el contenedor con la versión de CUDA 9 y la versión 7 de Cudnn, estos valores se pueden ajustar desde los parámetros ARG en caso de ser requeridos, adicionalmente este contenedor tambien se puede utilizar para OpenMP.

Para construir se debe ejecutar

`
docker build -t mno_cuda_gcc . 
`

[Script](CUDA/construye.sh)

Para probar la instalación:

`
nvidia-docker run --runtime=nvidia --rm mno_cuda_gcc nvidia-smi
`
Con el resultado: 

`
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
`

Verificamos la versión del compilador: 

`
nvidia-docker run --runtime=nvidia --rm mno_cuda_gcc nvcc --version
`

Con el resultado: 

`
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2017 NVIDIA Corporation
Built on Fri_Sep__1_21:08:03_CDT_2017
Cuda compilation tools, release 9.0, V9.0.176
`

Probando el queryDevice tenemos el resultado con las caracteristicas de la tarjeta: 

`
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
`

Probamos compilar un programa 

Iniciamos el contenedor 

`
nvidia-docker run -dit -v $PWD:/programas  --name=mno_cuda_gpu  mno_cuda_gcc
`

Compilamos:

`
nvidia-docker exec -it mno_cuda_gpu nvcc /programas/suma_vectorial.cu -o suma_vectorial.out
`

Ejecutamos:

`
nvidia-docker exec -it mno_cuda_gpu  /programas/suma_vectorial.out 10
`

Con resultado: 

`
0+0 = 0
1+1 = 2
2+4 = 6
3+9 = 12
4+16 = 20
5+25 = 30
6+36 = 42
7+49 = 56
8+64 = 72
9+81 = 90
`


