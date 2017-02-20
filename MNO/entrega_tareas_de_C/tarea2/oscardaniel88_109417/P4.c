#include <stdio.h>
main(void){
    int c;
    int lines =0;
    while( (c = getchar()) != EOF){
       if(c=='\n')
          lines++;
    }
    printf("%d\n",lines);
}
