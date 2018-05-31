// Daniel Sharp 138176
// Ejercicio 4A

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
    char *s = "Campos verdes";
    // Asignamos el espacio de memoria para el string. Dado que sizeof(char)=1 no es necesario incluirlo en la función
    char *str =(char *) malloc(strlen(s)+1);
    //copiamos el string a la variable str
    strcpy(str, s);
    char *s_duplicado;
    s_duplicado = duplica_string(str);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    free(str);
    return 0;
}
