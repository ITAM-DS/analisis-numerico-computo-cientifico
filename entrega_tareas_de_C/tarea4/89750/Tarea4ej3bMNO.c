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
    while(*(s=corta_string(s)) != 'v');
    printf("%s\n",s);
return 0;
}
