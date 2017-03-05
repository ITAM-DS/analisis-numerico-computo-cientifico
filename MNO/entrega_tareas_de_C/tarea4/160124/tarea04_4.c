/*************************************************************************
# ITAM
## Maestría en Ciencia de Datos
## Tarea 04 Ejercicio 4
### Metódos Numéricos y Optimización
#### Profesor: Erick Palacios
#### Alumna: Gabriela Flores Bracamontes - 160124
Instrucciones:
a) Modifica el programa para que en lugar de inicializar el string s con un tamaño 50 sea dinámica su inicialización, es decir, que no tengas que escribir 50 o algún valor definido para el tamaño del string s.
    Utiliza malloc.

b) Escribe una función voltea_string que reciba como parámetro un char * y devuelva un char * cuya operación sea devolver un string volteado, así, al llamar voltea_string con el string Campos verdes tenemos:
    sedrev sopmaC
El prototipo de voltea_string es:
    char *voltea_string(char *s);
    Utiliza malloc.
************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Prototipo de funciones:*/
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

char *voltea_string(char *s){
    int i=0, j = strlen(s);
    char *p;
    p = malloc(j);

    for(j = strlen(s)-1; j>=0; j--) *(p+i ++) = *(s+j);
    *(p+i)='\0';
    return p;
}

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){
    char *s = "Campos verdes";
    char *s_duplicado=malloc(strlen(s));
    char *s_volteado= malloc(strlen(s_duplicado));
    PrintTitles(" Tarea 04 - Ejercicio 4");

    PrintSubTitles("Inciso a - Duplicado");
    s_duplicado = duplica_string(s);
    s_volteado = voltea_string(s);
    printf("%s\n", s_duplicado);

    PrintSubTitles("Inciso b - Volteado");
    printf("%s\n", s_volteado);

    free(s_duplicado);
    free(s_volteado);
    PrintTitles(" By Gabs");
    return 0;

}