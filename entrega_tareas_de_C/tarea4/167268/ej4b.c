#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){
    char *p;
    p =(char*) malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
char *voltea_string(char *s){
    char *p;
    char t;
    int i = 0;
    int n=strlen(s);
    p = (char*)malloc(strlen(s)+1);
    if (p!=NULL)
	strcpy(p,s);
    while(n>i){
      t = p[i];
      p[i++]=p[--n];
      p[n]=t;
    }
   return p; 
}
int main(void){
    char s[] = "Campos verdes";
    char *p =(char*)malloc(strlen(s)+1);
    char *string_duplica;
    char *string_volteado;
    strcpy(p,s);
    string_duplica=duplica_string(p);
    string_volteado = voltea_string(p);
    printf("%s\n", string_duplica);
    printf("%s\n", string_volteado);
    free(string_duplica);
    free(p);
    return 0;
}
