## Dockerfile proyecto equipo 9 MNO 2018
## Se incluye el soporte para nvidia-docker 
## y compilador nvcc

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