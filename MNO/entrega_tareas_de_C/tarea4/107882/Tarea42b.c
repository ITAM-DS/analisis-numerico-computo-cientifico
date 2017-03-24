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
    int longitud,i=0;
    char c;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
   while((c=getchar())!=EOF) {
      if(c != 32 && c!= '\n')  
        linea[i++]=c;
   }  
   linea[i]='\0';
   printf("\n%s\n\n", linea);
   
   return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
        if(c != 32)
          linea[i] = c;
    }
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    
    if(c==EOF) return 200;
    return i;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    do{
            linea_max[i] = linea[i];
        if(linea_max[i] == '\0') i=-1;
        i++;    
    }while(i);
}
