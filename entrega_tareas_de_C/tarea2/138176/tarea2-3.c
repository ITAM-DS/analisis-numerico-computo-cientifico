// Daniel Sharp 138176

#include <stdio.h>
main(void){
    int c, count;
    c = getchar();
    count = 0;
    while(c != 10){ // se evalúa la condición con el número 10 porque en ASCII representa el salto de línea que es lo que pide el inciso.
        c = getchar();
	count++;
    }
    printf("%i\n", count);
}
