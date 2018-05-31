#include<stdio.h>
char *corta_string(char *apuntador){
    if(*apuntador!='\0'){
    apuntador=apuntador+1;
    return apuntador;
}
return "error";
}

int main(void){
    char *s="";
    s=corta_string(s);
    printf("%s\n",s);
 
return 0;
}