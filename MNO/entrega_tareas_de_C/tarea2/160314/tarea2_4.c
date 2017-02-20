#include <stdio.h>
main(void){
    int c, nl=0;
    while((c = getchar()) != EOF){
    if((c = getchar()) == '\n'){
    ++nl;
    }
    }
    ++nl;
    printf("número de lineas %d\n", nl);
    
}

