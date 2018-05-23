#include<stdio.h>
#include <string.h>
char *corta_string(char *apuntador){
    int n;
    n = strlen(apuntador);
    if(n)
        apuntador=apuntador+1;
    else
        apuntador = "ERROR: El string ingresado no tiene caracteres";
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    char *aux = strstr(s, " "); //buscamos donde está el caracter espacio " ".
    int position = aux - s;
    int pos = strlen(s) - position;
    s=corta_string(s+pos); //corta el "nuevo" string  que empieza con " ".
    printf("%s\n",s);
return 0;
}
