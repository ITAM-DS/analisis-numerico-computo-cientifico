#include<stdio.h>
char error[] = "Error, no hay caracter" ;

char *corta_string(char *apuntador){

    if(*apuntador !='\0'){
    apuntador=apuntador+1;

  }else{
    apuntador = error;
  }
  return apuntador;
}

int main(void){
    char *s="";

    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
