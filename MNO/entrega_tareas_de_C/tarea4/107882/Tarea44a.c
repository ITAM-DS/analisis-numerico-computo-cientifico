#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CADENA "Campos verdes"

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){
    char *s;
    s=(char *)malloc(strlen(CADENA)+1);
    s=CADENA;
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    return 0;
}
