#include <stdio.h>

int  main(void){
    int c;
    int n=0;
    while((c = getchar()) != EOF && c!='\n'){
        n=n+1;
    }
printf("Numero de caracteres : %d\n", n); 
}
