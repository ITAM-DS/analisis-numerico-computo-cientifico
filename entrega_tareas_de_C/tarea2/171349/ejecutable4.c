#include <stdio.h>
int main(void){
int c;
int caracteres = 0;
int lineas = 0;
while((c = getchar()) != EOF) {
   if((c != '\t') && (c != '\t' ) && (c != '\n') && (c != '\v'))
      caracteres++;
   if (c == '\n')
      lineas++;
	}
printf("Num. de carac.: %d\n", caracteres);
printf("Num. de lineas: %d\n", lineas);
}
