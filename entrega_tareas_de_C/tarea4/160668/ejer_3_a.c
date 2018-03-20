#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){

	char *clon = apuntador;
	int i;
	i=0;
	while(*clon != '\0'){
		i++;
		clon=clon+1;
	}

	if(i == 0)
	{
		printf("ERROR: el string debe de tener al menos un caracter");
		return apuntador;
	}
	else
	{
		apuntador=apuntador+1;
    		return apuntador;
	}    
}

int main(void){
	char *s="";
	s=corta_string(s);
	printf("%s\n",s);
 
return 0;
}

