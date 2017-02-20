#include <stdio.h>
int main(void){
    int c;
    int linea =0;
    while( (c = getchar()) != EOF){
	if(c=='\n')
		linea++;
    }
    printf("Líneas en el archivo  %d\n",linea);
}
