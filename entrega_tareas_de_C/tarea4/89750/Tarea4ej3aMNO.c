#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    if(strlen(apuntador)>1){
    return apuntador+1;
    }
    else
	return "Error: El string no cuenta con al menos un caracter \n";
}

int main(void){
    char *s="Campos verdes";
    char *s2="H";
    s=corta_string(s);
    s2=corta_string(s2);
    printf("El primer string cortado es: %s\n",s);
    printf("El segundo string cortado es: %s\n",s2);
return 0;
}
