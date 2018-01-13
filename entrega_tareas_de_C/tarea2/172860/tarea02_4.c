/*
Tarea 02 Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

4) Modifica el programa tarea02_3.c para que cuente el número de líneas dado un archivo de stdin

*/

#include <stdio.h>
main(void){
    int c, nl;
    nl=0;
    c = getchar();
    while( c != EOF){
        if(c== '\n')
            nl++;
        c = getchar();   
    } 
    printf("Número de lineas: %d\n", nl);
}
