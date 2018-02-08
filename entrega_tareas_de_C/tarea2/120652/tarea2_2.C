#include <stdio.h>
main(void){
    int cantidad = 0;
    while(getchar() != 10){ // 10 es salto de linea
       cantidad++;
    }
    printf("%i \n",cantidad);
}
