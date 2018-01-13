#include <stdio.h>

main(void){
    int c;
    
    long char_coutn;
    char_coutn = 0;
    
    while ((c=getchar()) != EOF && c!='\n'){
        ++char_coutn;
    }
    
    printf("%d\n", char_coutn);
}
