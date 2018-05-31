#include <stdio.h>
#include<stdlib.h>
#include <mpi.h>

// Definimos la funcion que calcula el x al cuadrado
long double f(long double *x){
	return (*x)*(*x);
}


int main(int argc, char *argv[])
{
	int i, rank, size;

	// Iniciamos MPI, obtenemos el id del proceso y el numero de procesos
	MPI_Init (&argc, &argv);
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	MPI_Comm_size (MPI_COMM_WORLD, &size);

	// Definimos e inicializamos variables:
	long long cuenta, segmentos;
	long double x, y, dx, area = 0.0, area_segmento = 0.0, rango_inicio, rango_fin;

	//Revisamos los argumentos de entrada. Si no son exactamente 3 argumentos salimos del programa:
	if(argc <= 3 || argc > 4)
	{
		if(rank == 0)printf("Numero de argumentos erroneo: %i , se esperaban: 3\n", argc-1);
		MPI_Finalize();
		exit(0);
	}

	// Almacenamos los 3 argumentos de entrada:
	rango_inicio  = atof(argv[1]);
	rango_fin	= atof(argv[2]);
	segmentos 	= atoi(argv[3])*size;

	// Revisamos que el rank de inicio sea menor al de fin y que el número de segmentos sea mayor o igual a uno. En caso opuesto salimos del programa:
	if(rango_fin <= rango_inicio || segmentos < 1)
	{
        if(rank == 0)printf("Argumento erroneo, revisar que inicio<fin y segmentos>=1\n");
        MPI_Finalize();
        exit(0);
    }

		// Calculamos de dx:
	dx = (rango_fin-rango_inicio)/(long double)segmentos;

	// Cada procesador calcula una parte del AUC:
	for (i = rank*(segmentos/size); i<((rank+1)*(segmentos/size)); i++)
	{
	   long double x = i*dx;
	   y = f(&x);
	   area_segmento += (y*dx);
	}

	// Sumamos el area_segmento calculada por cada procesador, reduciendola al area:
	MPI_Reduce(&area_segmento, &area, 1, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0)printf("\n-------------------\n El AUC usando Riemann es: %Lf\n-------------------\n\n",area);
	MPI_Finalize();
	return 0;
}
