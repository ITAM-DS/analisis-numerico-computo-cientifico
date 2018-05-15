// Importar librerías
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define NV 6

int main ( int argc, char **argv );
void adjacency_matrix ( int am[NV][NV] );
int *dijkstra_distance ( int am[NV][NV] );
void encuentra_corto ( int mind[NV], int visitado[NV], int *d, int *v );
void update_mind ( int mv, int visitado[NV], int am[NV][NV], int mind[NV] );

int main ( int argc, char **argv ){
    int i;
    int max = 999999999;
    int j;
    int *mind;
    int am[NV][NV];

    adjacency_matrix( am );

    // Imprimir la matriz de adyacencia
    printf("matriz de adyacencia: \n \n");
    for ( i = 0; i < NV; i++ ){
        for ( j = 0; j < NV; j++ ){
            if ( am[i][j] == max){
            } else {
                fprintf(stdout, " %3d", am[i][j] );
            }
        }
        fprintf( stdout, "\n" );
    }
    mind = dijkstra_distance(am);

    // Imprimir las distancias mínimas para todo el vector
    printf("\n Distancias minimas al nodo cero para el vector: \n");
    for (i = 0; i< NV; i++){
        fprintf (stdout, "  %2d  %2d\n", i, mind[i]);
    }
    free ( mind );
    return 0;
}

// Para este ejercicio se va a definir el grafo como un matriz de adyacencia
// También se puede implementar como matriz rala para disminuir consumo de memoria
// Instanciar la Matriz
void adjacency_matrix ( int am[NV][NV] ){
    int i;
    // ponemos este número como infinito.
    int max = 99999999;
    int j;


    // Empezamos con una matriz con infinito y 0 en la diagonal.
    for ( i = 0; i < NV; i++){
        for ( j =0; j < NV; j++ ){
            if ( i==j ){
                am[i][j] = 0;
            } else{
                am[i][j] = max;
            }
        }
    }

    // Matriz para prueba - sustituimos las conexiones que sí tenemos
    // matriz simétrica
    am[0][1] = am[1][0] = 40;
    am[0][2] = am[2][0] = 15;
    am[1][2] = am[2][1] = 20;
    am[1][3] = am[3][1] = 10;
    am[1][4] = am[4][1] = 25;
    am[2][3] = am[3][2] = 100;
    am[1][5] = am[5][1] = 6;
    am[4][5] = am[5][4] = 8;

    return;
}


// Función del algoritmo de dijkstra
int *dijkstra_distance ( int am[NV][NV] ){
    int *visitado;
    int i;
    int md;
    int *mind;
    int mv;
    int step;

    // malloc para el # de vertices
    // visitado = ( int * ) malloc ( NV * sizeof ( int ) );
    visitado = calloc(NV, sizeof(int));

    // Cargamos las distancias de la primera etapa
    mind = calloc(NV, sizeof(int));
    for ( i = 0; i < NV; i++){
        // Dejamos constante el 0 - primera etapa
        mind[i] = am[0][i];
    }

    // Ahora corremos por etapas - max NV
    for ( step =1; step<NV; step++){
        encuentra_corto( mind, visitado, &md, &mv);

    // Almacenamos el nodo visitado
    visitado[mv] = 1;
    update_mind ( mv, visitado, am, mind);
    }

return mind;
}

void encuentra_corto ( int mind[NV], int visitado[NV], int *d, int *v){
    // Obtenemos el vector de movimientos posibles, nos quedamos con el más corto
    int i;
    int max = 99999999;
    *d = max;
    *v = -1;
    for ( i = 0; i < NV; i++){
        if ( !visitado[i] && mind[i] < *d ){
            *d = mind[i];
            *v = i;
        }
    }
return;
}

 void update_mind ( int mv, int visitado[NV], int am[NV][NV], int mind[NV] ){
    int i;
    int max = 99999999;

    for ( i = 0; i < NV; i++ ){
        // Si no se ha visitado
        if (!visitado[i]){
            if ( am[mv][i] < max ){
                if ( mind[mv] + am[mv][i] < mind[i]){
                    mind[i] = mind[mv] + am[mv][i];
                }
            }
        }
    }
return;
}
