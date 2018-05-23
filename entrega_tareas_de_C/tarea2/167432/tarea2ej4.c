#include <stdio.h>
main(void)
{
//   FILE *fp;
//   fp = fopen(filename,"r");
//Sólo se carga el .c pero no el .out
char c = getchar();
int nl;
while (c != EOF) 
{  
  if (c == '\n') 
  {
     ++nl; 
  }
  c = getchar();
} 
printf("El número de líneas es: %d\n",nl);
}
