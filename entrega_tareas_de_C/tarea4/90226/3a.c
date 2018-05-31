
#include<stdio.h>
char *corta_string(char *apuntador){
  if(*apuntador != ""){
    apuntador=apuntador+1; 
  }
  else *apuntador = "error";
  return apuntador;
}

int main(void){
  char *s="s";
  s=corta_string(s);
  printf("%s\n",s);
  
  return 0;
}