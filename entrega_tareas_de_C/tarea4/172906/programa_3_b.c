/* 
Arturo Gonzalez Bencomo 172906

Tarea4

Ejercicio3_b
*/

#include<stdio.h>
#include <string.h>


/*prototipo de funcion*/
char *corta_string(char *apuntador);

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
	return 0;
}

char *corta_string(char *apuntador){
	int len = strlen(apuntador);
	if(len > 0) {
		apuntador=apuntador+1;
		char *ptr = " "; 		
		while (*apuntador != *ptr){			
			apuntador=apuntador+1;
		}
		apuntador=apuntador+1;
	}
	else {apuntador = "error";}	
    return apuntador;
}
