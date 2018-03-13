#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
	int i;
	//char *string;
	i=0;
	//string=s;
    while(*s != '\0'){
        s=s+1;
	i++;
    }
return i++;
} 
int main(void){ //definición y declaracion de variable e inicializacion.
    char string[MAX_LONG]; 
    while (scanf("%s", string) != EOF)
    printf("longitud %s %lu\n", string, longitud_string(string));
  return 0;
   
}
