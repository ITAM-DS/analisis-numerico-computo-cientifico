#include <stdio.h>
main(void){
    int c;
    int nc=0;
    while((c = getchar()) !='\n'){
        ++nc;
    }
    printf("\nNúmero de caractere:%d\n", nc);

}