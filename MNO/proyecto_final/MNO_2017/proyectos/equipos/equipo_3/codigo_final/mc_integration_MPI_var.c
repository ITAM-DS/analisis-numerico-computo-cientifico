#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

//Para applicar este codigo es el mismo processo presentado al fin en mc_integration_MPI.c.



double unif(double a,double b);
double f(double x, double y,double z) ;
double simulacion_local(double a_x,double b_x,double a_y,double b_y,double a_z,double b_z,int N,int raiz,int choice);

int main(int argc, char *argv[]){

int N=atoi(argv[1]);
double a_x,a_y,a_z;
double b_x,b_y,b_z;

a_x=atof(argv[2]);
b_x=atof(argv[3]);

a_y=atof(argv[4]);
b_y=atof(argv[5]);

a_z=atof(argv[6]);
b_z=atof(argv[7]);

double start, end;

double simul_local[2];
int raiz_local;

int rango_processo;
int comm_sz;
int num_proceso;

double simul_general_mean=0;
double simul_general_for_var=0;
double ecart_type;

MPI_Init(&argc,&argv); //Iniciamos el communicator MPI_COMM_WORLD ,el alojamiento del espacio necessario
					   //y el almacamiento de los variables anteriores en cada memoria propria de cada processo de MPI_COMM_WORLD.

start = MPI_Wtime();//Te da el tiempo en segundo cuando un processo esta llamado porque hay MPI_Init() antes.

MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 		//cambiamos la valor de comm_sz=numeros de procesos en MPI_COMM_WORLD
MPI_Comm_rank(MPI_COMM_WORLD, &rango_processo);//Cuando el processo lea esta funcion cambia la valor del rango_processo=a su rango

raiz_local=time(NULL)+100*rango_processo;
simul_local[0]=simulacion_local(a_x,b_x,a_y,b_y,a_z,b_z,N,raiz_local,0);
simul_local[1]=simulacion_local(a_x,b_x,a_y,b_y,a_z,b_z,N,raiz_local,1);	//Cada processo llama la funcion simulacion_local
																			//y les conserva en su espacio de memoria de direction simul_local
//Aqui respectamos lo que dijimos en los commentarios de mc_integration:
//Para que el rand() pueda leer una seria de numeros differentes de los otros processos (100*rango_processo) y de
//cada nueva llamada del ejecutable (time(NULL)) damos raiz=time(NULL)+100*rango_processo.Con eso aproximamos bien la independancia de
//las simulaciones entre los processos y entre cada llamda del ejecutable.Puse 100 como multiplicado para evitar por ejemplo que el processo 1 si se
//ejecuta un segundo mas despues del processo 2 tenga la misma semilla.Puse antes N*rango_processo pero me dé cuenta que si N es mas de 1 000 000 000 vamos
//a poner una semilla mas grande para el processo3 que RAND_MAX() (el modulo m)

if(rango_processo!=0){

	MPI_Send(&simul_local,2,MPI_DOUBLE,0,1,MPI_COMM_WORLD);	//Todos los processos de rango differentes de zeros envian sus datos alamcenados
															// en sus memorias con la direccion simul_local almaceneda en &simul_local
															// el a al processo maestro (rango 0).Pusimos 2 porque enviamos un array de tamano 2.
}

else{
 
	simul_general_mean+=simul_local[0];		//recardamos que cada processo tiene un lugar en su memoria(simul_local) donde alamceniaron el resultado de la funcion
	simul_general_for_var+=simul_local[1]; //simulacion_local(...) y aqui el processo 0 va a agregar progressivamente los resultados de todos los processos
										  //en las variable simul_general_mean y simul_general_for_var
	                            	     //Es por eso que antes que su variable simul_local cambia, guardamos el resultado de la llamada de la funcion por el process 0.
								
	for(num_proceso=1;num_proceso<comm_sz;num_proceso++){

		MPI_Recv(&simul_local,2, MPI_DOUBLE, num_proceso,1, MPI_COMM_WORLD,MPI_STATUS_IGNORE);//El processo 0 recibe todos los datos de los otros processos
		                                                                                      //y les alamacena en la direction de memoria simul_local 
																							  //Aqui no nos utilizamos los informaciones guardados
																							  // en el status de los processos mensajes
		simul_general_mean+=simul_local[0];
		simul_general_for_var+=simul_local[1];				
	}	 	
}

if (rango_processo==0){


	simul_general_mean=(1/(double)comm_sz)*simul_general_mean;	

	ecart_type=sqrt((1/(double)(comm_sz))*(simul_general_for_var)-pow(simul_general_mean,2)); //Esta es la formula developada de la estimacion 
																							  // no corregida de la varianza.

	printf("\n\n");

	printf("Integral sobre [%1.2f,%1.2f][%1.2f,%1.2f][%1.2f,%1.2f] de log(x)-y^2+z: %1.8f\n\n ",a_x,b_x,a_y,b_y,a_z,b_z,simul_general_mean);

	printf("Interval de confianza de 95/100 es:\n [%1.8f,%1.8f] \n\n",simul_general_mean-(1.96*ecart_type)/sqrt(N),simul_general_mean+(1.96*ecart_type)/sqrt(N));

	printf("Numero de simulaciones realizados de manera pseudo-independiente en el cluster: %d\n \n",N*comm_sz);

}

end = MPI_Wtime();//Te da el tiempo cuando se acaba un processo porque hay MPI_finalize() despues.

MPI_Finalize();

if (rango_processo == 0) { 
    printf("Tiempo de ejecucion = %f s \n\n\n", end-start);//Te da la differencia entre el tiempo de inicio y de acabo del processo 0.
}

return 0;

}

double unif(double a, double b){
    return ( rand()/(double)RAND_MAX ) * (b-a) + a ;
}

double f(double x, double y,double z) { return log(x)-pow(y,2)+z; }


double simulacion_local(double a_x,double b_x,double a_y,double b_y,double a_z,double b_z,int N,int raiz,int choice){
	int i=0;

	double sim_x;
	double sim_y;
	double sim_z;
	double sim_mean;
	double sim_for_var;
	
	srand(raiz); 

	for (i=0;i<N;i++){

		sim_x=unif(a_x,b_x);
		sim_y=unif(a_y,b_y);
		sim_z=unif(a_z,b_z);

		if (choice==0) {

			sim_mean+=f(sim_x,sim_y,sim_z);
		}

		else {

			sim_for_var+=pow(f(sim_x,sim_y,sim_z),2);
		}
	}

	if (choice==0){
		return (b_x-a_x)*(b_y-a_y)*(b_z-a_z)*(1/(double)N)*sim_mean;
	}

	else {
		return pow((b_x-a_x)*(b_y-a_y)*(b_z-a_z),2)*(1/(double)N)*sim_for_var;
	}
}

