#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/

// Modificar la función copia para que no use break pero que sí use el índice i
// Modificar la función copia para que no use índices y sólo use apuntadores
// Escribe una función voltea que reciba un string s e imprima el string al revés.
// Añade la función para que el programa lea líneas y las imprima volteadas
// ¿Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

// Cuando se escribe extern no se tiene que inicializar la variable adentro de la función

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
        }
    if(max > 0) {
      printf("%s\n", linea_max);
      printf("%d\n", max);
      }
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    int j;
    extern char linea[];
    for(j=0, i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++) {
        linea[i] = c;
        linea[i-j] = linea[i]; // estas 3 líneas quitan espacios de la primera línea leída
        if(linea[i] == ' ')
          j++;
      }
    if(c == '\n'){
        linea[i] = c;
        linea[i-j] = linea[i]; // estás 3 líneas quitan espacios de las demás líneas leídas
        if(linea[i] == ' ')
          j++;
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

//void voltea(void) {  //regresa las lineas volteadas
//  extern char s = linea[];
//  char e = s + strlen(s);
//  while ( --e > s ) { t = s;s++=e;e=t; }
//}
