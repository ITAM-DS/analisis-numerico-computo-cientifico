#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *s);

int main(void){
    char *s = "Campos verdes";
    char *s_volteado=malloc(strlen(s));
    s_volteado = voltea_string(s);
    printf("%s\n",s_volteado);
    free(s_volteado);
    return 0;
}

char *voltea_string(char *s){
  char *aux;
  int i,j;
  aux = malloc(strlen(s)+1);
  i=0;
  j=0;
  for(j=strlen(s)-1;j>=0;j--){
    *(aux+j)=*(s+i);
    i++;
  }
  return aux;
}
