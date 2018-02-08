#include <stdio.h>
main(){
	int c, cont;
	c = 1;
	cont = 1;
	while(c !=EOF){
	  c = getchar();
	  if(c == '\n'){
	  	cont++;
	  }
	}
	printf("Número de líneas = %d\n", cont);
 }

