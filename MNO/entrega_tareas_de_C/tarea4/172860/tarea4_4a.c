/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 4 inciso a:

El siguiente programa duplica un string:

a) Modifica el programa para que en lugar de inicializar el string s con un tamaño 50
 sea dinámica su inicialización, es decir, que no tengas que escribir 50 o algún valor 
 definido para el tamaño del string s.

Utiliza malloc.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){
    size_t longitud;
    char *s;
    longitud = strlen("Campos verdes") + 1;
    s = malloc(sizeof(char) * longitud);
    strcpy(s,"Campos verdes");
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    free(s);
    return 0;
}
