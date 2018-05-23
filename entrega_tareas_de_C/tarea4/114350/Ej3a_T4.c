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
        printf("ERROR");    // Si el string tiene más de un caracter entonces devuelve el string sin el caracter inicial, si no dice ERROR
        return apuntador;
    }
    else{
        apuntador=apuntador+1;
        return apuntador;
    }
    
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);

    char *s2= "";
    s2=corta_string(s2);
    printf("%s\n", s2);
 
return 0;
}
