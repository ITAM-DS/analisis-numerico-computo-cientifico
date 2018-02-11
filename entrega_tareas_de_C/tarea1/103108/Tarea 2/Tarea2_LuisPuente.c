#include <stdio.h>
int main(void){
    int c;
    int contador=0;
    while((c = getchar()) != EOF && c !='\n'){
        contador++;
    }

printf("Caracteres: %d \n", contador);
}

