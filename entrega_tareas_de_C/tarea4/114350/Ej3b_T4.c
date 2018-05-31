#include<stdio.h>
char *corta_string(char *apuntador){
    int i;
    i=0;
    char *pointer = apuntador;
    while(*pointer != '\0'){     // lógica del ejercicio 1 
        i++;
        pointer++;
    }

    if (i == 0){
        printf("ERROR");
        return apuntador;
    }
    else{
        apuntador=apuntador+1;
        return apuntador;
    }
    
}

int main(void){
    char *s="Campos verdes";
    s=corta_string((s+5));    //de donde comenzara el nuevo string 
    printf("%s\n",s);
 
return 0;
}