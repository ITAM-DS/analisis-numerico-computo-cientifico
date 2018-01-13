#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
char *voltea(char *s);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    char *volteado;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 0)
        volteado = voltea(linea_max);
        printf("%s", volteado);
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

char *voltea(char *s){  
    char *v;
    char tem;
    int m=0, n=strlen(s);
    v = (char*) malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
    if(v!=NULL)
        strcpy(v,s);
    while(n>m){
     tem = v[m];
     v[m++] = v[--n];
     v[n] = tem;
 }
 return v;
}
