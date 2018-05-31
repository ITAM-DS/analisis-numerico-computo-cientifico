#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
	s++;
    }
return i;
}

int main(void){
    char *apuntador;
    char str1[MAX_LONG], str2[MAX_LONG], str3[MAX_LONG], str4[MAX_LONG];
// Se utilizará la función fscanf para leer desde standar input.
    fscanf(stdin, "%s %s %s %s", str1, str2, str3, str4);
    apuntador = str1;
    printf("longitud %s: %d\n", str1, longitud_string(apuntador));
    apuntador = str2;
    printf("longitud %s: %d\n", str2, longitud_string(apuntador));
    apuntador = str3;
    printf("longitud %s: %d\n", str3, longitud_string(apuntador));
    apuntador = str4;
    printf("longitud %s: %d\n", str4, longitud_string(apuntador));
    return 0;
}
