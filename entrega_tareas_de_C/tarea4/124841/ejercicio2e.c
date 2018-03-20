#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
void voltea(char c[]); //prototipo funcion voltea
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        voltea(linea);
        if( longitud > max){
            max = longitud;
            copia();
        }
      }
    if(max > 0)
        printf("\nLinea mas larga:\n");
       voltea(linea_max);
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
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') break;
        i++;    
    }
}


/*voltea: recibe un string y lo imprime volteado*/
void voltea(char c[]){
   int i=0;
   while(*(c+i) != '\0' )
    i++;              //calcula longitud y de ahi imprime desde la  ultima posicion a la primera los caracteres del string 
   while(i>=0){
printf("%c", *(c+i)); 
 i--;
}
}
