#include<stdio.h>
#include<string.h>


char *corta_string(char *apuntador){
    if(strlen(apuntador) != '\0')
	return apuntador + 1;//sin el caracter inicial
	else
		return "Error\n"; //El Error
}



int main(void){
    char *s="Campos Verdes";
    

s=corta_string(s);
    printf("%s\n",s);

return 0;
}
