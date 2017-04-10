#include<string.h>
#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    int numcar=0;
    numcar = strlen(s);
    if (numcar >0){
    s=corta_string(s);
    printf("%s\n",s);
	}
    else printf("Error:Tiene menos de un caracter Â\n");
return 0;
}
