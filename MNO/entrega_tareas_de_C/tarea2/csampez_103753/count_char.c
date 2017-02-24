#include <stdio.h>
int main(void){
    int c;
    long nc = 0;
    while( (c=getchar()) != '\n'){
        ++nc;   
    } 
    printf("El total de caracteres es %ld\n", nc);
}
