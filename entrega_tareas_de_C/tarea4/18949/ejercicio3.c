/*
 * ejercicio3.c
 *
 *  Created on: Mar 2, 2017
 *      Author: Javier Quiroz
 */
#include<stdio.h>

char *corta_string(char *apuntador){

// inciso a)
	if ( (*apuntador == '\0') ||  (*(apuntador +1) == '\0') ) return "Error en corta_string";
    apuntador=apuntador+1;

    return apuntador;
}

int main(void){
/*
 * a) La funcion corta_string no hace un chequeo si el string que recibe como parámetro debe de
 * tener al menos un caracter. Modifica esta función de modo que haga este chequeo:
 *
 * Si el string tiene más de un caracter entonces devuelve el string sin el caracter inicial.
 * Si no se cumple lo anterior entonces devuelve un mensaje de error.
 *
 * Respuesta: Se muestra en el codigo
 *
 * b) Cómo modificas la forma en que es llamada corta_string dentro de main de modo que devuelva:
 *  verdes ?? (hay un espacio antes del string "verdes").
 *
 *   Respuesta: Se muestra en el codigo
 */
    char *s="Campos verdes";
    char *t = "a";
    char *u = "una cadena mas larga";

    s=corta_string(s);
    printf("%s\n",s);

 //inciso a)
    t=corta_string(t);
    printf("%s\n",t);

    u=corta_string(u);
    printf("%s\n",u);

// inciso b)
    s=corta_string(s+4);
    printf("%s\n",s);



return 0;
}

