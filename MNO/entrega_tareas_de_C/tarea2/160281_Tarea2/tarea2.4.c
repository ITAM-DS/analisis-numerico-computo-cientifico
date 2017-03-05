#include <stdio.h>

int  main(void){
    int c;
    int n=0;
    int l=0;
    while((c = getchar()) != EOF){
        n=n+1;
        if(c == '\n'){
        l=l+1;
        }
    }
printf("Numero de caracteres : %d\n", n); 
printf("Numero de lineas : %d\n", l); 
}
