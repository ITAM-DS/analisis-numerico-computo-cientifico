#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *voltea_string(char *s){  
  char *p;
  p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
  if(p!=NULL){
    for (int i = 0; i <= strlen(s); i++) {
     p[i] = s[strlen(s) - i - 1];
    }
}  
    return p;
  
}

int main(void){
  char s[50] = "Campos verdes";
  char *s_duplicado;
  s_duplicado = duplica_string(s);
  printf("%s\n", s_duplicado);
  free(s_duplicado);
  return 0;
}