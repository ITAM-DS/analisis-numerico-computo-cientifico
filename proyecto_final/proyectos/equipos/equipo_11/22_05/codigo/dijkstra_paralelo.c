# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <omp.h>

# define NV 6

int main ( int argc, char **argv );
int *dijkstra_distance ( int am[NV][NV] );
void encuentra_corto ( int s, int e, int mind[NV], int visitado[NV], int *d,
  int *v );
void adjacency_matrix ( int am[NV][NV] );
void timestamp ( void );
void update_mind ( int s, int e, int mv, int visitado[NV], int am[NV][NV],
  int mind[NV] );


// FUNCION MAIN

int main ( int argc, char **argv )

{

// Se definen las variables que se usan en la funcion main:
  int i;
  int max = 99999999;
  int j;
  int *mind;
  int am[NV][NV];

// Se usa la funcion timestamp para imprimir la hora en la que empieza a correr el codigo
  timestamp ( );
  fprintf ( stdout, "\n" );

// Se inicializan los datos
  adjacency_matrix ( am );


// Se imprime la matriz de distancias
  fprintf ( stdout, "\n" );
  fprintf ( stdout, "  Matriz de distancias:\n" );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < NV; i++ )
  {
    for ( j = 0; j < NV; j++ )
    {
      if ( am[i][j] == max )
      {
        fprintf ( stdout, "  Inf" );
      }
      else
      {
        fprintf ( stdout, "  %3d", am[i][j] );
      }
    }
    fprintf ( stdout, "\n" );
  }

// Se corre el algoritmo
  mind = dijkstra_distance ( am );

// Se imprimen los resultados
  fprintf ( stdout, "\n" );
  fprintf ( stdout, "  Distancias minimas al nodo 0:\n");
  fprintf ( stdout, "\n" );
  for ( i = 0; i < NV; i++ )
  {
    fprintf ( stdout, "  %2d  %2d\n", i, mind[i] );
  }

// Se libera la memoria
  free ( mind );

  fprintf ( stdout, "\n" );

// Se usa la funcion timestamp para imprimir la hora en la que termina de correr el codigo
  fprintf ( stdout, "\n" );
  timestamp ( );

  return 0;
}

// ----------------------------------------------------------------------------------

// FUNCIÓN DIJKSTRA: CORRE EL ALGORITMO
int *dijkstra_distance ( int am[NV][NV]  )

