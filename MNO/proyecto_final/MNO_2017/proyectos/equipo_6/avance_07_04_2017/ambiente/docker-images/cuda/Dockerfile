FROM ubuntu:14.04

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
