/*************************************************************************
# ITAM
## Maestría en Ciencia de Datos
## Tarea 04 Ejercicio 2
### Metódos Numéricos y Optimización
#### Profesor: Erick Palacios
#### Alumna: Gabriela Flores Bracamontes - 160124
Instrucciones:
a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.
b) Modifica el programa para que quite los espacios de cada línea leída.
c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.
d) Modifica la función copia para que no use índices y sólo apuntadores.
e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.
f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?
************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
#define MasDe80 80

/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/
void PrintTitles(char Title[50]);
void PrintSubTitles(char Title[50]);
int obtenlinea(void); 
void copia(void);



void PrintTitles(char Title[50])
{
printf("\n---------------------------------------------------------------------------------------------------------\n");
printf("------------------------------------------------ %s ------------------------------------------------\n", Title);
printf("---------------------------------------------------------------------------------------------------------\n");

}

void PrintSubTitles(char Title[50])
{
printf("------------------------------------------------ %s ------------------------------------------------\n", Title);
}  

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    PrintSubTitles("");    
    PrintSubTitles("Inciso a");    
    printf("\n a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.\n");
    PrintSubTitles("");    
    PrintSubTitles("");    
        while((longitud = obtenlinea()) > 0)
{
        if( longitud >= MasDe80)
        {
            copia();
            printf("\n%s \n", linea_max);
         
        }
 }
    PrintTitles("By: Gabriela Flores Bracamontes");
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') break;
        i++;    
    }
}






	


