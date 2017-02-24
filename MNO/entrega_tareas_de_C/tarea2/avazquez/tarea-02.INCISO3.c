#include <stdio.h>
void main(void){
    int c,i=0;
    //la variable c debe ser intera ya que lafuncion get char devuelve valores enteros, es decir, devielve valores en codigo ascii
    //c=getchar(); Comentamos la invocacion a getchar() y la lectura la haga de la entrada estandar
    //EOF --> significa End Of File o fin de un archivo.
    while( c != 10){ // cacho el valor ascii del espacio el cual indica que ya no hay mas caracteres en la linea.
        c=getchar();
        ++i;
    }
   printf("El total de caracteres es: %i\n",i-1);
}

