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
    char *s="";
    char *s2 = "Campos verdes";
    printf("Primer string ingresado: %s\n",s);
    printf("Segundo string ingresado: %s\n",s2);
    printf("-----------\n");

    s=corta_string(s);
    printf("%s\n",s);
    s2=corta_string(s2);
    printf("%s\n",s2);

return 0;
}
