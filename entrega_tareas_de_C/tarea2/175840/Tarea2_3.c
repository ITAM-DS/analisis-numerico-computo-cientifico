#include <stdio.h>

int main(){
    int c = 0;
    while(getchar() != '\n')
        c++;

    printf("\nEl total de letras es : %d\n",c);
    return 0;
}
