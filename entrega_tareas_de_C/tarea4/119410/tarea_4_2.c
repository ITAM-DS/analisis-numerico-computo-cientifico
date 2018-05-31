#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/

// ¿Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?
// Cuando se escribe extern no se tiene que inicializar la variable adentro de la función

/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);
char *voltea(char *p);
void copia2(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    char *s_flip;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 0) {
      printf("linea mas larga: %s\n", linea_max);
      printf("tamaño: %d\n", max);
      char *p = linea_max;
      s_flip = voltea(p);
      printf("linea mas larga volteada: %s\n", s_flip);
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

/*copia: copia del arreglo "linea" al arreglo "linea_max" - sin break, con índice*/
void copia(void){
    int i;
    int j;
    extern char linea[], linea_max[];
    i=0;
    j=1;
    while(j){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') {
          j=0;
        }
        i++;
    }
}

// función copia con apuntadores

void copia2(void){
    extern char linea[], linea_max[];
    char *p = linea;
    char *pmax = linea_max;
    while(*p){
        *pmax = *p;
        p++;
        pmax++;
    }
}

char *voltea(char *p) {
  char *inicio = p;
  char *fin = inicio + strlen(p) -1;
  char temp;
  while (fin>inicio)
  {
    temp = *inicio;
    *inicio++ = *fin;
    *fin-- = temp;

  }
  return p;
}
