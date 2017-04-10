#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
	s=s+1;
    }
return i;
}
 
int main(void){
    printf("tarea4 inciso b ----- ");
    int c;
   // char string1[] = CADENA_PRUEBA; //definicion y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definicion y declaracion.
   // printf("cadena: %s\n", string1);
   // printf("longitud cadena: %d\n", longitud_string(string1));
   // strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    //printf("cadena2: %s\n", string2);
    //printf("longitud cadena: %d\n", longitud_string(string2));
    while(scanf("%s",string2) && (c = getchar()) != EOF){
        printf("'%s' tiene longitud:%d\n", string2,longitud_string(string2));
    }
return 0;
}
