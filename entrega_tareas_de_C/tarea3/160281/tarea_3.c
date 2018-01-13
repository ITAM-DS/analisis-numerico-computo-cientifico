#include<stdio.h>

void ent_dir(int *arreglo,int size){
    int i;
    for(i = 0; i < size; i++){
        if ( (i % 2) == 1 ){
           printf("Valor de entrada p[%d]: %d\n", i, *(arreglo+i));
           printf("Direccion del arreglo: &p[%d]: %p\n", i, (arreglo+i));
         }
     }
}

int  main(){
    int col, row, size_uni,size_multi;
    int arreglo_multi[3][3] = {{-1, -2, -3},{-4, -5, -6},{-7,-8,-9}};
    int arreglo[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};

    row = sizeof(arreglo_multi) / sizeof(arreglo_multi[0]);
    col = sizeof(arreglo_multi[0])/sizeof(arreglo_multi[0][0]);
    size_uni = sizeof(arreglo)/sizeof(arreglo[0]);
    size_multi = row*col;

    printf("Arreglo unidimensional \n");
    ent_dir(&arreglo[0],size_uni);

    printf("Arreglo multidimensional[3][3] \n");
    ent_dir(&arreglo_multi[0][0], size_multi);
    return 0;
}
