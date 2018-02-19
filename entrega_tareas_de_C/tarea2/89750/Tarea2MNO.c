#include <stdio.h>
main(void){
    int c;
    int countchar = 0;
    int countline = 0;
    while((c = getchar()) != EOF){
        if(c != '\n') {
            countchar++;
	}
	else
	    countline++;
    } 
    printf("%d caracteres en stdin\n",countchar);
    printf("%d lineas en stdin\n",countline);
}
