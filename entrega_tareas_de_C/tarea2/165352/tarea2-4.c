#include <stdio.h>
int main(void){
    int c = 0, contador = 0;
    while(((c = getchar()) != EOF)){
	if((c == '\n'))++contador;
    }
printf("Numero de lineas es %d \n", contador);
}

/* La prueba de este código se puede realizar utilizando el archivo.txt */

