#include <stdio.h>
int main(void){
    int c;
    int cont=0;
    while((c = getchar()) != EOF){

        if (c == '\n'){
	    cont++;
	}
    }

printf("Lineas: %d \n", cont);
}
