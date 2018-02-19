#include <stdio.h>
main(){
	int cont;
	cont = 0;
	while(getchar() !='\n'){
	  cont++;	
	}
	printf("Número de caracteres = %d\n", cont);
 }

