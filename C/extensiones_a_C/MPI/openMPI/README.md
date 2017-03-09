#Levantar un cluster con openmpi y docker

Si queremos en nuestros sistemas levantar un cluster de forma pseudo distribuida (es decir, nuestros nodos estarán en nuestra máquina local) es necesario tener [docker](https://www.docker.com/) instalado.

Usaremos una imagen de docker construída con el siguiente Dockerfile para instalar [openmpi](https://www.open-mpi.org/):

```
FROM ubuntu:14.04
RUN apt-get update -y && apt-get install -y build-essential \
	nano \
	man \
	openssh-server
RUN groupadd mpi_user
RUN useradd mpi_user -g mpi_user -m -s /bin/bash
ADD openmpi-2.0.2.tar.gz /opt/
RUN cd /opt && chown -hR mpi_user:mpi_user openmpi-2.0.2
RUN mkdir -p /var/run/sshd
RUN echo "mpi_user ALL=(ALL:ALL) NOPASSWD:ALL" | (EDITOR="tee -a" visudo)
RUN echo "mpi_user:mpi" | chpasswd
USER mpi_user
RUN cd /opt/openmpi-2.0.2 && ./configure --prefix=/opt/openmpi-2.0.2 -with-sge && make all install
ENV PATH="/opt/openmpi-2.0.2/bin:$PATH"
ENV LD_LIBRARY_PATH="/opt/openmpi-2.0.2/lib:LD_LIBRARY_PATH"
```

El Dockerfile anterior debe estar en una carpeta, por ejemplo:

```
$/home/docker_mpi/
```

Si observan las líneas de este Dockerfile es necesario que se encuentre en esta ruta, el archivo: [openmpi-2.0.2.tar.gz](https://www.open-mpi.org/software/ompi/v2.0/). Modifiquen lo necesario en este Dockerfile si existe otra versión.

Revisamos:

```
$ls /home/docker_mpi/
Dockerfile 			openmpi-2.0.2.tar.gz
```

Cambiamos a la ruta /home/docker_mpi/ y construímos:

```
$cd /home/docker_mpi/
$docker build -t openmpi_mno_2017/openmpi:v1 .
```

Probablemente tengan que añadir un `sudo` o si están en un sistema Mac OS X/ Windows e instalaron docker (no versión beta) tengan que añadir `$(docker-machine config default)` dependiendo del nombre de la máquina virtual que levantaron para usar docker, por ejemplo `default`.







