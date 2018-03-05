#include<stdio.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/

// Modificar la función copia para que no use break pero que sí use el índice i
// Modificar la función copia para que no use índices y sólo use apuntadores
// Escribe una función voltea que reciba un string s e imprima el string al revés.
// Añade la función para que el programa lea líneas y las imprima volteadas
// ¿Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

// Cuando se escribe extern no se tiene que inicializar la variable adentro de la función

/*definición de variables externas*/
int max;
char linea[MAXLINEA];

int main(void){
    int longitud;
    extern int max;
    extern char line[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 0) {
      printf("%s\n", linea_max);
      printf("%d\n", max);
      }
return 0;
}
