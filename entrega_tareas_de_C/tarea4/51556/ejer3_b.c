#include<stdio.h>
#include<string.h>


char *corta_string(char *apuntador){
    if(strlen(apuntador) != '\0')
	return apuntador + 1;
	else
		return "Error\n";
}



int main(void){
    char *s="Campos Verdes";
	while(*s!= ' '){
		s=corta_string(s);
	}
    printf("%s\n",s);

return 0;
}
