#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){  
    char *p;
    p = (char*)malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){
    char s[] = "Campos verdes";
    char *s_duplicado;
    char *n = (char*)malloc(strlen(s)+1);
    strcpy(n,s);
    s_duplicado = duplica_string(n);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    free(n);
    return 0;
}
