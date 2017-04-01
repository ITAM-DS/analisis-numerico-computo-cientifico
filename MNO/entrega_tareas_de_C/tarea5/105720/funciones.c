// Tarea 5

// 105720
// Sonia Mendizabal Claustro


// Ejercicio c
// Modifica el archivo funciones.c para que alojes e inicialices a
// las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. 
// Modifica main.c para que llame a una función dentro del archivo funciones.c 
// que inicialice y aloje a las matrices anteriores y llame a otra función 
// para que las desaloje una vez hecha la multiplicación (usa free)




#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"


//definiciones de variables que serán externas solo apuntadores
static int i=0,j=0, k=0;
static double **matriz1;
static double **matriz2;
static double **matriz_resultado;




void aloja_espacio_e_incializa_matrices(void){

    // matriz 1
    matriz1 = malloc(  NUM_REN_MAT1 * sizeof(double) );
    for (i = 0; i <= NUM_REN_MAT1 -1 ; i++){
        *(matriz1 + i) = malloc(NUM_COL_MAT1  * sizeof(double));
    }
    // columna 1
    *( *( matriz1 + 0 ) + 0 ) = 0;
    *( *( matriz1 + 1 ) + 0 ) = 4;
    *( *( matriz1 + 2 ) + 0 ) = -1;
    // columna 2  
    *( *( matriz1 + 0 ) + 1 ) = 1.5;
    *( *( matriz1 + 1 ) + 1 ) = -5;
    *( *( matriz1 + 2 ) + 1 ) = 2.5;
    
    
    
    // matriz 2
    matriz2 = malloc(  NUM_REN_MAT2 * sizeof(double) );
    for (i = 0; i <= NUM_REN_MAT2 -1 ; i++){
        *(matriz2 + i) = malloc(NUM_COL_MAT2  * sizeof(double));
    }
    // columna 1
    *( *( matriz2 + 0 ) + 0 ) = 1;
    *( *( matriz2 + 1 ) + 0 ) = 0;
    // columna 2  
    *( *( matriz2 + 0 ) + 1 ) = 0;
    *( *( matriz2 + 1 ) + 1 ) = -1;
    // columna 3  
    *( *( matriz2 + 0 ) + 2 ) = 0;
    *( *( matriz2 + 1 ) + 2 ) = 1;
     
    
    
    // matriz resultado (reng_mat1 x col_mat2)
    matriz_resultado = malloc(  NUM_REN_MAT1 * sizeof(double) );
    for (i = 0; i <= NUM_REN_MAT1 -1 ; i++){
        *(matriz_resultado + i) = malloc(NUM_COL_MAT2  * sizeof(double));
    }
    
}



void libera_espacio(void){

    // matriz 1
    free(matriz1);
    // matriz 2
    free(matriz2);
    // matriz resultado
    free(matriz_resultado);

}



void imprime_matrices(void){
    
    printf("Matriz1\n");
        for(i = 0; i < NUM_REN_MAT1; i++ ){ //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
            for(j = 0; j < NUM_COL_MAT1; j++){
                if(j < NUM_COL_MAT1 - 1)
                printf("matriz1[%d][%d]=%4.2f\t", i, j, matriz1[i][j] );
                else
                printf("matriz1[%d][%d]=%4.2f\n", i, j, matriz1[i][j] );
            }
        }
    printf("\n");
    
    printf("Matriz2\n");
        for(i = 0; i < NUM_REN_MAT2; i++){
            for(j=0; j < NUM_COL_MAT2; j++){
                if(j < NUM_COL_MAT2 - 1)
                printf("matriz2[%d][%d]=%4.2f\t", i, j, matriz2[i][j] );
                else
                printf("matriz2[%d][%d]=%4.2f\n", i, j, matriz2[i][j] );
            }
        }
    printf("\n");
}

void imprime_matriz_resultado(void){

    printf("Matriz resultado\n");    
        for(i = 0; i < NUM_REN_MAT1; i++){
            for(j=0; j < NUM_COL_MAT2; j++){
                if(j < NUM_COL_MAT2 - 1)
                printf("matriz_res[%d][%d]=%4.2f\t", i, j, matriz_resultado[i][j] );
                else
                printf("matriz_res[%d][%d]=%4.2f\n", i, j, matriz_resultado[i][j] );
            }
        }

    printf("\n");

}

void multiplica_matrices(void){
    for(i = 0; i < NUM_REN_MAT1; i++){
        for(k = 0; k < NUM_COL_MAT2; k++){
            matriz_resultado[i][k] = 0;
            for(j = 0; j < NUM_COL_MAT1; j++)
                matriz_resultado[i][k] = matriz_resultado[i][k] + matriz1[i][j] * matriz2[j][k];
        }
    }
}