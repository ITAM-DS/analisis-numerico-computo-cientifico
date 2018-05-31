#include <stdio.h>
main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}

//Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?
//EOF siginica "End Of File",es un indicador o marca de que no hay más información que recuperar de una fuente de datos, indica que se llegó al final del fichero.
//La interpretación de C como resultado de la operación de lectura en caso de ser EOF es, por lo general, -1. y por ello debe definirse como entero o int.
