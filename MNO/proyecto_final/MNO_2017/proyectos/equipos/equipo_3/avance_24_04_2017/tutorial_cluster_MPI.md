
TUTORIAL CLUSTER MPI DE NIKYLE NGUYEN CON DOCKER COMPOSE !


Es el trabajo de Nikyle Nguyen en licence MIT disponible en [github](https://github.com/NLKNguyen/alpine-mpich)

Es el co-autor tambien del libro [Distributed MPI cluster with Docker Swarm mode](http://ieeexplore.ieee.org/document/7868429/?reload=true) 2017 IEEE 7th Annual Computing and Communication Workshop and Conference (CCWC), Las Vegas, NV, USA, 2017, pp. 1-7.

Hay [videos explicativos](https://asciinema.org/a/93067) para ver como utilizar su docker compose o su docker swarm para implementar un cluster para MPI.

Pero voy a presentar rapidamente los principales etapas para levantar rapidamente 10 contenedores para ejecutar el codigo en MPI de Erick [hello_clase.c](hello_clase.c)

1)Crear un carpeta y hacer git clone https://github.com/NLKNguyen/alpine-mpich

2)En la carpeta creado hacer :cd alpine-mpich/cluster/project

3)Poner hello_clase.c en esta carpeta

4)Regresar en la carpeta cluster : cd ..

5)Hacen en el terminal : ./cluster.sh help
	/Podemos ver que hay possibles de hacer muchas llamadas a esto archivo cluster.sh para construir destruir restart de manera automatizado el cluster

6)Normalmente estamos en alpine-mpich/cluster y si esta el caso en el terminal hacer: ./cluster.sh up size=10
	/Habiamos creado un cluster de 10 contenadores que estan listo para executar de manera parallel el codigo hello_clase.c
	Normalmente al final debemos tener:

	===> CLUSTER READY 

                            ##         .          
                      ## ## ##        ==          
                   ## ## ## ## ##    ===          
               /"""""""""""""""""\___/ ===        
          ~~~ {~~ ~~~~ ~~~ ~~~~ ~~~ ~ /  ===- ~~~ 
               \______ o           __/            
                 \    \         __/               
                  \____\_______/                  
                                                  
                 Alpine MPICH Cluster             

 More info: https://github.com/NLKNguyen/alpine-mpich

==============================================================

To run MPI programs in an interative shell:
  1. Login to master node:
     Using Docker through command wrapper:
     $ ./cluster.sh login

     Or using SSH with keys through exposed port:
     $ ssh -o "StrictHostKeyChecking no" -i ssh/id_rsa -p 2222 mpi@localhost
       where [localhost] could be changed to the host IP of master node

  2. Execute MPI programs inside master node, for example:
     $ mpirun hostname
      *----------------------------------------------------*
      | Default hostfile of connected nodes in the cluster |
      | is automatically updated at /etc/opt/hosts         |
      | To obtain hostfile manually: $ get_hosts > hosts   |
      * ---------------------------------------------------*


To run directly a shell command at master node:
     $ ./cluster.sh exec [COMMAND]

     Example: 
     $ ./cluster.sh exec mpirun hostname



7)Ahora vamos a la carpeta a project: cd ./project

8)Hacer :ls 
	Normalmente debemos ver:

	hello_clase.c  mpi_hello_world.c(el file por default)


9)Hacer en el terminal: docker run --rm -it -v $(pwd):/project nlknguyen/alpine-mpich 
	(Si no funciona empezar de nuevo a llamar ./cluster.sh up size=10)
	Normalmente estamos ahora en:
	/project $ 
	Esta es la linea de command del nodo maestro

9)Hacemos: ls (/project $ ls)
	Normalmente debemos ver como resultado:
	hello_clase.c  mpi_hello_world.c

10)Ahora hacemos: mpicc -o hello_clase hello_clase.c
	Para crear el ejcutable hello_clase

11)Para lanzar el codigo hacemos por ejemplo: mpirun -n 20 ./hello_clase
	Normalmente tenemos:

	Hola del procesador 0 de 20!
	Hola del procesador 1 de 20!
	Hola del procesador 2 de 20!
	Hola del procesador 3 de 20!
	Hola del procesador 4 de 20!
	Hola del procesador 5 de 20!
	Hola del procesador 6 de 20!
	Hola del procesador 7 de 20!
	Hola del procesador 8 de 20!
	Hola del procesador 9 de 20!
	Hola del procesador 10 de 20!
	Hola del procesador 11 de 20!
	Hola del procesador 12 de 20!
	Hola del procesador 13 de 20!
	Hola del procesador 14 de 20!
	Hola del procesador 15 de 20!
	Hola del procesador 16 de 20!
	Hola del procesador 17 de 20!
	Hola del procesador 18 de 20!
	Hola del procesador 19 de 20!

12)Quitar el nodo maestro : exit

13)Regresamos a cluster : cd ..

14)Podemos ver los contenedores donde los processos trabajaron: ./cluster.sh list 
	( es un docker-compose ps)


	===> LIST CONTAINERS

         __v_
        (.___\/{
~^~^~^~^~^~^~^~^~^~^~^~^~
$ docker-compose ps

       Name                     Command               State           Ports          
------------------------------------------------------------------------------------
cluster_master_1     mpi_bootstrap role=master  ...   Up      0.0.0.0:2222->22/tcp   
cluster_registry_1   /entrypoint.sh /etc/docker ...   Up      0.0.0.0:5000->5000/tcp 
cluster_worker_1     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_2     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_3     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_4     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_5     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_6     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_7     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_8     mpi_bootstrap role=worker  ...   Up                             
cluster_worker_9     mpi_bootstrap role=worker  ...   Up         


15)Podemos hacer otra cosa (utilizar docker swarm) ver el tutorial de Nkyle Nguyen


**GRACIAS A NYKILE NGUGYEN y LOS CONTRIBUTORES DE SU GITHUB**


