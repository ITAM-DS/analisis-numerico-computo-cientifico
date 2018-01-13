#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){  
    char *p;
    p = (char*) malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s){  
    char *v;
    char tem;
    int m=0, n=strlen(s);
    v = (char*) malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(v!=NULL)
        strcpy(v,s);
    while(n>m){
     tem = v[m];
     v[m++] = v[--n];
     v[n] = tem;
 }
 return v;
}

int main(void){
    char s[] = "Campos verdes";
    char*m=(char *)malloc(strlen(s)+1);
    char *s_duplicado;
    char *s_volteado;
    strcpy(m,s);
    s_duplicado = duplica_string(m);
    s_volteado = voltea_string(m);
    printf("%s\n", s_duplicado);
    printf("%s\n", s_volteado);
    free(s_duplicado);
    free(m);
    return 0;
}   
