#include <stdio.h>
int main(void){
    int c;
    int i=0;
    c = getchar();
    while( c != '\n'){
        putchar(c);
        c = getchar(); 
        i++;  
    } 
    printf("\n%i\n", i);
    return 0;
}