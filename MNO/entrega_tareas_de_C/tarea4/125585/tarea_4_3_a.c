#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *corta_string(char *apuntador){
	int longitud_string;
	longitud_string=strlen(apuntador);
	if(longitud_string>0){
    	apuntador=apuntador+1;
	}//if 
	else{
		printf("Error, el resultado no es correcto por el tamaño del string");
	}//else
	return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
return 0;
}