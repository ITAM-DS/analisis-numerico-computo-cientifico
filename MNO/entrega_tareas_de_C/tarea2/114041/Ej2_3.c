#include <stdio.h>
main(void){
   //inicializamos la variable que tomara el valor de cada caracter del arreglo;
   int c;

   // inicializamos el contador de caracteres;
   long num_char;
   num_char = 0;

   // recorremos el string hasta que veamos el interlineado y vamos contando el numero de caracteres;
   while ((c=getchar()) != EOF && c!='\n'){
       ++num_char;
   }

   //imprimimos el resultado;
   printf("%ld\n", num_char);
}
