/************************************************************************************************/
/************ Arturo Gonzalez Bencomo 172906, Arturo Torre Gonzalez 90226 ***********************/
/************************************************************************************************/
/********************************** kernel.cu ************************************************/
/************************************************************************************************/
/** Este programa especifica como tal la funcion matrixMultiplication, y el kernel que es como **/
/** tal el codigo ejecutado en el GPU ***********************************************************/


/*Importamos librerias*/
#include <math.h>
#include <iostream>
#include "cuda_runtime.h"
#include "kernel.h"
#include <stdlib.h>

using namespace std;


/*Esta funcion es el kernel que ejecuta la multiplicacion en paralelo*/
__global__ 
void matrixMultiplicationKernel(float* A, float* B, float* C, int N) {

    int ROW = blockIdx.y*blockDim.y+threadIdx.y;
    int COL = blockIdx.x*blockDim.x+threadIdx.x;

    float tmpSum = 0;

    if (ROW < N && COL < N) {
        // each thread computes one element of the block sub-matrix
        for (int i = 0; i < N; i++) {
            tmpSum += A[ROW * N + i] * B[i * N + COL];
        }
    }
    C[ROW * N + COL] = tmpSum;
}


/* Esta funcion prepara los parametros del kernel, se especifica 1 grid de 1 bloque asi como */
/* 256 threads por bloque que corresponden al total de operaciones producto punto. ***********/
void matrixMultiplication(float *A, float *B, float *C, int N){

    // Estructuras de datos tipo dim3    
    dim3 threadsPerBlock(N, N);
    dim3 blocksPerGrid(1, 1);
        if (N*N > 512){
            threadsPerBlock.x = 512;
            threadsPerBlock.y = 512;
            blocksPerGrid.x = ceil(double(N)/double(threadsPerBlock.x));
            blocksPerGrid.y = ceil(double(N)/double(threadsPerBlock.y));
        }

    //Este renglon inicializa el computo en paralelo en la GPU.
    matrixMultiplicationKernel<<<blocksPerGrid,threadsPerBlock>>>(A, B, C, N);
}

