//Ejercicio3 By Ricardo Lastra

//a) La funcion corta_string no hace un chequeo si el string que recibe como parámetro debe de tener al menos un caracter. Modifica esta función de modo que haga este chequeo:

//Si el string tiene más de un caracter entonces devuelve el string sin el caracter inicial.

//Si no se cumple lo anterior entonces devuelve un mensaje de error.

#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    if(strlen(apuntador) != '\0')
	return apuntador + 1;//sin el caracter inicial
	else
		return "Error, introduce algun caracter!!!\n"; //El Error
}

int main(void){
    char *s="Campos Verdes";
    

s=corta_string(s);
    printf("%s\n",s);

return 0;
}
