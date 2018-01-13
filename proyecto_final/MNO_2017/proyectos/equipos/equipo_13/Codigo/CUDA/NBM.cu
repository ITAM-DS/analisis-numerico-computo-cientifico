#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <cuda_runtime.h>

//#include "leergml.h"
extern "C"{
#include "leergml.h"
}


extern "C"{
int leer_red(RED *red, FILE *stream);
}

//RED red;
int twom;                // Va a ser el doble del número de aristas
                         // lo queremos para muchas cosas.
int **m;                 // El conteo de las aristas.

int arista_1, arista_2;

__host__ __device__ int kronecker(int x, int y){
    if(x==y) return 1;
    else return 0;
}

__device__ RED red;
RED h_red;

void FillStructs(){
    RED h_red;

    RED *d_red;

    cudaGetSymbolAddress( (void**)&d_red, red);

    cudaMemcpy(d_red, &h_red, sizeof(RED), cudaMemcpyHostToDevice);
}

__global__ void generar(int i, int j, int k, int l, int * matriz){
    int d_arista_1 = threadIdx.x;
    int d_arista_2 = threadIdx.y;
    d_arista_1 = 0;
    for(i=0;i<red.nnodos;i++){
        for(j=0;j<red.nodo[i].grado;j++){
            d_arista_2=0;
            for(k=0;k<red.nnodos;k++){
                for(l=0;l<red.nodo[k].grado;l++){
                        matriz[d_arista_1+d_arista_2] = \
                            kronecker(red.nodo[k].id,red.nodo[i].arista[j].entrada)* \
                            (1-kronecker(red.nodo[i].id,red.nodo[k].arista[l].entrada));
                    d_arista_2++;
                }
            }
            d_arista_1++;
        }
    }
}
    

int matriz(int argc, char *argv[])
{
    int u,i,j,k,l;

    fprintf(stderr,"Leyendo la red...\n");

    leer_red(&red,stdin);
    for (u=twom=0; u<h_red.nnodos; u++) twom += h_red.nodo[u].grado;
    fprintf(stderr,"Red con %i nodos y %i aristas\n",
        h_red.nnodos,twom/2);
    fprintf(stderr,"\n");

    FillStructs();

    int ** nbm;
    int renglon, columna;

    nbm = (int **)calloc(2*twom,sizeof(int));
    for (renglon=0; renglon<2*twom;renglon++){
        nbm[renglon] = (int *)calloc(2*twom,sizeof(int));
    }

    int (*d_nbm)[2*twom];

    cudaMalloc((void**)&d_nbm, (4*twom*twom)*sizeof(int));

    cudaMemcpy(d_nbm, nbm, (4*twom*twom)*sizeof(int), cudaMemcpyHostToDevice);

    int *d_i,*d_j,*d_k,*d_l;

    cudaMalloc((void**)&d_i,sizeof(int));
    cudaMalloc((void**)&d_j,sizeof(int));
    cudaMalloc((void**)&d_k,sizeof(int));
    cudaMalloc((void**)&d_l,sizeof(int));

    cudaMemcpy(d_i,&i,sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_j,&j,sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_k,&k,sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_l,&l,sizeof(int),cudaMemcpyHostToDevice);

    generar<<<128,128>>>(*d_i,*d_j,*d_k,*d_l,*d_nbm);

    cudaMemcpy (nbm, d_nbm, (4*twom*twom)*sizeof(int), cudaMemcpyDeviceToHost);

    for(renglon=0;renglon<twom;renglon++){
        for(columna=0;columna<twom;columna++){
            printf("%i    ", nbm[renglon][columna]);
        }
    printf("\n");
    }
 
    cudaFree(d_nbm);
    cudaFree(d_i);
    cudaFree(d_j);
    cudaFree(d_k);
    cudaFree(d_l);

    return 0;

}    
