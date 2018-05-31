#include <stdio.h>
main(void){
	int c;
	int d=-1;
	while( c != '\n'){
	c = getchar();
	d++;
	}
	printf("%d\n",d);
}
