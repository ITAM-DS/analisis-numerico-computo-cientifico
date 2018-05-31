#include <stdio.h>
main(void){
  int c;
  int char_counter = 0;
  int line_counter = 0;
  while((c = getchar()) != EOF) {
    if((c != ' ') && (c != '\t' ) && (c != '\n') && (c != '\v') && (c != '\f') && (c != '\r'))
      char_counter++;

    if (c == '\n')
      line_counter++;
  }
  printf("Numero de caracteres: %d\n", char_counter);
  printf("Numero de lineas: %d\n", line_counter);
}


