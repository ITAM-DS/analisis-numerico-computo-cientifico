#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *voltea_string(char *s){
    char *p;
    p = malloc(strlen(s)+1);
    int i = 0;
    int flag = 1;
    char *len = s + strlen(s) - 1;
    while(flag){
        *(p + i) = *len;
        if(*(s + i) == '\0')
            flag = 0;
        i++;
        len--;
    }
    return p;
}

int main(void){
    char *s = "Campos Verdes";
    char *p;
    p = malloc(strlen(s) + 1);
    p = s;
    char *s_duplicado;
    s_duplicado = voltea_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    return 0;
}