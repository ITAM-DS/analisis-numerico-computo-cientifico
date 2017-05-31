#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

long matriz_size;
double** A_master;

double** crea_espacio(long n)
{
	long i;
	double **m;
	m = (double**)malloc(n*sizeof(double*));
	for (i=0;i<n;i++)
		m[i] = (double*)malloc(n*sizeof(double));
	return m;
}

void inicia(double** A, long n)
{
	A[0][0]=2;
	A[0][1]=5;
	A[0][2]=9;
	A[0][3]=3;	
	A[1][0]=2;
	A[1][1]=6;
	A[1][2]=10;
	A[1][3]=4;
	A[2][0]=3;
	A[2][1]=7;
	A[2][2]=1;
	A[2][3]=5;	
	A[3][0]=4;
	A[3][1]=8;
	A[3][2]=2;
	A[3][3]=8;	
}

double** obten_matriz(long size)
{
	double** m=crea_espacio(size);
	inicia(m,size);
	return m;
}

void reemplaza(int pid, double* rowk,long k,long n)
{
	long i=0;
	for(i=0;i<n;i++)
	{A_master[k][i]=rowk[i];}
}

void imprime_matriz(int pid, double **A, long n)
{
	printf("\n *************** MATRIZ INICIAL****************\n");
	long i, j;
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("PID%i: %f ",pid,A[j][i]);
		}		
		printf("\n");
	}
}

void imprime_matriz_lu(double** A, long n)
{
	long i, j;
	float u=1, c=0;
	printf("\n *************** MATRIX L:****************\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if(i<j)
			printf("%f ",c);
			else if(i>j)
			printf("%f ",A[j][i]);
			else 
			printf("%f ",u);
		}
		printf("\n");
	}
	
	printf("\n *************** MATRIX U:****************\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if(i<=j)
			printf("%f ",A[j][i]);
			else 
			printf("%f ",c);
		}
		printf("\n");
	}

}

void factoriza_lu_mpi(double** A_local, long n, int argc, char* argv[])
{
	int pid; /*Procesador id*/
	int nprocs, i,j,k,p,mymin,mymax; /*nprocs:Número de procesadores, columnas y renglones y división de la matriz dependiendo del tamaño de la matriz*/
	int nrows;
	int data_tag =9999; /*Etiqueta con la que vamos a identificar que el mensaje que llegó es el que esperamos*/
	int root_process=0;
	
	MPI_Status status;
	double time_start, time_end;
	
	
	MPI_Init(&argc, &argv); /*START MPI */
	MPI_Comm_rank(MPI_COMM_WORLD, &pid); /*DETERMINE RANK OF THIS PROCESSOR*/ /*Procesadores*/
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs); /*DETERMINE TOTAL NUMBER OF PROCESSORS*/
	
	time_start=MPI_Wtime();
	double rowk[n];
	nrows=n/nprocs; /*trunca a una posición, divide el número de renglones para que les toque el mismo número a cada procesador*/
		
	mymin=pid * nrows; /*inicio de los renglones para el procesador*/
	mymax=mymin + nrows - 1; /*fin de los renglones para el procesador actual*/
	
	if(pid==nprocs-1 && (n-(mymax+1))>0) /*Cubriendo el caso en el que el número de procesadores no sea un múltiplo de la dimensión de la matriz*/
	{mymax=n-1;}

	for(k=0;k<n;k++)
	{   
		if(k>=mymin && k<=mymax)
		{
			for(j=k+1;j<n;j++)
			{
				A_local[k][j]=A_local[k][j] / A_local[k][k];
			}

			if(nprocs>1) /*Si el número de procesadores es 1, entonces no hay nada que enviar*/
			{
				for(p=pid;p<nprocs;p++) /*El último procesador no envía mensaje sólo lo recibe*/
				{
					MPI_Send(&A_local[k][0], n , MPI_DOUBLE, p, data_tag, MPI_COMM_WORLD);
				}
			}
		}

		if(nprocs>1)
		{
			if(k<=mymax)
			{
				MPI_Recv(&rowk, n, MPI_DOUBLE, MPI_ANY_SOURCE, data_tag, MPI_COMM_WORLD, &status);
								
				if(pid==nprocs-1)
					{reemplaza(pid, rowk,k,n);}
			}
		}

		for(i=(((k+1) > mymin) ? (k+1) : mymin);i<=mymax;i++)
		{
			for(j=k+1;j<n;j++)
			{
				if(nprocs>1)
				{
					A_local[i][j] = A_local[i][j] - A_local[i][k] * rowk[j];
				}
				else
				{
					A_local[i][j] = A_local[i][j] - A_local[i][k] * A_local[k][j];
				}
			}
		}
	}
	time_end=MPI_Wtime();
	MPI_Finalize();  /* EXIT MPI */
	
	if(pid==0)
	{imprime_matriz(pid,A_master,matriz_size);}
	
	if(pid==nprocs-1)
	{imprime_matriz_lu(A_master,matriz_size);}
}

void libera(double ** M, long n)
{
	long i;
	if (!M) return;
	for(i=0;i<n;i++)
		free(M[i]);
	free(M);
}

int main(int argc, char *argv[])
{

	if(argc !=2)
	{
		printf("Introducir el tamaño de la matriz = ");
		scanf("%lu",&matriz_size);
	}
	else
	{
		matriz_size=atol(argv[1]);
	}

	double** matrix=obten_matriz(matriz_size);

	A_master=obten_matriz(matriz_size);

	clock_t begin, end; /*Comienza el reloj*/
	double tiempo;
	begin = clock();

	factoriza_lu_mpi(matrix,matriz_size,argc,argv);
	end = clock();
	tiempo = ((double)(end - begin)) / CLOCKS_PER_SEC;

	/*imprime_matriz_lu(matrix,matriz_size);*/
	printf("\n*****************************************************\n");
	printf("Tamaño de la matriz :%lu \n",matriz_size);
	printf("Tiempo usado en la factorización LU : %f seconds\n",tiempo);
	printf("*******************************************************\n");
	libera(matrix,matriz_size);
	libera(A_master,matriz_size);
	return 0;
}

