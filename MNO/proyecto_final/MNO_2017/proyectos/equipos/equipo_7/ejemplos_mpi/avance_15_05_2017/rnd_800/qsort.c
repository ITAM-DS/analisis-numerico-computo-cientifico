#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
   int n;
   int lectura=0;
   int i=0;
   int j;
   long numeros[100];
   //long mtime, seconds, useconds;

   FILE *input;
   input=fopen("omi.txt","r");

   fscanf (input, "%d", &lectura);
   while (!feof (input))
     {
       numeros[i]=lectura;
       //printf ("%d \n", lectura);
       i++;
       fscanf (input, "%d", &lectura);
     }
   fclose (input);

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < i; n++ )
   {
      printf("%ld ", numeros[n]);
   }

   qsort(numeros, i, sizeof(long int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < i; n++ )
   {
      printf("%ld ", numeros[n]);
   }

   return(0);
}
