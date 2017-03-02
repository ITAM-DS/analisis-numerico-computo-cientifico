#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    if(strlen(apuntador)>1)return apuntador+1;
    else
        return "¡peligro! te vas a quedar sin caracteres\n";
}

int main(void){
    char *s="Campos verdes";
    while(*(s=corta_string(s)) != ' ');
    printf("%s\n",s);
return 0;
}
