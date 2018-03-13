#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *voltea_string(char *s);
char *duplica_string(char *s);

int main(void){
    char *s;
    s = malloc(sizeof(s));
    s = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    char *v_string;
    v_string = voltea_string(s);
    printf("%s\n", v_string);
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

char *voltea_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
    int largo = strlen(s+1);
    int i=0;
    for (i=0;i<largo;i++)
        p[i]=s[largo-1-i];
    return p;
}