#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *voltea_string(char *s){
    int i=0, max=strlen(s);

    char *apuntador;
    apuntador = malloc(strlen(s)+1);
    
    while(max!=0)
    {
        *(apuntador+i) = *(s+max-1);
        i++;
        max--;
    }
     *(apuntador+i) = '\0';
    return apuntador;
 }

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
    if(p!=NULL)
        strcpy(p,s);
    return p;
}

int main(void){
    char *s = "Campos verdes";
    char *s_duplicado;
    char *s_invertido;
    s_duplicado = duplica_string(s);
    s_invertido = voltea_string(s);
    printf("Duplicado: %s\n", s_duplicado);
    printf("Invertido: %s\n", s_invertido);
    free(s_duplicado);
    free(s_invertido);
    return 0;
}


