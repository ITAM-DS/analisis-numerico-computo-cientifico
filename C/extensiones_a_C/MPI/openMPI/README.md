# Levantar un cluster de forma pseudo distribuida con openmpi y docker

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

Si observan las líneas de este Dockerfile es necesario que se encuentre en esta ruta el archivo: [openmpi-2.0.2.tar.gz](https://www.open-mpi.org/software/ompi/v2.0/). Modifiquen lo necesario en este Dockerfile si existe otra versión.

Revisamos:

```
$ls /home/docker_mpi/
Dockerfile 			openmpi-2.0.2.tar.gz
```

Cambiamos a la ruta `/home/docker_mpi/` y construímos la imagen con nombre `openmpi_mno/openmpi:v1`:

```
$cd /home/docker_mpi/
$docker build -t openmpi_mno/openmpi:v1 .
```

Probablemente tengan que añadir un `sudo` o si están en un sistema Mac OS X/ Windows e instalaron docker (no versión beta) tengan que añadir `$(docker-machine config default)` dependiendo del nombre de la máquina virtual que levantaron para usar docker, por ejemplo `default`:

```
$cd /home/docker_mpi/
$docker $(docker-machine config default) build -t openmpi_mno/openmpi:v1 .
```

Una vez construída esta imagen (teniendo un `Successfully build`) es recomendable crear un directorio en el que estén los programas de mpi. Por ejemplo:

```
$cd /home/docker_mpi/
$mkdir /home/docker_mpi/ejemplos_mpi
```

Ejecuten en la línea de comandos:

```
$docker run -dit -v /home/docker_mpi/ejemplos_mpi:/results -p 22 -h master --name master_container openmpi_mno/openmpi:v1 /bin/bash
```

El comando anterior levanta un contenedor con nombre `master_container` utilizando la imagen `openmpi_mno/openmpi:v1` y el nombre del host es `master`.

Para levantar otro contenedor con nombre `nodo1_container` y nombre de host `nodo1` ejecuten en la línea de comandos (estando en la misma ruta de `/home/docker_mpi/ejemplos_mpi`:

```
$docker run -dit -v /home/docker_mpi/ejemplos_mpi:/results -p 22 -h nodo1 --name nodo1_container openmpi_mno/openmpi:v1 /bin/bash
```

Revisen las ip de cada contenedor haciendo:

```
$docker inspect master_container|grep IPA
```

```
$docker inspect nodo1_container|grep IPA
```

Supongamos que la ip del `master_container` es `172.17.0.2` y del `nodo1_container` es `172.17.0.3`. 

Entren al `master_container` haciendo:

```
$docker exec -it master_container /bin/bash
```

Reinicien servicio ssh:

```
mpi_user@master:/$sudo service ssh restart
```

Modifiquen el archivo `/etc/hosts` escribiendo después de la última línea de este archivo la ip del `nodo1_container`:

```
...
172.17.0.3 nodo1
```

Generen una llave:

```
mpi_user@master:~$ssh-keygen
```

Den `enter` (poco seguro, en cuestión de autentificación) hasta que obtengan una llave generada en la ruta:

```
/home/mpi_user/.ssh/id_rsa.pub
```

Salgan del master, entren al `nodo1_container`, reinicien servicio ssh y entren nuevamente al master:

```
mpi_user@master:/$exit
$docker exec -it nodo1_container /bin/bash
mpi_user@nodo1:/$sudo service ssh restart
mpi_user@nodo1:/$exit
$docker exec -it master /bin/bash
```

Copien la llave al `nodo1_container`:

```
mpi_user@master:/$ ssh-copy-id -i /home/mpi_user/.ssh/id_rsa.pub mpi_user@nodo1
```

Escriban el password `mpi` y entren al `nodo1_container` con:

```
mpi_user@master:/$ssh mpi_user@nodo1
```

no les debe de pedir password:

```
mpi_user@master:/$ ssh mpi_user@nodo1
Welcome to Ubuntu 14.04.4 LTS (GNU/Linux 4.1.19-boot2docker x86_64)

 * Documentation:  https://help.ubuntu.com/
Last login: Fri Mar 17 01:58:47 2017 from master
mpi_user@nodo1:~$
```

Listo! Ya tienen un clúster de forma pseudo distribuida con openmpi y docker :). Los programas serán ejecutados desde el `master_container`, si quieren también ejecutarlos desde el `nodo1_container` deben de realizar los pasos que hicimos para el `master_container` en el `nodo1_container`.

