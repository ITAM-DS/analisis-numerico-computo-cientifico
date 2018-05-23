#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *duplica_string(char *s, int len){  
    char *p;
    p = malloc(len+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string (char *str, int len){
    char tmp, *dst;
    char *src;
    src = malloc(len+1); //USamos malloc para alocar memoria en función del len del string
    if(src!=NULL){
        strcpy(src,str);
    }

    src = str;
    dst = src + len -1;
      
        
        while (src < dst) 
        {
            tmp = *src;
            *src++ = *dst;
            *dst-- = tmp;
            
        }
 return str;
}

int main(void){
    
    printf(" -------Programa 1, usa malloc en lugar de[50]------ \n\n");
    printf(" Lo que hacemos es pasar el size del char S[] de forma dinámica a la función duplica \n\n");

    char s[] = "Campos verdes";
    // Lo que hacemos es pasar el size del char S[] de forma dinámica a la función duplica
    size_t len;
    len = strlen(s);
    char *s_duplicado;
    s_duplicado = duplica_string(s,len);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    printf(" \n\n");
    printf(" -------Programa 2 usa malloc y voltea el string------ \n\n");
    
    printf("%s\n",voltea_string(s,len));




    return 0;
}
