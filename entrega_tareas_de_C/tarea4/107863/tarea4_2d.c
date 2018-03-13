// Este archivo tiene los puntos abc de la pregunta 4

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 80) // cambio de restriccion
        printf("%s", linea_max);
return 0;
}
 
/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n' && c!= " "; i++) //no cuenta espacios
        linea[i] = c;
    if(c == '\n' ){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}
 
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    extern char linea[], linea_max[];
    char *linea_copia;
    char *linea_max_copia;
    linea_max_copia=linea_max;

    *linea_copia = linea;
    while(*linea_copia != '\0'){ //cambio del while para quitar break
        linea_max_copia=linea_max;
        linea_copia++;    
    }

}