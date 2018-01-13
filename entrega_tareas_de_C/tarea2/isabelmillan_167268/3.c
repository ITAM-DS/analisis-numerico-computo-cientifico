#include <stdio.h>
int main(void){
    int c;
    int n =0;

	 while( (c = getchar()) != '\n'){
        	n++;
	}
    printf("El número de caracteres es %d\n", n);
}
