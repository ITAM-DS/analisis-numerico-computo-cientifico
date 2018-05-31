#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
// Luis Fernando Cantú
// CU 000125755

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    // Se modifica el siguiente segmento para que imprima
    // las líneas con más de 80 caracteres en lugar de la
    // línea con el mayor número de caracteres.
    while((longitud = obtenlinea()) > 0) {
      if(longitud >= 80) {
        copia();
        printf("%s", linea_max);
      }
    }
    //     if( longitud > max){
    //         max = longitud;
    //         copia();
    //     }
    // if(max > 0)
    //     printf("%s", linea_max);
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
