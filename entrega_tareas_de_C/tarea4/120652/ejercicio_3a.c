#include<stdio.h>

char *corta_string(char *apuntador){
    // Verifica que el string tenga mas de un caracter. Basta con el el caracter de la segunda
    // posicion no sea el caracter con el que terminan los strings
    if(*(apuntador+1) != '\0')
        apuntador=apuntador+1;
    else
        apuntador = "ERROR";
    return apuntador;
}

int main(void){
    // Ejemplo 1
    char *s="Campos verdes";
    s=corta_string(s);
    printf("Ejemplo que funciona: %s\n",s);
    
    // Ejemplo que deberia fallar.
    char *t="c";
    t=corta_string(t);
    printf("Ejemplo que deberia fallar: %s\n",t);
    
return 0;
}
