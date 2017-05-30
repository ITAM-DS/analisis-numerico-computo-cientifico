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

int kronecker(int x, int y){
    if(x==y) return 1;
    else return 0;
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
    int ** adyacencias;
    int renglon, columna;

    adyacencias = (int **)calloc(2*red.nnodos,sizeof(int));
    for (renglon=0; renglon<red.nnodos;renglon++)
        adyacencias[renglon] = (int *)calloc(red.nnodos,sizeof(int));
   
    int sal,ent;
    for(sal=0;sal<red.nnodos;sal++){
        for(ent=0;ent<red.nodo[sal].grado;ent++){
                adyacencias[sal][red.nodo[sal].arista[ent].entrada] = 1;
        }
    }
    
    for(renglon=0;renglon<red.nnodos;renglon++){
        for(columna=0;columna<red.nnodos;columna++){
            printf("%i    ", adyacencias[renglon][columna]);
        }
    printf("\n");
    }
 
   #endif
}
