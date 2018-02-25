#include <stdio.h>
main(void){
    int c;
    int i;
    i=0;
    
    while( c = getchar() != EOF ){
        
        if (c == '\n' || c == EOF) {
            i++;
        }
    }
    
    printf("%d ",i);
    return 0;
    
}
 