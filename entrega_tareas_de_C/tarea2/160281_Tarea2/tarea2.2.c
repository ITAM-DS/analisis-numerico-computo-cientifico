#include <stdio.h>

int  main(void){
    int c; //es un int porque el ultimo digito es -1 para getchar()
    //while sigue hasta que getchar() = -1 que par stdio en EOF tambien es -1
    while((c = getchar()) != EOF){
        putchar(c);
    }
}
