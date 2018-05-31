#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int base = 10;
int length = 2;

int main(void) {
	// Inicializamos las variables para el programa
	char *string = "012345671289";	// String a evaluar
	char *w;						// Substring a buscar
	int n = strlen(string);			// Longitud del string
	int m = length;				// Longitud del subestring

	// La Longitud del substring a buscar debe se menor que la del string
	if(m <= n) {
		// Inicilizamos variables de apoyo
		char *subString = (char *) malloc(m + 1);	// Variable de ayuda para generar substrings
		int i, j;									// Indice para el for-loop
		int start;									// Valor de inicio para el for-loop

		// Dependiendo si es 1 dígito o más es cómo se cálcula el valro inicial (para incluir el 0)
		if(length == 1) {
			start = (int)pow(base, length - 1) - 1;
		} else {
			start = (int)pow(base, length - 1);
		}
		int end = (int)pow(base, length) - 1;

		// Inicializamos el for-loop para generar todas las posibles combinaciones de números de longitud indicada
		for(j = start; j <= end; j++) {
			int frequency = 0;						// Variable que va a guardar las repeticiones
			char *block = (char *) malloc(length + 1);
			sprintf(block, "%d", j);
			w = block;

			// Inicializamos un for-loop para comparar la subcadena
			for(i = 0; i <= (n - m); ++i) {
				// Generamos un subString de longitud m y que vaya barriendo el string original
				strncpy(subString, string + i, m);
				
				// Comparamos los dos strings.
		    	if(!strcmp(w, subString)) {
		        	++frequency;
		    	}
			}
			
			// Imprimimos la frecuencia y probabilidad de aparicion del substring dentro del string
			printf("Frequency of %s = %d\n", w, frequency);
			printf("Probability of %s = %f\n", w, (float)frequency/n);
		}
		
	} else {
		// En caso de que no se cumpla la condición, mandamos un mensaje de error
		printf("La longitud de la subcadena w debe ser menor o igual que la cadena inicial s\n");
	}
	return 0;
}