// Tarea 5

// 105720
// Sonia Mendizabal Claustro


// Ejercicio d
// Compara tu resultado usando la subrutina de Fortran dgemm y 
// los siguientes archivos definiciones2.h, main2.c, funciones2.c



#include"definiciones2.h"

extern void dgemm_(char *transaA, char *transaB,int *m,int *n,int *k,double *alpha,double *A,int *lda,double *B,int *ldb,double *beta,double *C,int *ldc);
extern double (*matriz1)[], (*matriz2)[], (*matriz_resultado)[];

int main(void){
    char TRANSA, TRANSB;
    int M = NUM_REN_MAT1;
    int K = NUM_COL_MAT1;
    int N = NUM_COL_MAT2;
    double ALPHA, BETA;
    
    TRANSA = 'N';
    TRANSB = 'N';
    ALPHA = 1.0;
    BETA = 0.0;
    
    aloja_espacio_e_incializa_matrices();
    imprime_matrices();
    dgemm_(&TRANSA, &TRANSB, &N, &M, &K, &ALPHA, *matriz2, &N, *matriz1, &K, &BETA, *matriz_resultado, &N);
    imprime_matriz_resultado();
    libera_espacio();
return 0;
}