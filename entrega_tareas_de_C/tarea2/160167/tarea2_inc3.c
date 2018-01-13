//Tarea2 By Ricardo Lastra


//3)Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:
//$echo -e "hola\n" | ./ejecutable.out
//entonces el programa imprime 4

#include <stdio.h>
void main(void){
	int c;
	int i =  0;
	while(c != '\n'){
		c = getchar();
		++i;
	}
	printf("El numero de caracteres es: %i\n", i-1);
}



