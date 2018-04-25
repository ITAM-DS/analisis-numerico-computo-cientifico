#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea(char *s);
char *duplica_string(char *s);
int longitud_string(char *s);

int main(void){    
    char *s = (char*) malloc(sizeof("Campos verdes") * sizeof(char));
    char *s_duplicado;
    char *s_voltea;
    s = "Campos Verdes";
    s_duplicado = duplica_string(s);
    s_voltea = voltea(s);
    printf("Cadena duplicada: \t%s\n", s_duplicado);
    printf("Cadena invertida: \t%s\n", s_voltea);
    printf("Cadena original : \t%s\n", s);
    free(s_duplicado);
    free(s_voltea);
    return 0;
}

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea(char *s){    

    int i, longitud ;

    char *src = malloc(longitud_string(s)+1);
    
    if(src != NULL){
        longitud = longitud_string(s);                
        for(i=longitud; i > 0 ; i--){
            src[longitud - i] = s[i-1];            
        }        
        src[longitud] = '\0';        
    }
    return src;
}


int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s++;
        i++;
    }

return i;
}