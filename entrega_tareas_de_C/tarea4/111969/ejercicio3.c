#include<stdio.h>
#include<string.h>


char *corta_string(char *apuntador){
    size_t len;
    len = strlen(apuntador);
    if(len > 1){
        apuntador=apuntador+1;

    }else {printf("Lo siento, el string solamente tiene un carcater");}
    
    return apuntador;
}

char *corta_string2(char *apuntador){
    size_t len;
    char *ret;
    len = strlen(apuntador);
    if(len > 1){
        apuntador=apuntador+1;
        
        const char ch = ' ';
        ret = strchr(apuntador,ch);


    }else {printf("Lo siento, el string solamente tiene un carcater");}
    
    return ret;
}


int main(void){
    printf("-----Prueba con mas de un carcater-----\n");
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);
    printf("\n\n");
    printf("-----Prueba con un carcater-----\n");
        char *c="C";
    s=corta_string(c);
    printf("%s\n",c);
    printf("\n\n");
    printf("-----Inciso b) imprima solo verdes -----\n");
    printf("Aqu modificamos el main directamente\n\n");
    char z[] = "Campos verdes";
    char *ret;
    const char ch = ' ';
    ret = strchr(z,ch);
    printf("%s\n",ret);
    printf("-----Inciso b2) imprima solo verdes -----\n");
    printf("Aqui modificamos la funcion corta_string2 para que lo haga desde ahi \n\n");
    char *f = "Campos verdes";
    f=corta_string2(f);
    printf("%s\n",f);
 
return 0;
}

