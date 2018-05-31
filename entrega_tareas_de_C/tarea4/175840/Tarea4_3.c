#include<stdio.h>


char *corta_string(char *apuntador);
int longitud_string(char *s);
void corta_cadena(char *s);


int main(void){
    
    char *s1 ="Campos Verdes";
    char *s2 = "C";
    char *s3 = "Prueba Texto";

    corta_cadena(s1);
    corta_cadena(s2);
    corta_cadena(s3);
 
return 0;
}


void corta_cadena(char *s){
    int i = 0;
    if(longitud_string(s) > 1 ){
        s=corta_string(s);        
        printf("%s\n",s);
    }        
    else 
        printf("La cadena debe ser de longitud mayor a 1\n",s);        


    while(s[i] != ' '){
        s=corta_string(s);
    }
    printf("%s\n",s);
   
}

char *corta_string(char *apuntador){
    apuntador = apuntador + 1;
    return apuntador;
}

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s++;
        i++;
    }

return i;
}