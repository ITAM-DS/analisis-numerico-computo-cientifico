// Daniel Sharp 138176

#include <stdio.h>
main(void){
    int c, count;
    c = getchar();
    count = 0;
    while(c != EOF){ // Se recorre el archivo mientras no se llegue a su final.
    if(c == 10){ // El if evalúa si el char actual es igual a 10, pues este representa un salto de línea en ASCII.
        count++;
      }
      c = getchar();
    }
    printf("%i\n", count);
}
