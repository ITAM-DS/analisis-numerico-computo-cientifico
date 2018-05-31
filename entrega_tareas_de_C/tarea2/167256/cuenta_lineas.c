#include <stdio.h>
int main() {
    int contador = 0;
    int c;
    while ((c=getchar()) != EOF)
      if(c=='\n')
        ++contador;
    printf("Número de líneas en archivo: %ld\n", contador);
    return 0;
}
