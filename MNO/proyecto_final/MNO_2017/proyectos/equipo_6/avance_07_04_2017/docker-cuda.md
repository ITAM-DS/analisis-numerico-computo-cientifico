#+Title:     Docker NVIDIA
#+Author:    Adrian Vázquez
#+Email:     radianstk@gmail.com
#+DATE:      2017
#+DESCRIPTION: Generación de Imagen CUDA para NVIDIA versión 8.0
#+KEYWORDS:  CUDA parallel 
#+LANGUAGE:  en

#+STARTUP: beamer
#+STARUP: oddeven

#+LaTeX_CLASS: beamer
#+LaTeX_CLASS_OPTIONS: [presentation, smaller]

#+BEAMER_THEME: DarkConsole

#+OPTIONS: H:1 toc:nil 

#+SELECT_TAGS: export
#+EXCLUDE_TAGS: noexport

#+COLUMNS: %20ITEM %13BEAMER_env(Env) %6BEAMER_envargs(Args) %4BEAMER_col(Col) %7BEAMER_extra(Extra)


* ¿por que Docker y ENVIDIA?
#+BEGIN_QUOTE
- Facil reproducir el ambiente *cuda ENVIDIA*
- Habilitación de ambiete de desarrollo facilmente
- Instalación de drivers ENVIDIA unicamente
#+END_QUOTE


* Implementacación Imagen: MNO-CUDA/CUDA 8.0

![nvidia-gpu-docker](https://cloud.githubusercontent.com/assets/3028125/12213714/5b208976-b632-11e5-8406-38d379ec46aa.png)

- /NVIDIA GPU DOCKER/, [[https://cloud.githubusercontent.com/assets/3028125/12213714/5b208976-b632-11e5-8406-38d379ec46aa.png][NVIDIA]] 

#+BEGIN_QUOTE
The *NVIDIA® CUDA®* Toolkit provides a comprehensive development environment for C and C++ developers building GPU-accelerated applications. The CUDA Toolkit includes a compiler for NVIDIA GPUs, math libraries, and tools for debugging and optimizing the performance of your applications. You’ll also find programming guides, user manuals, API reference, and other documentation to help you get started quickly accelerating your application with GPUs. 
#+END_QUOTE

[[https://developer.nvidia.com/cuda-toolkit][NVIDIA Toolkit]]


* Dockerfile 
#+BEGIN_QUOTE

ROM ubuntu:14.04

MAINTAINER Adrián Vázquez <radianstk@gmail.com>

ENV REFRESHED_AT 2017-04-06

## Actualizamos
RUN \
    apt-get -qq update; apt-get upgrade -y -qq; \
    apt-get install -y -qq wget curl git jq nano man openssh-server; \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Arreglamos el LOCALE
RUN echo "es_MX.UTF-8 UTF-8" >> /etc/locale.gen \
    && locale-gen es_MX.utf8 \
    && /usr/sbin/update-locale LANG=es_MX.UTF-8 \
    && dpkg-reconfigure locales

RUN groupadd cuda_user

RUN useradd cuda_user -g cuda_user -m -s /bin/bash

ADD cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64.deb /tmp/

RUN dpkg -i /tmp/cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64.deb

## Instalamos CUDA
RUN \
    apt-get -qq update; apt-get upgrade -y -qq; \
    apt-get install -y -qq cuda; \
    apt-get clean

## Limpiamos tmp
    && rm -fr /tmp/*

RUN echo "cuda_user ALL=(ALL:ALL) NOPASSWD:ALL" | (EDITOR="tee -a" visudo)

RUN echo "cuda_user:cuda" | chpasswd

USER cuda_user

ENV PATH="/usr/local/cuda-8.0/bin:$PATH"

ENV LD_LIBRARY_PATH="/usr/local/cuda-8.0/lib64:LD_LIBRARY_PATH"

CMD ["/bin/bash"]

#+END_QUOTE
[[file:docker-images/Dockerfile]]

* Construimos la Imagen
#+BEGIN_QUOTE

- docker build -t cuda_mno/cuda:v1 . 

#+END_QUOTE
[[file:images/docker-images.png]]


* Construimos el contenedor
#+BEGIN_QUOTE

- nvidia-docker run -ti -v /home/radianv/optimizacion/CUDA:/CUDA-LOCAL -h mno-cuda --name mno-cuda cuda_mno/cuda:v1

#+END_QUOTE
[[file:images/docker-container.png]]


by ADVP
