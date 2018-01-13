#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
	s=s+1;
        i++;
    }
return i;
}

int main(void){
    char string1[MAX_LONG]; //definicin y declaracion de variable e inicializacion.
    while(scanf("%s",string1)==1){
    	printf("cadena: %s\n", string1);
    	printf("longitud cadena: %d\n", longitud_string(string1));
    }
return 0;
}
