#include <stdio.h>

int main(void){
  int c;
  int i = 1;
  while((c=getchar()) != EOF){
    if(c == '\n')i++;
  }
  printf("%d\n",i);
 }