#include<stdio.h>
char error[] = "Error, no hay char!" ;

char *corta_string(char *apuntador){

    if(*apuntador !='\0'){
    while(*apuntador !=' ')apuntador++;

  }else{
    apuntador = error;
  }
  if(*apuntador == ' ')apuntador++;
  return apuntador;
}

int main(void){
    char *s="Campos verdes";

    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
