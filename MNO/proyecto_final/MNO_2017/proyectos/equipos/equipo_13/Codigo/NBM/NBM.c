#define VERBOSE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "leergml.h"


RED red;
int twom;                // Va a ser el doble del número de aristas
                         // lo queremos para muchas cosas.
int **m;                 // El conteo de las aristas.

int arista_1, arista_2;

int kronecker(int x, int y){
    if(x==y) return 1;
    else return 0;
}

int generar(int i, int j, int k, int l, int ** matriz){
    for(i=0;i<red.nnodos;i++){
        for(j=0;j<red.nodo[i].grado;j++){
            arista_2=0;
            for(k=0;k<red.nnodos;k++){
                for(l=0;l<red.nodo[k].grado;l++){
                        matriz[arista_1][arista_2] = \
                            kronecker(red.nodo[k].id,red.nodo[i].arista[j].entrada)* \
                            (1-kronecker(red.nodo[i].id,red.nodo[k].arista[l].entrada));
                    arista_2++;
                }
            }
            arista_1++;
        }
    }
}
    

int main(int argc, char *argv[])
{
    int u;

    #ifdef VERBOSE
    fprintf(stderr,"Leyendo la red...\n");
    #endif
    leer_red(&red,stdin);
    for (u=twom=0; u<red.nnodos; u++) twom += red.nodo[u].grado;
    #ifdef VERBOSE
    fprintf(stderr,"Red con %i nodos y %i aristas\n",
        red.nnodos,twom/2);
    #endif
    #ifdef VERBOSE
    fprintf(stderr,"\n");
    #endif

    #ifdef VERBOSE
    int ** nbm;
    int renglon, columna;

    nbm = (int **)calloc(2*twom,sizeof(int));
    for (renglon=0; renglon<2*twom;renglon++){
        nbm[renglon] = (int *)calloc(2*twom,sizeof(int));
    }

 
    int i,j,k,l;

    generar(i,j,k,l,nbm);

    for(renglon=0;renglon<twom;renglon++){
        for(columna=0;columna<twom;columna++){
            printf("%i    ", nbm[renglon][columna]);
        }
    printf("\n");
    }
 
   #endif


}    
