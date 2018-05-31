#include<stdio.h>
char *corta_string(char *apuntador){
  while(*apuntador != ' ')
    apuntador++;
    
  return ++apuntador;
}

int main(void){
  char *s = "Campos verdes";
  s = corta_string(s);
  printf("%s\n",s);
 
  return 0;
}
