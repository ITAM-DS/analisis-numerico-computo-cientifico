#!/bin/bash

echo"/**********************************************************************

(MPI) Multiplicacion A*B = C
 
*********************************************************************/

#include \"stdio.h\"
#include \"mpi.h\"
#include <sys/time.h>
#define N    500        /* numero de filas y columnas (supongamos que todo sera cuadrado) */


MPI_Status status;

double a[N][N],b[N][N],c[N][N];  //matrix A, B y C
       
main(int argc, char **argv){
 struct timeval start, stop; //vamos a medir cuanto tarda
 int numberOfTasks, //numero de tareas
 mtype, //tipo de mensaje
 taskID, //id de la tarea
 numberOfWorkers, //numero de workers
 source, //quien manda el mensaje
 destination, //a quien le mandan el mensaje
 rows, //filas
 averageRow, //promedio de filas por nodo
 extra, //por si no se divide completo
 offset,i,j,k;
 //first initialization
 MPI_Init(&argc, &argv); //inicializamos MPI
 MPI_Comm_rank(MPI_COMM_WORLD, &taskID);
 MPI_Comm_size(MPI_COMM_WORLD, &numberOfTasks);

 numberOfWorkers = numberOfTasks-1;

 //---------------------------- master ----------------------------//
 /* VAMOS A DECIRLE AL MAESTRO QUE INICIALICE LAS MATRICES */
 
 if (taskID == 0) { 
   for (i=0; i<N; i++) {
      for (j=0; j<N; j++) {   
		a[i][j]= 1.0;
		b[i][j]= 2.0;
		}
    }

    /* mandamos los datos de las matrices a los workers*/
 
 gettimeofday(&start, 0);
 
 averageRow = N/numberOfWorkers; 
 extra= N%numberOfWorkers;
 offset = 0;
    
 for (destination=1; destination<=numberOfWorkers; destination++){       
	if(destination<=extra){
		rows = averageRow+1;
	}else{
		rows = averageRow;
	}
    mtype = 1;
    MPI_Send(&offset, 1, MPI_INT, destination, mtype, MPI_COMM_WORLD);
    MPI_Send(&rows, 1, MPI_INT, destination, mtype, MPI_COMM_WORLD);
    MPI_Send(&a[offset][0], rows*N, MPI_DOUBLE,destination,mtype, MPI_COMM_WORLD);
    MPI_Send(&b, N*N, MPI_DOUBLE, destination, mtype, MPI_COMM_WORLD);
    offset = offset + rows;
  }

  /* Recibimos los resultados de los workers */
  for (i=1; i<=numberOfWorkers; i++){
     mtype = 2;
     source = i;
     MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&c[offset][0], rows*N, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
  }
  gettimeofday(&stop, 0);
  /*Imprimimos parte de los datos de la matriz de resultados c */
  printf(\"c[0][0] = %6.2f    c[0][499] = %6.2f \n\",c[0][0],c[0][N-1]);
  printf(\"c[499][0] = %6.2f  c[499][499] = %6.2f \n\",c[N-1][0],c[N-1][N-1]);
  
  fprintf(stdout,\"Tiempo = %.6f\n\n\",(stop.tv_sec+stop.tv_usec*1e-6)-(start.tv_sec+start.tv_usec*1e-6));

 
 } 

  /*---------------------------- workers----------------------------*/
 if (taskID > 0) {
     source = 0;
     mtype = 1;
     MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&a, rows*N, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&b, N*N, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
  
    /* Multiplicacion de matrices */
	 for (k=0; k<N; k++)
		for (i=0; i<rows; i++) {
          c[i][k] = 0.0;
		  for (j=0; j<N; j++)
			c[i][k] = c[i][k] + a[i][j] * b[j][k];
         }

     mtype = 2;
     MPI_Send(&offset, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD);
     MPI_Send(&rows, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD);
     MPI_Send(&c, rows*N, MPI_DOUBLE, 0, mtype, MPI_COMM_WORLD);
	}  
    
  MPI_Finalize();
}">mpimm.c