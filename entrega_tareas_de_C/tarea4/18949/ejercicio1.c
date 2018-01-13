/*
 * ejercicio1.c
 *
 *  Created on: Feb 27, 2017
 *      Author: Javier Quiroz
 */


#include<stdio.h>
#include<string.h>

#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string_vieja(char s[]){
    int i;
    i=0;
    while(s[i] != '\0')
        i++;
return i;
}

int longitud_string(char *s){
    int i = 0;
    char *p = s;

    while(*(p)  != '\0') {
        p++;
        i++;
    }
return i;
}

/*
 * a) cambiar longitud_string a que use apuntadores
 *
 * Respuesta: Se presenta el driver siguiente para probar este inciso: Para ver
 * sus resultados a que cambiar
 *
 * b) Investiga el uso de la función scanf para que imprima la longitud de los
 * strings del archivo.txt: hamburguesas permisos exponencialmente 549
 *  $./ejercicio_1_scanf.out < archivo.txt
 *

longitud hamburguesas: 12
longitud permisos: 8
longitud exponencialmente: 16
longitud 549: 3

 */
int main(void){

// inciso a
	char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion.

    char string3[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    int tamanio = 0;
    printf( "a) \n");
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(string1));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(string2));



//inciso b
    printf( "b) \n");
    while ( ( tamanio = scanf( "%s", string3 ) ) > 0 )
    	printf( "Longitud %s: %d \n", string3, strlen(string3) );


    return 0;


}




