#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
char linea_voltea[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void);
void copia(void); 
void voltea(char *s);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    extern char linea_voltea[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        copia();
        voltea(linea);
       	printf("%s", linea_voltea);
       
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
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') break;
        i++;    
    }
}




/*voltea: copia del arreglo "linea" al arreglo y lo voltea*/
void voltea(char *s){ 
    int tam;
    int i;
    extern char linea[], linea_voltea[];
    i=0;
    tam= strlen(s)-1;
  

    while(1){
        linea_voltea[i] = s[tam];
        if(s[i] == '\0') break;
        i++;    
        tam--;
    }
   
}


