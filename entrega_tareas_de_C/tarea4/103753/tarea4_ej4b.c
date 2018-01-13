#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s){
    int n = strlen(s);
    char *m;
    int i = 0;
    m = malloc(n);
    while(n != 0){
        *(m+i) = *(s+n-1); //se almacena char
        i++, n--;  //decrementos en indice que explora aumento indice que escribe
        *(m+i)='\0';  //char para guardar 
    }
    return m;
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