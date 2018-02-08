// Tarea 2, inciso 4.
// Luis Fernando Cantú
// CU: 000125755

// Este programa cuenta el Número
// de caracteres sin considerar
// los espacios en blanco.

#include <stdio.h>
#include <ctype.h>

int main(void) {
  int nc = 0;
  int nl = 0;
  int ch;

  while((ch = getchar()) != EOF) {
    if (ch != '\n' && ch != ' ') {
      ++nc;
    }
    if (ch == '\n') {
      ++nl;
    }
  }

  printf("Número de líneas: %i.\n", nl);
  printf("Número de caracteres: %i.\n", nc);
  return 0;
}
