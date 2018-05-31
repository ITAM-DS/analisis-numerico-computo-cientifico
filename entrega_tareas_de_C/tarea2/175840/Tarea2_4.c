#include <stdio.h>

int main(){
    int c = 0;
    int lineas = 0;
    c = getchar();
    while(c != EOF ){
        c = getchar();
        if(c == '\n')
            lineas++;
    }

    printf("\nEl total de lineas es : %d\n",lineas);
    return 0;
}
