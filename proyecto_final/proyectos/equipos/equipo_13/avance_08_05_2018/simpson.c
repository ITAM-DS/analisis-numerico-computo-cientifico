#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

/* función a integrar: x^2 */
#define func(x) x*x


int main (int argc, char * argv[])
{

  double a; /* límite inferior */
  double b; /* límite superior */
  int num_of_iter; /* número de subintervalos, será el mismo número de subintervalos para cada proceso */
  int num_of_procs; /* número de procesos a lanzar ingresado por el usuario*/
  int my_rank; /* Rango para controlar los procesos que se lanzan */
  double result = 0.0; /* Resultado */

/* Iniciamos MPI */

	  MPI_Init(&argc, &argv);
	  MPI_Comm_size(MPI_COMM_WORLD, &num_of_procs); /* límite inferior */
	  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

/* convertimos a,b a float, número de subintervalos a entero ya que no podemos controlar lo que el usuario meterá en mpirun*/
  a = atof(argv[1]);
  b = atof(argv[2]);
  num_of_iter = atoi(argv[3]);
  num_of_iter += (num_of_iter % 2);


 /* este es el programa que se debe enviar a todos los procesos (SPMD)*/  

  double h = (b - a) / num_of_iter; /* tamaño del paso */

  int local_iter = num_of_iter / num_of_procs;
  int local_idx = my_rank * local_iter;
  int local_end = my_rank * local_iter + local_iter;

  if ((num_of_iter % num_of_procs) != 0) {
    if (my_rank == (num_of_procs - 1))
      local_end += (num_of_iter % num_of_procs);
  }

  printf("Corriendo el proceso:%d \n", my_rank); /* Con esto probaremos la asicronia del algoritmo */
  double x;
  double accum = 0.0;

  for ( ; local_idx < local_end; local_idx++) {
    x = a + local_idx * h;
    if ((local_idx % 2) == 0)
      accum += func(x) * 2;
    else
      accum += func(x) * 4;
  }


 /* Inicia la sección crítica */ 
  MPI_Reduce(&accum, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (my_rank == 0) { 

    result += func(b);
    result *= (h/3.0);
    printf("El resultado regresa al proceso: %d, resultado =  %.20f\n", my_rank, result);
  }

  MPI_Finalize();
  return 0;
}

