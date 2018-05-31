#include<stdio.h>
#include <string.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
void copia_sin_break(void);
void copia_sin_break_apuntador(void);
void quitaEspacios(char* s);
void voltea(char *s);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    
    /*while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 0)
        printf("%s", linea_max);
    */
        
    while((longitud = obtenlinea()) > 0)
    {       
        if(longitud > 80){
            //copia();
            copia_sin_break_apuntador();
            printf("a) Línea de mas de 80 caracteres ...\n");
            printf("%s\n", linea);
            printf("b) Línea sin espacios ...\n");
            quitaEspacios(linea);
            printf("%s\n", linea);
            printf("e) Línea al revés ...\n");
            voltea(linea);
            printf("%s\n", linea);
        }
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
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') break;
        i++;    
    }
}

/*copia_sin_break : Modifica la función copia para no usar break*/
void copia_sin_break(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(linea_max[i] != '\0'){
        linea_max[i] = linea[i];        
        i++;    
    }
}

/*copia_sin_break : Modifica la función copia para que no use índices y sólo apuntadores.*/
void copia_sin_break_apuntador(){
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(*(linea_max + i) != '\0'){
        *(linea_max +i) = *(linea + i);
        i++;    
    }
}


/* quitaEspacios: quita los espacios de una linea */
void quitaEspacios(char* s){
  char *i = s;
  char *j = s;
  while(*j != 0){
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

/* voltea: recibe un string s e imprima el string s al revés */
void voltea(char *s)
{    
    char *src = s;
    char *end = src + strlen(src) - 1;
    while (end > src){
        char t = *end;
        *end-- = *src;
        *src++ = t;
    }
}