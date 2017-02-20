// 2) Modifica main para que sólo se llame una vez a la función getchar()


#include <stdio.h>

main(void){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    } 
}


