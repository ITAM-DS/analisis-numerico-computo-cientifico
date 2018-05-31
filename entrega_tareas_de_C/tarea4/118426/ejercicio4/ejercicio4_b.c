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
    int i,n;
    n = strlen(s);
    char *p;
    p = malloc(n * sizeof(char));
    for (i=0; i<n; i++)
        p[i] = s[n-i-1];  //se le resta uno para que no copie '\0'.
    return p;
}

int main(void){
    char *s;
    char *s_duplicado;
    char *s_volteado;
    s = "Campos verdes";
    s_duplicado = duplica_string(s);
    s_volteado = voltea_string(s);
    printf("String Original: %s\n", s);
    printf("Duplicado: %s\n", s_duplicado);
    printf("volteado: %s\n", s_volteado);
    free(s_duplicado);
    free(s_volteado);
    return 0;
}
