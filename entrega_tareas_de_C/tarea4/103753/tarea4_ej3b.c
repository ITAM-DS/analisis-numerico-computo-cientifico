#include <stdio.h>
#include <string.h>

char *corta_string(char *apuntador){
    if( strlen(apuntador)>1){
    	return apuntador+1;
    }
    else
        return "ERR: No se tiene al menos un carácter\n";
}

int main(void){
    char *s="Campos verdes";
    while(*(s=corta_string(s)) != 'v');  //se añade la condición de paro, corta string hasta encontrar v para que imprima verdas y no " verdes"
    printf("%s\n",s);
return 0;
}
