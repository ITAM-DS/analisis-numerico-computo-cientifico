#include <stdio.h>

main(void){
    int c;
    int count = 0;
    while( (c = getchar() ) != EOF){
        if ( c == '\n'){
	    ++count;
        }
    }
    printf("%d\n lineas", count);
}
