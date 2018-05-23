#include <stdio.h>
#include<string.h>
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

  linea[i] = '\0';

  j += i;

  return j;

}

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

  int i = strlen(s);
  int j = 0;
  char mv[i];

  printf("En sentido contrario:\n");

  for (int j; j < i; j++) { // igual que en 4

    mv[j]= s[i-j-1];
  }
  printf("%s\n",mv );
  printf("\n");

}
