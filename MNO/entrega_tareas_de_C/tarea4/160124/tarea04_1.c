/*************************************************************************
# ITAM
## Maestría en Ciencia de Datos
## Tarea 04
### Metódos Numéricos y Optimización
#### Profesor: Erick Palacios
#### Alumna: Gabriela Flores Bracamontes - 160124
************************************************************************/
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

void PrintTitles(char Title[50]);
void PrintSubTitles(char Title[50]);

void PrintTitles(char Title[50])
{
printf("\n\n\n---------------------------------------------------------------------------------------------------------\n");
printf("------------------------------------------------ %s ------------------------------------------------\n", Title);
printf("---------------------------------------------------------------------------------------------------------\n");

}

void PrintSubTitles(char Title[50])
{
printf("------------------------------------------------ %s ------------------------------------------------\n", Title);
}  

int longitud_string(char *s){ //Iniciso a)
    int i=0;
    while(*s != '\0'){
    s+=1;
    i++;
    }
return i;
}

int main(void){
	PrintTitles(" Tarea 04 - Ejercicio 1");
    PrintSubTitles(" Inciso a "); 
    char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definición y declaracion.
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(string1));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(string2));

/*
Inciso b
*/
    PrintSubTitles(" Inciso b "); 
    char phrase[MAX_LONG];
    //printf("Escribe una frase que no exceda de 200 caracteres:\n");
	while(scanf("%s", phrase) != EOF){
		printf("%s -> %d\n", phrase, longitud_string(phrase));
	}
	
PrintTitles("By: Gabriela Flores Bracamontes");
return 0;
}