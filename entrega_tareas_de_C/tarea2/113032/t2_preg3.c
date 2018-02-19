#include <stdio.h>
    main(void){
    int c;
    int num_chars = 0;

    while( (c = getchar())!= '\n'){
        num_chars++;
        }
      printf("Número de caracteres: %d\n", num_chars);
}
