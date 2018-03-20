#include<stdio.h>
#include <string.h>

char *corta_string(char *apuntador){
    if(strlen(apuntador)>1){
    	apuntador=apuntador+1;
    }
    else{
	apuntador="¡Error! El string ingresado debe tener más de un caracter.";

    }
return apuntador;
}

int main(void){
    char *s="C";
    s=corta_string(s);
    printf("%s\n",s);
 
return 0;
}
