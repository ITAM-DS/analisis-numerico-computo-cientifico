// 4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin:

#include <stdio.h>

main(void){
    int c;
    int n;
    
    n= 0;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            n++;
        }
    } 
    printf("Numero de lineas: %d\n", n);
}


