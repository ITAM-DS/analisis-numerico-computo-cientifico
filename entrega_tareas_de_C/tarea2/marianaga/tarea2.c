#include <stdio.h>
main(void){
	int c;
	int nc = 0;
	while((c = getchar()) != '\n'){
		nc ++;
	}	
	printf("número de caracteres: %d\n", nc);

}
