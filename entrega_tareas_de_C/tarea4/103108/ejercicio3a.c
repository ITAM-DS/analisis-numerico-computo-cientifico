#include<stdio.h>
#include <string.h>

char *corta_string(char *apuntador){
    if(strlen(apuntador)>1){
    	apuntador=apuntador+1;
    }
    else{
	apuntador="Error";

    }
return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
 
return 0;
}
