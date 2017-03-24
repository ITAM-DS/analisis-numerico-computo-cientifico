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
char *voltea_string(char *s){
    char *p;
    p = malloc(strlen(s)+1);
    if(p !=NULL){
        for(int i = strlen(s) - 1; i >= 0; i--){
            *(p + ((strlen(s) - 1) - i)) = *(s + i);
        }
        *(p + strlen(s))='\0';
    }
    return p;
}
int main(void){
    char *s = "Campos verdes";
    char *s_duplicado = malloc(strlen(s));
    s_duplicado = voltea_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    return 0;
}