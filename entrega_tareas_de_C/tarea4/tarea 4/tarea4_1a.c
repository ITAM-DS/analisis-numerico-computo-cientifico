#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

/*

scanf():  Es una función que pertenece a stdio, y permite al usuario ingresar caracteres desde el teclado
hasta que presione enter. En terminal aparecera un promt cuando sea el ciclo de esta función que permitira, desde la misma,
ingresar caracteres desde el teclado hasta que presione enter, pero solo guardara la cadena que no este separada por un espacio.
La función recive como argumentos el tipo de dato que puede
ingresar el usuario, esto se puede extender a regular expressions.  Como ejemplo de string es  scanf("%s", &str);

*/


int longitud_string(char *s){

int i =0;
    while( *s != '\0')
    {
      s = s+1; // incrementa apuntador
      i++;
    }


return i;
}

int main(void){
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion.
    char cadena[MAX_LONG];
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(string1));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(string2));






return 0;
}
