#include <stdio.h>
int main(void){
    int c = 0, contador = 0;
    while(((c = getchar()) != EOF) && (c !='\n')){
        contador++;
    }
printf("Numero de caracteres es %d \n", contador);
}

