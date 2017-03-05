#include<stdio.h>
char *corta_string(char *apuntador){
    if(*apuntador != '\0'){
        apuntador=apuntador+1;
    }
    else{
        fprintf(stderr, "El string no tiene al menos un caracter.");
    }
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}