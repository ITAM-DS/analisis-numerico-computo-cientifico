#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CADENA "Campos verdes"


char *voltea_string(char *s){
    char *ptr;
    int n=strlen(s),i;
    ptr = malloc(n+1);
    if(ptr!=NULL)
        for(i=n-1;i>=0;i--)
         *(  ptr+n-1-i)=*(s+i);
        ptr[n]='\0';
    
    return ptr;

}
char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){
    char *s, *s_duplicado;
    s=(char *)malloc(strlen(CADENA)+1);
    s=duplica_string(CADENA);
    s_duplicado = duplica_string(s);
    printf("\n%s\n", s_duplicado);
    s_duplicado=voltea_string(s);
    printf("%s\n\n", s_duplicado);

    free(s_duplicado);	
    free(s);
    return 0;
}
