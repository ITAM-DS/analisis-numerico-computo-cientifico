// Tarea 2: Analisis numerico y optimizacion
// Autor: Victor Augusto Samayoa Donado
// Descripcion: Este programa cuenta el numero de lineas en un archivo

#include <stdio.h>
int main(void){
    int contar_char = 0, contar_line = 0;
    int c;
    while( c != EOF){
        c = getchar();
        // Quitamos de la cuenta los "espacios" (el codigo ASCII para " " es 32)
        // Quitamos de la cuenta los "saltos de linea" (el codigo ASCII para "\n" es 10)
        // Quitamos de la cuenta los "retornos de carro" (el codifo ASCII para "\r" es 13)
        // Quitamos de la cuenta el final de un archivo EOF
        if(c != 32 && c != 10 && c != 13 && c != EOF) {
            contar_char++;
        }
        // Contamos los "saltos de linea" que están dados por \n con codigo ASCII 10)
        // Se incluye el "retorno de carro" qie está dado por \r con codigo ASCII 13)
        // También se incluye el EOF en caso de que sea la última línea
        if(contar_char != 0 && (c == 10 || c == 13 || c == EOF)){
            contar_line++;
            contar_char = 0;
        }
    }
    printf("%d\n", contar_line);
    return 0;
}