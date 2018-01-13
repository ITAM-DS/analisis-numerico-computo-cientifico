#include <stdio.h>
#include <time.h>

void bubble_sort(long [], long);

int main()
{
  long n, c, d, swap;
  int lectura=0;
  int i=0;
  int j;
  long numeros[100];
  unsigned long micros = 0;
  float millis = 0.0;
  clock_t start, end;

  FILE *input;
  input=fopen("trail.txt","r");

  fscanf (input, "%d", &lectura);
  while (!feof (input))
    {
      numeros[i]=lectura;
      //printf ("%d \n", lectura);
      i++;
      fscanf (input, "%d", &lectura);
    }
  fclose (input);


  start = clock();
  bubble_sort(numeros, i);
  end = clock();
  micros = end - start;
  millis = micros / 1000;
  printf("%f\n", millis); //my time keeps being returned as 0

  printf("Lista en orden ascendente:\n");

  for ( c = 0 ; c < i ; c++ )
     printf("%ld\n", numeros[c]);

  return 0;
}

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
