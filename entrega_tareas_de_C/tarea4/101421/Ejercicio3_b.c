#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
	int i=0,len=0;
    char *s="Campos verdes";
    len = strlen(s);
    if(len >0)
    	while( s[i] != ' ')
    		i++;
    s=corta_string(s+i);
	printf("%s\n",s);
return 0;
}