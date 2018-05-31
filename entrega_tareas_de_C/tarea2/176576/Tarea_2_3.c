#include <stdio.h>
main(void){
    int c;
    int line_c = 0;
    while((c = getchar()) != EOF){
	if ((c == '\n')) {
	   line_c++;
	}    
    } 
    printf("Lineas: %d \n", line_c);
}

