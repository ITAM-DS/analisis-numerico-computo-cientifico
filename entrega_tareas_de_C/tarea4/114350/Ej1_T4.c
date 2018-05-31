#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

int longitud_string(char *s){ // para la parte a del ejercicio 1
    int i;
    i=0;

    while(*s != '\0'){
        i++;
        s++;
    }
        
return i;
}
 
int main(void){
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    //char string2[MAX_LONG]; //definición y declaracion.
    //printf("cadena: %s\n", string1);
    //printf("longitud cadena: %d\n", longitud_string(string1));
    //strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    char *pointer;
    pointer = string1;
    printf("longitud string1: %d\n", longitud_string(string1));
    //printf("cadena2: %s\n", string2);
    //printf("longitud cadena: %d\n", longitud_string(string2));
    char str1[MAX_LONG], str2[MAX_LONG], str3[MAX_LONG], str4[MAX_LONG];
    //char file[200];
   // file = fopen("texto.txt", "r+");
    //fgets(file, MAX_LONG, stdin);
    fscanf(stdin, "%s %s %s %s", str1, str2, str3, str4); // para la parte b del ejercicio 1

    printf("Longitud %s: %d\n", str1, longitud_string(str1));
    printf("Longitud %s: %d\n", str2, longitud_string(str2));
    printf("Longitud %s: %d\n", str3, longitud_string(str3));
    printf("Longitud %s: %d\n", str4, longitud_string(str4));

    //fclose(file);

    

return 0;
}