#include<stdio.h>
char *corta_string(char *apuntador){
    char *error = "Error";
    apuntador=apuntador+1;
    if(*apuntador != 0)
        return apuntador;
    else
        return error;
}

int main(void){
    char *s="a";
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
