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
    s=corta_string(s);
    printf("%s\n",s);
return 0;
}