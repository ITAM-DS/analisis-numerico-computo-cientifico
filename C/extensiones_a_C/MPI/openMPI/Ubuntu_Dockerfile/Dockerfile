# Modificación a Dockerfile para MacOS:
# https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/MPI/openMPI
# 2017_04_26
# Mantainer: Camilo Abboud Schael

# El Dockerfile fue modificado para: 
# Ubuntu 16.04
# Docker version 1.13.1 

FROM ubuntu:14.04
RUN apt-get update -y && apt-get install -y build-essential \
	nano \
	man \
	openssh-server
RUN groupadd mpi_user
RUN useradd mpi_user -g mpi_user -m -s /bin/bash
ADD openmpi-2.0.2.tar.gz /opt/
RUN cd /opt &&  chown -hR mpi_user:mpi_user openmpi-2.0.2.tar
RUN sudo tar -xf /opt/openmpi-2.0.2.tar -C /opt ### UNZIP EN CARPETA OPT
RUN mkdir -p /var/run/sshd
RUN echo "mpi_user ALL=(ALL:ALL) NOPASSWD:ALL" | (EDITOR="tee -a" visudo)
RUN echo "mpi_user:mpi" | chpasswd
USER mpi_user
RUN cd /opt/openmpi-2.0.2 && sudo ./configure --prefix=/opt/openmpi-2.0.2 -with-sge && sudo make all install #sudo 
ENV PATH="/opt/openmpi-2.0.2/bin:$PATH"
ENV LD_LIBRARY_PATH="/opt/openmpi-2.0.2/lib:LD_LIBRARY_PATH"