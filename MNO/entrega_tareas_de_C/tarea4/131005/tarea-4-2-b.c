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
    while((longitud = obtenlinea()) > 0){
        if( longitud > 1){
            max = longitud;
            copia();
        }
    if(max > 0)
        printf("%s", linea_max);
    max = 0;
    }
    printf("\n");
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
    int i, aux;
    extern char linea[], linea_max[];
    i = 0;
    aux = 0;
    while(1){
        if(linea[i] == ' '){
            linea_max[aux] = linea[i + 1];
            i++;
        } else
            linea_max[aux] = linea[i];
        if(linea_max[aux] == '\0') break;
        i++;
        aux++;
    }
}
