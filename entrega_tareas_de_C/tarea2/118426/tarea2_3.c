#include <stdio.h>
main(void){
    int c, i ;
    	i = 0;
	while (1){
        c = getchar();
	if (c == EOF || c == '\n'){ break; }
	putchar(c);
	i = i + 1;
    }
    printf("\n");
    printf("Número de caracteres: %d\n", i);
}
