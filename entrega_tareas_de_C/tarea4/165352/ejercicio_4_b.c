#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *s)
{ 
int buflen = 1; 
char * src; 
char * dst; 
char * rtn; 
	if(!s) 
		return(0); 
	src = s; 
	while(*src++) 
		buflen++; 
	dst = rtn = malloc(buflen); 
	src--; 
	while(src != s) 
		*dst++ = *--src; 
	*dst = 0; 
	return(rtn); 
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
