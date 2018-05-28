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



int main ( int argc, char **argv )

{
  int i;
  int max = 99999999;
  int j;
  int *mind;
  int am[NV][NV];

  timestamp ( );
  fprintf ( stdout, "\n" );

  adjacency_matrix ( am );

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

  mind = dijkstra_distance ( am );

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "  Distancias minimas al nodo 0:\n");
  fprintf ( stdout, "\n" );
  for ( i = 0; i < NV; i++ )
  {
    fprintf ( stdout, "  %2d  %2d\n", i, mind[i] );
  }

  free ( mind );

  fprintf ( stdout, "\n" );

  fprintf ( stdout, "\n" );
  timestamp ( );

  return 0;
}

int *dijkstra_distance ( int am[NV][NV]  )

{
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

  visitado = ( int * ) malloc ( NV * sizeof ( int ) );

  visitado[0] = 1;
  for ( i = 1; i < NV; i++ )
  {
    visitado[i] = 0;
  }

  mind = ( int * ) malloc ( NV * sizeof ( int ) );

  for ( i = 0; i < NV; i++ )
  {
    mind[i] = am[0][i];
  }

  # pragma omp parallel private ( my_first, my_id, my_last, my_md, my_mv, my_step ) \
  shared ( visitado, md, mind, mv, nth, am )
  {
    my_id = omp_get_thread_num ( );
    nth = omp_get_num_threads ( );
    my_first =   (   my_id       * NV ) / nth;
    my_last  =   ( ( my_id + 1 ) * NV ) / nth - 1;

    # pragma omp single
    {
      printf ( "\n" );
      printf ( "  Thread %d: Paralelizacion usa %d threads\n", my_id, nth );
      printf ( "\n" );
    }
    fprintf ( stdout, "  Thread %d:  Primer nodo=%d  Ultimo nodo=%d\n", my_id, my_first, my_last );

    for ( my_step = 1; my_step < NV; my_step++ )
    {

      # pragma omp single
      {
        md = max;
        mv = -1;
      }

      encuentra_corto ( my_first, my_last, mind, visitado, &my_md, &my_mv );

      # pragma omp critical
      {
        if ( my_md < md )
        {
          md = my_md;
          mv = my_mv;
        }
      }

      # pragma omp barrier

      # pragma omp single
      {
        if ( mv != - 1 )
        {
          visitado[mv] = 1;
          printf ( "  Thread %d: Conectando nodo %d.\n", my_id, mv );
        }
      }

      # pragma omp barrier

      if ( mv != -1 )
      {
        update_mind ( my_first, my_last, mv, visitado, am, mind );
      }

      #pragma omp barrier
    }

    # pragma omp single
    {
      printf ( "\n" );
      printf ( "  Thread %d: Termina paralelizacion.\n", my_id );
    }
  }

  free ( visitado );

  return mind;
}

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
