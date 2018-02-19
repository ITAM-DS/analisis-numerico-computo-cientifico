#include <stdio.h>
 
 int main()
 {
    int c=0,indice=0;
    c = getchar();
 
    while(c != EOF)
    {
       printf("Resultado igual a: %d\n", c);
       c = getchar();
       if(c==10) indice++;
    }
 
    printf("El número de letras es: %d\n",indice);
    return 0;
 }
