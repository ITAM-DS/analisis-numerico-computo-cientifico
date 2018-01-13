#include <stdio.h>
int main(void){
    int c;
    do{
        c = getchar();
        putchar(c);
    }
    while(c != EOF);
    return(0);
}