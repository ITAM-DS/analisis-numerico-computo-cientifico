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

    char *s="Campos verdes";
    
    // Se agrega un while para que corte hasta que vea la v.
    while(s[0] != 'v')
        s=corta_string(s);

    printf("%s\n",s);
return 0;
}
