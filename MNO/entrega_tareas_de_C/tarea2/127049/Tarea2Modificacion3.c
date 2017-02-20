#include <stdio.h>
int main(void){
    int c = getchar();
    int i =0;
    while((c = getchar()) != EOF){
        if(c=='\n')
	i++;
    }
    printf("El numero de lineas es %d",i);
}


