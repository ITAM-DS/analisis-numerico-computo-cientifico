#include <stdio.h>
main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}
# 2_1.C se declara como entero debido a que ela función getchar trabaja codigo ascii, donde EOF quiere decir al final del archivo.
