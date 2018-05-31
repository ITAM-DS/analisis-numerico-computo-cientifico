#include <stdio.h>
#include <stdlib.h>
char error[] = "Error";

char *corta_string(char *apuntador) {
  char *aux = apuntador;
  while(*aux != ' ' && aux){
    aux++;
  }
  if(*aux == ' '){
    apuntador = aux;
  }
  if (*apuntador) {
    apuntador++;
  } else {
    apuntador = error;
  }
  return apuntador;
}

int main(void) {
  char *s = "Campos verdes";
  s = corta_string(s);
  printf("%s\n", s);
  return 0;
}
