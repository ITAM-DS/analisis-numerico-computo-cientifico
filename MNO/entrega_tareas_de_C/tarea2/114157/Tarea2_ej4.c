#include <stdio.h>
main(void){
    
    int c;
    
    long line_count;
    line_count=0;
    
    
    while ((c = fgetc(stdin)) != EOF){
        if(c == '\n'){
            ++line_count;
        }
    }
    
    printf("%d\n",line_count);
}
