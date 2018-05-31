/*********************************** Arturo Gonzalez Bencomo - 172906 *****************************************/

/**************************************************************************************************************
Instrucciones:
3. Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número.
Al dar enter (salto de línea) el programa termina. Por ejemplo:
$echo -e "hola\n" | ./ejecutable.out
****************************************************************************************************************/


#include <stdio.h>

int main() {
   int c=0,contador=0;
   c = getchar();

   while(c != 10 && c != EOF)
   {
      printf("El valor es: %d\n", c);
      c = getchar();
      contador++;
   }

   printf("El total de caracteres es: %d\n",contador);
   return 0;
}


