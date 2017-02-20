#include <stdio.h>
main(void){
    int c;
int i = 0;
    while( (c = getchar()) != EOF){
        if(c == '\n')
            i++;
    }
    printf("Lineas: %d\n", i);
}
