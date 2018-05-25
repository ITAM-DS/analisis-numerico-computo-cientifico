// Se cargan las librarias necesarias
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Se inicializan las variables del metodo congruencial
int m = 2048;
int a = 65;
int c = 1;

// Se inicializan las funciones a utilizar
int seed(void);
int randCongruencial(int seed);
char *DecimalToBinary(int integer);


// Se define la funcion principal del programa
int main(void) {
	int x0 = seed();
	int rand;
	char *binary;
	rand = randCongruencial(x0);
	binary = DecimalToBinary(rand);
	printf("%s\n", binary);
	return 0;
}

// Se define la funcion que genera numeros pseudoaleatorios
int randCongruencial(int seed) {
	// Inicializamos los parametros del método congruencial
	int x0 = seed%m;
    return (a*x0 + c)%m;
}

// Se define la funcion que convierte un numero de base 10 a base 2
char *DecimalToBinary(int integer) {
	// Inicializamos las variables
	int remainder;

	// Calculamos la longitud del entero en bits
	int length = floor(log(integer)/log(2) + 1);
	int max = floor(log(m)/log(2) + 1);

	// Reservamos el espacio del apuntador que va a contener el binario
	char *my_binary = (char *)malloc(length);
	char *binary = (char *)malloc(max);
	char *ptr = (char *)malloc(1);

	// Inicializamos el bucle para calcular lso restos
	remainder = integer % 2;
	integer /= 2;
	sprintf(ptr, "%d", remainder);
	strcpy(my_binary, ptr);
	int counter = 1;
	while (integer > 0) {
	    remainder = integer % 2;
	    sprintf(ptr, "%d", remainder);
	    strcat(my_binary, ptr);
	    integer /= 2;
	    counter++;
	}

	// El binario esa invertido, por l oqeu lo reordenamos
	char *p1 = my_binary;
    char *p2 = my_binary + length - 1;
    while (p1 < p2) {
        char tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }

    int i;
    for(i = 1; i <= (max - length); i++) {
    	strcat(binary, "0");
    }
    
    strcat(binary, my_binary);
  	return binary;
}

// Se define la funcion que genera las "semillas"
int seed(void) {
	// Inicializamos las variables
	int seed, t, pid;

	// Solitiamos los segundos al reloj de la CPU
	t = time(NULL);

	// Solicitamos el ID del proceso
	pid = getpid();

	// Calculamos la semilla a partir de estos dos valores
	seed = abs(((t*181)*((pid - 83)*359))%104729);
	return seed;
}