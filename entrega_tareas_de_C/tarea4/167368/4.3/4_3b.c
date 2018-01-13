#include<stdio.h>

char *corta_string(char *apuntador);

int main(void){
    char *s = "Campos Verdes";
    s = corta_string(s);
    printf("%s\n",s);

return 0;
}

char *corta_string(char *apuntador){
    
    int len;
    for (len = 0; *(apuntador+len)!=' '; ++len){ //encuentra ""
    }
    if(len > 0){
        apuntador = apuntador+len; // avanza len
        return apuntador;
    }
    else{
        return "Error!!!";
    }  
}