#include<stdio.h>
#include <string.h>
char *corta_string(char *apuntador){
        if(apuntador+1=='\0'){
        printf("No hay suficientes strings en %s\n", apuntador);
        return 0;
        }
        else {
        apuntador=apuntador+1;
        return apuntador;
        }
}

int main(void){  
    char s[]="Campos verdes";
    char *p; 
    p=strtok (s," ");
   // printf("%s\n",p);
    p=strtok (NULL, " ,.-");
   // s=corta_string(p);
    printf("%s\n",corta_string(p));
return 0;
}


