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
    int i=0, j = strlen(s);
    char *p;
    p = malloc(j);

    for(j = strlen(s)-1; j>=0; j--) *(p+i ++) = *(s+j);
    *(p+i)='\0';
    return p;
}

int main(void){
    char *s = "Campos verdes";
    char *s_duplicado;
    char *s_volteado;
    s_duplicado = duplica_string(s);
    s_volteado = voltea_string(s);
    printf("El string duplicado es: %s\n", s_duplicado);
    printf("El string volteado es: %s\n",s_volteado);
    free(s_duplicado);
    free(s_volteado);
    return 0;
}
