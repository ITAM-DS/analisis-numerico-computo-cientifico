#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
	int i;
	i=0;
	while(*s != '\0'){
		i++;
		s=s+1;
	}

return i;
}

int main(void){
    	char string1[] = CADENA_PRUEBA;
	char string2[MAX_LONG];
    	printf("cadena: %s\n", string1);
    	printf("longitud cadena: %d\n", longitud_string(string1));
	strcpy(string2, "leer libros y revistas");
	printf("cadena2: %s\n", string2);
	printf("longitud cadena: %d\n", longitud_string(string2));
return 0;
}
