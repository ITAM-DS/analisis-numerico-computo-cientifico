#include <stdio.h>
#include <string.h>

int main(void){
    char str[100];
    int c, n = 0, len;
    
    while( (c = getchar()) != '\n'){
        str[n] = c;
        n++;
        
    } 
    len = strlen(str);
    printf("%d\n", len);
    printf("\n");

return(0);
}
