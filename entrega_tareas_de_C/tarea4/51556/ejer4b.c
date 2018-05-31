
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
	char *a;
	int j, i;
	a = malloc(strlen(s)+1);
	i=0;
	if(a !=NULL){
		for(j=strlen(s)-1;j>=0;j--){
			*(a+i) = *(s+j);
			i++;
		}
		*(a+i)='\0';
	}
	return a;
}

int main(void){
    char s[50] = "Campos verdes";
    char *s_duplicado, *s_volteado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    s_volteado = voltea_string(s);
    printf("%s\n", s_volteado);
    free(s_volteado);
    return 0;
}
