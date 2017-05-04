#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>


double unif(double a,double b);
double f(double x, double y,double z) ;
double simulacion_local(double a_x,double b_x,double a_y,double b_y,double a_z,double b_z,int N,int raiz);

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

double simul_local;

int rango_processo;
int comm_sz;
int num_proceso;

double simul_general=0;

double simul_processo[200];//El numero max de comm_siz debe ser <=200 
double ecart_type=0;	   //simul_processo sirve unicamente a guardar los simulaciones por processo para calcular despues la desviacion estandar.	

MPI_Init(&argc,&argv); //Iniciamos: el communicator MPI_COMM_WORLD ,el alojamiento del espacio necessario
					   //y el almacamiento de los variables anteriores en cada memoria associada a cada processo de MPI_COMM_WORLD.

MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); //cambiamos la valor de comm_sz que va a ser igual a numeros de procesos en MPI_COMM_WORLD
MPI_Comm_rank(MPI_COMM_WORLD, &rango_processo);//Cuando el processo lea esta funcion va a almacenar su rango dentro MPI_COMM_WORLD en el variable rango_processo

simul_local=simulacion_local(a_x,b_x,a_y,b_y,a_z,b_z,N,time(NULL)+N*rango_processo);//Cada proceso llama la funcion simulacion_local
																					//y les conserva en su espacio de memoria de direction &simul_local

//Aqui respetamos lo que dijimos en los comentarios de mc_integration:
//Pusimos raiz(semilla)=time(NULL)+N*rango_processo para que el rand() del proceso pueda leer una seria de numeros diferente 
//de las serias leidas por el rand() de los otros procesos con N*rango_processo.Ademas con time(NULL) cada nueva llamada del ejecutable tiene una seria de numeros differentes para rand().
//Con eso aproximamos bien la independancia de las simulaciones entre los processos y entre cada llamada del programo.

if(rango_processo!=0){

	MPI_Send(&simul_local,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD);	//Cada processo de rango differente de cero envia su resultado de la funcion
															//simulacion_local alamacenado en la direcion &simul_local de su memoria 
															//al processo maestro (rango 0).
}

else{
 
	simul_processo[0]=simul_local;
	simul_general+=simul_local; //Recordamos que cada processo tiene un lugar en su memoria(&simul_local) donde alamceniaron el resultado de la funcion
								//simulacion_local(...). El processo 0 va a agregar progressivamente los resultados de todos los processos
	                            //en la variable simul_general.Es por eso que antes que su variable simul_local cambie, guardamos el resultado de la primera 
								//llamada de la funcion simulacion_local del processo 0 en simul_general.

	for(num_proceso=1;num_proceso<comm_sz;num_proceso++){

		MPI_Recv(&simul_local,1, MPI_DOUBLE, num_proceso,1, MPI_COMM_WORLD,MPI_STATUS_IGNORE);//El processo 0 recibe todos los simulaciones de los otros 
		                                                                                      //processos y les alamacena en la direction de memoria de 
																							  //la variable simul_local.
																							  //Aqui no utilizamos la informacione guardada
																							  //en el status de los processos mensajes.

		simul_processo[num_proceso]=simul_local;//Guardamos aqui en la variable simul_processo todos los resultados de la funcion simulacion_locale en los otros processos.
		simul_general+=simul_local;				//para calcular un aproximacion de la desviacion estandar despuès.
	}

	 	
}

if (rango_processo==0){

	int j=0;

	simul_general=(1/(double)comm_sz)*simul_general;
	
	for (j=0;j<comm_sz;j++){

		ecart_type+=pow(simul_processo[j]-simul_general,2);// Hay un problema de promediar con esta manera la varianza. 
		                                                   // ver el fin del codigo en el commentario sobre el problema de estimar la varianza
	}													   // en el caso de MPI.		

	ecart_type=sqrt((1/(double)(comm_sz-1))*ecart_type);

	printf("\n\n");

	printf("Integral sobre [%1.2f,%1.2f][%1.2f,%1.2f][%1.2f,%1.2f] de sin(x)+y+z^2:%1.8f\n\n ",a_x,b_x,a_y,b_y,a_z,b_z,simul_general);

	printf("Interval de confianza de 95/100 es :\n [%1.8f,%1.8f] \n\n",simul_general-(1.96*ecart_type)/sqrt(N),simul_general+(1.96*ecart_type)/sqrt(N));

	printf("Numero de simulaciones realizados de manera pseudo-independiente en el cluster :%d\n \n",N*comm_sz);
}

