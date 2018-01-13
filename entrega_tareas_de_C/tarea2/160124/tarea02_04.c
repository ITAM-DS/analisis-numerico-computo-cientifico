/*************************************************************************
# ITAM
## Maestría en Ciencia de Datos
### Metódos Numéricos y Optimización
#### Profesor: Erick Palacios
#### Alumna: Gabriela Flores Bracamontes - 160124
1) Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?
 R1: EOF significa End-Of-Line y por default tiene el valor de -1. 
 R1: La variable c se define de tipo entero, poque se va a utilizar para leer los valores en ascii de los caracteres que se escriban en la consola.
2) Modifica main para que sólo se llame una vez a la función getchar()
3) Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número. Al dar enter (salto de línea) el programa termina.
4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin

Bibliografía:
http://stackoverflow.com/questions/1622092/problem-with-eof-in-c
************************************************************************/

#include <stdio.h>
#include <string.h>
int main(void){
    int c, totalc, totall;
    c = 0;
    totalc=0;
    totall=0;
    printf("---------------------------------------------------------------------\n");
    printf("Texto ingresado\n");
    printf("---------------------------------------------------------------------\n");
    while ((c = getchar()) != EOF)
	{
	if(c=='\n')  totall++;
	totalc++;
	putchar(c);
	}
    printf("---------------------------------------------------------------------\n");
    printf("| Tot. Líneas |\t Tot. Carac.|\n");
    printf("|      %d      |\t    %d     |\n", totall, totalc);
    printf("---------------------------------------------------------------------\n");
	return 0;
   }
