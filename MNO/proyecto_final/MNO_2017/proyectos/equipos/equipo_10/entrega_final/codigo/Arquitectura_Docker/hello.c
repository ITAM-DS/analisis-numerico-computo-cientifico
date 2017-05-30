#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MASTER 0               /* taskid of first task */
#define FROM_MASTER 1          /* setting a message type */
#define FROM_WORKER 2          /* setting a message type */
int NRA = 0;
int NRB = 0;
int NCA = 0;
int NCB = 0;
void read_file(FILE *fp, int* rowMaxIndex, int* columnMaxIndex);
double** allocate_matrix(int rowMaxIndex, int columnMaxIndex, FILE *fp);
int main (int argc, char *argv[])
{
int numtasks,              /* number of tasks in partition */
taskid,                /* a task identifier */
numworkers,            /* number of worker tasks */
source,                /* task id of message source */
dest,                  /* task id of message destination */
mtype,                 /* message type */
rows,                  /* rows of matrix A sent to each worker */
averow, extra, offset, /* used to determine rows sent to each worker */
i, j, k, rc;           /* misc */
int rowMaxIndexA, columnMaxIndexA;
int rowMaxIndexB, columnMaxIndexB;
double **a, **b;
FILE *fpA, *fpB;
rowMaxIndexA=0;
columnMaxIndexA=0;
rowMaxIndexB=0;
columnMaxIndexB=0;
MPI_Status status;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
if (numtasks < 2 ) {
  printf("Need at least two MPI tasks. Quitting...\n");
  MPI_Abort(MPI_COMM_WORLD, rc);
  exit(1);
  }

numworkers = numtasks-1;
  //Vamos a leer de los archivos
  fpA = fopen("filename.csv","r"); // read mode
  if(fpA == NULL){
perror("Error while opening the file.\n");
exit(EXIT_FAILURE);
}
  read_file(fpA, &rowMaxIndexA, &columnMaxIndexA);
  a = allocate_matrix(rowMaxIndexA,columnMaxIndexA, fpA);
  NRA=rowMaxIndexA;
  NCA=columnMaxIndexA;
  fpB = fopen("filename2.csv","r"); // read mode
  if(fpB == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
}
  read_file(fpB, &rowMaxIndexB, &columnMaxIndexB);
  b = allocate_matrix(rowMaxIndexB,columnMaxIndexB, fpB);
  NRB=rowMaxIndexB;
  NCB=columnMaxIndexB;
  double c[NRA][NCB];
  if(columnMaxIndexA!=rowMaxIndexB){
printf("Multiplicacion indefinida\n");
MPI_Abort(MPI_COMM_WORLD, rc);
exit(1);
  }

/**************************** master task ************************************/
   if (taskid == MASTER)
   {
      printf("mpi_mm has started with %d tasks.\n",numtasks);
      printf("Initializing arrays...\n");
      /* Send matrix data to the worker tasks */
      averow = NRA/numworkers;
      extra = NRA%numworkers;
      offset = 0;
      mtype = FROM_MASTER;
      for (dest=1; dest<=numworkers; dest++)
      {
         rows = (dest <= extra) ? averow+1 : averow;
         printf("Sending %d rows to task %d offset=%d\n",rows,dest,offset);
         MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&NCA, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
        // MPI_Send(&NRA, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&NCB, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         offset = offset + rows;
      }

      /* Receive results from worker tasks */
      mtype = FROM_WORKER;
      for (i=1; i<=numworkers; i++)
      {
         source = i;
         MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&c[offset][0], rows*NCB, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
         printf("Received results from task %d\n",source);
      }

      /* Print results */

      printf("******************************************************\n");
      printf("Result Matrix:\n");
      for (i=0; i<NRA; i++)
      {
         printf("\n");
         for (j=0; j<NCB; j++)
printf("%6.2f   ", c[i][j]);
      }
      printf("\n******************************************************\n");
      printf ("Done.\n");

   }


/**************************** worker task ************************************/
   if (taskid > MASTER)
   {
      mtype = FROM_MASTER;
      MPI_Recv(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&NCA, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&NCB, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      printf("Columnas de B %d\n", NCB);
      printf("rows %d\n", rows);
      for (k=0; k<NCB; k++)
         for (i=0; i<rows; i++)
         {
            c[i][k] = 1.0;
            for (j=0; j<NCA; j++)
               c[i][k] = c[i][k] + a[i][j] * b[j][k];
        printf("Imprimiendo matriz C[%d][%d] %f\n",i,k,c[i][k]);
        }
      mtype = FROM_WORKER;
      MPI_Send(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
      MPI_Send(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
      MPI_Send(&c, rows*NCB, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD);


   }

   MPI_Finalize();
}


void read_file(FILE *fp, int * rowMaxIndex, int * columnMaxIndex){
char part[1024];
    char *token;
int idx;
*rowMaxIndex = 0;
*columnMaxIndex=0;
while(fgets(part,1024,fp) != NULL){
        token = NULL;
 while((token = strtok((token == NULL)?part:NULL,",")) != NULL){
            if(*rowMaxIndex == 0){ // only want to increment column count on first loop
                *columnMaxIndex=*columnMaxIndex+1;
            }
for(idx = 0;idx<strlen(token);idx++){
                if(token[idx] == '\n'){ // this assumes there will be a \n (LF) at the end of the line
                    *rowMaxIndex=*rowMaxIndex+1;
                    break;
                }
}
 }
}
}

double** allocate_matrix(int rowMaxIndex,int columnMaxIndex, FILE *fp){
    int idx;
double **mat;
int i, j;
char part[1024];
char *token;
// allocate the matrix
    mat=malloc(sizeof(double *) * rowMaxIndex);
 if (mat == NULL){
        printf("ERROR: out of memory\n");
    }
for(idx = 0;idx<rowMaxIndex;idx++){
        mat[idx] = malloc(sizeof(double *) * columnMaxIndex);
if (mat[idx] == NULL){
            printf("ERROR: out of memory\n");
            break;
        }
    }

rewind(fp);
i = j = 0;
    while(fgets(part,1024,fp) != NULL){
        token = NULL;
        while((token = strtok((token == NULL)?part:NULL,",")) != NULL){
            mat[i][j] = atoi(token);
            j = (j+1)%columnMaxIndex;
        }
        i++;
    }

    fclose(fp);
return mat;
}