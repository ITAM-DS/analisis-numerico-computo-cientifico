#include <stdio.h>
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
    if(max > 0)
        printf("%s", linea_max);
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i,nls=0; // se ocupan dos iteradores uno para los caracteres general y otro para los que son distintos de ' '
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n';i++)
    if(c != ' '){
        linea[nls++] = c;
    }
    if(c == '\n'){
        linea[nls] = c;
        nls++;
    }
    linea[nls]='\0'; //este caracter es necesario para almacenar strings
    return nls;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    // ambio a apuntadores, se usa el hecho que los array de char tmb son apuntadores
    while(*(linea+i) != '\0'){
        *(linea_max+i) = *(linea+i);
        //se cambia la condición de paro a formato negativo para meterla en el while (cuidado con usar linea y no linea_max...
        i++;    
    }
}

