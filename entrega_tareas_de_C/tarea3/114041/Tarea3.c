#include<stdio.h>
void imprime_valores(int *valor,int n_rows, int n_cols);
void imprime_direcciones(int *valor,int n_rows, int n_cols);



int main(){
    int i,j;

    // definimos los arreglos
    int arreglo[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int arreglo_mult[][3]={{-1,-2,-3},{-4,-5,-6}};

    // Imprimimos el arreglo
    printf("\n Imprimimos el arreglo\n");
    int longitud_arreglo = sizeof(arreglo)/sizeof(arreglo[0]);
    for(i=0;i<longitud_arreglo;i++){
        printf("arreglo[%d]=%d\n",i, arreglo[i]);
    }

    // probamos la funcion de imprimir valores pares
    printf("\n Mostramos los valores pares del arreglo\n");
    imprime_valores(arreglo, longitud_arreglo, 0);

    // imprimimos las direcciones de memora del arreglo
    printf("\n Imprimimos las direcciones del arreglo\n");
    for(i=0;i<longitud_arreglo;i++){
        printf("arreglo[%d]=%p\n",i, &arreglo[i]);
    }

    // probamos la funcion de imprimir las direeciones pares
    printf("\n Mostramos las direcciones de memoria pares del arreglo\n");
    imprime_direcciones(arreglo, longitud_arreglo, 0);



    // Imprimimos el arreglo multidimensional
    printf("\n Imprimios el arreglo multidimensional\n");
    int longitud_arreglo_mult = sizeof(arreglo_mult)/sizeof(arreglo_mult[0]);
    int num_columnas = sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0]);
    for(i=0;i<longitud_arreglo_mult;i++){
        for(j=0;j<num_columnas;j++)
            printf("arreglo_mult[%d][%d] = %d\t", i,j,arreglo_mult[i][j]);
        printf("\n");
    }

    // Probamos la funcion de imprimir valores pares del arreglo multidimensional

    printf("\n Mostramos los valores pares del arreglo multidimensional\n");
    imprime_valores(&arreglo_mult[0][0],longitud_arreglo_mult,num_columnas);

    printf("\n Imprimimos las direcciones de memora del arrreglo multidimensional\n");
    for(i=0;i<longitud_arreglo_mult;i++){
        for(j=0;j<num_columnas;j++)
            printf("arreglo_mult[%d][%d] = %p\t", i,j,&arreglo_mult[i][j]);
        printf("\n");
    }


    printf("\n Mostramos las direcciones de memoria pares del arreglo multidimensional\n");
    imprime_direcciones(&arreglo_mult[0][0],longitud_arreglo_mult,num_columnas);
    printf("\n");

    return 0;
}



void imprime_valores(int *valor,int n_rows, int n_cols){

    int i,j;

    if (n_cols==0){
        // imprimimos los valores
        for(i=0;i<n_rows;i++){
            if(i%2==1){
                printf("*(arreglo[0] + %i) = %i\n", i,*(valor + i));
            }
        }
    }else{
            for(i=0;i < n_rows;i++){
               for(j=0;j<n_cols;j++){
                   if((i*n_cols+j)%2==1){
                     printf("arreglo_mult[%d][%d] = %d\t", i,j,*(valor + i*n_cols + j));
                   }
               }
               printf("\n");
            }
        }

}


void imprime_direcciones(int *valor,int n_rows, int n_cols){

    int i,j;

    if (n_cols==0){
        // imprimimos los valores
        for(i=0;i<n_rows;i++){
            if(i%2==1){
                printf("*(arreglo[0] + %i) = %p\n", i,(valor + i));
            }
        }
    }else{
            for(i=0;i < n_rows;i++){
               for(j=0;j<n_cols;j++){
                   if((i*n_cols+j)%2==1){
                     printf("arreglo_mult[%d][%d] = %p\t", i,j,(valor + i*n_cols + j));
                   }
               }
               printf("\n");
            }
        }

}
