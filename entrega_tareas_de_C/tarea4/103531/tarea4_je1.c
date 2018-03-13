#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    while(*(s+i) != '\0')
        i = i + 1;
//	printf("longitud: %d\n",i - 1);
return i;
}

int main(void){
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion.

    FILE *stream;
    char ss_1[1];
    char ss_2[1];
    char ss_3[1];
    char ss_4[1];
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(string1));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(string2));

    //Leemos el archivo en txt
    stream = fopen("archivo.txt","r");
    fscanf(stream, "%ss", &ss_1[0]);
    printf("longitud hamburguesas : %d\n",longitud_string(ss_1));
    fscanf(stream, "%ss", &ss_2[0]);
    printf("longitud permisos : %d\n",longitud_string(ss_2));
    fscanf(stream, "%ss", &ss_3[0]);
    printf("longitud exponencialmente : %d\n",longitud_string(ss_3));
    fscanf(stream, "%ss", &ss_4[0]);
    printf("longitud 549 : %d\n",longitud_string(ss_4));
return 0;
}
