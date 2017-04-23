---
title: "MPI usando SWARM, Docker, Compose"
author: "Oscar Camarena, Maximiliano Alvarez"
date: "17 de abril de 2017"
output: html_document
---

##Primero hagamos nuestro Dockerfile

```{}
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

RUN cd /opt/openmpi-2.0.2 && ./configure--enable-orterun-prefix-by-default -with-sge && make all install

ENV PATH="/opt/openmpi-2.0.2/bin:$PATH"

ENV LD_LIBRARY_PATH="/opt/openmpi-2.0.2/lib:LD_LIBRARY_PATH"

RUN cd ~

ADD hello.c /home/mpi_user/

RUN cd /home/mpi_user && mpicc hello.c -o hello.out

EXPOSE 22

ENTRYPOINT ["/bin/bash"]

#docker build -t johnydickens/openmpi:v1 .

```

Nos vamos a la ruta de nuestro archivo *Dockerfile* y lo construimos

```{}
docker build -t johnydickens/openmpi:v2 .
```

Lo publicamos en *Docker Hub*

```{}
docker push johnydickens/openmpi:v2
```

##Levantemos las instancias en *AWS*

```{}
$Env:MACHINE_DRIVER="amazonec2"
$Env:AWS_ACCESS_KEY_ID=""
$Env:AWS_SECRET_ACCESS_KEY=""
$Env:AWS_DEFAULT_REGION="us-west-1"
$Env:AWS_INSTANCE_TYPE="t2.micro"


for ($i=1; $i -le 3; $i++){
docker-machine create mpi-node$i                            
docker-machine ssh mpi-node$i sudo usermod -aG docker ubuntu
}  
```

Obtenemos la IP de *mpi-node1*

```{}
docker-machine ip mpi-node1
52.53.178.231
```

Nos conecamos a *mpi-node1* e iniciamos SWARM

```{}
docker-machine ssh mpi-node1

docker swarm init --advertise-addr 52.53.178.231
```

Nos salimos y conectamos todos los *workers* al *master*

```{}
for($i=2; $i -le 3; $i++){
   & "C:\Program Files\Docker\Docker\Resources\bin\docker-machine.exe" env mpi-node$i | Invoke-Expression 
   docker swarm join --token   SWMTKN-1-4b03qhiq7tfsgwy3f4gbpxt54h4lwx4zeqo766p8u6cp5eq5sb-6yqbxrvzd6x1n91lpb4cav9lv 52.53.178.231:2377
}
```

Nos conectamos nuevamente a *mpi-node1* y hacemos una red con **driver** *overlay*

```{}
docker network create --driver overlay mpi
docker network ls
```

Creamos nuestro *swarm-docker-compose.yml* en *mpi-node1*

*swarm-docker-compose.yml*

```{}
version: "3"
 
services:
 
  master:
    image: johnydickens/openmpi:v2
    entrypoint: /bin/bash
    ports:
      - 22:22
    networks:
      - mpi
    stdin_open: true
    tty: true
    
  nodo1:
    image: johnydickens/openmpi:v2
    entrypoint: /bin/bash
    ports:
      - 22:22
    networks:
      - mpi
    stdin_open: true
    tty: true

  nodo2:
    image: johnydickens/openmpi:v2
    entrypoint: /bin/bash
    ports:
      - 22:22
    networks:
      - mpi
    stdin_open: true
    tty: true

      
networks:
  mpi:
    external: true

```

Hacemos deploy

```{}
docker stack deploy -c swarm-docker-compose.yml mpi
```

Hay que abrir el puerto 7946 en AWS para que los nodos se puedan ver por el *docker-network*

Reiniciemos el servicio ssh de cada container...
```{}
sudo service ssh restart
```

Luego hacemos nuestra llave ssh desde el nodo que sera el maestro

```{}
ssh-keygen
```

Y la pegamos en los demas nodos

```{}
ssh-copy-id mpi_user@mpi_master
```

Cuando podemos ver todos los nodos ejecutamos nuestro programa
```{}
mpirun --prefix /opt/openmpi-2.0.2/ -n 3 -H mpi_master,mpi_nodo1,mpi_nodo2 hello.out
```
