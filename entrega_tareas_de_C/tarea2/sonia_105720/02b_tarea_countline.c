// Tarea 2
// Sonia Mendizabal 


// 4) Modifica el programa de 3) para que cuente el numero de lineas dado un archivo de stdin

#include <stdio.h>
#include <string.h>

int main(void){
    char aux;
    int c, n = 0, lineas = 0;

    while( (c = getchar()) != EOF){
        aux = c;
        
        if(aux == '\n'){
            lineas++;
        }
        n++;
    } 

    printf("count lineas %d\n", lineas);
    printf("\n");

return(0);
}
