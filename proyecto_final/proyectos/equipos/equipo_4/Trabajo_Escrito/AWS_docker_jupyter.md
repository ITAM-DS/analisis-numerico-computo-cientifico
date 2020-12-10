# Instancias en AWS, Docker y jupyter notebooks

En este notebook veremos cómo levantar una instancia utilizando AWS, y utilizar jupyter notebooks con una imagen de Docker.

## Servicio EC2 

**1.** Crea tu grupo de seguridad

##### `Inbound rules` 

Asegúrate que tu IP se encuentre habilitado para un el protocolo `SSH` (en automático se especifíca el puerto 22) y un `Custom TCP` con un puerto 9999, que es el que se utilizará después para acceder a jupyter notebook.

**2.** Crea tu instancia 

`Launch instances` 

> 2.1 Escoge una AMI (Amazon Machine Image, nosotros optaremos por una `Ubuntu Server 20.04 LTS (HVM) de 64-bit (x86)`

> 2.2 Escoge un tipo de instancia, nosotros utilizaremos una `t2.micro` con 1GB de RAM ya que sólo lo utilizaremos para jupyter notebook. 

> 2.3 Configura los detalles de tu instancia:

>    + Especifica una VPC con su subnet
>    + Habilita que se autoasigne una dirección IP
>    + Selecciona un grupo de seguridad existente (el que creaste al principio que contiene tu IP)
>    + Revisa, lanza y escoge una llave existente.

Una vez que el estado de tu instancia este en `Running`,

**3.** Conéctate a la instancia, desde la terminal de tu computadora local y posicionándote en tu folder `.ssh`

```
ss -i "key-mno-2020.pem" ubuntu@ec2-52-87-152-40.compute-1.amazonaws.com
```

En la línea de comandos de la instancia, escribe:

```
#!/bin/bash
region=us-east1
name_instance=mi-nodo
sudo apt-get update
sudo apt-get install -y git curl python3-pip && pip3 install --upgrade pip&& pip3 install awscli --upgrade
##etiquetar instancia
INSTANCE_ID=$(curl -s http://169.254.169.254/latest/meta-data/instance-id)
PUBLIC_IP=$(curl -s http://169.254.169.254/latest/meta-data/public-ipv4)
aws ec2 create-tags --resources $INSTANCE_ID --tag Key=Name,Value=$name_instance-$PUBLIC_IP --region=$region
##install docker for ubuntu:
sudo apt-get install -y apt-transport-https ca-certificates gnupg-agent software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
sudo apt-get update
sudo apt-get install -y docker-ce
service docker start
groupadd docker
usermod -aG docker ubuntu && newgrp docker
```

**4.** Habilita JUPYTERLAB

Una vez que entraste a la instancia:
    
```
mkdir /home/ubuntu/jupyter

cd /home/ubuntu/jupyter

nano Dockerfile
```

**Copia y pega**

```
FROM ubuntu:bionic

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive && echo "America/Mexico_City" > /etc/timezone && apt-get install -y tzdata

ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

RUN apt-get update && apt-get install -y \
            sudo \
            nano \
            git \
            python3-dev \
            python3-pip \
            python3-setuptools \
            nodejs && pip3 install --upgrade pip  && pip3 install awscli --upgrade

RUN groupadd miuser
RUN useradd miuser -g miuser -m -s /bin/bash
RUN echo 'miuser ALL=(ALL:ALL) NOPASSWD:ALL' | (EDITOR='tee -a' visudo)
RUN echo 'miuser:miuser' | chpasswd
RUN pip3 install jupyter jupyterlab --upgrade
USER miuser
RUN jupyter notebook --generate-config && sed -i 's/#c.NotebookApp.port = .*/c.NotebookApp.port = 9999/' /home/miuser/.jupyter/jupyter_notebook_config.py && \
sed -i "s/#c.NotebookApp.password = .*/c.NotebookApp.password = u'sha1:adedf57e8cdb:85aea79ca13b11865d8e2dba56dbb312d7ab50d5'/" ~/.jupyter/jupyter_notebook_config.py
```

En la terminal de la instancia:

```
nombre_imagen=jupyter_image
nombre_contenedor=jupyter_contenedor
docker build . -t $nombre_imagen
```

```
docker run -w=/home/miuser/ -p 9999:9999 -v /home/ubuntu/jupyter:/home/miuser/jupyter --name $nombre_contenedor -dit $nombre_imagen jupyter lab --ip=0.0.0.0 --no-browser
```

**5.** Accede al jupyter notebook desde un navegador

```
ec2-52-87-152-40.compute-1.amazonaws.com:9999
```

La contraseña será la default: **qwerty**

**6.** Clona el repositorio dentro del jupyter notebook habilitado

> 6.1 Abre una terminal 

```
git clone https://github.com/lecepe00/PageRank-eigenvectores-eigenvalores

cd PageRank-eigenvectores-eigenvalores

git status
```

De lado izquierdo verás un menú donde puedes acceder con GUI al folder del repositorio clonado. 
Dale click, navega y crea archivos. 

Para agregar este archivo al repositorio, se realizaron los siguientes comandos desde la terminal de jupyter:

```
git status

git add Trabajo_Escrito/AWS_docker_jupyter.md

git commit -m "Agregar markdown de instrucciones aws, docker, jupyter"

git push
```

## Referencias

Palacios M., Erick. (2020).  Wiki, Repositorio - analisis-numerico-computo-cientifico [1.2.Instalación de herramientas útiles en AWS](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/1.2.Instalaci%C3%B3n-de-herramientas-%C3%BAtiles-en-AWS)
