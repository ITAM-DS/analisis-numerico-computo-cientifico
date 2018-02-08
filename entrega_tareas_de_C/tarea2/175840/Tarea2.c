#include <stdio.h>

main(void){
    int c;

    while( getchar() != EOF){
        putchar(c);
        c = getchar();
    }
}

