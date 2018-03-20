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

    size_t tam;
    char *s;

    tam = strlen("Campos verdes") + 1;

    s = malloc(sizeof(char) * tam);

    strcpy(s,"Campos verdes");

    char *s_duplicado;

    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);


    free(s);

    return 0;
}
