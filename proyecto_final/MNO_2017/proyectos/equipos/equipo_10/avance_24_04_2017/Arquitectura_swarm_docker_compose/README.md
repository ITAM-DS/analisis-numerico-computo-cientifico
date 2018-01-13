# Swarm Docker Compose MPI Cluster

* Ya esta generado el cluster sin embargo hay dos detalles:
	* El primero: Si nos conectamos al container master con *docker exec -it <nombre de container> bash* no podemos hacer *ssh mpi_user@mpi_nodo1* ni *ssh mpi_user@mpi_nodo1* manda timeout
	* El segundo: Derivado de lo anterior no podemos correr el programa hello.c en modo distribuido
