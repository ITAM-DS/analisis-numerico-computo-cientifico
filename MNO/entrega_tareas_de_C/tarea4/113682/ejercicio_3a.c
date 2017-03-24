#include<stdio.h>
char *corta_string(char *apuntador){
    if(apuntador != NULL){
    	apuntador = apuntador + 1;
	printf("jgjg");
    }
    else
	printf("Error string vacio");

 return apuntador;
}

int main(void){
char *s;
s=corta_string(s);
printf("%s\n",s);
return 0;
}
