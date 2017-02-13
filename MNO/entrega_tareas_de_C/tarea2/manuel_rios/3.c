// 3) Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número.
// Al dar enter (salto de línea) el programa termina. Por ejemplo:

#include <stdio.h>

main(void){
    int c;
    int n;
    
    n= 0;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            n = n;
        }
        else{
            n++;
        }
    } 
    printf("Numero de caracteres: %d\n", n);
}


