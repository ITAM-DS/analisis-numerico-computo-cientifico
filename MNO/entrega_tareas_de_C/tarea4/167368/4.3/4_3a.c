#include<stdio.h>

char *corta_string(char *apuntador);

int main(void){
    char *s = "Campos verdes";
    s = corta_string(s);
    printf("%s\n",s);

return 0;
}

char *corta_string(char *apuntador){
    
    int len;
    for (len = 0; *(apuntador+len)!='\0'; ++len){
    }
    //len = strlen(apuntador);
    if(len > 0){
        apuntador = apuntador+1;
        return apuntador;
    }
    else{
        return "Error!!!";
    }  
}