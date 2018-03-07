#include<stdio.h>
char *corta_string(char *apuntador){
	int i=0;
	char c;
	char *error="Error: El string debe de ser de longitud mayor a 1";
	while((c=*(apuntador+i)) != '\0') i++;
	if(i==1){return error;}
    else {apuntador=apuntador+1;}
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    char *er="c";
    s=corta_string(s);
    er=corta_string(er);
    printf("%s\n",s);
    printf("%s\n", er);
    
 
return 0;
}
