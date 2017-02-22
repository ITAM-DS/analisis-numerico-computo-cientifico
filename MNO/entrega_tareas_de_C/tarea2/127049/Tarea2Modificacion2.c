#include <stdio.h>
int main(void){
    int c = getchar();
    int i =0;
    while((c = getchar()) != '\n' && c != EOF){
        i++;
    }
    printf("El numero de caracteres es %d",i);
}



