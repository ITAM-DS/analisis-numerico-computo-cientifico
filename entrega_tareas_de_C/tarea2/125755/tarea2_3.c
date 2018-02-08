// Tarea 2, inciso 3.
// Luis Fernando Cantú
// CU: 000125755

#include <stdio.h>
int main(void) {
  int charCount = 0;
  while (getchar() != '\n') {
    charCount++;
  }
  printf("El número de caracteres es de: %i\n", charCount);
}
