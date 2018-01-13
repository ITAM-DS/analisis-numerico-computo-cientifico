#include<stdio.h>
#include <stdlib.h>
#include <time.h>

long matriz_size;

/*Aloja espacio en memoria para la matriz con el tamaño indicado en la ejecución del código*/
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

void imprime_matriz(double** A, long n) /*Imprime la matriz inicial*/
{
	printf("\n *************** MATRIZ INICIAL****************\n");
	long i, j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		printf("%f ",A[j][i]);
		printf("\n");
	}
}

void factoriza_lu(double** A, long n)
{
	long i,j,k;
	for(k=0;k<n;k++)
	{
	
		for(j=k+1;j<n;j++)
		{
			A[k][j]=A[k][j]/A[k][k]; /*Factores de multiplicación para la matriz L*/	
		}
		for(i=k+1;i<n;i++)
		{
			for(j=k+1;j<n;j++) /*j son las columnas*/
			{	
				A[i][j]=A[i][j] - A[i][k] * A[k][j]; /*Le hace la operación al renglón correspondiente*/
			}		
		}	
	}
}


void imprime_matriz_lu(double** A, long n)
{
	long i, j;
	float u=1, c=0;
	printf("\n *************** MATRIZ L:****************\n");
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
	
	printf("\n *************** MATRIZ U:****************\n");
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

void libera(double ** M, long n)
{
	long i;
	if (!M) return;
	for(i=0;i<n;i++)
	free(M[i]);
	free(M);
}

int main(int argc, char *argv[]) /*argc: conteo de argumentos y argv arreglo de cadenas*/
{
	if(argc !=2) /*validando que entre el parámetro del tamaño de la matriz*/
	{
		printf("Introducir el tamaño de la matriz = ");
		scanf("%lu",&matriz_size);
	}
	else
	{
		matriz_size=atol(argv[1]); /*Para que lo interprete como texto*/
	}

	double** matrix=obten_matriz(matriz_size);
	imprime_matriz(matrix,matriz_size);

	clock_t begin, end; /*Comienza el reloj*/
	double tiempo;
	begin = clock();
	factoriza_lu(matrix,matriz_size);
	end = clock();
	tiempo = ((double)(end - begin)) / CLOCKS_PER_SEC;

	imprime_matriz_lu(matrix,matriz_size);
	printf("\n*****************************************************\n");
	printf("Tamaño de la matriz :%lu \n",matriz_size);
	printf("Tiempo usado en la factorización LU : %f seconds\n",tiempo);
	printf("*******************************************************\n");
	libera(matrix,matriz_size);
	return 0;
}
