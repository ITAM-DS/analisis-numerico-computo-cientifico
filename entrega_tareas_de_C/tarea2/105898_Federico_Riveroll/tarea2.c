#include <stdio.h>
// Tarea 2, Federico Riveroll

// 1) EOF quiere decir End Of File, y la funcion getchar lanza una funcion para que el usuario
// en consola escriba un caracter y lo envie con Enter, pero recibe su valor clave en forma de numero, por eso c debe ser entero. La funcion putchar lo imprime en consola (vuelve a convertir la clave en valor del caracter para el humano).



main(void){

    // 2) Programa modificado para poner la condicion en el while.

//    int c;
//    while( c = getchar()){
//	putchar(c);
//	printf("algo");
//    } 


    // 3) contar caracteres

//    int c;
//    int i = 0;
//    while((c = getchar()) != EOF && c != '\n'){
//	i ++;
//    } 
//    printf("Total de caracteres: ");
//    printf("%d", i);
//    printf("\n---\n");


     // 4) Leer linea por linea y contar

   static const char filename[] = "archivo.txt";
   FILE *file = fopen ( filename, "r" );
   int cuenta_lineas = 0;
   if ( file != NULL )
   {
      char line [ 128 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
         fputs ( line, stdout ); /* write the line */
	 cuenta_lineas ++;
      }
      fclose ( file );
      printf("Total de lineas: ");
      printf("%d", cuenta_lineas);
      printf("\n ------ \n");
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }
   return 0;
}




