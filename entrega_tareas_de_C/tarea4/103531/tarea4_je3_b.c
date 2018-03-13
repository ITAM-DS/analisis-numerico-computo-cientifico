#include <stdio.h>
#include <string.h>
//Modificamos la funcion original corta_string()
int main()
{
   char s1[100] = "Campos verdes";
   char s2[4] = " \n\t";
   char *ptr;
   //Voy a aplicar una funcion de token para segmentar las palabras
   ptr = strtok( s1, s2);    // Primer token con la primera palabra de $
   ptr = strtok( NULL, s2);//Tomamo el segundo token y lo imprimos
   printf( "%s\n", ptr );

   return 0;
}