MPI_Finalize();//liberacion de los alojamientos de la memoria
return 0;

}

//Aqui los expliacaciones estan en el programo secuencial mc_integration.c para unif y simulacion_local.

double unif(double a, double b){
    return ( rand()/(double)RAND_MAX ) * (b-a) + a ;
}

double f(double x, double y,double z) { return sin(x)+y+pow(z,2); }


double simulacion_local(double a_x,double b_x,double a_y,double b_y,double a_z,double b_z,int N,int raiz){
	int i=0;

	double sim_x;
	double sim_y;
	double sim_z;
	double sim;
	
	srand(raiz); 

	for (i=0;i<N;i++){

		sim_x=unif(a_x,b_x);
		sim_y=unif(a_y,b_y);
		sim_z=unif(a_z,b_z);

		sim+=f(sim_x,sim_y,sim_z);
	}

	return (b_x-a_x)*(b_y-a_y)*(b_z-a_z)*(1/(double)N)*sim;
}



//Para hacer funcionado nuestro codigo en el cluster MPI de Nguyen con todos los contenedores trabajando:

//Suponemos que estamos en el caso donde no tenemos levantado ningun cluster MPI de Nguyen
//Pero tenemos su carpeta alpine_mpich
//Hacer cd /alpine-mpich/cluster
//Hacer ./cluster.sh up size=10 (para crear los contenedores y lo mas importante los imagines que van a permiter de enviar los documentos
//                               con nlknguyen/alpine-mpich por ejemplo)

//Ahora tenemos 10 contenedores y 3 nuevas imagenes:
// localhost:5000/mpi 
// nlknguyen/alpine-mpich
// registry

//Para nuestro caso nlknguyen/alpine-mpich es la mas importante porque va a permitir cuando vamos a "reload" el cluster de poner nuevos
//datos dentro el nodo maestro.En efecto:

//(*)Poner en la carpeta project el archivo mc_integration_MPI.c
//Ir a la carpeta project 
//Y hacer docker run --rm -it -v $(pwd):/project nlknguyen/alpine-mpich
//hacer dentro el contenedor creado por el imagen nlknguyen/alpine-mpich : mpicc mc_integration_MPI.c -o mc_integration_MPI -lm
//Quitar el contenedor y regresar a la carpeta cluster
//Hacer un reload del cluster creado con ./cluster.sh reload size=10
//Ir al contenedor maestro : ./cluster.sh login
//Para ejecutar nuestro codigo hacer por ejemplo: mpirun -n 30 ./mc_integration_MPI 1000000 0 1 1 10 0 1
//Para probar que funciona la communicacion entre los procesos y contenedores puedes probar : mpirun -n 30 ./mpi_hello_world

//Si quieres poner otros programos empezar al nivel (*)


//Problema con la varianza estimada:

//En realidad "simul_general" es:

//sum(V*f(Xi))/(com_size*N) con i=1....com_size*N con:

//Xi independiente y Xi~unif3D(ax,bx,ay,by,az,bz) 

//V es el volume :V=(a_x-b_x)(a_y-b_y)(a_z-b_z)

//simul_general permite estimar la integral con com_size*N simulaciones.(Consecuencia del teorema de MC).

//Normalmente estimamos la varianza en este caso como:

//Varianza=sum((V*f(Xi)-simul_general)^2)/((com_size*N)-1) con i=1....com_size*N (1)

//Pero hacemos eso en el aglorithmo :

//Varianza=sum(simul_local_j-simul_general)^2)/(com_size-1) con j=1....com_size (2)

//Que no corresponden a la verdad estimacion de la varianza en nuestro caso!!
//Porque la difficultad de estimar la varianza correctamente es guardar todas las simulaciones hechos en todos los processos
//despues de haber estimado el integral. (en el caso anterior 30 000 000 simulaciones).

//Pero transformé la relacion (1) para hacer transformaciones que permiten de aproximar la varianza (1) a condicion de hacer 
//dos simulaciones en cada processo:

//	>V*f(X) con X~unif3D

//	>V^2*f(x)^2 con X~unif3D

//Vamos a hacer eso en un otro codigo mc_integration_MPI_var.c porque necessitamos cambiar el simulacion_local , los MPI_Recv y MPI_Send 
//porque ahora los processos tienen que enviar al processo0 un array de 2 dimensiones al lugar de un double sencillo o de enviar 2 mensajes distinctos.
