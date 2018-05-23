#include <stdio.h>
main(void){
    int cantidad = 0;
    int c;
 
    while( (c=getchar()) != EOF){
       if(c==10) // este while lee todos los caracteres de un archivo y aumenta cantidad SOLO si es igual a salto de linea.
       	 cantidad++;
    }
    printf("%i \n",cantidad);
}
