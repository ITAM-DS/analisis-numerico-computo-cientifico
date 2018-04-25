#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
char linea[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    while((longitud = obtenlinea()) > 0) //cambio para que solo imprima las lineas de longitud mayor a 80
        if( longitud > 80){
           printf("longitud: %d, linea: %s", longitud, linea);
        }
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
 

