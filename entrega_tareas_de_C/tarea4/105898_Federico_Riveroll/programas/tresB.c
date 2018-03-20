#include<stdio.h>
char *corta_string(char *apuntador){
    while(*apuntador != ' ')
    	apuntador=apuntador+1;
    apuntador=apuntador+1;
    if(*apuntador == '\0'){
	return "Error";
    }
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
 
return 0;
}
