#include "stdio.h"
#define N 10
void add(int *a, int *b, int *c)
{
 int tID = 0;
 while (tID < N)
 {
 c[tID] = a[tID] + b[tID];
 tID += 1;
 }
}
int main()
{
 int a[N], b[N], c[N];
 // Fill Arrays
 for (int i = 0; i < N; i++)
 {
 a[i] = i,
 b[i] = 1;
 }
 add (a, b, c);
 for (int i = 0; i < N; i++)
 {
 printf("%d + %d = %d\n", a[i], b[i], c[i]);
 }
 return 0;
}
