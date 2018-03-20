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
   char *s_turned;
   s_turned=malloc(strlen(s)+1);
   if(s_turned!=NULL){
       int n=strlen(s)-1;
       for(int i=0; i<strlen(s);i++){
           s_turned[i]=s[n];
             n-=1;
   }   
   s_turned[strlen(s)+1]='\0';
  }
  return s_turned;
}


int main(void){
    char *s;  //se declara apuntador a caracter
    s=malloc(strlen("Campos verdes")+1);  // se asigna memoria con malloc
    s=strcpy(s,"Campos verdes"); //se guarda el string 
    char *s_duplicado;
    char *s_volteado;
    s_duplicado = duplica_string(s); //se duplica igual que en el programa original
    printf("%s\n", s_duplicado);
    s_volteado=voltea_string(s);
    printf("%s\n", s_volteado);
    free(s_volteado);
    free(s_duplicado);
    free(s);

    
    return 0;
}
