## Tarea 3
### Miguel Rodrigo Castañeda Santiago
### CU 175840


Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.


Programa: 

```
#include <stdio.h>
#include <stdlib.h>

void imprime_valor(int *valor, int tipo, int size);

int main()
{
    int arreglo_1[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int arreglo_2[2][3] = {{-1,-2,-3},{-4,-5,-6}};
    int size = 0;


    printf("Arreglo 1: \n");
    size = sizeof(arreglo_1)/sizeof(arreglo_1[0]);
    imprime_valor(arreglo_1,0,size);
    imprime_valor(arreglo_1,1,size);
    printf("\n");

    printf("Arreglo 2: \n");
    size = sizeof(arreglo_2)/sizeof(arreglo_2[0][0]);
    imprime_valor(arreglo_2,0,size);
    imprime_valor(arreglo_2,1,size);
    printf("\n");

    return 0;
}

/*
 *  Parámetros:
 *  int *valor apuntador al arreglo
 *  int tipo   tipo de reporte 0 imprime el valor, <> 0 imprime la dirección de memoria
 *  int size   tamaño del arreglo
 */
void imprime_valor(int *valor, int tipo, int size){
    for(int i=0; i< size; i++){
        if( (i%2) != 0){
            if(tipo ==0) // Imprime valor
                printf("p[%d] = %d\n",i, *(valor + i));
            else         // Imprime memoria
                printf("p[%d] = %p\n",i, (valor + i));
        }
    }
}
```
Archivo: [Tarea3.c](Tarea3.c)

Se compila y se ejecuta

```
gcc -Wall Tarea3.c -o tarea3.out
./tarea3.out 

```

Salida  

```
Arreglo 1:
p[1] = -2
p[3] = -4
p[5] = -6
p[7] = -8
p[9] = -10
p[1] = 0x7fffcd872704
p[3] = 0x7fffcd87270c
p[5] = 0x7fffcd872714
p[7] = 0x7fffcd87271c
p[9] = 0x7fffcd872724

Arreglo 2:
p[1] = -2
p[3] = -4
p[5] = -6
p[1] = 0x7fffcd8726e4
p[3] = 0x7fffcd8726ec
p[5] = 0x7fffcd8726f4
```


