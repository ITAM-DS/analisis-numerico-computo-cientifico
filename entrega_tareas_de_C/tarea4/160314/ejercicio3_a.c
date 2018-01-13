#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int longitud_string(char *s){ //La función recibe como argumento un apuntador
    int i;
    i=0;
    while(*s != '\0'){
       s=s+1;
       i++;
}
return i;

}

int main(void){
    char *s="Campos verdes";
    if(longitud_string(s)>1){
    s=corta_string(s);
    printf("%s\n",s);
    }
    else
    printf("error\n");    
return 0;
}
