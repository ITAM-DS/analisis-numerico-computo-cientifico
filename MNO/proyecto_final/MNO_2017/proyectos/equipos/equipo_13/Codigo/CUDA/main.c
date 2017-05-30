#define VERBOSE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <cuda_runtime.h>

#include "leergml.h"

RED red;
int twom;                // Va a ser el doble del número de aristas
                         // lo queremos para muchas cosas.

extern void generar(int i, int j, int k, int l, int * matriz);

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

    void generar(int i, int j, int k, int l, int * matriz);

    int renglon, columna;

    for(renglon=0;renglon<twom;renglon++){
        for(columna=0;columna<twom;columna++){
            printf("%i    ", *nbm[renglon][columna]);
        }
    printf("\n");
    }
 
    return 0;
    
}