{

// Se definen las variables que se usan en la funcion main:
  int *visitado;
  int i;
  int max = 99999999;
  int md;
  int *mind;
  int mv;
  int my_first;
  int my_id;
  int my_last;
  int my_md;
  int my_mv;
  int my_step;
  int nth;

// Se empieza solo cono el nodo cero conectado al arbol
  visitado = ( int * ) malloc ( NV * sizeof ( int ) );

  visitado[0] = 1;
  for ( i = 1; i < NV; i++ )
  {
    visitado[i] = 0;
  }

// La distancia de un paso es el estimador inicial de la distancia minima
  mind = ( int * ) malloc ( NV * sizeof ( int ) );

  for ( i = 0; i < NV; i++ )
  {
    mind[i] = am[0][i];
  }

// Inicia la region paralela
// Se definen las variables locales y globales, respectivamente
  # pragma omp parallel private ( my_first, my_id, my_last, my_md, my_mv, my_step ) \
  shared ( visitado, md, mind, mv, nth, am )
  {
    my_id = omp_get_thread_num ( );
    nth = omp_get_num_threads ( );
    my_first =   (   my_id       * NV ) / nth;
    my_last  =   ( ( my_id + 1 ) * NV ) / nth - 1;

// Se usa omp single para indicar que este bloque de codigo se debe ejecutar por un unico thread (sin importar cuál de los threads sea)
    # pragma omp single
    {
      printf ( "\n" );
      printf ( "  Thread %d: Paralelizacion usa %d threads\n", my_id, nth );
      printf ( "\n" );
    }
    fprintf ( stdout, "  Thread %d:  Primer nodo=%d  Ultimo nodo=%d\n", my_id, my_first, my_last );

    for ( my_step = 1; my_step < NV; my_step++ )
    {

// Se usa omp single para fijar el valor de la variable global md al valor máximo. Esto lo hace solo un thread.
      # pragma omp single
      {
        md = max;
        mv = -1;
      }

// Todos los threads trabajan. Cada thread encuentra el nodo no conectado mas cercano para cada uno de los nodos no conectados.
      encuentra_corto ( my_first, my_last, mind, visitado, &my_md, &my_mv );

// Se determina, para cada uno de los threads, la distancia mas corta. Solo un thread puede llevar a cabo esta tarea a la vez. Para que no haya mas de un thread al mismo tiempo ejecutando esta parte del codigo se usa omp critical.
      # pragma omp critical
      {
        if ( my_md < md )
        {
          md = my_md;
          mv = my_mv;
        }
      }

// Se usa omp barrier para el codigo no se siga ejecutando hasta que todos los threads hayan terminado con la tarea anterior.
      # pragma omp barrier

// Se conecta el nodo mas cercano. Esto lo hace solo un thread.
      # pragma omp single
      {
        if ( mv != - 1 )
        {
          visitado[mv] = 1;
          printf ( "  Thread %d: Conectando nodo %d.\n", my_id, mv );
        }
      }

// Se usa omp barrier para que los threads no continuen trabajando hasta que se haya actualizado el valor de la variable visitado
      # pragma omp barrier

// Cada thread actualiza su porcion del vector de minimas distancias (mind) revisando si el camino desde el nodo cero hasta el nodo conectado mas cercano mas la distancia del nodo mas cercano a otro nodo es mas chica que el valor actual.
      if ( mv != -1 )
      {
        update_mind ( my_first, my_last, mv, visitado, am, mind );
      }

// Se usa omp barrier para asegurar que no continue la siguiente tarea hasta que todos los threads terminen de actualizar el vector de distancias minimas.
      #pragma omp barrier
    }

// Se puede terminar la region paralela cuando todos los nodos se conectan
    # pragma omp single
    {
      printf ( "\n" );
      printf ( "  Thread %d: Termina paralelizacion.\n", my_id );
    }
  }

// Se libera memoria
  free ( visitado );

// La funcion regresa el vector de distancias minimas
  return mind;
}

// ----------------------------------------------------------------------------------

// FUNCION ENCUENTRA CORTO: ENCUENTRA EL NODO NO CONECTADO MAS CERCANO
void encuentra_corto ( int s, int e, int mind[NV], int visitado[NV], int *d,
  int *v )


{
  int i;
  int max = 99999999;

  *d = max;
  *v = -1;

  for ( i = s; i <= e; i++ )
  {
    if ( !visitado[i] && ( mind[i] < *d ) )
    {
      *d = mind[i];
      *v = i;
    }
  }
  return;
}

// ----------------------------------------------------------------------------------


// FUNCION ADJ MATRIX: INICIALIZA LOS DATOS
void adjacency_matrix ( int am[NV][NV] )


{
  int i;
  int max = 99999999;
  int j;

  for ( i = 0; i < NV; i++ )
  {
    for ( j = 0; j < NV; j++ )
    {
      if ( i == j )
      {
        am[i][i] = 0;
      }
      else
      {
        am[i][j] = max;
      }
    }
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

// ----------------------------------------------------------------------------------

// FUNCION TIMESTAMP: IMPRIME FECHA Y HORA
void timestamp ( void )

{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

// ----------------------------------------------------------------------------------

// FUNCION UPDATE_MIND: ACTUALIZA EL VECTOR DE DISTANCIAS MINIMAS
void update_mind ( int s, int e, int mv, int visitado[NV], int am[NV][NV],
  int mind[NV] )

{
  int i;
  int max = 99999999;

  for ( i = s; i <= e; i++ )
  {
    if ( !visitado[i] )
    {
      if ( am[mv][i] < max )
      {
        if ( mind[mv] + am[mv][i] < mind[i] )
        {
          mind[i] = mind[mv] + am[mv][i];
        }
      }
    }
  }
  return;
}
