#include <stdio.h>
main(void){
    int c;
    int line_counter = 0;
    while( (c=getchar()) != EOF){
        
        if((c == '\n')){
        	line_counter++;
    	}
    }
    printf("lineas %i",line_counter); 
}