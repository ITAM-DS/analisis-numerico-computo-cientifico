/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 2-e*/

/*Escribe una funcion voleta que reciba un string s e imprima el string s al reves*/

#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
char printlinea[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);

/*imprime la línea con longitud mayor o igual a 80*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=80;
    while((longitud = obtenlinea()) > 0){
            voltea();
            printf("%s", printlinea);
            }
return 0;
printf("\n");
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
    /*Se agrega la condición para leer solo los caracteres que no esten en blanco*/
    if(c!=' ')linea[i]=c;
    /*NUeva condicion*/
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}

  //Generando la funcion voltea

void voltea(void) {
    /* code */
    int i;
    int n;
    extern char linea[], printlinea[];
    i=0;
    //Se resta 1 a la longitud del arreglo linea para no copiar al
    // caracter nulo '\0'
    n=strlen(linea)-1;
    while(1){
      printlinea[i]=linea[n];
      if(linea[i]=='\0') break;
      i++;
      n--;
    }
  }
