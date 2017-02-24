//Tarea2 By Ricardo Lastra


//4)Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin:
//./ejecutable.out < archivo.txt



#include <stdio.h>
void main(void){
	int c;
	int i =  0;
	while(c != '\n' ){
		c = getchar();
		if (c == 10)
		++i;
	}
	printf("El numero de lineas es: %i\n", i);
}



