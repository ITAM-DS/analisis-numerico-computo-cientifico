#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Compile
// gcc seq_800_1.c -o seq_800_1.out -lm
// ./seq_800_1.out > time_sequential_800.txt


int  Compare(const void* a_p, const void* b_p);



int main()
{
  //long n, c, d, swap;
  int lectura=0;
  int i=0;
  int c;
  long numeros[800000];
  time_t start_t, end_t;
  long double diff_t;


  //long mtime, seconds, useconds;

  FILE *input;
  input=fopen("muestra800.txt","r");

  fscanf (input, "%d", &lectura);
  while (!feof (input))
    {
      numeros[i]=lectura;
      //printf ("%d \n", lectura);
      i++;
      fscanf (input, "%d", &lectura);
    }
  fclose (input);


  /* Sort local list using built-in quick sort */
  time(&start_t);
  qsort(numeros, i, sizeof(long int), Compare);
  time(&end_t);
  diff_t = difftime(end_t, start_t);
  printf("Execution time = %Lf\n", diff_t);

  for ( c = 0 ; c < 100 ; c++ )
     printf("%ld\n", numeros[c]);

  return 0;
}



/*-------------------------------------------------------------------
 * Function:    Compare
 * Purpose:     Compare 2 ints, return -1, 0, or 1, respectively, when
 *              the first int is less than, equal, or greater than
 *              the second.  Used by qsort.
 */
int Compare(const void* a_p, const void* b_p) {
   int a = *((int*)a_p);
   int b = *((int*)b_p);

   if (a < b)
      return -1;
   else if (a == b)
      return 0;
   else /* a > b */
      return 1;
}  /* Compare */
