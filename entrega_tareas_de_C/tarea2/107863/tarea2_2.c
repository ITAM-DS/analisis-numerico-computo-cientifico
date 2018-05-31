#include <stdio.h>
main(void){
    int c;
    
    while( c = getchar()!= EOF){
        putchar(c);
        c = getchar();   
    } 
}