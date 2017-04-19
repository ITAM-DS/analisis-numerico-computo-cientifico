#include <stdio.h>

void quick_sort(long arr[100],int,int);

int main()
{
  long n, c, d, swap;
  int lectura=0;
  int i=0;
  int j;
  long numeros[100];

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

  quick_sort(numeros,0,i-1);

  printf("Lista en orden ascendente:\n");

  for ( c = 0 ; c < i ; c++ )
     printf("%ld\n", numeros[c]);

  return 0;
}

void quick_sort(long arr[100],int low,int high)
{
 int pivot,j,temp,i;
 if(low<high)
 {
  pivot = low;
  i = low;
  j = high;

  while(i<j)
  {
   while((arr[i]<=arr[pivot])&&(i<high))
   {
    i++;
   }

   while(arr[j]>arr[pivot])
   {
    j--;
   }

   if(i<j)
   {
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
  }

  temp=arr[pivot];
  arr[pivot]=arr[j];
  arr[j]=temp;
  quick_sort(arr,low,j-1);
  quick_sort(arr,j+1,high);
 }
}
