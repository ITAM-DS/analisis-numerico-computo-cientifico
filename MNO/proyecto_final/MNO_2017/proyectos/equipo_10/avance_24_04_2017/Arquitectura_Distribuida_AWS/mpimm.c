
/**********************************************************************

 Message Parsing Interface (MPI) Matrix Multiplication A*B = C
 
*********************************************************************/

#include "stdio.h"
#include "mpi.h"
#include <sys/time.h>
#define N    500        /* number of rows and columns in matrix */


MPI_Status status;

double a[N][N],b[N][N],c[N][N];  //matrix used 
       
main(int argc, char **argv){
 struct timeval start, stop;
 int numberOfTasks,
 mtype,
 taskID,
 numberOfWorkers,
 source,
 destination,
 rows,
 averageRow,
 extra,
 offset,i,j,k;
 //first initialization
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &taskID);
 MPI_Comm_size(MPI_COMM_WORLD, &numberOfTasks);

 numberOfWorkers = numberOfTasks-1;

 //---------------------------- master ----------------------------//
 if (taskID == 0) {
   for (i=0; i<N; i++) {
      for (j=0; j<N; j++) {   
  a[i][j]= 1.0;
  b[i][j]= 2.0;
     }
          }

    /* send matrix data to the worker tasks */
 
   gettimeofday(&start, 0);
 
          averageRow = N/numberOfWorkers; //average rows per worker
   extra= N%numberOfWorkers;  //extra rows
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

    /* wait for results from all worker tasks */
  for (i=1; i<=numberOfWorkers; i++){
     mtype = 2;
     source = i;
     MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&c[offset][0], rows*N, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
  }
  gettimeofday(&stop, 0);
 
  
  printf("Upper Left = %6.2f    Upper Right = %6.2f \n",c[0][0],c[0][N-1]);
  printf("Lower Left = %6.2f    Lower Right = %6.2f \n",c[N-1][0],c[N-1][N-1]);
  
  fprintf(stdout,"Time = %.6f\n\n",(stop.tv_sec+stop.tv_usec*1e-6)-(start.tv_sec+start.tv_usec*1e-6));

 
 } 

  /*---------------------------- worker----------------------------*/
 if (taskID > 0) {
     source = 0;
     mtype = 1;
     MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&a, rows*N, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&b, N*N, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
  
    /* Matrix multiplication */
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
} 