#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    int i=0;
    

    while(s[i] != ' '){
	i++;
    }

    s=corta_string(s+i);
    printf("%s\n",s);
 
return 0;
}
