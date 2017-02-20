#include <stdio.h>
main(void){
    int c,n=0;
    while( (c = getchar()) != '\n'){
        n++;
    }
    printf("Cantidad de letras : %d\n", n-1); 
}