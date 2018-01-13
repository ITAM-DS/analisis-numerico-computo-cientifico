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
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion
    while(scanf("%s",string2)==1)
    	printf("longitud %s:\t %d\n", string2, longitud_string(string2));
return 0;
}
