
#include <stdio.h>
main(void){
    int k;
    int c;
    k=0;
    c = getchar();
    while( c != -1 && c!= '\n'){
// tambien podríamos sustituir el -1 por EOF
          c = getchar();
          k++ ;
    }

    printf("%d ",k);
    return 0;
}
