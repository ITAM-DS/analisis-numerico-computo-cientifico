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
    char *stv;
    int m, i;
    stv = (char *) malloc(sizeof(char));	
    m = strlen(s);
    for(i=m; i > -1; i--)
	*(stv + i) = *(s + m - 1 -i);
 return stv; 
}

int main(void){
    char *s;
    char *s_duplicado;
    s = (char *) malloc(sizeof(char));
    s = "Campos verdes";
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    printf("voltado: %s\n",voltea_string(s_duplicado));
return 0;
}
