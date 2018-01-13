/*
PUNTO A) linea: 31
PUNTO B) Linea: 16
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1);
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

// ### PUNTO B)
char *voltea_string(char *s){
    int tam;
    char *p;
    tam = strlen(s);
    p = malloc(tam+1);

    for (int i = tam; i >= 0 ; --i)
    {
    *(p+tam-i-1) = *(s+i);
    }
    *(p+tam+1)='\0';
    return p;
}

int main(void){
    // PUNTO A)
    char *s = "Campos verdes";
    // Segunda opción ocupando la función que utiliza malloc
    // char *s = duplica_string("Campos verdes");
    char *s_duplicado;
    char *s_volteado;
    s_duplicado = duplica_string(s);
    s_volteado = voltea_string(s);
    printf("Cadena original: %s\n", s);
    printf("Cadena duplicada: %s\n", s_duplicado);
    printf("Cadena volteada: %s\n", s_volteado);
    // Liberación de memoria
    free(s_duplicado);
    free(s_volteado);
    return 0;
}