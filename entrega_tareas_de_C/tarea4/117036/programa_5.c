
/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 2-c*/

/*Modifica la funcion copia para que no use break pero todavia use el indice i*/

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);

/*imprime la línea con longitud mayor o igual a 80*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=80;
    while((longitud = obtenlinea()) > 0)
        if( longitud >= max){
            copia();
            printf("%s", linea_max);
        }
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
    /*Se agrega la condición para leer solo los caracteres que no esten en blanco*/
    if(c!=' ')linea[i]=c;
    /*NUeva condicion*/
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
    int aux = 1;
    while(aux){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') aux=aux-1;
        i++;
    }
}
