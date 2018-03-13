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
    while((longitud = obtenlinea()) > 0)
        if( longitud > max && longitud < 80){ // modicacion (a)
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
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){ // mod (b)
        if (c!= ' '){						     // mod (b)		
	linea[i] = c;}else{i--;}}				     // mod (b)
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
	char *ap_linea, *ap_linea_max;
	ap_linea = &linea[0];
	ap_linea_max = &linea_max[0];
    while(*ap_linea != '\0'){                                        // mod (c) y (d)
        *ap_linea_max = *ap_linea; 				     // mod (c) y (d)
        ap_linea++;						     // mod (d)
	ap_linea_max++;    					     // mod (d)
    }
}




