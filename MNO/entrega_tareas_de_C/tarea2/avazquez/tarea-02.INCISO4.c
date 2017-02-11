#include <stdio.h>
void main(void){
    int c,i=0;
    //la variable c debe ser intera ya que lafuncion get char devuelve valores enteros, es decir, devielve valores en codigo ascii
    //c=getchar(); Comentamos la invocacion a getchar() y la lectura la haga de la entrada estandar
    //EOF --> significa End Of File o fin de un archivo.
    while( c != EOF ){
        c=getchar();
	if (c == 10)
         i++;
    }
   printf("El total de lineas en el archivo es: %i\n",i);
}

