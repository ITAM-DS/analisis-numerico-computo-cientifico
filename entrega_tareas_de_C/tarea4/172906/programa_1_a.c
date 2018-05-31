/* 
Arturo Gonzalez Bencomo 172906

Tarea4

Ejercicio1A
*/


#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Epale compadre"

// Definimos el prototipo de la funcion
int longitud_string(char *s);

// Funcion principal main 
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

//Hacemos como tal la implementacion de la funcion longitud_string
int longitud_string(char *s){
    int i=0;    
    while(*s != '\0'){
    	s=s+1;
    	i++;        
    }
	return i;
}
