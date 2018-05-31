#include <stdio.h>
int main(void){
int c;
int caracteres = 0;
while((c = getchar()) != EOF && c != '\n'){
	caracteres ++;
    } 
printf("Num. de carac.: ");
printf("%d", caracteres);
printf("\n");
}
