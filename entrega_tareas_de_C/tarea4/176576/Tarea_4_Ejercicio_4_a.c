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
    char *s;
    char *str_2 = "Campos verdes";
    char *string_v;
    s = malloc(strlen(str_2)+1);
    strcpy(s, str_2);
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf(s_duplicado);
    free(s_duplicado);
    free(s);
    return 0;
}

