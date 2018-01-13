// código_base: https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform

#include <mpi.h>
#include <stdio.h>
#include <time.h> // semilla-tiempo
#include <stdlib.h>
#include <stdbool.h> // bool type
#include <float.h> // epsilon
#include <string.h> // hello_world
#include <math.h> // cos, sin
#include <limits.h> //para epsilon de la máquina (if type = double)


int main(){
  int comm_sz, my_rank, proc;
	double mu = 0, sigma =1; // este será el input en
	static double z0, z1; // static: no reset value (acumular, versión funcion)
    double u1, u2, norm_sim;
    double epsilon = DBL_MIN; //  2.2250738585e-308 // FLT_EPSILON;//
	bool simula_bool; //default = false
	const double two_pi = 2.0*3.14159265358979323846;
	
  simula_bool = !simula_bool; // --> True 
	// Condición de aceptación/rechazo de Metrópolis-Hastings
	
	if (!simula_bool) // skip, no entra aquí en esta primera versión
		norm_sim = z1 * sigma + mu; // N(0,1) --> N(mu,sig^2) 
		
  MPI_Init(NULL,NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
  do // Simulación Normal Box-Müller
	{
		  srand (time(NULL)+ my_rank);  // srand --> Inicia semilla; time(NULL) --> get time; 
									                  // No está funcionando time, solo my_rank como semilla
		// Genera v.a. ~ Unif(0,1)
      u1 = rand() * (1.0 / RAND_MAX); // RAND_MAX = 2,147,483,647 (32 bits en GNU C)
		  u2 = rand() * (1.0 / RAND_MAX);  // rand() ente (0,RAND_MAX)
	}
	while ( u1 <= epsilon*10); // Si la uniforme generada es muy pequeña, repita simulación


	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2); // Se están generando 2 rand_norm's
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2); // ¿Cómo aprovechar la segunda simulación?
	norm_sim = z0 * sigma + mu; // N(0,1) --> N(mu,sig^2) 

    //slave
    if(my_rank!=0){
    	printf("Rank=%d de comm_sz= %d!\n, u1= %1.4f, u2= %1.4f,norm_sim = %1.4f\n", 
    			my_rank, comm_sz, u1, u2, norm_sim);
         
    	MPI_Send(&norm_sim,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
    			//data, len, type, destino, tag, ...world);
    
    } else{ //master
    	
    	printf("Rank=%d de comm_sz= %d!\n", my_rank, comm_sz,epsilon);
     	
     	for(proc=1; proc <comm_sz; proc++){
     		
     		MPI_Recv(&norm_sim,1, MPI_DOUBLE, proc,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      		printf("recv_norm_sim %f\n",norm_sim);
     }
    }
    MPI_Finalize();
}