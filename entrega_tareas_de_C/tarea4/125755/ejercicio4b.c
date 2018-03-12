// Luis Fernando Cantú
// CU 000125755

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
    char *p = malloc(strlen(s) + 1);
    char *p2 = s + strlen(s) - 1;

    int i = 0;
    while(i < strlen(s)){
      p[i++] = *p2--;
    }
    return p;
}

int main(void){
    char *s = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);

    char *s_volteado;
    s_volteado = voltea_string(s);
    printf("%s\n", s_volteado);


    free(s_duplicado);
    free(s_volteado);
    return 0;
}
