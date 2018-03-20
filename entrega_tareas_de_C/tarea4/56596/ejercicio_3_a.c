#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *corta_string(char *apuntador){
  if (strlen(apuntador) == 0) {
    printf("No puedo recortar una cadena vacia\n");
    exit(1);
  }
  apuntador = apuntador+1;
  return apuntador;
}

int main(void){
  char *s = "";
  s = corta_string(s);
  printf("%s\n",s);
  return 0;
}
