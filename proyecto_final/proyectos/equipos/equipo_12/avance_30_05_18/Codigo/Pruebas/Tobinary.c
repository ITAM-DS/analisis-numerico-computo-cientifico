// Se cargan las librarias necesarias
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Definimos la longitud maxima de los numeros
static const int long_max = 10;
static const long int max_number = 4286977318;

// Se inicializan las funciones a utilizar
char *DecimalToBinary(long int integer);
long int stringToInt(void);

// Se define la funcion principal del programa
int main(void) {
	long int rand;
	char *binary;
	int contar_char = 0;
    int c1;
    char *ptr;
    char *integerS = (char *)malloc(long_max);
    char *stringInt = (char *)malloc(long_max);
    long int integerL;

    while( c1 != EOF){
        c1 = getchar();
        // Quitamos de la cuenta los "espacios" (el codigo ASCII para " " es 32)
        // Quitamos de la cuenta los "saltos de linea" (el codigo ASCII para "\n" es 10)
        // Quitamos de la cuenta los "retornos de carro" (el codifo ASCII para "\r" es 13)
        // Quitamos de la cuenta el final de un archivo EOF
        if(c1 != 32 && c1 != 10 && c1 != 13 && c1 != EOF) {
            char c2 = c1;
            integerS[contar_char]= c2;
            contar_char++;
        }
        // Contamos los "saltos de linea" que están dados por \n con codigo ASCII 10)
        // Se incluye el "retorno de carro" qie está dado por \r con codigo ASCII 13)
        // También se incluye el EOF en caso de que sea la última línea
        if(contar_char != 0 && (c1 == 10 || c1 == 13 || c1 == EOF)){
            int i;
            if(contar_char < long_max) {
                for(i = 1; i <= (long_max - contar_char); i++) {
                    strcat(stringInt, "0");
                }
            }

            strcat(stringInt, integerS);
            integerL = strtol(stringInt, &ptr, 10);
            contar_char = 0;
            memset(integerS, 0, long_max);
            memset(stringInt, 0, long_max);
            rand = integerL;
			binary = DecimalToBinary(rand);
			printf("%s\n", binary);
		}
	}
	return 0;
}

// Se define la funcion que convierte un numero de base 10 a base 2
char *DecimalToBinary(long int integer) {
	// Inicializamos las variables
	int remainder;

	// Calculamos la longitud del entero en bits
	long int length = floor(log(integer)/log(2) + 1);
	long int max = floor(log(max_number)/log(2) + 1);

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

	// El binario esa invertido, por lo que lo reordenamos
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