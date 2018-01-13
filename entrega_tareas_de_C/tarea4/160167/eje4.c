//Ejercicio 4 By Ricardo Lastra
//a) Modifica el programa para que en lugar de inicializar el string s con un tamaño 50 sea dinámica su inicialización, es decir, que no tengas que escribir 50 o algún valor definido para el tamaño del string s.
//Utiliza malloc.


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
    char *sPoint = "Campos verdes";//INCISO a)
    char *r;
    char *s_duplicado;
    r = sPoint;
    r = malloc(strlen(sPoint));//Usando Malloc
    s_duplicado = duplica_string(sPoint);
    printf("%s\n", s_duplicado);
    printf("Adress: %p\n", sPoint);
    free(s_duplicado);
    return 0;
}
