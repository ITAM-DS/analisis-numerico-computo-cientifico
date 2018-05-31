#include<stdio.h>
char *corta_string(char *apuntador){
    if(apuntador[0]=='\0')
      return "ERROR: el string no tiene caracteres";
    else{
      apuntador=apuntador+1;
      return apuntador;
    }
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
