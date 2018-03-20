#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA]; //use esta variable para guardar lineas sin espacios
 
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
        copia();
        printf("%s\n", linea_max); //para que salga sin espacios
    }
        
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
    int i, j;
    extern char linea[], linea_max[];
    i=0;   //para ver espacios entre linea
    j=0;   //para copiar e ir recorriendo
    while(1){
        if(linea[i]==' '){
            i++;
        }
        else{
            linea_max[j] = linea[i];   //Copia en la nueva referencia sin espacios
            if(linea_max[j] == '\0') break;
            i++;
            j++;
        }
            
    }
}