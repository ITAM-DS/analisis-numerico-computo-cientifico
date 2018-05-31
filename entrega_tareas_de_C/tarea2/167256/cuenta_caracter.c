#include <stdio.h>
int main() {
    int contador = 0;
    while (getchar() != '\n')
        ++contador;
    printf("Número de caracteres ingresados: %ld\n", contador);
    return 0;
}
