#include <stdio.h>
int main(void){
    int c;
    int cont=0;
    while((c = getchar()) != EOF && c !='\n'){
        cont++;
    }

printf("Caracteres: %d \n", cont);
}
