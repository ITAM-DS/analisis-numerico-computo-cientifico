#include<stdio.h>
char *corta_string(char *apuntador){
	if(!apuntador) {return "ERROR no hay al menos un caracter";}
	else {
    	apuntador=apuntador+1;
    	return apuntador;
    }
}

int main(void){
    char *s="Campos verdes";
    char *s_malo;
    printf("Pregunta a):\n");
    printf("%s\n",corta_string(s_malo));
    printf("\n");
    printf("Pregunta b):\n");
    while(*s!=' ')
    	s=corta_string(s);
    printf("%s\n",corta_string(s));
    printf("\n");

return 0;
}