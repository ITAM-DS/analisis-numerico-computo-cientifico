#include<stdio.h>

void valores(int *arreglo, int num){
    int i;
    for(i = 0; i < num; i++){
        if ( (i % 2) == 1 ){
                printf("Valor p[%d]: %d\n", i, *(arreglo+i));
            }
        }
}

void direccion(int *arreglo, int num){
    int i;
    for(i = 0; i< num; i++){
        if ( (i % 2) == 1 ){
                printf("Direccion: &p[%d]: %p\n", i, (arreglo+i));
            }
        }
}

int  main(){
    int len_a1,len_a2, fila, col;
    int arreglo_mult[2][3] = {{-1, -2, -3},{-4, -5, -6}};
    int arreglo[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};

    len_a1 = sizeof(arreglo)/sizeof(arreglo[0]);
    fila = sizeof(arreglo_mult) / sizeof(arreglo_mult[0]); // filas del arreglo
    col = sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0]); // columnas del arreglo
    len_a2 = fila*col; // total

   
    printf("Arreglo 1 dimension \n");
    valores(&arreglo[0],len_a1);//Se envia la direccion de memoria como argumento
    direccion(&arreglo[0],len_a1);

    printf("Arreglo 2 dimensiones \n");
    valores(&arreglo_mult[0][0], len_a2);
    direccion(&arreglo_mult[0][0], len_a2);
    return 0;
}
