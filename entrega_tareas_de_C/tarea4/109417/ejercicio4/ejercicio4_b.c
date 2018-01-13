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
    int i = 0;
    int stop = 1;
    p = malloc(strlen(s)+1);
    char *start = s;
    char *end = start + strlen(s) -1;
    while(stop){
      *(p+i) = *end;
       if(*(start+i)=='\0')
	 stop = 0;
      i++;
      end--;
    }
   return p; 
}
int main(void){
    char *s2 = "Campos verdes";
    char *s;
    s = malloc(strlen(s2));
    s = s2;
    char *s_volteado;
    s_volteado = voltea_string(s2);
    printf("%s\n", s_volteado);
    free(s_volteado);
    return 0;
}
