
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s){
   char *p;
   int c=strlen(s),i;
   p=malloc(strlen(s)); 
   i=0;
   while(i<c){
   *(p+i)=*(s+c-i-1);
   i++;
   }
   return p;
}



int main(void){
    char *s="Campos verdes";
    char *s_duplicado,*s_voltea;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    s_voltea=voltea_string(s);
    printf("%s\n",s_voltea);
    free(s_voltea);
    return 0;
}
