

#include <stdio.h>

void print_valor(int *valor,int number_of_rows, int number_of_cols){
    printf("\n Impresion del Valor\n");
    for(int i=0;i < number_of_rows;i++){
            for(int j=0;j<number_of_cols;j++){
                if((i*number_of_cols+j)%2==1){
                    printf(" Valor[%d][%d] = %d\t", i, j, *(valor + i*number_of_cols + j));
                    if(number_of_cols>1) {
                        printf("\n");
                    }
                }
            }
            printf("\n");
    }
}

void print_mem(int *valor,int number_of_rows, int number_of_cols){
     printf("\n Impresion de memoria \n");
    for(int i=0;i < number_of_rows;i++){
            for(int j=0;j<number_of_cols;j++){
                if((i*number_of_cols+j)%2==1){
                    printf(" Memoria[%d][%d] = %p\t", i, j, &(valor[i*number_of_cols + j]));
                    if(number_of_cols>1) {
                        printf("\n");
                    }
                }
            }
            printf("\n");
    }
}

void print_mem(int *valor, int number_rows, int number_cols);

int main() {
    printf("Tarea 3: \n Elizabeth Solis Diaz\n");

    int arreglo[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int arreglo_mult[][3] = {{-1,-2,-3},{-4,-5,-6}};

    printf("\n Arreglo Unidimensional: \n");
    print_valor(arreglo, 10, 1);
    print_mem(arreglo, 10, 1);
    
    printf("\nArreglo Multidimensional: \n");
    print_valor(arreglo_mult,2,3);
    print_mem(arreglo_mult,2,3);

    return 0;
}

