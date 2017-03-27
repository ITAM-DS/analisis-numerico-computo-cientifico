/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 3 inciso a:

El siguiente programa elimina el primer caracter de un string:

a) La funcion corta_string no hace un chequeo si el string que recibe como parámetro debe de tener al menos un caracter. 

Modifica esta función de modo que haga este chequeo:

    Si el string tiene más de un caracter entonces devuelve el string sin el caracter inicial.

    Si no se cumple lo anterior entonces devuelve un mensaje de error.

*/

#include<stdio.h>
char *corta_string(char *apuntador){
	int i;
	i=0;
	while(*(apuntador+i) != '\0')
		i++;
	if(i > 1){
		apuntador=apuntador+1;
		return apuntador;
	}
	else
		return "Error: La cadena no tiene más de un caracter\n";
    
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
return 0;
}