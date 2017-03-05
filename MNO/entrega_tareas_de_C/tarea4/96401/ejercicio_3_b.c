#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    
    do{
        s=corta_string(s);
    }
    while(*s != ' ');
    printf("%s\n",s);
    return 0;
}