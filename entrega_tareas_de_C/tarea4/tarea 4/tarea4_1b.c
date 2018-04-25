#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

/*

scanf():  Es una función que pertenece a stdio, y permite al usuario ingresar caracteres desde el teclado
hasta que presione enter. En terminal aparecera un promt cuando sea el ciclo de esta función que permitira, desde la misma,
ingresar caracteres desde el teclado hasta que presione enter, pero solo guardara la cadena que no este separada por un espacio.
La función recive como argumentos el tipo de dato que puede
ingresar el usuario, esto se puede extender a regular expressions.  Como ejemplo de string es  scanf("%s", &str);

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

// if( longitud_string(l) <=2 ){
//   printf("longitud %s : %d \n",l,longitud_string(l));
// }else

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
