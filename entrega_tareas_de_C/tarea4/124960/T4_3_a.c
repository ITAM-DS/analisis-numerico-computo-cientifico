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
    char *s="";
    s=corta_string(s);    
    printf("%s\n",s);
    

return 0;
}
