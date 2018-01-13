
**Equipo 3**

Esta semana hemos logrado la paralelización de la integración Monte Carlo con intervalos de confinaza, por lo que seguiremos avanzando sobre los objetivos secundarios del proyecto: Simulación MCMC para una función dada.

**Camilo**
La idea es poder escalar el proyecto a simulación MonteCarlo, por lo que se necesitará una simulación de una función simétrica, por ejemplo, una distribución normal. Se requiere una simulación normal por cada dimensión de la función a estimar en cada iteración del MCMC. 

Una forma fácil de hacer una simulación normal es con el método Box-Müller, que logra su cometido haciendo cambios de coordenas polares a una variable uniforme. El trabajo de esta semana fue generar una simulación uni-dimensional.
[box_muller.c](box_muller.c)

Escalar el método a más dimensiones se logra normalizando(Porceso Maestro), puesto que que cada simulación es independeinte de la otra. La matriz de covarianzas resulta ser diagonal. Lo anterior resta velocidad a la convergencia de una simulación Monte Carlo, pero tendremos que vivir con ello.

Lista de dudas:

- ¿Cómo agregar librerías no soportadas por MPI?
- ¿Cómo hacer una doble paralelización? (Partición Región+ Dimencionalidad)
- Problemas con scanf para elegir una función

**Marin:**

Terminé el programo [mc_integration_MPI_var.c](mc_integration_MPI_var.c) que calcula la integracion 3D de manera parallela (MPI) de una funcion f definida en el codigo y regresa el valor estimado con su intervalo de confianza de 95%.Ahora la varianza utilizado para construir el intervalo de confianza esta bien estimado por el codigo pero no es la varianza corregida.

Para utilizar el codigo tenemos que poner este formato en el terminal del nodo maestro:

mpirun -n 10 ./MC_integration_MPI_var.out N ax bx ay by cx bx

N:numero de simulaciones identica para todos los processos  
ax,bx:el tamano de integration de f para la variable x.  
ay,by:el tamano de integration de f para la variable y.  
az,bz:el tamano de integration de f para la variable z.  

Aqui puse los resultados que regresa esto algoritmo.[Resultados](resultados.txt).

**Objetivos Proximo Avance**: Se iniciarán las primeros intenros por generar la simulación Monte Carlo. Se generalizará y terminará la función Box-Müller.


