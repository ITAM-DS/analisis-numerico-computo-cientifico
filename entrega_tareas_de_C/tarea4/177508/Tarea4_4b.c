#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *voltea_string(char *s){  

int len;
int i=0;
len = strlen(s);
char a[len];

for(i=0;i<=len;i++){
	a[i] = s[len-i];
}
return a;
}


char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){
    char s[50] = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    
    printf("%s",voltea_string(s));
    free(s_duplicado);
    return 0;
}
