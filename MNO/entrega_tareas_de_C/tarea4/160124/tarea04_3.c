/*************************************************************************
# ITAM
## Maestría en Ciencia de Datos
## Tarea 04 Ejercicio 2
### Metódos Numéricos y Optimización
#### Profesor: Erick Palacios
#### Alumna: Gabriela Flores Bracamontes - 160124
Instrucciones:
a) La funcion corta_string no hace un chequeo si el string que recibe como parámetro debe de tener al menos un caracter. Modifica esta función de modo que haga este chequeo:
	Si el string tiene más de un caracter entonces devuelve el string sin el caracter inicial.
	Si no se cumple lo anterior entonces devuelve un mensaje de error.
b) Cómo modificas la forma en que es llamada corta_string dentro de main de modo que devuelva: verdes ?? (hay un espacio antes del string "verdes").
************************************************************************/

#include<stdio.h>
#include<string.h>

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
char *corta_string(char *apuntador){
	return ((strlen(apuntador))>0)? apuntador+1 :"Error la cadena está vacía";
}

int main(void){
    printf("Se utilizan las cadenas \n *s1='Campos verdes' \n *s2=''\n *s3='H'\n");
    /*Inciso a*/
    PrintSubTitles("Inciso a ");
    char *s1="Campos verdes", *s2="",*s3="H";
	printf("%s\n",corta_string(s1));

    PrintSubTitles("Inciso b ");
	/*Inciso b*/
    while(*(s1=corta_string(s1)) != ' ');
    printf("%s\n",s1);
	
    while(*(s2=corta_string(s2)) != ' ');
    printf("%s\n",s2);

    while(*(s3=corta_string(s3)) != ' ');
    printf("%s\n",s3);
    PrintTitles("By: Gabriela Flores Bracamontes");

return 0;
}