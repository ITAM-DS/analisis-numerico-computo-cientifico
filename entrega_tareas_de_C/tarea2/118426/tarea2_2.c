#include <stdio.h>
main(void){
    int c;
	while (1){
        c = getchar();
	if (c == EOF){ break; }
	putchar(c);
    }
}
