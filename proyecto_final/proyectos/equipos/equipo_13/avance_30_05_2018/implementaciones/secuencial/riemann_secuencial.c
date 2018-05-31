#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la funcion que calcula el x al cuadrado
long double f(long double *x){
	return (*x)*(*x);
}

int main(int argc, char **argv){
	long long cuenta, segmentos;
	long double x, y, dx, area = 0.0, rango_inicio, rango_fin;

	//Revisamos los argumentos de entrada. Si no son exactamente 3 argumentos salimos del programa:
	if(argc <= 3 || argc > 4) {printf("Numero de argumentos erroneo: %i , se esperaban: 3 \n", argc-1);exit(0);}

  // Almacenamos los 3 argumentos de entrada:
  rango_inicio  = atof(argv[1]);
	rango_fin	= atof(argv[2]);
	segmentos 	= atoi(argv[3]);

  // Revisamos que el rango de inicio sea menor al de fin y que el número de segmentos sea mayor o igual a uno. En caso opuesto salimos del programa:
	if(rango_fin <= rango_inicio || segmentos < 1) {printf("Argumento erroneo, revisar que inicio<fin y segmentos>=1\n");exit(0);}

	// Calculamos de dx:
	dx = (rango_fin-rango_inicio)/(long double)segmentos;

	// Calculamos el area para cada segmento y los sumamos:
	for(cuenta = 0; cuenta < segmentos; cuenta++){
		x = cuenta*dx;
		y = f(&x);
		area += y*dx;
	}

	printf("AUC utilizando Riemann:  %Lf\n", area);

	return(0);
}
