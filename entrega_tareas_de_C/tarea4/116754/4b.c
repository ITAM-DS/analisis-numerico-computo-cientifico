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
    int length = strlen(s);
    char *p;
    int i=0;
    p = malloc(length);
    while(length != 0){
        *(p+i) = *(s+length-1);
        i++, length--;
        *(p+i)='\0';
    }
    return p;
}
    

int main(void){
    char *s = "Campos verdes";
    char *s_duplicado = malloc(strlen(s));
    char *s_volteado = malloc(strlen(s));
    s_duplicado = duplica_string(s);
    s_volteado = voltea_string(s_duplicado);
    printf("%s\n", s_volteado);
    free(s_volteado);
    free(s_duplicado);
    return 0;
}
