#include<stdio.h>
#include<string.h>

char *corta_string(char *apuntador){

    if(strlen(apuntador) > 0){
      apuntador = apuntador + 1;
    } else{
      apuntador = "Error";
    }

  // apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s+5);
    printf("%s\n",s);

return 0;
}
