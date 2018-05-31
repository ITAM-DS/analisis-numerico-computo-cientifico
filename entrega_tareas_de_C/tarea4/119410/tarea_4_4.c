#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Modificar el programa para que la inicialización del string sea dinámica
// (no predeterminar el tamaño del string) -> malloc

// Escribir una función voltea_string que reciba como parámetro char * y devuelva char *
// que regrese la frase volteada -> malloc

char *duplica_string(char *s2){
    char *p;
    p = malloc(strlen(s2)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s2);
    return p;
}

char *voltea_string(char* s2) {
  char *p;
  p = malloc(strlen(s2)+1);
  if(p!=NULL) p=s2;
  char *inicio = p; //src
  char *fin = inicio + strlen(p) -1; //dst
  char temp;
  while (fin>inicio)
  {
    temp = *inicio;
    *inicio++ = *fin;
    *fin-- = temp;

  }
  return p;
}

int main(void){
    char *s;
    char *s2;
    char *s_duplicado;
    char *s_flip;
    s = "Campos verdes";
    s2 = malloc(strlen(s)+1); //inicialización dinámica con malloc
    if(s2!=NULL) strcpy(s2,s);
    s_duplicado = duplica_string(s2);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    s_flip = voltea_string(s2);
    printf("%s\n", s_flip);
    free(s_flip);
    return 0;
}
