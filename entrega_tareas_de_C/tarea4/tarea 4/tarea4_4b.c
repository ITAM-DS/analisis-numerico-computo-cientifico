#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *voltea_string(char *s);


char *duplica_string(char *s){
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

int main(void){
  char s[] = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
char *svm = voltea_string(s);
printf("%s\n", svm);
    return 0;
}

char *voltea_string( char *s){
int i = 0;
int a = strlen(s);
char *sv = malloc(a*sizeof(char));

for(i; i<a; i++){
  sv[i] = s[a-(i+1)];

}

return sv;

}
