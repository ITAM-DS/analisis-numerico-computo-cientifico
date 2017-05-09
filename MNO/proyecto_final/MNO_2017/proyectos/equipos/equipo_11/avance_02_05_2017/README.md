## Avance_02_05_2017

---

### Integrantes:

---

- Mariana Godina
- Sonia Mendizábal

### Trabajo:

---


#### Equipo

**Mariana y Sonia** 

Esta semana trabajamos en conjunto para construir
el cluster de forma pseudo distribuida con openmpi y docker.
Levantamos cinco contenedores,  master y 4 nodos que se comunican 
existosamente al master. 

Como primer paso, ejecutamos el programa de C `hello_clase.c`. Al probarlo 
con un sólo procesador obtenemos el resultado esperado. 

Después, ejecutamos el programa con dos procesadores.
Sin embargo, obtenemos el siguiente error:
```
[master:00611] [[22732,0],0] usock_peer_send_blocking: send() to socket 29 failed: Broken pipe (32)
[master:00611] [[22732,0],0] ORTE_ERROR_LOG: Unreachable in file oob_usock_connection.c at line 315
[master:00611] [[22732,0],0]-[[22732,1],0] usock_peer_accept: usock_peer_send_connect_ack failed
--------------------------------------------------------------------------
mpirun was unable to find the specified executable file, and therefore
did not launch the job.  This error was first reported for process
rank 1; it may have occurred for other processes as well.

NOTE: A common cause for this error is misspelling a mpirun command
      line parameter option (remember that mpirun interprets the first
      unrecognized command line token as the executable).

Node:       nodo1
Executable: /home/pruebas/hello_clase.out
```
Seguimos trabajando para solucionarlo.


De forma paralela, iniciamos el plateamiento del 
algoritmo para las funciones
de Right Sided Jacobi de las notas 
`3.4.2.SVD_con_computo_en_paralelo.pdf` y 
el capítulo 4 del libro de Golub.


Seguimos estudiando su planteamiento, 
las funciones de MPI para lograr el ordenamiento 
cíclico y la lectura de `stdin` y `stdout` (I/O)
del capítulo 8 del libro de Pacheco.









---