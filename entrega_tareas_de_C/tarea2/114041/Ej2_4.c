#include <stdio.h>
main(void){
    //inicializamos la variable que tomara el valor de cada caracter del arreglo;
    int c;

    // inicializamos el contador de renglones;
    long row_count;
    row_count=0;

   // recorremos el string hasta que veamos el interlineado y aumentamos el contador de renglones;
    while ((c = fgetc(stdin)) != EOF){
        if(c == '\n'){
            ++row_count;
        }
    }

    //imprimimos el resultado;
    printf("%ld\n",row_count);
}
