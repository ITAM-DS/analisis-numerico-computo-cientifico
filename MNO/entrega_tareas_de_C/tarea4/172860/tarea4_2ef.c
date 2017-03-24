/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 2 incisos e y f:

El siguiente programa lee un conjunto de líneas del archivo archivo.txt e imprime la línea más larga:

e) Escribe una función voltea que reciba un string s e imprima el string s al revés. 
Añade esta función para que el programa lea líneas y las imprima volteadas.

f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

Las variables extern obtienen su valor y de la variable externa declarada y definida afuera de las
funciones, por lo que su valor se tiene un tiempo de vida permanente entre llamados de una función a otra. 
Además su valor puede ser modificado en las funciones.

*/

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(void);

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
    if(max > 0)
        printf("%s", linea_max);
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
    voltea();
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

void voltea(void){
    extern char linea[];
    char nueva_linea[MAXLINEA];
    int i, index, lon;
    index=0;
    lon=0;
    while(linea[lon] != '\0')
        lon++;
    for(i= lon -1 ; i >= 0; i--){
        nueva_linea[index]=linea[i];
        index++;
    }
    nueva_linea[index]='\0';
    printf("%s", nueva_linea);
}