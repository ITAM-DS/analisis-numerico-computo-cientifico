#include <stdio.h>
main(void){
	int c;
	int nl = 0;
	while((c = getchar()) != EOF){
		if(c == '\n')
			nl ++;	
	}	
	printf("número de lineas: %d\n", nl);

}
