/*
PUNTO A) linea: 7, 38
PUNTO B) linea: 15, 35
*/
#include<stdio.h>
char *corta_string(char *apuntador){
    // ### PUNTO A)
    if(*(apuntador=apuntador+1)!='\0'){
    	return apuntador;
    }
    printf("Error: Se introdujo un único caracter\n");
    return --apuntador;
}

// ### PUNTO B)
char *corta_string_B(char *apuntador){
	if ( *(apuntador+1)=='\0' )
	{
		printf("Error: Se introdujo un único caracter\n");
		return apuntador;
	}
	printf("%s\n", apuntador);
	while(*(apuntador+1)!=' ' && *(apuntador+1)!='\0'){
		apuntador++;
	}
	return apuntador+2;
}

int main(void){
    char *s="Campos verdes";
    char *f="X";
    printf("Cadena original: %s\n", s);
    s=corta_string(s);
    printf("Quitando primer caracter: %s\n",s);
    // ### PUNTO B)
    s=corta_string_B(s);
    printf("Quitando hasta primer espacio: %s\n",s);
    printf("Intentando con un solo caracter (X): \n");
    f=corta_string(f);
    printf("%s\n", f);

return 0;
}