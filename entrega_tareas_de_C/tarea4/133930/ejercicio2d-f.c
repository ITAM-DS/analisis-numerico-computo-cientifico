#include <stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);
void voltea(char s[]);

/*imprime la línea con tamaño más grande*/
int main(void) {
  int longitud;
  extern int max;
  extern char linea_max[MAXLINEA];
  max = 0;
  while ((longitud = obtenlinea()) > 0)
    if (longitud > 80) {
      max = longitud;
      copia();
      voltea(linea_max);
      printf("%s", linea_max);
    }
  return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void) {
  int c;
  int i;
  int j = 0;
  extern char linea[];
  for (i = 0; i < MAXLINEA - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    if (c == ' ') {
      i--;
      j++;
    } else {
      linea[i] = c;
    }
  }
  if (c == '\n') {
    linea[i] = c;
    i++;
  }
  linea[i] = '\0'; // este caracter es necesario para almacenar strings
  j += i;
  return j;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void) {
  int help = 1;
  extern char linea[], linea_max[];
  char *p_linea, *p_linea_max;
  p_linea = &linea;
  p_linea_max = &linea_max;
  while (help) {
    *p_linea_max = *p_linea;
    if (*p_linea_max == '\0') {
      help = 0;
    }
    p_linea++;
    p_linea_max++;
  }
}

void voltea(char s[]) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  char help[i];
  printf("Backwards string:\n");
  for (int j = i; j >= 0; j--) {
    help[i-j] = s[j];
    printf("%c", help[i-j]);
  }
  printf("\n");
}

/*
Extern es para hacer variables globales.
*/
