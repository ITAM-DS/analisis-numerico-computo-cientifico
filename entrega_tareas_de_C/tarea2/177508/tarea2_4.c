#include <stdio.h>
main(void){
	int c;
	int d=-1;
	while( c != EOF){	
	c = getchar();
	if( c == '\n'){
		d++;
	}
}
	printf("%d\n",d);
}
