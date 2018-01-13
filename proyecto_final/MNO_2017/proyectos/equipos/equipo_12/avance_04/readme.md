## Avance 04

Haciendo uso de las funciones de paso de mensaje de MPI como son MPI_Send y MPI_Recv se implementa el código de manera distribuida y pseudo-distribuida, esta implementación supone que se ha levantado un docker con contenedores master_container y nodo1.

Las sentencias para correr el programa son:
Entrar al contenedor: sudo docker exec -it master_container /bin/bash
Compilar: mpicc lu_mpi.c -o lu_mpi.out
Ejecución con un solo procesador indicando el número de procesadores: mpiexec -n 2 lu_mpi.out 4 (el 4 indica el tamaño de la matriz)

Para ejecutar de manera pseudodistribuida:
Entrar al contenedor del nodo1: sudo docker exec -it nodo1 /bin/bash
Compilar: mpicc lu_mpi.c -o lu_mpi.out
Ejecutar de manera pseudo-distribuida en el master container: mpirun --prefix /opt/openmpi-2.1.0/ -n 2 -H master,nodo1 lu_mpi.out 4
