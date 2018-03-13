#include<stdio.h>


char *corta_string(char *apuntador){
    

    if(apuntador[0] == '\0'){
    	char *mensaje = "error, no hay ni un caracter";
    	return mensaje;
    }

    int i=0;
    while(apuntador[i]!=' '){
    	apuntador=apuntador+1;
    }
    

    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
 
return 0;
}