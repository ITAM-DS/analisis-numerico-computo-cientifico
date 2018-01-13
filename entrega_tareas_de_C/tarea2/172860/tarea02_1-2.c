/*
Métodos Numéricos y Optimización
Tarea 02 
Ixchel G. Meza Chávez

*/

// 1) EOF es una constante simbólica que significa End Of File, y se usa para indicar que no se puede leer mas datos 
//    de la fuente de datos, la cual puede ser un archivo o el stream. Para causar un EOF se debe oprimir ctrl+D. 
//    En C los caracteres son enteros. La funcion getchar (que lee caracteres) regresa un caracter sin signo convertido a entero. 
//    En el caso de EOF, getchar regresa el valor simbólico EOF para indicar que se acabó el archivo. 
//    El valor para C de EOF es -1.

// 2) modificar main para que sólo se llame una vez la función getchar()
#include <stdio.h>
int main(){
    int c;
    c = getchar();
    c = -1;
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}
