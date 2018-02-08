#include <stdio.h>
main(void){
    int c,i;
    i=0;
    c = getchar();
    while( c != EOF && c!= '\n'){
        putchar(c);
        c = getchar();  
        i++ ;
    } 
    
    printf("%d ",i);
    return 0;
}
 