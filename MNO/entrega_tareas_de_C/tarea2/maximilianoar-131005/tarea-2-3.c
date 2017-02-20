#include <stdio.h>
main(void){
    int c;
    int i = 0;
    while( (c = getchar()) != '\n'){
        i++;
    }
    printf("Largo: %d\n", i);
}
