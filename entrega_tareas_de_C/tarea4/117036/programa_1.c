/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 1-a*/
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
//Se declara el apuntado *s
int longitud_string(char *s){
    int i;
    i=0;
    // Se recorre el string con el apuntador
    while(*s != '\0')
    {
      s=s+1;
        i++;
}
return i;
}

int main(void){
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion.
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(string1));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(string2));
return 0;
}
