#include <stdio.h>
#include <mpi.h>

main(int argc, char **argv)
{
	int ierr, num_procs, my_id;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	//printf("---------------------------------------");
	//printf("Soy el proceso con id: %i de un total de %i procesos\n", my_id, num_procs);

	// Inicia programa especifico
	float i, throws = 100.0, circleDarts = 0.0;
        long double randX, randY;
    
    	srand(time(NULL)+my_id); 

    	for (i = 0; i < throws; ++i) {
   	   randX = rand() / (double)RAND_MAX;
   	   randY = rand() / (double)RAND_MAX;
   	   if (randX * randX > randY) ++circleDarts;
   	 }

   	 //printf("Area bajo la curva de proceso %i :\n", my_id);
   	 printf("%f\n", (circleDarts/throws));
	ierr = MPI_Finalize();
}
