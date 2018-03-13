#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

/*
scanf():
La función scanf permite leer varios tipos de datos de una sola vez, tales como enteros, números decimales o cadenas de caracteres.

#include <stdio.h>
int scanf(const char *format,...);

Aquí se pueden indicar varios especificadores de formato en la variable de tipo puntero format, dependiendo del tipo que se quiere leer,
 como con printf. Si todo va bien, devuelve el número de datos leídos. Si hay algún error, devuelve EOF.
Si usamos el especificador %s para leer una cadena, la función lee caracteres hasta encontrar un espacio, un intro, un tabulador, un
 vertical o un retorno de carro. Los caracteres que lee se guardan en un array que debe ser lo suficientemente grande como para almacenarlos.
  Añade el carácter nulo al final automáticamente.
*/

int longitud_string( char *s ){

int i =0;
    while( *s != ' ' && *s!='\0')
    {
      s = s+1; // incrementa apuntador
      i++;
    }

return i;
}

int main(void){

    char cadena[MAX_LONG];

// "%[^\n]" corresponde a una regular expression que acepta carecteres diferentes a \n (enter).
    scanf("%[^\n]",&cadena);
    int a=0;
    char *l;
    l = cadena;
    int i =0;
    int j =0;

if(l[0]!='\0'){

    while (l[0] !='\0') {
      j = 0;
      a = longitud_string(l);
      printf("longitud ");

        for( i; i<a;i++){
          printf("%c",l[i]);
        }

      printf(" : %d\n",a);
      l = &(l[a-1]);

      // if( l[1] == ' ' && l[1] != '\0'){l = &(l[2]);}

      while(l[j+1] == ' '){ // Por si existen mas espacios
        j++;
      }
      l = &(l[j+1]);

      i =0;
     }
}


return 0;
}
