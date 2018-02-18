/************************************* Arturo Gonzalez Bencomo 172906 *****************************/

/**************************************************************************************************
Instrucciones
Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin:
./ejecutable.out < archivo.txt
**************************************************************************************************/



#include <stdio.h>

int main()
{
   int c=0,contador=0;
   c = getchar();

   while(c != EOF)
   {
      printf("El valor es: %d\n", c);
      c = getchar();
      if(c==10) contador++;
   }

   printf("El total de lineas es: %d\n",contador);
   return 0;
}



