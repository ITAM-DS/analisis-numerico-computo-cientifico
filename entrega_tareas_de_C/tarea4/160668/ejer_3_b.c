#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string((s+5));
    printf("%s\n",s);
 
return 0;
}
