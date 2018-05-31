#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <time.h>

/* función a integrar: cos(x) */
#define func(x) cos(x)


int main (int argc, char * argv[])
{
  clock_t begin = clock();
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
  float n = 99999.0;
  float i = 0.0;
  float randX, randY;
  float puntos_bajo_curva = 0.0;
  srand(time(NULL)+1);

for(i=0; i<n; ++i){
	randX=rand()/(double)RAND_MAX;
	randY=rand()/(double)RAND_MAX;
	if(func(randX) > randY)++puntos_bajo_curva;
}

 /* Inicia la sección crítica */ 
  MPI_Reduce(&accum, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (my_rank == 0) { 

    result += puntos_bajo_curva/n;
    printf("El resultado regresa al proceso: %d, resultado =  %.20f\n", my_rank, result);
  }

  MPI_Finalize();
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tiempo en el proceso:%d fue de %.20f\n", my_rank,time_spent);

  return 0;
}

