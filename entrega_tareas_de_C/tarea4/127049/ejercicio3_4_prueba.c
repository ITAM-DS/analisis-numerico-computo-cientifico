#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
     int i;
     i=0;
	while(apuntador[i] !=0)
	i++;
	if(i>1){
		apuntador=apuntador+1;
     		return apuntador;
	}
	else
	return "La cadena es de longitud 1 \n";
}

int main(void){
    char *s="Campos verdes";
    while(*(s=corta_string(s))!=' '); 
    s=corta_string(s);
    printf("%s\n",s);
return 0;
}
