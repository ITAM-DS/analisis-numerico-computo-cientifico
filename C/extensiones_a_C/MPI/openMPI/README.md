# Levantar un cluster de forma pseudo distribuida con openmpi y docker

Si queremos en nuestros sistemas levantar un cluster de forma pseudo distribuida (es decir, nuestros nodos estarán en nuestra máquina local) es necesario tener [docker](https://www.docker.com/) instalado.

Si tienen una instancia en AWS con una imagen de ubuntu 16.04 se puede usar el siguiente script para el launching de la instancia (12gb son suficientes) y se realice: instalación de docker, creación de imagen de openmpi y creación de la network a usar en cada contenedor `ompi-network` e identificar a su instancia: **(de hecho este bash-script serviría para crear una imagen de AWS)**

```
#!/bin/bash
region=us-west-2
name_instance=ompi-node
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
# Adding docker repository.
add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
apt-get update
apt-cache policy docker-ce
apt-get install -y docker-ce nano awscli
service docker start
service ssh start
INSTANCE_ID=$(curl -s http://169.254.169.254/latest/meta-data/instance-id)
PUBLIC_IP=$(curl -s http://169.254.169.254/latest/meta-data/public-ipv4)
aws ec2 create-tags --resources $INSTANCE_ID --tag Key=Name,Value=$name_instance-$PUBLIC_IP --region=$region

mkdir -p /home/ubuntu/docker_mpi/
chmod gou+wxr /home/ubuntu/docker_mpi/
echo -e "FROM ubuntu:xenial \n
RUN apt-get update -y && apt-get install -y build-essential \
	nano \
	man \
	sudo \
	openssh-server \
	sshpass \n
RUN groupadd mpi_user \n
RUN useradd mpi_user -g mpi_user -m -s /bin/bash \n
ARG file_ompi=\$file_ompi \n
ARG dir_ompi=\$dir_ompi \n
RUN mkdir -p /home/mpi_user/openmpi/installation \n
RUN if [ ! -d "/home/mpi_user/openmpi/installation/\$dir_ompi" ]; then mkdir -p /home/mpi_user/openmpi/installation/; wget https://www.open-mpi.org/software/ompi/v3.0/downloads/\$file_ompi -P /home/mpi_user/openmpi/installation; cd /home/mpi_user/openmpi/installation && tar -xzvf \$file_ompi;fi \n
ARG inst_ompi=\$inst_ompi \n
RUN cd /home/mpi_user/openmpi/installation && chown -hR mpi_user:mpi_user \$dir_ompi \n
RUN mkdir -p /var/run/sshd \n
RUN echo 'mpi_user ALL=(ALL:ALL) NOPASSWD:ALL' | (EDITOR='tee -a' visudo) \n
RUN echo 'mpi_user:mpi' | chpasswd \n
USER mpi_user \n
RUN cd \$inst_ompi/ && ./configure --prefix=\$inst_ompi -with-sge && make all install \n
ENV PATH=\$inst_ompi/bin:\$PATH \n
ENV LD_LIBRARY_PATH=\$inst_ompi/lib:\$LD_LIBRARY_PATH \n" > /home/ubuntu/docker_mpi/Dockerfile

cd /home/ubuntu/docker_mpi/
file_ompi=$(wget https://www.open-mpi.org/software/ompi/v3.0/downloads/ -q -O -|grep -m 1 .tar.gz|sed -n 's/.*"\(openmpi.*\)".*/\1/;p')
dir_ompi=$(basename -s ".tar.gz" $file_ompi)
inst_ompi=/home/mpi_user/openmpi/installation/$dir_ompi
sudo docker build --build-arg file_ompi=$file_ompi --build-arg dir_ompi=$dir_ompi --build-arg inst_ompi=$inst_ompi -t openmpi_mno/openmpi:v1 .
echo "inst_ompi=$inst_ompi" >> /home/ubuntu/.profile
mkdir -p /home/ubuntu/openmpi_ejemplos
chmod gou+wrx /home/ubuntu/openmpi_ejemplos
sudo docker network create -d bridge --subnet 172.18.0.1/16 ompi-network

```


Supondremos un sistema ubuntu 16.04 en el que se tiene un user `ubuntu` y usaremos una imagen de docker construída con el siguiente Dockerfile para instalar [openmpi](https://www.open-mpi.org/):

```
FROM ubuntu:xenial
RUN apt-get update -y && apt-get install -y build-essential \
	nano \
	man \
	sudo \
	openssh-server \
	sshpass
RUN groupadd mpi_user
RUN useradd mpi_user -g mpi_user -m -s /bin/bash
ARG file_ompi=$file_ompi
ARG dir_ompi=$dir_ompi
RUN mkdir -p /home/mpi_user/openmpi/installation
RUN if [ ! -d "/home/mpi_user/openmpi/installation/$dir_ompi" ]; then mkdir -p /home/mpi_user/openmpi/installation/; wget https://www.open-mpi.org/software/ompi/v3.0/downloads/$file_ompi -P /home/mpi_user/openmpi/installation; cd /home/mpi_user/openmpi/installation && tar -xzvf $file_ompi;fi
ARG inst_ompi=$inst_ompi
RUN cd /home/mpi_user/openmpi/installation && chown -hR mpi_user:mpi_user $dir_ompi
RUN mkdir -p /var/run/sshd
RUN echo "mpi_user ALL=(ALL:ALL) NOPASSWD:ALL" | (EDITOR="tee -a" visudo)
RUN echo "mpi_user:mpi" | chpasswd
USER mpi_user
RUN cd $inst_ompi/ && ./configure --prefix=$inst_ompi -with-sge && make all install
ENV PATH=$inst_ompi/bin:$PATH
ENV LD_LIBRARY_PATH=$inst_ompi/lib:$LD_LIBRARY_PATH
```

El Dockerfile anterior debe estar en una carpeta, por ejemplo: **(OJO: esta ruta está creada en el sistema, existe un user llamado ubuntu, deben modificar lo respectivo para cada persona)**

```
/home/ubuntu/docker_mpi/
```


Revisamos:

```
ls /home/ubuntu/docker_mpi/
Dockerfile 			
```

Cambiamos a la ruta `/home/ubuntu/docker_mpi/` y construímos la imagen con nombre `openmpi_mno/openmpi:v1`:



```
cd /home/ubuntu/docker_mpi/
file_ompi=$(wget https://www.open-mpi.org/software/ompi/v3.0/downloads/ -q -O -|grep -m 1 .tar.gz|sed -n 's/.*"\(openmpi.*\)".*/\1/;p')
dir_ompi=$(basename -s ".tar.gz" $file_ompi)
inst_ompi=/home/mpi_user/openmpi/installation/$dir_ompi
sudo docker build --build-arg file_ompi=$file_ompi --build-arg dir_ompi=$dir_ompi --build-arg inst_ompi=$inst_ompi -t openmpi_mno/openmpi:v1 .
```

Una vez construída esta imagen (teniendo un `Successfully built`) es recomendable tener la versión instalada de su openmpi en el archivo `.profile`:

```
echo "inst_ompi=$inst_ompi" >> /home/ubuntu/.profile
```

y crear un directorio en el que estén los programas de mpi. Por ejemplo:

```
mkdir /home/ubuntu/openmpi_ejemplos
```

Creamos una docker network:

```
sudo docker network create -d bridge --subnet 172.18.0.1/16 ompi-network
```

Levantamos el contenedor de master con nombre `master_container` y una ip de `172.18.0.2` a partir de la imagen construída, se mapea el directorio de `/home/ubuntu/openmpi_ejemplos` dentro del contenedor a la ruta `/openmpi_ejemplos`, se abre el puerto 22 del contenedor y se mapea al puerto 2222 y el hostname es `master_ompi`.

```
sudo docker run --net=ompi-network --ip=172.18.0.2 -dit -v /home/ubuntu/openmpi_ejemplos:/openmpi_ejemplos -p 2222:22 -h master_ompi --name master_container openmpi_mno/openmpi:v1 /bin/bash
```

Levantamos el contenedor nodo1 con nombre `nodo1_container` y una ip de `172.18.0.3` el hostname es `nodo1_ompi`.

```
sudo docker run --net=ompi-network --ip=172.18.0.3 -dit -v /home/ubuntu/openmpi_ejemplos:/openmpi_ejemplos -p 2223:22 -h nodo1_ompi --name nodo1_container openmpi_mno/openmpi:v1 /bin/bash
```

Ejecutar:

```
sudo docker exec -it master_container sudo /bin/bash -c 'echo "172.18.0.2 master" >> /etc/hosts'
```

Generar una llave para autenticar conexiones del master al nodo1:

```
sudo docker exec -it master_container ssh-keygen -f /home/mpi_user/.ssh/id_rsa -t rsa -N ''
```

en la ruta:

```
/home/mpi_user/.ssh/id_rsa.pub
```

Reiniciar servicio ssh en master:

```
sudo docker exec master_container /bin/sh -c 'sudo /etc/init.d/ssh restart'
```

Crear archivo de ssh en master:

```
sudo docker exec master_container /bin/sh -c 'echo "Host nodo1\nHostname 172.18.0.3\nUser mpi_user\nStrictHostKeyChecking no" > /home/mpi_user/.ssh/config'

```
Reiniciar servicio ssh en nodo1:

```
sudo docker exec nodo1_container /bin/sh -c 'sudo /etc/init.d/ssh restart'

```

Copien la llave al `nodo1_container`:

```
sudo docker exec -it master_container /bin/bash -c 'sshpass -p "mpi" ssh-copy-id -i /home/mpi_user/.ssh/id_rsa.pub mpi_user@nodo1'
```

Si ejecutan la siguiente línea deberían de entrar al nodo1_container sin que se les pida password:

```
sudo docker exec -it master_container ssh mpi_user@nodo1
```

Salgan con `exit`

Listo! Ya tienen un clúster de forma pseudo distribuida con openmpi y docker :). Los programas serán ejecutados desde el `master_container`, si quieren también ejecutarlos desde el `nodo1_container` deben de realizar los pasos que hicimos para el `master_container` en el `nodo1_container`.

Algunos ejemplos de prueba (los programas se encuentran en [ejemplos](./ejemplos))

```
ruta_ompi=/openmpi_ejemplos

sudo docker exec -w=$ruta_ompi -it master_container mpicc hello_clase.c -o hello_clase.out

sudo docker exec -w=$ruta_ompi -it master_container mpirun -n 1 -H master hello_clase.out

sudo docker exec -e inst_ompi=$inst_ompi -w=$ruta_ompi -it master_container mpirun --prefix $inst_ompi -n 1 -H nodo1 hello_clase.out

sudo docker exec -e inst_ompi=$inst_ompi -w=$ruta_ompi -it master_container mpirun --prefix $inst_ompi -n 2 -H master,nodo1 hello_clase.out

sudo docker exec -w=$ruta_ompi -it master_container mpicc trapecio_compuesto_mpi.c -o trapecio_compuesto_mpi.out -lm

sudo docker exec -e inst_ompi=$inst_ompi -w=$ruta_ompi -it master_container mpirun --prefix $inst_ompi -n 2 -H master,nodo1 trapecio_compuesto_mpi.out

```
