#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    while(s[0]!=' '){
    s=corta_string(s);
	}//
    printf("%s\n",s);
 
return 0;
}