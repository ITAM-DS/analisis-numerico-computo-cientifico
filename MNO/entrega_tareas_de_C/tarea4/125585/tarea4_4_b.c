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
    int longitud_linea, avance;
    longitud_linea = strlen(s);
    char *volteado= malloc(sizeof(s)+1);
    //extern char linea[];
    *(volteado +longitud_linea)='\0'; //para que sea un string
    for(avance=0; avance < longitud_linea; avance++){
        *(volteado+longitud_linea-avance-1)= *(s+avance);
    }//for
    //printf("%s",volteado);
    return volteado;
}// char *voltea_string(char *s)


int main(void){
    char s[50] = "Campos verdes";
    char *s_duplicado;
    char *volteado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);

    volteado = voltea_string(s);
    printf("%s\n", volteado );
    free(s_duplicado);
    return 0;
}