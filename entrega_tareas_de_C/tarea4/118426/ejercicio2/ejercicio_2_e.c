#include<stdio.h>
#include <string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
char linea[MAXLINEA];
char linea_print[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void voltea(void);

/* Imprime todas las líneas con longitud mayor a 0*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    while((longitud = obtenlinea()) > 0){
        voltea();
        printf("%s", linea_print);
    }
return 0;
printf("\n");
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
    linea[i]='\0';
    return i;
}


// copia del arreglo "linea" al arreglo "lina_print" al revés.
// al momento de copiar se tiene problemas con los guinoes y apóstrofe  "- '"
void voltea(void){
    int i;
    int n;
    extern char linea[], linea_print[];
    i=0;
    n = strlen(linea) - 1; // se le resta 1 para que cuando copie el final de la línea, no copie el '0\'
    while(1){
        linea_print[i] = linea[n]; 
	if(linea[i] == '\0') break;
	i++;
	n--;
    }
}


