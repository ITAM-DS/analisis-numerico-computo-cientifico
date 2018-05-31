#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *s){  
    char *end = s + strlen(s) - 1;
    while (end > s)
    {
        char t = *end;
        *end-- = *s;
        *s++ = t;
    }
}


int main(void){
    char *s;
    s = (char *) malloc(sizeof(int)*10);
    strcpy(s,"Campos verdes");
    char *s_volteado;
    s_volteado = voltea_string(s);
    printf("%s\n", s_volteado);

    return 0;
}
