#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
char linea_volt[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
void voltea(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=1;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            voltea();
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


/*
void voltea(char * s){
     int i=0;
     int len = 0;
     int c; 
     len = obtenlinea();
     extern char linea[];
     char linea_volt[len];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
     for(i=len;i>=0;i--){
	linea_volt[len-i] = linea[i];
}
printf("%s",linea_volt);

}

*/




void voltea(void){ 
    int i,len;
    extern char linea[], linea_max[];
    i=0;
    len =strlen(linea)-1;

    while(i <=len){
        linea_max[i] = linea[len-i];
        i++;    
    }
    printf("%s",linea_max);
}