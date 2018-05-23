#include <stdio.h>
main(void){
    int c;
    int counter = 0;
    while( (c=getchar()) != '\n'){
        
        counter++;
    }
    printf("caracteres %i",counter); 
}