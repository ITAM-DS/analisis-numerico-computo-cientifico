// Tarea 2: Analisis numerico y optimizacion
// Autor: Victor Augusto Samayoa Donado
// Descripcion: Este programa cuenta el numero de caracteres en un string

#include <stdio.h>
int main(void){
    int contar = 0;
    int c;
    while( c != EOF){
        c = getchar();
        // Quitamos de la cuenta los "espacios" (el codigo ASCII para " " es 32)
        // Quitamos de la cuenta los "saltos de linea" (el codigo ASCII para "\n" es 10)
        // Quitamos de la cuenta los "retornos de carro" (el codifo ASCII para "\r" es 13)
        // Quitamos de la cuenta el final de un archivo EOF
        if(c != 32 && c != 10 && c != 13 && c != EOF) {
            contar++;
        }
	}
	printf("%d\n", contar);
	return 0;
}