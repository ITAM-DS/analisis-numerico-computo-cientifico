
/*
#include <stdio.h>
int main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}
*/

#include <stdio.h>
int main(void){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
}
