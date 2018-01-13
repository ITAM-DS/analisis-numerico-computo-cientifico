#include <stdio.h>
#include <time.h>

// Compile
// gcc seq_400_1.c -o seq_400_1.out -lm
// ./seq_400_1.out > time_sequential_400.txt

void bubble_sort(long [], long);

int main()
{
  long n, c, d, swap;
  int lectura=0;
  int i=0;
  int j;
  long numeros[400000];
  time_t start_t, end_t;
  double diff_t;


  //long mtime, seconds, useconds;

  FILE *input;
  input=fopen("muestra400.txt","r");

  fscanf (input, "%d", &lectura);
  while (!feof (input))
    {
      numeros[i]=lectura;
      //printf ("%d \n", lectura);
      i++;
      fscanf (input, "%d", &lectura);
    }
  fclose (input);


  //gettimeofday(&start, NULL);
  time(&start_t);
  bubble_sort(numeros, i);
  time(&end_t);
  diff_t = difftime(end_t, start_t);
  printf("Execution time = %f\n", diff_t);



  /*printf("Lista en orden ascendente:\n");

  for ( c = 0 ; c < 10 ; c++ )
     printf("%ld\n", numeros[c]);*/

  return 0;
}


// funcion

void bubble_sort(long list[], long n)
{
  long c, d, t;

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */

        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}
