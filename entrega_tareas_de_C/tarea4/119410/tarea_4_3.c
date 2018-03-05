#include<stdio.h>

// Función que quita la primera palabra del string (todo antes del primer espacio)

char *corta_string(char *apuntador) {
  char *apuntador2 = apuntador;
  while (*apuntador2 != ' ') {
    apuntador2++;
  }
  apuntador2++;
  return apuntador2;
}

// Función que quita la primera letra del string
// Si el string sólo tiene una letra devuelve mensaje de error

/*char *corta_string(char *apuntador){
  size_t strlen(char *apuntador);
  if(strlen(apuntador) == 1)
    printf("string tiene sólo 1 caracter:");
  else
    apuntador=apuntador+1;
    return apuntador;
}*/

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
