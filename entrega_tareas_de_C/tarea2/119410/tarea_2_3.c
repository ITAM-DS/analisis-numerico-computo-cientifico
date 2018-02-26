#include <stdio.h>

main(void){
    int c;
    int count = 0;
    while( (c = getchar() ) != EOF){
        if ( (c != ' ') && (c != '\n') ){
	    ++count;
        }
    }
    printf("%d\n caracteres", count);
}
