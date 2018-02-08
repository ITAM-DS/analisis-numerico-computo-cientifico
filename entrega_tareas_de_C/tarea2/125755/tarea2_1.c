// Tarea 2, inciso 1.
// Luis Fernando Cantú
// CU: 000125755

#include <stdio.h>
int main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();
    }
}

/*
1. Investiga lo que quieren decir las letras EOF.
¿Por qué se debe definir c como int?

EOF es un caracter especial que se utiliza en C
para indicar que se ha llegado al final de un archivo
(End Of File, en inglés).

Se debe definir a c como un int porque el tipo char es
otro tipo de entero, pero menor que int por 8 bits.
*/
