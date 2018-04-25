#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *chr)
{ 
int len = 1; 
char * a; 
char * b; 
char * c; 
	if(!chr) 
		return(0); 
	a = chr; 
	while(*a++) 
		len++; 
	b = c = malloc(len); 
	a--; 
	while(a != chr) 
		*b++ = *--a; 
	*b = 0; 
	return(c); 
}

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

int main(void){

	char *s;	
	s = "Campos verdes";
	char *s_duplicado;
	char *s_volteado;

	s_duplicado = duplica_string(s);
	printf("%s\n", s_duplicado);
	free(s_duplicado);

	s_volteado = voltea_string(s);
	printf("%s\n", s_duplicado);
	free(s_volteado);	
  	return 0;
}
