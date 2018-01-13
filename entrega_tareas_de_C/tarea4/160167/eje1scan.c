//Tarea 4  By Ricardo Lastra

//b) Investiga el uso de la función scanf para que imprima la longitud de los strings del archivo.txt:

//The C library function int scanf(const char *format, ...) reads formatted input from stdin.

//Usamos scanf para archivo de  texto de hamburguesas


#include<stdio.h>
#include<string.h>
#define HAMBURGUESAS 200
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
	s=s+1;
        i++;
	}
return i;
}

int main(void){
    char string3[HAMBURGUESAS]; //Definimos para eje1 de Scanf
    while (scanf(" %s", string3) == 1){//el espacio despues de las comillas permite el enter en el output
	printf( "longitud %s: %d\n", string3, longitud_string(string3));
	}

return 0;
}
