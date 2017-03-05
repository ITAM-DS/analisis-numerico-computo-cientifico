

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
char linea_maxv[MAXLINEA];
/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    extern char linea_maxv[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
            voltea();
        }
    if(max > 0)
        printf("%s", linea_max);
        printf("%s\n", linea_maxv);
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
/* d)modifica la función copia para que no use índices y sólo apuntadores */
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
   int i,j;
   extern char linea[], linea_maxv[];
   i=0,j=0;
   for(i=max-1; i>=0;i--){
   linea_maxv[j] = linea[i];
   j++;
   } 

}
