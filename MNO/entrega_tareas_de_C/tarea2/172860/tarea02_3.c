/*
Tarea 02 Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

3) Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número. Al dar enter (salto de línea) el programa termina.

*/

#include <stdio.h>
main(void){
    int c, nc;
    nc=0;
    c = getchar();
    while( c != '\n'){
        nc++;
        c = getchar();   
    } 
    printf("Número de caracteres: %d\n", nc);
}
