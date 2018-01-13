#include<stdio.h>

void print_value(int n_arr, double *arreglo); 
void print_address(int n_arr, double *arreglo);

///////////////////////////////////////////////////////////

void main(){
        // Input
    double arreglo[]={0,1,2,3,4,5,6,7,8,9};
    double matrix[2][3]={{11,12,13},
                          {21,22,23}};
    int n_arr, area, rows, cols;//, *p_arr, *p_multi;
    
    // dimensiones
    n_arr = sizeof(arreglo)/sizeof(arreglo[0]);
    rows = sizeof(matrix)/ sizeof(matrix[0]);
    cols = sizeof(matrix[0])/sizeof(matrix[0][0]);
    area = sizeof(matrix)/ sizeof(matrix[0][0]);
    
    //Funciones
    printf("n arreglo = %d \n", n_arr);
    print_value(n_arr, arreglo);
    print_address(n_arr, arreglo);
    
    printf("\n");
    printf("Fila %d y Columna %d\n", rows, cols);
    print_value(area, matrix[0]);
    print_address(area, matrix[0]);
}


/////////////////////////////////////////////////////////
void print_value(int n_arr, double *arreglo){
    int i;
    for(i = 0; i < n_arr; i++){
        if ( (i % 2) == 1 ){
                printf("Fila= %d Valor= %f\n", i, *(arreglo+i));
            }
        }
}

void print_address(int n_arr, double *arreglo){
    int i;
    
    for(i = 0; i < n_arr; i++){
        if ( (i % 2) == 1 ){
                printf("Fila = %d Direccion = %p\n", i, (arreglo+i));     
            }
        }
}