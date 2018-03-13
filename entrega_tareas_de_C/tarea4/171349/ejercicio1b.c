#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"


int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s++;
	i++;}
return i;
}
 
int main(void){
    char string[MAX_LONG]; //definición y declaracion.
	while (scanf("%s", string) != EOF){
    printf("cadena: %s\n", string);
    printf("longitud cadena: %d\n", longitud_string(string));}

return 0;
}
