#include <stdio.h>

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
