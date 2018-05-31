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
 *  Parametros:
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
