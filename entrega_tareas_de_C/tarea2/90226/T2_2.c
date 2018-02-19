#include <stdio.h>
 
 int main() {
    int c=0,indice=0;
    c = getchar();
 
    while(c != 10 && c != EOF)
    {
       printf("Resultado igual a: %d\n", c);
       c = getchar();
       indice++;
    }
 
    printf("El número de letras es: %d\n",indice);
    return 0;
 }
