#include <stdio.h>
main(void){
    int c;
    int l=0;
    while((c = getchar()) != EOF){
        if(c == '\n')
        l++;
    }
    printf("%d\n", l+1);

}