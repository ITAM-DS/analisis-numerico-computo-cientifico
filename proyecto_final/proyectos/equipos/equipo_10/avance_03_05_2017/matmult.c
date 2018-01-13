
/**********************************************************************

(MPI) Multiplicacion A*B = C
 
*********************************************************************/

#include "stdio.h"
#include "mpi.h"
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#define N    500        /* numero de filas y columnas (supongamos que todo sera cuadrado) */


MPI_Status status;

//double a[N][N],b[N][N],c[N][N];  //matrix A, B y C
double** allocate_matrix(int rowMaxIndex, int columnMaxIndex, FILE *fp);
double** allocate_matrix_res(int rowMaxIndex,int columnMaxIndex);
void read_file(FILE *fp, int* rowMaxIndex, int* columnMaxIndex);

main(int argc, char **argv){
 printf("entrando al main");
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
 int rowMaxIndexA, columnMaxIndexA;
 int rowMaxIndexB, columnMaxIndexB;
 double **a;
 double **b;
 double **c;
 FILE *fpA, *fpB;
 //Inicializamos MPI
 MPI_Init(&argc, &argv); //inicializamos MPI
 MPI_Comm_rank(MPI_COMM_WORLD, &taskID);
 MPI_Comm_size(MPI_COMM_WORLD, &numberOfTasks);
 numberOfWorkers = numberOfTasks-1;

 //---------------------------- master ----------------------------//
 /* Cargamos los datos desde el CSV */
 
  if (taskID == 0) { 
   fpA = fopen("filename.csv","r"); // read mode
    if(fpA == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
	read_file(fpA, &rowMaxIndexA, &columnMaxIndexA);
	a = allocate_matrix(rowMaxIndexA,columnMaxIndexA, fpA);
	fpB = fopen("filename2.csv","r"); // read mode
    if(fpB == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
	read_file(fpB, &rowMaxIndexB, &columnMaxIndexB);
	b = allocate_matrix(rowMaxIndexB,columnMaxIndexB, fpB);
	if(columnMaxIndexA == rowMaxIndexB){
		c=allocate_matrix_res(rowMaxIndexA,columnMaxIndexB);
	}
	
  }
  gettimeofday(&start, 0);
  if(numberOfTasks==1){
	  numberOfWorkers=1;
  }
  averageRow = rowMaxIndexA/numberOfWorkers; 
  extra= rowMaxIndexA%numberOfWorkers;
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
    MPI_Send(&a[offset][0], rows*rowMaxIndexA, MPI_DOUBLE,destination,mtype, MPI_COMM_WORLD);
    MPI_Send(&b, rowMaxIndexB*rowMaxIndexB, MPI_DOUBLE, destination, mtype, MPI_COMM_WORLD);
    offset = offset + rows;
  }
  
  for (i=1; i<=numberOfWorkers; i++){
     mtype = 2;
     source = i;
     MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&c[offset][0], rows*rowMaxIndexA, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
  }
  gettimeofday(&stop, 0);
  /*Imprimimos parte de los datos de la matriz de resultados c */
  printf("c[0][0] = %6.2f    c[0][499] = %6.2f \n",c[0][0],c[0][rowMaxIndexA-1]);
  printf("c[499][0] = %6.2f  c[499][499] = %6.2f \n",c[rowMaxIndexA-1][0],c[rowMaxIndexA-1][rowMaxIndexA-1]);
  
  fprintf(stdout,"Tiempo = %.6f\n\n",(stop.tv_sec+stop.tv_usec*1e-6)-(start.tv_sec+start.tv_usec*1e-6));
  
   if (taskID > 0) {
     source = 0;
     mtype = 1;
     MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&a, rows*rowMaxIndexA, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
     MPI_Recv(&b, rowMaxIndexB*rowMaxIndexB, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
  
    /* Multiplicacion de matrices */
	 for (k=0; k<rowMaxIndexA; k++)
		for (i=0; i<rows; i++) {
          c[i][k] = 0.0;
		  for (j=0; j<rowMaxIndexA; j++)
			c[i][k] = c[i][k] + a[i][j] * b[j][k];
         }

     mtype = 2;
     MPI_Send(&offset, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD);
     MPI_Send(&rows, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD);
     MPI_Send(&c,  rows*rowMaxIndexA, MPI_DOUBLE, 0, mtype, MPI_COMM_WORLD);
	}  
    
  MPI_Finalize();

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

double** allocate_matrix_res(int rowMaxIndex,int columnMaxIndex){
    int idx;
	double **mat;
	int i, j;
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
	return mat;
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
