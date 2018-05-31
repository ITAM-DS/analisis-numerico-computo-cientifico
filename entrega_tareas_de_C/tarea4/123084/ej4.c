#include<stdio.h>
#include<stdlib.h>
#include<string.h>



///va funcion
char *duplica_string(char *s){  
    char *p;
    

    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/ 
        
        if(p!=NULL)  // por si no hay espacio
        
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s){
    int tam;
    char *fvolt;
    fvolt = malloc(strlen(s)+1);
    tam= strlen(s)-1;

    int j;

    while(1){
        fvolt[j] = s[tam];
        if(s[j] == '\0') break;
        j++;    
        tam--;
    }

    return fvolt;
}

int main(void){
    char *s; //hacemos s 
    char *st2 = "Campos verdes";
    char *string_v;
    s = malloc(strlen(st2)+1); // por el fin de caracter
    strcpy(s, st2);
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf(s_duplicado);
    free(s_duplicado);
    free(s);
    return 0;
}