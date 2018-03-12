// Luis Fernando Cantú
// CU 000125755

#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);
void voltea(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
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
    // int i;
    extern char linea[], linea_max[];
    char *p, *pm;
    p = linea;
    pm = linea_max;
    // i=0;

    // Se modifica el loop para que no tenga i.

    while(1){
        *pm = *p;
        if(*pm == '\0') break;
        pm = pm+1;
        p = p+1;
    }

    // Se modifica el loop para que no aparezca un break dentro.
    // while(linea[i] != '\0'){
    //   linea_max[i] = linea[i];
    //   i++;
    // }
    // linea_max[i] = '\0';

    // while(1){
    //     linea_max[i] = linea[i];
    //     if(linea_max[i] == '\0') break;
    //     i++;
    // }
}

void voltea(void){
  extern char linea[], linea_max[];
  char *p = linea + strlen(linea) - 2;
  char *pm = linea_max;

  while(*p){
    (*pm++) = (*p--);
  }
  (pm+1) + '\n';
  pm = '\0';
}
