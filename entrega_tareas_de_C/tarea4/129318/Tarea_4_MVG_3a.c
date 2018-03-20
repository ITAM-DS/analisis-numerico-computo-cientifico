#include<stdio.h>
#include<string.h>

char *corta_string(char *apuntador){

    if(strlen(apuntador) > 0){
      apuntador = apuntador + 1;
    } else{
      apuntador = "Error, debes ingresar un string con mas de un caracter";
    }

    // apuntador=apuntador+1;
    return apuntador;
}

int main(void){
	char *s="";
	s=corta_string(s);
	printf("%s\n",s);

return 0;
}
