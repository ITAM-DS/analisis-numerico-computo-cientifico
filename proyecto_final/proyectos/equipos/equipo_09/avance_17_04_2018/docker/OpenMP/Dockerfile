## Dockerfile proyecto equipo 9 MNO 2018
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