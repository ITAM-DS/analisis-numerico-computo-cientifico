/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 1-b*/
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

/*

scanf():  Función del header <stdio.h>, permite al usuario ingresar caracteres
desde el teclado hasta que se presione enter. En la terminal aparecera un promt
cuando sea el ciclo de esta función que permitirá, ingresar caracteres,
solo guardará la cadena que no este separada por un espacio.
La función recive como argumentos el tipo de dato que puede
ingresar el usuario, esto se puede extender a regular expressions.
Como ejemplo de string es  scanf("%s", &str);
*/


int longitud_string( char *s ){

int i =0;
    // mientras el apuntador no este vacio
    while( *s != ' ' && *s!='\0')
    {
      // incrementa el apuntador
      s = s+1;
      i++;
    }


return i;
}

int main(void){

    char cadena[MAX_LONG];




// "%[^\n]" corresponde a una regular expression que acepta carecteres diferentes a \n -> (enter).
    scanf("%[^\n]",&cadena);
    //Para contar caracteres
    int a=0;
    //Para recorrer la cadena con apuntadores
    char *l;
    l = cadena;
    int i =0;
    int j =0;

//Si el primer valor de la cadena no es el string nulo
if(l[0]!='\0'){
    //Mientras no lo sea
    while (l[0] !='\0') {
      j = 0;
      a = longitud_string(l);
      printf("longitud ");

        for( i; i<a;i++){
          printf("%c",l[i]);
        }

      printf(" : %d\n",a);
      l = &(l[a-1]);


      // Espacios intermedios
      while(l[j+1] == ' '){
        j++;
      }
      l = &(l[j+1]);

      i =0;
     }
}


return 0;
}
