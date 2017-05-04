

*Marin* 

Programé [mc_integration_MPI.c](mc_integration_MPI.c) en el objetivo de aprovechar de MPI para estimar el integral multidimensional de un funcion con un cantitad importante de simulaciones independientes. Puse un parte de commentarios sobre el funcionamiento del codigo y el problema sobre la estimacion de la varianza en MPI.
Probamos estimar la varianza para construir un intervalo de confianza a 95/100 para tener una informacion adicional sobre la presicion de nuestra integral.

*Camilo*

Realicé un par de ajustes menores y comentarios al código de Marín y sobre todo, al cluster, puesto que estaba preocupado porque no estaba funcionando el cluster con todos los procesadores. 
Lo cual se puede probar con el atributo: MPI_Get_processor_name(processor_name, &name_len).


**Trabajo en equipo:**

**Cluster:**

Decidimos trabajar con la verión automática creada por *Nikle Nguyen* para levantar un cluster en mpi.
Lo probamos en el cluster y entendimos que debemos tener cuidado con la forma de levantar el cluster porque puede estar trabajando sobre un único procesador, a pesar de tener varios procesos en varios contenedores.
Por lo tanto, coordinamos la forma correcta de hacerlo y la pusimos en commentarios al fin del codigo[mc_integration_MPI.c](mc_integration_MPI.c).

**Código:**

Revizamos el código y llegamos a la conclusión de que no es fácil de paralelizar la varianza de la estimación de la integral, puesto que se requieren guardar todas las simulaciones después de haber estimado la integral (Ver comentarios código).

Objetivo de la proxima avance :

Hacer el codigo mc_integration_MPI_var.c que permite comparado a [mc_integration_MPI.c](mc_integration_MPI.c) de estimar de manera correcta la estimacion de la varianza para finalizar el integration de MC en MPI.
Empezar MCMC:Hasting-Metropolis al probar implementar una simulacion de la ley normal multidimensional dado una esperanza mu y una matriz de covarianza sigma.
