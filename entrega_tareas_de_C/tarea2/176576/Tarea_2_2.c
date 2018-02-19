#include <stdio.h>
main(void){
    int c;
    int char_c = 0;
    while((c = getchar()) != EOF){
        if ((c != '\n') && (c != ' ')){
           char_c++;
	}
    } 
    printf("Caracteres: %d\n", char_c);
}

