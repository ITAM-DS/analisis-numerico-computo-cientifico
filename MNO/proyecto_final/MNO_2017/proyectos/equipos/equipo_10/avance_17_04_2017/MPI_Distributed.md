---
title: "README"
author: "Oscar Camarena, Maximiliano Alvarez"
date: "16 de abril de 2017"
output: html_document
---

#Arquitectura de MPI distribuida en AWS

El siguiente archivo contiene las instrucciones paso a paso para levantar un ambiente de MPI distribuido utilizando *AWS*

##Lo Primero...
Entremos a nuestra consola de AWS y levantemos *N* servidores. Para fines de este tutorial *N=3*, cuando estemos creando estas maquinas nombraremos a una de ellas (indistintamente) como **Master** y las dems sern **Nodo1** y **Nodo2**

Una vez hecho eso vamos a generar el contenido nuestro archivo de hosts el cual tiene las IP's publicas de cada una de nuestras maquinas dentro de un *shell* mediante el comando **echo** de la siguiente manera:

*hosts.sh*

```{engine='bash' eval=FALSE}
#!/bin/bash

echo "127.0.0.1 localhost
52.53.250.233 master
54.193.91.20 nodo1
54.241.134.251 nodo2


# The following lines are desirable for IPv6 capable hosts
::1 ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
ff02::3 ip6-allhosts">hosts

sudo mv hosts /etc/
```


Usando la misma tecnica generaremos un programa en c que nos ayude a probar que la implementacion de MPI fue exitosa. Para esto escribiremos del contenido del programa en C dentro de un commando echo para luego redirigirlo a un archivo llamado *hello.c*

*hello.sh*

```{engine='bash' eval=FALSE}
#!/bin/bash

echo "#include<stdio.h>
#include<string.h>
#include<mpi.h>
int main(){
int max_string=100;
char greeting[max_string];
int comm_sz;
int my_rank;
int q;\
MPI_Init(NULL,NULL);
MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
if(my_rank!=0){
 sprintf(greeting, \"Hola del procesador %d de %d!\", my_rank, comm_sz);
 MPI_Send(greeting, strlen(greeting)+1,MPI_CHAR,0,0,MPI_COMM_WORLD);
}else{
 printf(\"Hola del procesador %d de %d!\n\", my_rank, comm_sz);
 for(q=1;q<comm_sz;q++){
  MPI_Recv(greeting, max_string, MPI_CHAR,q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  printf(\"%s\n\",greeting);
 }
}
MPI_Finalize();
}">hello.c

```

El siguiente paso es generar el archivo que nos ayuda a instalar *MPI* en todos nuestras mquinas. Estos archivos sern distribuidos en paralelo a todos nuestros nodos y de manera automatica para hacer nuestra arquitectura escalable de manera facil.

*installmpi.sh*

```{engine='bash' eval=FALSE}
#!/bin/bash

sudo apt-get update -y
sudo apt-get install -y build-essential
sudo apt-get install -y nano
sudo apt-get install -y man
sudo apt-get install -y openssh-server

sudo groupadd mpi_user

sudo useradd mpi_user -g mpi_user -m -s /bin/bash

wget https://www.open-mpi.org/software/ompi/v2.0/downloads/openmpi-2.0.2.tar.gz

sudo tar xf openmpi-2.0.2.tar.gz -C /opt/

cd /opt

sudo chown -hR mpi_user:mpi_user openmpi-2.0.2

mkdir -p /var/run/sshd

cd /opt/openmpi-2.0.2

sudo ./configure --prefix=/opt/openmpi-2.0.2 --enable-orterun-prefix-by-default -with-sge

sudo make all install

```

Una vez instalado *MPI* en todos los nodos debemos cambiar algunas variables de ambiente en la consola, para eso generaremos un archivo llamado *sourcefile* que nos ayudara con esta tarea:

*sourcefile*
```{engine='bash' eval=FALSE}
#!/bin/bash
echo "export PATH=\"/opt/openmpi-2.0.2/bin:\$PATH\"
export LD_LIBRARY_PATH=\"/opt/openmpi-2.0.2/lib:LD_LIBRARY_PATH\"">sourcefile2
```

Por ltimo necesitamos un archivo maestro que nos ayude a orquestar el despliegue de los archivos a cada una de las mquinas y que ejecute todas estas tareas en rden. Dicho archivo lleva el nombre de *setup_env.sh* y su contenido se presenta a continuacion.

*setup_env.sh*

```{engine='bash' eval=FALSE}

#!/bin/bash 

#Obtenemos la informacion de nuestras instancias en AWS
aws ec2 describe-instances | \
jq '.Reservations[].Instances[].PublicDnsName' | \
tr '"' ' ' > instancias

#Quitamos los espacios en blanco que llegara a tener el archivo de instancias
sed 's/ //g' instancias > instancias2
rm instancias
mv instancias2 instancias

#Instalamos parallel en todas las maquinas
parallel --nonall --slf instancias "sudo apt-get install -y parallel"

#Distribuimos y ejecutamos el archivo installmpi.sh en todos los nodos
parallel --nonall --basefile installmpi.sh  --slf instancias "./installmpi.sh"

#distribuimos y ejecutamos el archivo sourcefile en todos los nodos
parallel --nonall --basefile sourcefile  --slf instancias "source sourcefile"

#Distribuimos y colocamos en la ruta correcta el archivo de hosts
parallel --nonall --basefile hosts.sh  --slf instancias "./hosts.sh"

#Distribuimos el codigo de prueba en C a todos los nodos para luego compilarlo
parallel --nonall --basefile hello.sh  --slf instancias "./hello.sh"

```

**NOTA: todos los archivos .sh tienen permisos de ejecucion**

**TIP: Hay que revisar las reglas de seguridad de los nodos para que tengan una regla *Inbound* que permita ver la IP publica desde cualquier otra IP**

Nos conectamos al nodo maestro mediante *ssh*


```{engine='bash' eval=FALSE}
ssh -i "ubuntu2.pem" ubuntu@ec2-52-53-194-89.us-west-1.compute.amazonaws.com

```

Luego el *tricky*... tenemos que hacer una llave ssh

```{engine='bash' eval=FALSE}
ssh-keygen
```

Damos enter enter enter enter hasta que acabe (todo con default)

Luego hacemos un copy paste de la llave

```{engine='bash' eval=FALSE}

cat /home/ubuntu/.ssh/id_rsa.pub

#copiamos con ctrl+c

```

Nos conectamos a cada uno de los nodos y hacemos lo siguiente

```{engine='bash' eval=FALSE}
cd .ssh

nano authorized_keys

#pegamos la llave al final
```

Nos conectamos a cada uno de los nodos y una vez conectados compilamos el archvio hello.c

```{engine='bash' eval=FALSE}
source sourcefile2
mpicc hello.c -o hello.out
```

Probamos ejecutando en el nodo maestro

```{engine='bash' eval=FALSE}
mpiexec -n 3 hello.out
```

Ejecutamos en modo distribuido
```{engine='bash' eval=FALSE}
mpirun --prefix /opt/openmpi-2.0.2/ -n 3 -H master,nodo1,nodo2 hello.out
```


