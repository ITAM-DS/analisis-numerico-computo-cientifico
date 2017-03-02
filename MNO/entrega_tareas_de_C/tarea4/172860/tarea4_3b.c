/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 3 inciso b:

El siguiente programa elimina el primer caracter de un string:

b) Cómo modificas la forma en que es llamada corta_string dentro de main, 
de modo que devuelva: verdes ?? (hay un espacio antes del string "verdes")

*/

#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    while(*(s=corta_string(s)) != ' ');
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}