#include <stdio.h>
main(void){
    int c;
    int num_lineas = 0;

    while( (c = getchar())!= EOF){
        if (c == '\n') {
        	num_lineas++;
        }
    }
    printf("Numero de lineas: %d\n", num_lineas);
}
