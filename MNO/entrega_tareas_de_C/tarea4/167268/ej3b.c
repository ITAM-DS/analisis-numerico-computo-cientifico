#include<stdio.h>
char *corta_string(char *apuntador){
    int i=0;
    while(*(apuntador+i)!='\0')
        i++;
    if(i>1){
        apuntador=apuntador+1;
        return apuntador;
    }
    else
        return "Error: La cadena es muy corta\n";
}


int main(void){
    char *s="Campos verdes";
    while(*s!=' '){ 
    	s=corta_string(s);
    }
    s = corta_string(s);
    printf("%s\n",s);

return 0;
}
