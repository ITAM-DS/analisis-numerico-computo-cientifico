/************************************************************************************************/
/************ Arturo Gonzalez Bencomo 172906, Arturo Torre Gonzalez 90226 ***********************/
/************************************************************************************************/
/********************************** MatrixMul.cu ************************************************/
/************************************************************************************************/
/** Este programa escrito en c++ hace una multiplicacion matricial de forma paralela utilizando */
/** cuda. ***************************************************************************************/


/*Se importan librerias*/

#include <iostream>            //Equivalente a stdio.h
#include <vector>              //Clase vector que permite crear arrays dinamicos.
#include <stdlib.h>            //stdlib de c
#include <time.h>              //Manejo de funciones de tiempo
#include <cuda_runtime.h>      //Administrador del runtime de cuda
#include "kernel.h"            //Importamos el archivo de prototipo del kernel
#include "kernel.cu"           //Implementacion del kernel
#include "dev_array.h"         //Estructura de datos tipo array
#include <math.h>              //Funciones matematicas, la necesitamos para rellenar la matriz inicial 

using namespace std;

int main()
{
    // Este Programa llevara a cabo la multiplicacion matricial A*B y asignara el resultado a C    
    int N = 16;                                 
    int SIZE = N*N;                               //Tamanio de las matrices 16x16 

    // Asignamos el espacio en memoria de las matrices en la memoria principal
    vector<float> h_A(SIZE);
    vector<float> h_B(SIZE);
    vector<float> h_C(SIZE);

    // Inicializamos las matrices dentro del programa principal con valores iniciales de seno y coseno (funciones de la libreria math.h) 
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            h_A[i*N+j] = sin(i);
            h_B[i*N+j] = cos(i);
        }
    }

    // Reservamos el espacio en memoria en el GPU
    dev_array<float> d_A(SIZE);
    dev_array<float> d_B(SIZE);
    dev_array<float> d_C(SIZE);

    // Copiamos las variables en memoria principal a memoria del device
    d_A.set(&h_A[0], SIZE);
    d_B.set(&h_B[0], SIZE);

    //Mandamos llamar la funcion matrixMultiplication definida en el archivo kernel.cu, que es la que lleva a cabo el procesamiento paralelo.
    matrixMultiplication(d_A.getData(), d_B.getData(), d_C.getData(), N);
    
    //
    cudaDeviceSynchronize();

    d_C.get(&h_C[0], SIZE);
    cudaDeviceSynchronize();


    // Imprimimos matrices originales y salida para comprobar la operacion
    // h_A
    cout << "MATRIZ A\n";    
    for (int ROW=0; ROW < N; ROW++){
        for (int COL=0; COL < N; COL++){
            cout << h_A[ROW * N + COL];
            cout << " ";
        }
        cout << "\n";
    }

    // h_B    
    cout << "MATRIZ B\n";
    for (int ROW=0; ROW < N; ROW++){
        for (int COL=0; COL < N; COL++){
            cout << h_B[ROW * N + COL];
            cout << " ";
        }
        cout << "\n";
    }

    // h_C
    cout << "MATRIZ C\n";
    for (int ROW=0; ROW < N; ROW++){
        for (int COL=0; COL < N; COL++){
            cout << h_C[ROW * N + COL];
            cout << " ";
        }
        cout << "\n";
    } 
    
    return 0;
}
