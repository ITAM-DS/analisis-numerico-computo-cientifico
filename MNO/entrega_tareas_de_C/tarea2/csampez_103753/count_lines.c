#include <stdio.h>
int main(void){
    long nl = 0;
    int c;
    while( (c=getchar()) != EOF ) {
        if ( c == ('\n') ) {
            ++nl;
        }
    }
    printf("El total de lineas es %ld\n", nl);
}