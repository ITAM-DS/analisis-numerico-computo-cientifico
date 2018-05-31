// Luis Fernando Cantú
// CU 000125755

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
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
