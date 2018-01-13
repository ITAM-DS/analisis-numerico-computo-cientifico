#include <stdio.h>
main(void){
    int c,n=0;
    while( (c = getchar()) != EOF){
          if (c == '\n'){
               n++;
          }
    }
    printf("Cantidad de líneas : %d\n", n); 
}