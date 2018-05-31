/************************************************************************************************/
/************ Arturo Gonzalez Bencomo 172906, Arturo Torre Gonzalez 90226 ***********************/
/************************************************************************************************/
/********************************** kernel.cu ***************************************************/
/************************************************************************************************/
/** Este programa especifica como tal la funcion para convertir de rgb a grayscale **************/
/** tal el codigo ejecutado en el GPU ***********************************************************/


/*Importamos librerias*/
#include <math.h>
#include <iostream>
#include "cuda_runtime.h"
#include "kernel.h"
#include <stdlib.h>

using namespace std;

/*Esta funcion es el kernel que ejecuta grayscale en paralelo sobre cada pixel de la matriz*/
__global__
void grayscale(float *RED, float *GREEN, float *BLUE, float *GRAY){
    int ROW = blockIdx.y*blockDim.y+threadIdx.y;
    int COL = blockIdx.x*blockDim.x+threadIdx.x;

    float tmpSum = 0;

    if (ROW < N && COL < N) {
        // each thread computes one element of the block sub-matrix
        for (int i = 0; i < N; i++) {
            // Esta funcion es la que lleva a cabo la transformacion de colores rgb a blanco y negro
            GRAY[y][x]  = truncf(0.2989*px[0] + 0.587*px[1] + 0.114*px[2]);
        }
    }
    C[ROW * N + COL] = tmpSum;
}

