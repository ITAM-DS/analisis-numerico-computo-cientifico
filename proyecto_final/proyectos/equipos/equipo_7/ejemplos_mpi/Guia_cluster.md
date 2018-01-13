
# construimos la imagen
docker build -t openmpi_mno/openmpi:v1 .

# Levantamos el contenedor

## Master container
docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h master --name master_container openmpi_mno/openmpi:v1 /bin/bash

## Nodo 1-8 container
docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo1 --name nodo1_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo2 --name nodo2_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo3 --name nodo3_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo4 --name nodo4_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo5 --name nodo5_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo6 --name nodo6_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo7 --name nodo7_container openmpi_mno/openmpi:v1 /bin/bash

docker run -dit -v /Users/omardiaz/Dropbox/ITAM_Master/Optimizacion/analisis-numerico-computo-cientifico/MNO/proyecto_final/MNO_2017/proyectos/equipos/equipo_7/ejemplos_mpi:/results -p 22 -h nodo8 --name nodo8_container openmpi_mno/openmpi:v1 /bin/bash

# Revisamos la IP de cada contenedor

docker inspect master_container|grep IPA

docker inspect nodo1_container|grep IPA
docker inspect nodo2_container|grep IPA
docker inspect nodo3_container|grep IPA
docker inspect nodo4_container|grep IPA
docker inspect nodo5_container|grep IPA
docker inspect nodo6_container|grep IPA
docker inspect nodo7_container|grep IPA
docker inspect nodo8_container|grep IPA

## Las IP son las siguientes:
master_conatainer y nodos 1-8
"IPAddress": "172.17.0.2",
"IPAddress": "172.17.0.3",
"IPAddress": "172.17.0.4",
"IPAddress": "172.17.0.5",
"IPAddress": "172.17.0.6",
"IPAddress": "172.17.0.7",
"IPAddress": "172.17.0.8",
"IPAddress": "172.17.0.9",
"IPAddress": "172.17.0.10",

# Entramos al master container, reinciamos servicio ssh, damos ips del cluster y generamos llaves

docker exec -it master_container /bin/bash
sudo service ssh restart

Editamos le archivo etc/hosts agregando las ips del cluster

y generamos llaves

ssh-keygen

# Iniciamos le loop para conectar en el cluster cada nodo i

mpi_user@master:/$exit
$docker exec -it nodoi_container /bin/bash
mpi_user@nodoi:/$sudo service ssh restart
mpi_user@nodoi:/$exit
$docker exec -it master_container /bin/bash

ssh-copy-id -i /home/mpi_user/.ssh/id_rsa.pub mpi_user@nodoi (pwd= mpi)
mpi_user@master:/$ssh mpi_user@nodo1
exit
exit


Reinicia el loop
