#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    int i;
    i = strlen(apuntador);
    if (i>0){
        apuntador=apuntador+1;
    }
    else{
        apuntador="Error en cadena";
    }
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    while(*(s=corta_string(s)) != ' ');{
    s=corta_string(s-1);    
    printf("%s\n",s);
}    

return 0;
}
