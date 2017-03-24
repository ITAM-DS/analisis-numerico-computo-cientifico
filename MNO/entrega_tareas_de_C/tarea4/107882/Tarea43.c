#include<stdio.h>

char *corta_string(char *apuntador){
    if((*apuntador)!='\0')
    	apuntador=apuntador+1;
    else
      apuntador="Ha ocurrido un error, la cadena está vacía";
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s+5);
    printf("%s\n",s);

return 0;
}
