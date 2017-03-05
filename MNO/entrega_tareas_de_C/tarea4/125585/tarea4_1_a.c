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
    }//while
return i;
}
 
int main(void){
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion.
    char *ap_string1, *ap_string2;
    ap_string1 = &string1;
    ap_string2 = &string2;
    printf("cadena: %s\n", string1);
    //printf("caracter: %c\n", *ap_string1 ); pruebita
    printf("longitud cadena: %d\n", longitud_string(ap_string1));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(ap_string2));
return 0;
}