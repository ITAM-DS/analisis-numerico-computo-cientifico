// Tarea 3

// 105720
// Sonia Mendizabal Claustro

#include<stdio.h>

void print_array(int *elems, int *arreglo){
    int pos, i, j;
    
    for(pos = 0; pos < elems; pos++){
        if ( (pos % 2) == 1 ){
                printf("posicion %d valor: %d\n", pos, *(arreglo+pos));
            }
        }
}

void print_pos(int *elems, int *arreglo){
    int pos, i, j;
    
    for(pos = 0; pos < elems; pos++){
        if ( (pos % 2) == 1 ){
                printf("posicion %d dirección: %p\n", pos, *(arreglo+pos));     
            }
        }
}


void main(){
    int len, row, column, lenmulti;    
    int arrmult[3][3] = {{-1, -2, -3},
                          {-4, -5, -6},
                          {-7, -8, -9}};
    int arr[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    
    
    // dimensiones
    len = sizeof(arr)/sizeof(arr[0]);
    row = sizeof(arrmult) / sizeof(arrmult[0]);
    column = sizeof(arrmult[0])/sizeof(arrmult[0][0]);
    lenmulti = row*column;
    
    //Funciones
    printf("Arreglo de longitud %d \n", len);
    print_array(len, arr);
    print_pos(len, arr);
    
    printf("\n");
    printf("Arreglo de renlones %d y columnas %d\n", row, column);
    print_array(lenmulti, arrmult);
    print_pos(lenmulti, arrmult);
}
    