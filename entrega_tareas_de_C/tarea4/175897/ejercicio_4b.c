#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *s){
    int i;
    int tam;
    char *voltea;

    voltea = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
    tam= strlen(s)-1;
  
    while(1){
        voltea[i] = s[tam];
        if(s[i] == '\0') break;
        i++;    
        tam--;
    }

    return voltea;

}

int main(void){
    char s[50] = "Campos verdes";
    char *s_voltea;
    s_voltea = voltea_string(s);
    printf("%s\n", s_voltea);
    free(s_voltea);
    return 0;
}
