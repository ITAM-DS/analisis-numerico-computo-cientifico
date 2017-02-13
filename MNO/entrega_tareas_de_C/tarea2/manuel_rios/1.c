// 1) Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int

// EOF significa "End of File", se indica ya que una nueva linea no es el final de un programa, sino solo de la linea
// esto hace que no se terminen lo loops

// Para que el EOF funcione, lo hace asignando un numero negativo a C, en este caso -1. De esta manera indica el final
// del archivo y por esto "c" es definido como int.


#include <stdio.h>
main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}

