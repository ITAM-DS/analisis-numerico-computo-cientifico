/* 
Arturo Gonzalez Bencomo 172906

Tarea4

Ejercicio4_a
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*protipo de funciones*/
char *duplica_string(char *s);

int main(void){
    char s[] = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    return 0;
}

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}