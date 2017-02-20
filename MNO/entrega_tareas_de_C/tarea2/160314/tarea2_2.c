#include <stdio.h>
main(void){
    int c;
    c=getchar();
    while(c != '\n'){
    putchar(c);
    c = getchar();
    }
}

