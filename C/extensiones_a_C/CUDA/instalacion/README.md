# Instalación 

Para usar CUDA es necesario que sus máquinas tengan una GPU de NVIDIA.

Se debe descargar el toolkit NVIDIA CUDA de [aquí](https://developer.nvidia.com/cuda-downloads) dependiendo de su sistema operativo.

El toolkit NVIDIA CUDA de acuerdo a las guías de instalación contiene:

* CUDA driver y Nvidia driver. (CUDA driver es una API de acuerdo a [liga](http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#driver-api), se utiliza por el CUDA Runtime de acuerdo a [liga](http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#versioning-and-compatibility) y el Nvidia driver incluye al CUDA driver y funcionalidad de bajo nivel por ejemplo interacción con el kernel del sistema operativo).

* tools para crear, construir y correr una aplicación de CUDA. (por ejemplo el compilador nvcc)

* libraries, header files, CUDA samples source code y otros.

**(los Nvidia drivers se pueden descargar manualmente de [aquí](http://www.nvidia.com/Download/index.aspx?lang=en-us)).**

## Mac OS X

En esta [página](http://docs.nvidia.com/cuda/cuda-getting-started-guide-for-mac-os-x/) encuentran documentación para instalación de CUDA en Mac OS X.

Una vez instalado:

* El device driver de NVIDIA.

* Toolkit para desarrollo.

* Compilador estándar de C, por ejemplo `gcc`.

Pueden hacer en sus sistemas: (ejemplo para CUDA-7.5)

```
export PATH=/Developer/NVIDIA/CUDA-7.5/bin:$PATH
export DYLD_LIBRARY_PATH=/Developer/NVIDIA/CUDA-7.5/lib:$DYLD_LIBRARY_PATH
```

y revisar que su sistema reconoce el comando siguiente:

```
$nvcc -V
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2015 NVIDIA Corporation
Built on Thu_Sep_24_00:26:39_CDT_2015
Cuda compilation tools, release 7.5, V7.5.19
```

## Ubuntu:

Para usar CUDA es necesario que sus máquinas tengan una GPU de NVIDIA. Pueden revisar esto con el comando siguiente:

```
$lspci | grep -i nvidia
```

En esta [página](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html) encuentran documentación para instalación de  CUDA en GNU/Linux.


## Amazon Web Services:

Seleccionar una **AMI** AWS ubuntu 18.04. 

El siguiente bash script identifica una instancia con el nombre de la variable `name_instance`, en la region `us-west-2`. Cambiar variables `region`, `user`, `ubuntu_version`, `name_instance` de acuerdo a su configuración. Utilizarlo en la sección de **User data** de la configuración de una instancia:

```
#!/bin/bash
region=us-west-2
user=ubuntu
ubuntu_version=ubuntu1804
name_instance=gpu-node
apt-get update
apt-get install linux-headers-$(uname -r) #to have kernel headers and development
#packages accordingly to the current kernel
apt-get install -y awscli build-essential
#To tag instances of type node
INSTANCE_ID=$(curl -s http://169.254.169.254/latest/meta-data/instance-id)
PUBLIC_IP=$(curl -s http://169.254.169.254/latest/meta-data/public-ipv4)
aws ec2 create-tags --resources $INSTANCE_ID --tag Key=Name,Value=$name_instance-$PUBLIC_IP --region=$region
toolkit_inst_network=$(wget http://developer.download.nvidia.com/compute/cuda/repos/$ubuntu_version/x86_64/ -q -O -|grep ".*repo.*amd64"|tail -1|sed -n 's/.*\(cuda-repo.*deb\).*/\1/;p')

mkdir /home/$user/cuda_toolkit
wget http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1604/x86_64/$toolkit_inst_network -P /home/$user/cuda_toolkit
dpkg -i /home/ubuntu/cuda_toolkit/$toolkit_inst_network #install toolkit
apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1604/x86_64/7fa2af80.pub
apt-get update
apt-get install linux-headers-$(uname -r) #to have kernel headers and development
#packages accordingly to the current kernel
apt-get install -y cuda #this will install nvidia driver, cuda driver and all libraries required
cuda_version=$(ls /usr/local/|grep cuda-)
echo "export PATH=/usr/local/$cuda_version/bin${PATH:+:${PATH}}" >> /home/$user/.profile
echo "export LD_LIBRARY_PATH=/usr/local/$cuda_version/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}" >>/home/$user/.profile
```

## Docker:


## Mandatory, recomended y optional actions:

Después de la instalación se recomienda consultar la sección de [mandatory actions](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#mandatory-post), [recommended actions](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#recommended-post) y [optional actions](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#optional-post). (Para información sobre Power 9 system pueden revisar la [liga](https://en.wikipedia.org/wiki/POWER9) y [la pregunta](https://devtalk.nvidia.com/default/topic/1028338/power9-for-ubuntu16-04/)).




