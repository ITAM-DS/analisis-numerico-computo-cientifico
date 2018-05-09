// Importar librerías
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define NV 6

// Definir variables globales

int am[NV][NV],  // distancia entre nodos
    mind[NV],  // distancia minima
    visitado[NV], // nodos visitados
    nthreads,  // numero de threads a usar
    nodos,  // numero de nodos manejados por cada thread
    md,  // minimo global
    mv;  // nodo en el cual se alcanza el minimo global

int main ( int argc, char **argv );
void adjacency_matrix ( int am[NV][NV] );
void dijkstra_distance ();
void encuentra_corto ( int mind[NV], int visitado[NV], int *d, int *v );
void update_mind ( int mv, int visitado[NV], int am[NV][NV], int mind[NV] );

// Para este ejercicio se va a definir el grafo como un matriz de adyacencia
// También se puede implementar como matriz rala para disminuir consumo de memoria
// Instanciar la Matriz

void adjacency_matrix(int am[NV][NV])
{  int i,j;
   int max = 99999999;
   for (i = 0; i < NV; i++)
      for (j = 0; j < NV; j++)  {
         if (j == i) am[i][j] = 0;
         else am[i][j] = max;
      }
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

void encuentra_corto(int mind[NV], int visitado[NV], int *d, int *v) {
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


void update_mind(int mv, int visitado[NV], int am[NV][NV], int mind[NV])
{  int i;
   int max = 99999999;
   for (i = 0; i < NV; i++)
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

void dijkstra_distance()
{
   int max = 99999999;
   #pragma omp parallel
   {  int startv,endv,
          step,
          mymd,
          mymv,
          me = omp_get_thread_num();

      #pragma omp single
      {  nthreads = omp_get_num_threads();  nodos = NV/nthreads;
         printf("there are %d threads\n",nthreads);  }
      // Note 3
      startv = me * nodos;
      endv = startv + nodos - 1;
      for (step = 0; step < NV; step++)  {

         #pragma omp single
         {  md = max; mv = 0;  }
         findmymin(startv,endv,&mymd,&mymv);

         #pragma omp critical
         {  if (mymd < md)
              {  md = mymd; mv = mymv;  }
         }

         #pragma omp single
         { !visitado[mv] = 0;  }

         updateohd(startv,endv);
         #pragma omp barrier
      }
   }
}

int main(int argc, char **argv) {
  int i;
  int max = 999999999;
  int j;
  int *mind;
  int am[NV][NV];

  adjacency_matrix( am );
  dijkstra_distance();

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
  for (i = 0; i< NV; i++){
      fprintf (stdout, "  %2d  %2d\n", i, mind[i]);
  }
  free ( mind );
  return 0;
}
