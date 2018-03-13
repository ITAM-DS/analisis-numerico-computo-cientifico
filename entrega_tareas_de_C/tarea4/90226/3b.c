
#include<stdio.h>
char *corta_string(char *apuntador){
  while (*apuntador!=32){
    apuntador=apuntador+1;  
  }
  return apuntador;
}

int main(void){
  char *s="campos verdes";
  s=corta_string(s);
  printf("%s\n",s);
  
  return 0;
}