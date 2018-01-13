#include <stdio.h>
main(void){
    //inicializamos la variable que tomara el valor de cada caracter del arreglo;
    int c;

   // recorremos el string y lo imprimimos;
    while( (c=getchar()) != EOF){
        putchar(c);
    }
}
