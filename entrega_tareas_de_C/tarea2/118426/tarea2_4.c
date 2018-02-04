#include <stdio.h>
main(void){
    int c, i ;
    	i = 0;
	/* se podía meter la condición c != EOF en el while pero la dejé así 
	para seguir con el flujo de mis respuestas anteriores*/
	while (1){
        c = getchar();
	if (c == EOF){ break; }
	putchar(c);
	if (c == '\n')
	i = i + 1;
    }
    printf("\n");
    printf("El número de líneas del archivo son: %d\n", i);
}
