#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    if(*apuntador == '\0'){
	return "Error";
    }
    return apuntador;
}

int main(void){
    char *s="ab";
    s=corta_string(s);
    printf("%s\n",s);
 
return 0;
}
