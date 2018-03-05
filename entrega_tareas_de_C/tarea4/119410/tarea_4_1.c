#include<stdio.h>
#include<string.h>

// 1a. Modificar la función longitud_string:
//     longitud_string(char *s)
//     Recorrer el string con un apuntador
//       escribir s = s+1; en el while
//       incluir una condición en el while para detener el loop.

#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    int count = 0;
    while(*s != '\0') {
        s = s+1;
        count++;
}
return count;
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
