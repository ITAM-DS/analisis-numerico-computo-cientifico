#include<stdio.h>
#include<string.h>
int longitud_string;//Para este problema, hacemos uso de la funcion de longitud

char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="";
    //Notar que en este codigo tambien podemos poner una cadena de texto y funciona bien
    //char *s="Campos verdes";
    longitud_string = strlen(s);
    if (longitud_string > 0)
    	    printf("%s\n",corta_string(s));
    else
	    printf("Error, el string debe tener, al menos, un caracter.");
return 0;
}
