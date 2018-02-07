#include <stdio.h>
int main(void){
  // C guarda los caracteres en ASCII como enteros.
    int c;
    // Inicializar el contador de caracteres.
    int i = 0;
    // EOF significa End of File,
    while((c = getchar()) != EOF){
      // El programa no cuenta cuando hay saltos de linea \n, es el entero 10 en ASCII.
      if(c != 10) i++;
    }
    // Imprime el número de caracteres.
    printf("Número de caracteres en el archivo: %d\n",i);
    // Sabemos que todo ejecutó bien.
    return(0);
}
