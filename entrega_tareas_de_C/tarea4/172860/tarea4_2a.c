/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 2 inciso a:

El siguiente programa lee un conjunto de líneas del archivo archivo.txt e imprime la línea más larga:

a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.

*/

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
#define MAX 80
/*definición de variables externas*/
//int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    //extern int max;
    extern char linea_max[MAXLINEA];
    //max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > MAX){
            //max = longitud;
            copia();
            printf("%s", linea_max);
        }
    //if(max > 0)
        //printf("%s", linea_max);
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