#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
	int len=0;
    char *s="Campos Verdes";
    len = strlen(s);
    if(len >0)
    {
    s=corta_string(s);
    printf("%s\n",s);
	}
    else printf("El String debe tener mas de un caracter\n");
return 0;
}