#include <stdio.h>
int main(void){
    int c;
    //c = getchar();
    //Para eliminar la linea c = getchar(); solo hay que meterla en el while directo
    while((c = getchar()) != EOF){
        putchar(c);
	// c = getchar();
    }
}
