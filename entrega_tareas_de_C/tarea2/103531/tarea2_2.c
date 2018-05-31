#include <stdio.h>
main(void){
    int c;
    while(1){// como vimos en clase podemos considerar al TRUE del while como 1
	     // por lo tanto la condicion siempre se cumple y el ciclo tambien
        c = getchar();
        putchar(c);
    }
}
